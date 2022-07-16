#include "StudentSystem.h"
#include<iostream>
using namespace std;
void StudentSystem::System_remind()
{
	cout << "��������ϣ�����еĲ�����\n";
	cout << "1�����ļ��е���ɼ�����ǰ����\n";
	cout << "2����ǰ������ӳɼ���\n";
	cout << "3��ɾ����ǰ����ָ��ѧ�ż���ɼ���\n";
	cout << "4��ɾ����ǰ���������ݣ�\n";
	cout << "5���޸ĵ�ǰ����ָ��ѧ�ŵĳɼ���\n";
	cout << "6����ѯ��ǰ����ָ��ѧ�ŵĳɼ���\n";
	cout << "7����ʾ��ǰ�����������ݣ�\n";
	cout << "8������ǰ���������ļ��У�\n";
	cout << "-1���˳�����ϵͳ��\n";
}
void StudentSystem::System_run()
{
	int choice{ 0 };
	System_remind();
	cin >> choice;
	while (1)
	{
		if (choice == -1) break;
		switch (choice)
		{
		case 1:core.read_data(); break;
		case 2:core.add_data(); break;
		case 3:core.delete_by_num(); break;
		case 4:core.delete_all(); break;
		case 5:core.change_data(); break;
		case 6:core.search_by_num(); break;
		case 7:core.show_all(); break;
		case 8:core.save_data(); break;
		default:cout << "������Ϸ�ָ�" << endl;
		}
		System_remind();
		cin >> choice;
	}
}
