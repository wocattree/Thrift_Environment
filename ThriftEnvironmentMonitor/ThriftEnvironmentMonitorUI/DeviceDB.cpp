﻿#include"DeviceDB.h"

DeviceDB::DeviceDB()
{
    _state = false;
    _mysql = new MYSQL;
    _fd = nullptr;
    memset(_field, NULL, sizeof(_field));
    _res = nullptr;
    _column = nullptr;
    memset(_query, NULL, sizeof(_query));
}

DeviceDB::~DeviceDB()
{
}

bool DeviceDB::Connect(const char* ip, const char* name, const char* cypher, const char* database_name, const int port)
{
    if (true == _state)
    {
        PLOG("info", "Database connected");
        return false;
    }
    //初始化mysql  
    mysql_init(_mysql);
    //返回false则连接失败，返回true则连接成功  
    //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
    if (!(mysql_real_connect(_mysql, ip, name, cypher, database_name, port, NULL, 0)))
    {
        PLOG("err", "Error connecting to database:%s", mysql_error(_mysql));
        return false;
    }
    else
    {
        _state = true;
        PLOG("info", "Connected succeed.");
        return true;
    }
    return true;
}

int DeviceDB::GetTableField(const char* table_name)
{
    if (false == _state)
    {
        PLOG("err", "Database not connected");
        return -1;
    }
    //查询内容
    sprintf_s(_query, "desc %s", table_name); //desc 语句获取字段数
    //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码 
    mysql_query(_mysql, "set names gbk");
    //返回0 查询成功，返回1查询失败  
    if (mysql_query(_mysql, _query))    //执行SQL语句
    {
        PLOG("err", "Query failed (%s)", mysql_error(_mysql));
        return false;
    }
    //获取结果集  
    if (!(_res = mysql_store_result(_mysql)))   //获得sql语句结束后返回的结果集  
    {
        PLOG("err", "Couldn't get result from %s\n", mysql_error(_mysql));
        return false;
    }
    //数据行数即为字段个数
    return mysql_affected_rows(_mysql);
}

bool DeviceDB::Query(const char* table_name)
{
    if (false == _state)
    {
        PLOG("err", "Database not connected");
        return false;
    }
    //获取字段数
    int field = GetTableField(table_name);
    //查询内容
    sprintf_s(_query, "select * from %s", table_name); //执行查询语句 
    //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码 
    mysql_query(_mysql, "set names gbk");
    //返回0 查询成功，返回1查询失败  
    if (mysql_query(_mysql, _query))    //执行SQL语句
    {
        PLOG("err", "Query failed (%s)\n", mysql_error(_mysql));
        return false;
    }
    else
    {
        PLOG("info", "query success");
    }
    //获取结果集  
    if (!(_res = mysql_store_result(_mysql)))   //获得sql语句结束后返回的结果集  
    {
        PLOG("err", "Couldn't get result from %s\n", mysql_error(_mysql));
        return false;
    }
    //打印数据行数  
    PLOG("info", "number of dataline returned: %lld\n", mysql_affected_rows(_mysql));

    //获取字段的信息  
    char* str_field[32];  //定义一个字符串数组存储字段信息  
    for (int i = 0; i < field; i++)  //在已知字段数量的情况下获取字段名  
    {
        str_field[i] = mysql_fetch_field(_res)->name;
    }
    for (int i = 0; i < field; i++)  //打印字段  
    {
        PLOG("info", "%10s\t", str_field[i]);
    }
    PLOG("info", "   ");
    //打印获取的数据  
    while (_column = mysql_fetch_row(_res))   //在已知字段数量情况下，获取并打印下一行  
    {
        for (int i = 0; i < field; i++)
        {
            PLOG("info", "%10s\t", _column[i]);//column是列数组  
        }
        PLOG("info", "   ");
    }
    return true;
}

bool DeviceDB::Implement(const char* sentence)
{
    if (false == _state)
    {
        PLOG("err", "Database not connected");
        return false;
    }
    //查询内容
    sprintf_s(_query, "%s", sentence); //desc 语句获取字段数
    //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码 
    mysql_query(_mysql, "set names utf8");
    //执行SQL语句
    if (mysql_query(_mysql, _query))
    {
        PLOG("err", "Query failed (%s)\n", mysql_error(_mysql));
        return false;
    }
    return true;
}
