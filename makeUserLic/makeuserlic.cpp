#include "makeuserlic.h"
#include <QMessageBox>


CNewSoftDlg::CNewSoftDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

CNewSoftDlg::~CNewSoftDlg()
{

}

void CNewSoftDlg::GetValue(QString & sName, QString & sKey)
{
	sName = ui.lineEdit_userName->text();
	sKey = ui.lineEdit_Key->text();
}

CNewLicDlg::CNewLicDlg(QWidget *parent)
{
	ui.setupUi(this);
}

CNewLicDlg::~CNewLicDlg()
{

}

void CNewLicDlg::GetValue(sLicRecordInfo & infoLic)
{
	infoLic.nSoftId = ui.comboBox_softName->currentData().toInt();
	infoLic.nLicType = ui.comboBox_LicType->currentIndex();
	infoLic.sDisc = ui.lineEdit_disc->text();
	infoLic.sUserName = ui.lineEdit_userName->text();
	infoLic.sMacCode = ui.lineEdit_macCode->text();
	infoLic.dtStart = ui.dateTimeEdit_from->dateTime();
	infoLic.dtEnd = ui.dateTimeEdit_to->dateTime();
}

void CNewLicDlg::SetSoftMap(const map<QString, int> & softmap)
{
	for (auto iter = softmap.begin(); iter != softmap.end(); iter++)
	{
		ui.comboBox_softName->addItem(iter->first, iter->second);
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
	if(m_db.GetSoftMap(qm) > 0)
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
		QString sName, sKey;
		pdlg->GetValue(sName, sKey);
		if(m_db.AddSoft(sName, sKey) > 0){
			AddPage(sName);
		}
		else{
			QMessageBox::warning(this, "add faild", "warning");
		}
	}
	delete pdlg;
}

void makeUserLic::OnLicMenu()
{
	CNewLicDlg dlg;
	map<QString,int> qm;
	if(m_db.GetSoftMap(qm) < 1)
	{
		QMessageBox::warning(this, "add soft first please!", "warning");
		return ;
	}

	dlg.SetSoftMap(qm);
	dlg.show();
	int n = dlg.exec();
	if (n == 1)
	{
		sLicRecordInfo mli;
		dlg.GetValue(mli);
		if(m_db.AddUserLic(mli) > 0){}
		else{
			QMessageBox::warning(this, "add faild", "warning");
		}
	}
}