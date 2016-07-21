//CRMenu.h
//2012-6-12-20:56

#ifndef	CRMENU_H
#define CRMENU_H

#include "LDay.h"

struct daoShuRi
{
	Date aNewDate;
	int day;
	string shuXing;
	string name;
};

struct today
{
	Date day;
	string thing;
};

class CRMenu
{
public:
	void printSpace(int spaceNumber, int i=0);
	void getSystemTimeAndDate();
	void helpMeFile();
	void printHelpMe();
	void printDate();
	void printTime();
	void printHeader();
	void cleanScreen();
	void systemExit(int i);
	int faceMain();
private:
	void brain(int i);
	int faceMain1();
	int faceMain2();
	int faceMain3();
    int faceMain12();
    int faceMain123();
	int faceMain124();
	Date nowTime;
};


#endif