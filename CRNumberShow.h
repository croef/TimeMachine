//CRNumberShow.h
//2012-6-12-16:30

#ifndef CRNUMBERSHOW_H
#define CRNUMBERSHOW_H


#include "CRNumber.h"


class CRNumberShow
{
public:
	void setShowNumber(int n);
	void show();
protected:
	string setLine(string oldLine, string newLine);
	void getASingleNumber();
private:
	int aSingleNumber;
	int number;
	CRNumber aNumber;
	int theDigitOfTheNumber();
	string line1;
	string line2;
	string line3;
	string line4;
	string line5;
	string space;
};

#endif