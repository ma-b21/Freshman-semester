#pragma once

#include"file_manage.h"
class StudentSystem
{
private:
	manage_system core;
public:
	StudentSystem() {};
	~StudentSystem() {};
	void System_remind();
	void System_run();
};