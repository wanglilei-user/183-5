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
	MYSQL mysql, * sock;    // �������ݿ����ӵľ�����������ڼ������е� MySQL ����
	MYSQL_RES* res;       // ��ѯ��������ṹ����
	//MYSQL_FIELD* fd;     // �����ֶ���Ϣ�Ľṹ
	MYSQL_ROW row;       // ���һ�в�ѯ������ַ�������
	char  qbuf[256];      // ��Ų�ѯ sql ����ַ���
	char fun;
	char name[20], address[20], unit[20], phone[20], QQ[20], email[20],category[20];
	int minmum_salary, extra_salary, live_salary, phone_bill, water_ele_bill, house_bill, get_in_bill, sanitary_fee, public_money, should_salary, all_bill, real_salary;
	//char table_name[20];
	//	if (argc != 2) {  // ����������
	//		fprintf(stderr,"usage : mysql_select <userid>/n/n");
	//		exit(1);
	//	}
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql, "localhost", "root", "123456", "table1835", 0, NULL, 0)))//�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ�
	{
		fprintf(stderr, "Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8mb4");
	system("cls");
	while (1)
	{
		cout << "��ӭ��������ͨѶ¼����ϵͳ��" << endl << endl;
		cout << "��ѡ���ܣ���ʹ�ûس�ȷ��ÿһ�" << endl << endl;
		cout << "||A.����ͨѶ��Ϣ" << "||B.���루�޸ģ�ͨѶ��Ϣ" << "||C.ɾ��ͨѶ��Ϣ" << "||D.���ͨѶ��Ϣ" << "||Q.�˳�" << endl << endl;
		cin >> fun;
		if (fun == 'A'|| fun == 'a')
		{
			cout << "������������סַ����λ���绰��QQ��email�����ࣺ "<<endl;
			cin >> name>>address>> unit>> phone>> QQ>> email>> category;
			sprintf_s(qbuf ,"insert into adressbook ( name, address, unit, phone, QQ, email,category) values ('%s','%s','%s','%s','%s','%s','%s');" , name, address, unit, phone, QQ, email,category);
			mysql_query(&mysql,qbuf);
			//�˴����뱨�����
			mysql_query(&mysql, "select * from adressbook");
			res = mysql_store_result(&mysql);
			cout << "||" << "����" << "||" << "סַ" << "||" << "��λ" << "||" << "�绰" << "||" << "QQ" << "||" << "email" << "||" << "����" << "||" << endl;
			while (row = mysql_fetch_row(res))//��ѯ��1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6]<< "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'B' || fun == 'b')
		{
			cout << "������Ҫ�ı����Ϣ(name, address, unit, phone, QQ, email,category)��" << endl;
			cin >> name>>phone>>QQ;
			sprintf_s(qbuf, "UPDATE adressbook SET %s='%s' WHERE num='%s';",name,phone,QQ);
			mysql_query(&mysql, qbuf);
			//�˴����뱨�����
			mysql_query(&mysql, "select * from adressbook");
			res = mysql_store_result(&mysql);
			cout << "||" << "����" << "||" << "סַ" << "||" << "��λ" << "||" << "�绰" << "||" << "QQ" << "||" << "email" << "||" << "����" << "||" << endl;
			while (row = mysql_fetch_row(res))//��ѯ��1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6]<< "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'C' || fun == 'c')
		{
			cout << "������Ҫɾ����ͨѶ¼������" << endl;
			cin >> name;
			sprintf_s(qbuf, "DELETE FROM adressbook WHERE name='%s';", name);
			mysql_query(&mysql, qbuf);
			//�˴����뱨�����
			mysql_query(&mysql, "select * from adressbook");
			res = mysql_store_result(&mysql);
			cout << "||" << "����" << "||" << "סַ" << "||" << "��λ" << "||" << "�绰" << "||" << "QQ" << "||" << "email" << "||" << "����" << "||" << endl;
			while (row = mysql_fetch_row(res))//��ѯ��1
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
			cout << "||" << "����" << "||" << "סַ" << "||" << "��λ" << "||" << "�绰" << "||" << "QQ" << "||" << "email" << "||" << "����" << "||" << endl;
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
			cout << "��������ȷѡ�" << endl;
			system("pause");
		}
		//mysql_free_result(res);
		//mysql_close(sock);
		system("cls");
	}
	return 0;
}
