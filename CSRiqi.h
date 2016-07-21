//CSRiqi.h
//2012-6-15-12:00

#ifndef CSRIQI_H
#define CSRIQI_H
class CSRiqi
{
private:
	int year;
	int month;
	int day;
	int days;
	int panyear(int y);
	int panmonth(int m,int y);
public:
	void getdate(int y,int m,int d,int ds);
	int getday();
	int getyear();
	int getmonth();
};
#endif