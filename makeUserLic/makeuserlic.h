#ifndef MAKEUSERLIC_H
#define MAKEUSERLIC_H

#include <QtWidgets/QMainWindow>
#include <QDialog>
#include <QDateTime>
#include <QTableWidget>
#include <map>
using namespace std;
#include "ui_makeuserlic.h"
#include "ui_newSoft.h"
#include "ui_newLic.h"
#include "UserDB.h"

class makeUserLic : public QMainWindow
{
	Q_OBJECT

public:
	makeUserLic(QWidget *parent = 0);
	~makeUserLic();

	private slots:
		void OnSoftMenu();
		void OnLicMenu();
		void OnTabViewSize();

protected:
	bool GetSoftIdByName(const QString & sSoftName, int & id);
	QWidget * AddPage(const QString & name);
	void InitTabPage(QTableWidget *);

private:
	Ui::makeUserLicClass ui;
};

class CNewSoftDlg : public QDialog
{
	Q_OBJECT
public:
	CNewSoftDlg(QWidget *parent = 0);
	~CNewSoftDlg();

	void GetValue(sSoftRecordInfo & si);

	private slots:
		void OnBtnOk();
private:
	Ui::Dialog ui;
};

class CNewLicDlg : public QDialog
{
	Q_OBJECT
public:
	CNewLicDlg(QWidget *parent = 0);
	~CNewLicDlg();

	void SetSoftMap(const map<QString, int> &);

	void GetValue(sLicRecordInfo & infoLic);
private slots:
	void OnBtnOpenDir();
	void OnBtnMakeLic();
	void OnLicTypeChanged(int);

private:
	Ui::newLic ui;
};

#endif // MAKEUSERLIC_H
