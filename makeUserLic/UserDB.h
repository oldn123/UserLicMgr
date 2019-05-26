#pragma once
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDateTime>
#include <QStringList>
#include <map>
using namespace std;

struct sLicRecordInfo
{
	int		nRecordId;
	int		nSoftId;
	QString sUserName;
	QString sMacCode;
	int		nLicType;
	QString sDisc;
	QDateTime dtStart;
	QDateTime dtEnd;
};


class CUserDB
{
public:
	CUserDB(void);
	~CUserDB(void);

public:
	int GetSoftMap(map<QString,int> & qm);

	int AddSoft(const QString & sSoftName, const QString & sKey);
	int AddUserLic(sLicRecordInfo & );

protected:
	QSqlDatabase m_db;
};

