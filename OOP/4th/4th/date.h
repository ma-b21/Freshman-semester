#pragma once
const int day1[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};
const int day2[13]{0,31,29,31,30,31,30,31,31,30,31,30,31};
class date
{
private:
	int year;
	int month;
	int day;
public:

	date() :year(0), month(0), day(0){};
	~date() {};
	void set_date(int i, int j, int k);
	void show_date();
	bool Is_leap();
	void compute_date(int n);
};
