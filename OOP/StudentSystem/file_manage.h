#pragma once
#include<vector>
using namespace std;
struct student {
	long long number=0;
	int grade=0;
};
class manage_system
{
private:
	vector<student>S;
public:
	manage_system() {};
	~manage_system() {};
	void read_data();
	void add_data();
	void delete_by_num();
	void delete_all();
	void change_data();
	void search_by_num();
	void show_all();
	void save_data();
};