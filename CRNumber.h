//CRNumber.h
//2012-6-12-15:49

#ifndef CRNUMBER_H
#define CRNUMBER_H

#include <iostream>
using namespace std;

class CRNumber
{
public:
	void setNumber(int n);
	string getLine1();
	string getLine2();
	string getLine3();
	string getLine4();
	string getLine5();
private:
	int number;
	string line;
};

#endif