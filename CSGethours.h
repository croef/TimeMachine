//CSGethours.h
//2012-6-12-18:47

#ifndef CSGETHOURS_H
#define CSGETHOURS_H
#include "CSAllsecond.h"
class CSGethours :public CSAllsecond
{
private:
	double zonghours;
	int hours;
public:
    double getZonghours();
    int getHours();
};
#endif
