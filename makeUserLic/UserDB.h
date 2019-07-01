#pragma once
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDateTime>
#include <QStringList>
#include <map>
using namespace std;

struct sSoftRecordInfo
{
	int		nRecordId;	
	QString sName;
	QString	sSoftId;
	QString sKey1;
	QString sKey2;
};

struct sLicRecordInfo
{
	int			nRecordId;
	QString		sSoftId;
	QString		sUserName;
	QString		sMacCode;
	QString		sLicType;
	QString		sDisc;
	QDateTime	dtEnd;
};


class CUserDB
{
public:
	CUserDB(void);
	~CUserDB(void);

public:
	int GetSoftMap(map<QString,int> & qm);
	bool GetSoftInfo(int nIdSoft, sSoftRecordInfo &);

	int AddSoft(sSoftRecordInfo & );
	int AddUserLic(sLicRecordInfo & );

protected:
	QSqlDatabase m_db;
};

