//CSGetseconds.h
//2012-6-12-20:05
#ifndef CSGETSECOND_H
#define CSGETSECOND_H

#include "CSGetminutes.h"

class CSGetseconds:public CSGetminutes
{
private:
	double zongseconds;
	int seconds;
public:
	double getZongseconds();
	int getSeconds();
};

#endif