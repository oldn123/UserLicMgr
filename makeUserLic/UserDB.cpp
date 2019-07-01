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

bool CUserDB::GetSoftInfo(int nIdSoft, sSoftRecordInfo & info)
{
	QSqlQuery sql_query;
	QString selectsql;
	selectsql ="select * from soft while " ;//是否已经存在表car_bayonet_info
	sql_query.exec(selectsql);
	while(sql_query.next())
	{
		QString name = sql_query.value(1).toString();
		qm[name] = sql_query.value(0).toInt();
	}


	return true;
}

int CUserDB::GetSoftMap(map<QString,int> & qm)
{
	QSqlQuery sql_query;
	QString selectsql;
	selectsql ="select * from soft" ;//是否已经存在表car_bayonet_info
	sql_query.exec(selectsql);
	while(sql_query.next())
	{
		QString name = sql_query.value(1).toString();
		qm[name] = sql_query.value(0).toInt();
	}
	return qm.size();
}

int CUserDB::AddSoft( sSoftRecordInfo & sri )
{
	//创建表格
	QSqlQuery sql_query;
	
	QString selectsql;
	selectsql ="select * from sqlite_master where type = 'table' and name = 'soft'" ;//是否已经存在表car_bayonet_info
	sql_query.exec(selectsql);
	if(!sql_query.next())
	{
		if(!sql_query.exec("create table soft(id INTEGER PRIMARY KEY AUTOINCREMENT, name text, softId text, key1 text, key2 text)"))
		{
			qDebug() << "Error: Fail to create table."<< sql_query.lastError();
			return 0;
		}
		else
		{
			qDebug() << "Table created!";
		}		
	}

	selectsql.sprintf("INSERT INTO soft VALUES(NULL, '%s', '%s', '%s', '%s')", sri.sName.toStdString().c_str(), sri.sSoftId.toStdString().c_str(), sri.sKey1.toStdString().c_str(), sri.sKey2.toStdString().c_str());
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
	selectsql ="select * from sqlite_master where type = 'table' and name = 'lic'" ;//是否已经存在表car_bayonet_info
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
	selectsql.sprintf("INSERT INTO lic VALUES(NULL, %s, '%s', %s, '%s', '%s', '%s')", 
		info.sSoftId, 
		info.sUserName.toStdString().c_str(), 
		info.sLicType.toStdString().c_str(), 
		info.sMacCode.toStdString().c_str(), 
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
