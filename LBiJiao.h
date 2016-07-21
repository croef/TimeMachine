//LBiJiao.h
//2012-06-14-14:14
#ifndef LBIJIAO_H
#define LBIJIAO_H

struct Date
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};


class LBiJiao
{
public:
	int biJiao();
	void setDate(Date d1, Date d2);
private:
	Date date1;
	Date date2;
};
#endif