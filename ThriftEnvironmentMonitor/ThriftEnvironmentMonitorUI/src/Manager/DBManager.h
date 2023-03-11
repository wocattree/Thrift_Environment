#pragma once
////////////////////////////////
//filename:DBManager.h
//description:brief
//data:2023/3/11 20:51
//author:wocattree
////////////////////////////////

#ifndef MY_SQL_H
#define MY_SQL_H

#include<iostream>
#include<WinSock2.h>
#include<Windows.h>
#include<mysql.h>
#include "../Common/Logs.h"


class DBManager
{
private:
    DBManager();
    ~DBManager();

public:
	////////////////////////////////
	//funcname:GetInstance()
	//description:单例设计模式，默认构造和拷贝构造都是private
	//param:
	//return:
	//data:2022/10/16 13:21:45
	//author:wocattree
	///////////////////////////////
	static DBManager& GetInstance() 
	{
		static DBManager instance;
		return instance;
	}

	//连接数据库 参数为ip 用户名 密码 数据库名 端口
	bool Connect(const char* ip, const char* name, const char* cypher, const char* database_name, const int port);
	//获取表内的字段数
	int GetTableField(const char* table_name);
	//查询表 参数为表名
	bool Query(const char* table_name);
	//自由执行指令
	bool Implement(const char* sentence);


private:
	bool _state;//连接状态 true为已连接
	MYSQL* _mysql;//mysql连接  
	MYSQL_FIELD* _fd;//字段列数组  
	char _field[32][32];//存字段名二维数组  
	MYSQL_RES* _res;//这个结构代表返回行的一个查询结果集  
	MYSQL_ROW _column;//一个行数据的类型安全(type-safe)的表示，表示数据行的列  
	char _query[150];//查询语句  
};

////连接数据库
//m_pDeviceDB.Connect("localhost", "root", "1234", "test", 0);
//printf("\n");
////查询表
//m_pDeviceDB.Query("t_student");
//printf("\n");
////添加内容
//m_pDeviceDB.Implement("insert into t_student values(201916010001, '王五', '2019-09-09', now())");
//printf("\n");
////查询表
//m_pDeviceDB.Query("t_student");
//printf("\n");

#endif // !MY_SQL_H
