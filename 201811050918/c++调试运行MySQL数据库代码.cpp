#include <stdio.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>
#include <string.h>
using namespace std;

#pragma comment(lib,"libmysql.lib")
int main(int argc, char** argv)
{
	MYSQL mysql, * sock;    // 定义数据库连接的句柄，它被用于几乎所有的 MySQL 函数
	MYSQL_RES* res;       // 查询结果集，结构类型
	//MYSQL_FIELD* fd;     // 包含字段信息的结构
	MYSQL_ROW row;       // 存放一行查询结果的字符串数组
	char  qbuf[256];      // 存放查询 sql 语句字符串
	char fun;
	char name[20], address[20], unit[20], phone[20], QQ[20], email[20],category[20];
	int minmum_salary, extra_salary, live_salary, phone_bill, water_ele_bill, house_bill, get_in_bill, sanitary_fee, public_money, should_salary, all_bill, real_salary;
	//char table_name[20];
	//	if (argc != 2) {  // 检查输入参数
	//		fprintf(stderr,"usage : mysql_select <userid>/n/n");
	//		exit(1);
	//	}
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql, "localhost", "root", "123456", "table1835", 0, NULL, 0)))//中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等）
	{
		fprintf(stderr, "Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8mb4");
	system("cls");
	while (1)
	{
		cout << "欢迎来到个人通讯录管理系统！" << endl << endl;
		cout << "请选择功能：（使用回车确认每一项）" << endl << endl;
		cout << "||A.输入通讯信息" << "||B.插入（修改）通讯信息" << "||C.删除通讯信息" << "||D.浏览通讯信息" << "||Q.退出" << endl << endl;
		cin >> fun;
		if (fun == 'A'|| fun == 'a')
		{
			cout << "请输入姓名、住址、单位、电话、QQ、email、分类： "<<endl;
			cin >> name>>address>> unit>> phone>> QQ>> email>> category;
			sprintf_s(qbuf ,"insert into adressbook ( name, address, unit, phone, QQ, email,category) values ('%s','%s','%s','%s','%s','%s','%s');" , name, address, unit, phone, QQ, email,category);
			mysql_query(&mysql,qbuf);
			//此处输入报错代码
			mysql_query(&mysql, "select * from adressbook");
			res = mysql_store_result(&mysql);
			cout << "||" << "姓名" << "||" << "住址" << "||" << "单位" << "||" << "电话" << "||" << "QQ" << "||" << "email" << "||" << "分类" << "||" << endl;
			while (row = mysql_fetch_row(res))//查询表1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6]<< "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'B' || fun == 'b')
		{
			cout << "请输入要改变的信息(name, address, unit, phone, QQ, email,category)：" << endl;
			cin >> name>>phone>>QQ;
			sprintf_s(qbuf, "UPDATE adressbook SET %s='%s' WHERE num='%s';",name,phone,QQ);
			mysql_query(&mysql, qbuf);
			//此处输入报错代码
			mysql_query(&mysql, "select * from adressbook");
			res = mysql_store_result(&mysql);
			cout << "||" << "姓名" << "||" << "住址" << "||" << "单位" << "||" << "电话" << "||" << "QQ" << "||" << "email" << "||" << "分类" << "||" << endl;
			while (row = mysql_fetch_row(res))//查询表1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6]<< "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'C' || fun == 'c')
		{
			cout << "请输入要删除的通讯录姓名：" << endl;
			cin >> name;
			sprintf_s(qbuf, "DELETE FROM adressbook WHERE name='%s';", name);
			mysql_query(&mysql, qbuf);
			//此处输入报错代码
			mysql_query(&mysql, "select * from adressbook");
			res = mysql_store_result(&mysql);
			cout << "||" << "姓名" << "||" << "住址" << "||" << "单位" << "||" << "电话" << "||" << "QQ" << "||" << "email" << "||" << "分类" << "||" << endl;
			while (row = mysql_fetch_row(res))//查询表1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6]<< "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'D' || fun == 'd')
		{
			mysql_query(&mysql, "select * from adressbook");
			res = mysql_store_result(&mysql);
			cout << "||" << "姓名" << "||" << "住址" << "||" << "单位" << "||" << "电话" << "||" << "QQ" << "||" << "email" << "||" << "分类" << "||" << endl;
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6]<< "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'Q' || fun == 'q')
		{
			cout << "Bye."<<endl;
			system("pause");
			exit(1);
		}
		else
		{
			cout << "请输入正确选项！" << endl;
			system("pause");
		}
		//mysql_free_result(res);
		//mysql_close(sock);
		system("cls");
	}
	return 0;
}
