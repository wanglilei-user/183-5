#include <iostream>
#include<string.h>
using namespace std;
int main()
{
	int n, m, c=0;//��������
	string map[100];
	string::size_type position_head[100];
	string::size_type position_end[100];
	cout << "�����ͼ����(���С��100)�� ";
	cin >> n >> m;
	cout << endl;
	cout << "�����ͼ��" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> map[i];
	}
	cout << "��ͼΪ��" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << map[i] << endl;
	}
	cout << "���벡���������ڣ�" << endl;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cout << "��" << i << "���ڣ�" << endl;
		for (int i = 0; i < m; i++)
		{
			cout << map[i] << endl;
		}
		cout << "//////////" << endl;
		for (int i = 0; i < m; i++)
		{
				position_head[i] = map[i].find_first_of('X');
				position_end[i] = map[i].find_last_of('X');
		}
		for (int i = 0; i < m; i++)
		{
			//���򴫲�
			if (i == 0)
			{
				if (position_head[i + 1] != string::npos)
				{
					map[i].at(position_head[i + 1]) = 'X';
				}
			}
			else if (i == m - 1)
			{
				if (position_head[i - 1] != string::npos)
				{
					map[i].at(position_head[i - 1]) = 'X';
				}
			}
			else
			{
				if (position_head[i + 1] != string::npos)
				{
					map[i].at(position_head[i + 1]) = 'X';
				}
				if (position_head[i - 1] != string::npos)
				{
					map[i].at(position_head[i - 1]) = 'X';
				}
			}
			//���򴫲�
			if (position_head[i] > 1)
			{

				if (position_head[i]!= string::npos && map[i].at(position_head[i]) != string::npos)
				{
					if (map[i].at(position_head[i] + 1) != 'P')
					{
					map[i].at(position_head[i] + 1) = 'X';
					}
					map[i].at(position_head[i] - 1) = 'X';
				}
			}
			if (position_end[i] != string::npos && position_end[i] < (n - 1))
			{
					if (map[i].at(position_end[i]) != string::npos)
					{
						if (map[i].at(position_end[i] + 1) != 'P')
						{
							map[i].at(position_end[i] + 1) = 'X';						
						}
						map[i].at(position_end[i] - 1) = 'X';
					}
				
			}
			if (position_head[i]==1)
			{
				map[i].at(0) = 'X';
			}
			if (position_end[i] == n-2)
			{
				map[i].at(n-1) = 'X';
			}
		}
	}
}
