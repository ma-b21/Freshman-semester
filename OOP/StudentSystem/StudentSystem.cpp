#include "StudentSystem.h"
#include<iostream>
using namespace std;
void StudentSystem::System_remind()
{
	cout << "请输入你希望进行的操作：\n";
	cout << "1：从文件中导入成绩到当前表单；\n";
	cout << "2：向当前表单中添加成绩；\n";
	cout << "3：删除当前表单中指定学号及其成绩；\n";
	cout << "4：删除当前表单所有数据；\n";
	cout << "5：修改当前表单中指定学号的成绩；\n";
	cout << "6：查询当前表单中指定学号的成绩；\n";
	cout << "7：显示当前表单中所有数据；\n";
	cout << "8：将当前表单导出到文件中；\n";
	cout << "-1：退出管理系统；\n";
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
		default:cout << "请输入合法指令！" << endl;
		}
		System_remind();
		cin >> choice;
	}
}
