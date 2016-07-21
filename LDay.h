//LDay.h
//2012-6-12-16:56

#ifndef LDAY_H
#define LDAY_H

#include<iostream>

#include "LBiJiao.h"

using namespace std;

class LDay
{
private:
	Date newDate;
    Date oldDate;
	int i;
	int j;
	int days;
	LBiJiao aBiJiao;
	void getDay();
public:
	void setDay(Date date1,Date date2);
	int showDay();
};


#endif
