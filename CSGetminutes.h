//CSGetminutes.h
//2012-6-12-19:40

#ifndef CSGETMINUTES_H
#define CSGETMINUTES_H

#include "CSGethours.h"

class CSGetminutes:public CSGethours
{
private:
	double zongminutes;
	int minutes;
public:
	double getZongminutes();
	int getMinutes();
};
#endif