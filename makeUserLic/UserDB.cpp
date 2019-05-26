#include "UserDB.h"
#include <QtGlobal>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <QFileInfo>

CUserDB::CUserDB(void)
{
	char * sDbName = "user.db";
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName(sDbName);
	if (!m_db.open())
	{
		Q_ASSERT(0);
		qDebug() << "Error: Failed to connect database." << m_db.lastError();
	}
	else
	{
		qDebug() << "Succeed to connect database." ;
	}
}


CUserDB::~CUserDB(void)
{
}

int CUserDB::GetSoftMap(map<QString,int> & qm)
{
	QSqlQuery sql_query;
	QString selectsql;
	selectsql ="select * from soft" ;//�Ƿ��Ѿ����ڱ�car_bayonet_info
	sql_query.exec(selectsql);
	while(sql_query.next())
	{
		QString name = sql_query.value(1).toString();
		qm[name] = sql_query.value(0).toInt();
	}
	return qm.size();
}

int CUserDB::AddSoft( const QString & sSoftName, const QString & sKey )
{
	//��������
	QSqlQuery sql_query;
	
	QString selectsql;
	selectsql ="select * from sqlite_master where type = 'table' and name = 'soft'" ;//�Ƿ��Ѿ����ڱ�car_bayonet_info
	sql_query.exec(selectsql);
	if(!sql_query.next())
	{
		if(!sql_query.exec("create table soft(id INTEGER PRIMARY KEY AUTOINCREMENT, name text, key text)"))
		{
			qDebug() << "Error: Fail to create table."<< sql_query.lastError();
			return 0;
		}
		else
		{
			qDebug() << "Table created!";
		}		
	}

	selectsql.sprintf("INSERT INTO soft VALUES(NULL, '%s', '%s')", sSoftName.toStdString().c_str(), sKey.toStdString().c_str());
	if(!sql_query.exec(selectsql))
	{
		qDebug() << sql_query.lastError();
	}
	else
	{
		qDebug() << "inserted Wang!";
	}

	return 	sql_query.lastInsertId().toInt();
}

int CUserDB::AddUserLic(sLicRecordInfo & info)
{
	QSqlQuery sql_query;

	QString selectsql;
	selectsql ="select * from sqlite_master where type = 'table' and name = 'lic'" ;//�Ƿ��Ѿ����ڱ�car_bayonet_info
	sql_query.exec(selectsql);
	if(!sql_query.next())
	{
		if(!sql_query.exec("create table lic(id INTEGER PRIMARY KEY AUTOINCREMENT, softid INTEGER, username text, type INTEGER, mac text, timeFrom text, timeTo text, disc text)"))
		{
			qDebug() << "Error: Fail to create table."<< sql_query.lastError();
			return 0;
		}
		else
		{
			qDebug() << "Table created!";
		}		
	}
	selectsql.sprintf("INSERT INTO lic VALUES(NULL, %d, '%s', %d, '%s', '%s', '%s', '%s')", 
		info.nSoftId, 
		info.sUserName.toStdString().c_str(), 
		info.nLicType, 
		info.sMacCode.toStdString().c_str(), 
		info.dtStart.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str(), 
		info.dtEnd.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str(), 	
		info.sDisc.toStdString().c_str()
		);
	if(!sql_query.exec(selectsql))
	{
		qDebug() << sql_query.lastError();
	}
	else
	{
		qDebug() << "inserted Wang!";
	}

	return 	sql_query.lastInsertId().toInt();
}