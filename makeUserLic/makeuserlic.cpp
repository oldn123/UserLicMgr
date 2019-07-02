#include "makeuserlic.h"
#include <QMessageBox>
#include <QApplication>
#include <QDesktopServices>
#include <qdir.h>
#include "..\codedepend\LicSupport.h"
#ifdef QT_DEBUG
#pragma comment(lib, "..\\win32\\debug\\codedepend.lib")
#else
#pragma comment(lib, "..\\win32\\release\\codedepend.lib")
#endif

string qstr2str(const QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return string(cdata);
}

QString str2qstr(const string str)
{
	return QString::fromLocal8Bit(str.data());
}

CNewSoftDlg::CNewSoftDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(OnBtnOk()));
}

CNewSoftDlg::~CNewSoftDlg()
{

}

void CNewSoftDlg::OnBtnOk()
{
	bool bError = ui.lineEdit_softName->text().length() < 0;
	bError |= ui.lineEdit_Key1->text().length() < 0;
	bError |= ui.lineEdit_Key2->text().length() < 0;
	bError |= ui.lineEdit_softId->text().length() < 0;
	if (bError)
	{
	}
	
}

void CNewSoftDlg::GetValue(sSoftRecordInfo & sri)
{
	sri.sName = ui.lineEdit_softName->text();
	sri.sKey1 = ui.lineEdit_Key1->text();
	sri.sKey2 = ui.lineEdit_Key2->text();
	sri.sSoftId = ui.lineEdit_softId->text();
}

CNewLicDlg::CNewLicDlg(QWidget *parent)
{
	ui.setupUi(this);
	ui.lineEdit_macCode->setPlainText("ZWQ0YTY1ZTVhOGYzZGIxNDliNzhmYWJmOGNhMWM2ZjgwMTVmMTkxZTk2ZmE2NjMzNTNkZjAzNDlmODBlOTBiY2NmZThiYjQ1NmVhMTgzMzc3MjY4ZDkwNzZmZTBkNmFm");
	connect(ui.pushButton_makeLic, SIGNAL(clicked()), this, SLOT(OnBtnMakeLic()));
	connect(ui.opendirBtn, SIGNAL(clicked()), this, SLOT(OnBtnOpenDir()));
	connect(ui.comboBox_LicType, SIGNAL(currentIndexChanged(int)), this, SLOT(OnLicTypeChanged(int)));

	QDateTime dtNow = QDateTime::currentDateTime();
	dtNow = dtNow.addMonths(1);
	ui.dateTimeEdit_to->setDateTime(dtNow);

	ui.comboBox_LicType->clear();
	ui.comboBox_LicType->addItem(QString::fromLocal8Bit("试用-不限ip"), CLicSupport::cTrial_check_time);
	ui.comboBox_LicType->addItem(QString::fromLocal8Bit("试用-限ip"), CLicSupport::cTrial_check_ip_time);
	ui.comboBox_LicType->addItem(QString::fromLocal8Bit("正式-限ip"), CLicSupport::cLegal_check_ip);
	ui.comboBox_LicType->setCurrentIndex(0);
}

CNewLicDlg::~CNewLicDlg()
{

}

void CNewLicDlg::GetValue(sLicRecordInfo & infoLic)
{
	infoLic.sSoftId = ui.comboBox_softName->currentData().toString();
	infoLic.sLicType = ui.comboBox_LicType->currentData().toChar();
	infoLic.sDisc = ui.lineEdit_disc->text();
	infoLic.sUserName = ui.lineEdit_userName->text();
	infoLic.sMacCode = ui.lineEdit_macCode->toPlainText();
	infoLic.dtEnd = ui.dateTimeEdit_to->dateTime();
}

void CNewLicDlg::SetSoftMap(const map<QString, int> & softmap)
{
	for (auto iter = softmap.begin(); iter != softmap.end(); iter++)
	{
		ui.comboBox_softName->addItem(iter->first, iter->second);
	}
}

void CNewLicDlg::OnLicTypeChanged(int nType)
{
	if (nType < 0)
	{
		return;
	}
	char cData = 
		ui.comboBox_LicType->currentData().toChar().unicode();

	if (cData == CLicSupport::cTrial_check_time)
	{
		ui.lineEdit_macCode->setEnabled(false);
	}
	else
	{
		ui.lineEdit_macCode->setEnabled(true);
	}
}

void CNewLicDlg::OnBtnOpenDir()
{
	QString sLicFile = ui.textEdit_licCode->text();
	int nidx = sLicFile.lastIndexOf('\\');
	if (nidx < 0)
	{
		nidx = sLicFile.lastIndexOf('/');
	}
	sLicFile = sLicFile.left(nidx);
	bool ok = QDesktopServices::openUrl(QUrl::fromLocalFile(sLicFile));
	if (!ok)
	{
		QMessageBox::warning(this, "warning", "open path faild");
	}
}

