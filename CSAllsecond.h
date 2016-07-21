//CSAllsecond.h
//2012-6-12-17:50
#ifndef CSALLSECOND_H
#define CSALLSECOND_H

#include "LBiJiao.h"

class CSAllsecond
{
private:
	int day;
	int hour1;
	int hour2;
	int minute1;
	int minute2;
	int second1;
	int second2;
	double beginsecond;
	double endsecond;
	double chasecond;
	int wucha;
public:
    void setAllSecond(Date date1, Date date2);
	int getday();
	void getSecond();
	double getWucha();
	double getChasecond();
};
#endif