void CNewLicDlg::OnBtnMakeLic()
{
	int nIdxSoft = ui.comboBox_softName->currentData().toInt();
	sSoftRecordInfo sri;
	if(!CUserDB::GetInstance().GetSoftInfo(nIdxSoft,sri))
	{
		QMessageBox::warning(this, "warning", "query record faild");
		return ;
	}

	QString sMacCode = ui.lineEdit_macCode->toPlainText();

	char sMac[100] = {0};
	bool br = CLicSupport::decodeMac(sMac, sMacCode.toStdString().c_str(), "~!@#$%^&", "<>{}()|&");
	QString qPath = QCoreApplication::applicationDirPath();
	if (br)
	{
		QString qUser = ui.lineEdit_userName->text();
		QString qSoft = ui.comboBox_softName->currentText();		
		qPath += "/";
		qPath += qSoft;
		qPath += "/";
		qPath += qUser;
		qPath += "/";
		

		QDir dir;
		if(dir.mkpath(qPath))
		qPath += "license";

		br = CLicSupport::makeLicFile((char*)qstr2str(qPath).c_str(), qstr2str(sri.sSoftId).c_str(), CLicSupport::sKey1, CLicSupport::sKey2, sMac,
			qstr2str(ui.dateTimeEdit_to->text()).c_str(),ui.comboBox_LicType->currentData().toChar().unicode());

		if (!br)
		{
			QMessageBox::warning(this, "warning", "makeLicFile faild~");
		}
		else
		{
			if (strlen(sMac) > 0)
			{
				ui.textEdit_licCode->setText(qPath);
			}
			else
			{
				ui.textEdit_licCode->setText("find error!");
			}
		}
	}
}

makeUserLic::makeUserLic(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.actionSoft, SIGNAL(triggered()), this, SLOT(OnSoftMenu()));
	connect(ui.actionLic, SIGNAL(triggered()), this, SLOT(OnLicMenu()));
	connect(ui.tabWidget, SIGNAL(size()), this, SLOT(OnTabViewSize()));

	for (int i = ui.tabWidget->count() - 1; i >= 0; i--)
	{	
		ui.tabWidget->removeTab(i);
	}

	map<QString,int> qm;
	if(CUserDB::GetInstance().GetSoftMap(qm) > 0)
	{
		for (auto iter = qm.begin(); iter != qm.end(); iter++)
		{
			AddPage(iter->first);
		}
	}
}

makeUserLic::~makeUserLic()
{

}

void makeUserLic::InitTabPage(QTableWidget * ptw)
{
	QStringList header;
	header<<"user_info"<<"mac_code"<<"lic_type"<<"from_time"<<"to_time"<<"discribe";
	ptw->setRowCount(10);
	ptw->setColumnCount(header.size());
	ptw->setHorizontalHeaderLabels(header);
	ptw->setSelectionBehavior(QAbstractItemView::SelectRows);
	QRect rc = ptw->geometry();
	ptw->setColumnWidth(0,100);
}

QWidget *  makeUserLic::AddPage(const QString & name)
{
	QTableWidget * ptw = new QTableWidget;
	int nIdx = ui.tabWidget->addTab(ptw, name);

	ui.tabWidget->setTabText(nIdx, name);
	InitTabPage(ptw);
	return ptw;
}

bool makeUserLic::GetSoftIdByName(const QString & sSoftName, int & id)
{
	id = 0;
	return true;
}

void makeUserLic::OnTabViewSize()
{

}

void makeUserLic::OnSoftMenu()
{
	CNewSoftDlg * pdlg = new CNewSoftDlg(this);
	pdlg->setModal(true);
	pdlg->show();
	int n = pdlg->exec();
	if (n == 1)
	{
		sSoftRecordInfo sri;
		pdlg->GetValue(sri);
		if(CUserDB::GetInstance().AddSoft(sri) > 0){
			AddPage(sri.sName);
		}
		else{
			QMessageBox::warning(this, "warning", "add faild");
		}
	}
	delete pdlg;
}

void makeUserLic::OnLicMenu()
{
	CNewLicDlg dlg;
	map<QString,int> qm;
	if(CUserDB::GetInstance().GetSoftMap(qm) < 1)
	{
		QMessageBox::warning(this, "warning", "add soft first please!");
		return ;
	}

	dlg.SetSoftMap(qm);
	dlg.show();
	int n = dlg.exec();
	if (n == 1)
	{
		sLicRecordInfo mli;
		dlg.GetValue(mli);
		if(CUserDB::GetInstance().AddUserLic(mli) > 0){}
		else{
			QMessageBox::warning(this, "warning", "add faild");
		}
	}
}