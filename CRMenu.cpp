//CRMenu.cpp
//2012-6-12-21:05

#include "CRMenu.h"
#include "CRNumberShow.h"
#include "CSAllsecond.h"
#include "CSGethours.h"
#include "CSGetminutes.h"
#include "CSGetseconds.h"
#include "LPaiXu.h"
#include "CSRiqi.h"

#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string>

#define TODAYNUMBER 31

using namespace std;

void CRMenu::getSystemTimeAndDate()
{
	time_t now;	
	struct tm *fmt;
	time(&now);
	fmt = localtime(&now);
	nowTime.hour =  fmt->tm_hour;
	nowTime.minute =  fmt->tm_min;
	nowTime.second =  fmt->tm_sec;
	nowTime.year = fmt->tm_year+1900;
	nowTime.month = fmt->tm_mon+1;
	nowTime.day = fmt->tm_mday;
}

void CRMenu::helpMeFile()
{
	ofstream help("help.txt",ios::trunc);
	if (help.is_open())
	{
		help<<"Time machine\n";
		help<<"Hello, welcome to time machine. This software can compute anything of this time to another time.\n";
		help<<"Please do with screen, and enjoy it!\n";
		help<<"The software copyright belongs to ���� ��˧ ������!\n";
		help.close();
	}
}

void CRMenu::printHelpMe()
{
	cout<<"Time machine\n";
	cout<<"Hello, welcome to time machine. This software can compute anything of this time to another time.\n";
	cout<<"Please do with screen, and enjoy it!\n";
	cout<<"The software copyright belongs to ���� ��˧ ������!\n";
}

void CRMenu::printDate()
{
	getSystemTimeAndDate();
	cout<<nowTime.year<<"-"<<nowTime.month<<"-"<<nowTime.day<<endl;
}

void CRMenu::printTime()
{
	getSystemTimeAndDate();
	cout<<nowTime.hour<<":"<<nowTime.minute<<":"<<nowTime.second<<endl;
}

void CRMenu::printSpace(int spaceNumber, int i)
{
	for(int n=0; n<spaceNumber; n++)
		cout<<" ";
	if(i ==1 )
		cout<<endl;
}

void CRMenu::printHeader()

{
	cout<<"==============================================================================="<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout<<"                                  ʱ�⽺��"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout<<"                    ��ӭʹ�ñ�ϵͳ���밴����Ļ��ʾ���в�����"<<endl;
	cout<<"             Weclome to time machine, please operate with screen."<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout<<"==============================================================================="<<endl;
}

int CRMenu::faceMain()
{
	char i;
	int j=-1;
	do{
	j=-1;
	cleanScreen();
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	cout<<"                          1��������"<<endl;
	cout<<"                          2�������������ڵĲ�"<<endl;
	cout<<"                          3�������ĳ�������ĳ�����������"<<endl;
	cout<<"                          4����ʷ�ϵĽ���"<<endl;
	cout<<"                          5������"<<endl;
	cout<<"                          6���˳�"<<endl;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	cout<<"��������Ҫ���еĲ������[1-6]: ";
    cin>>i;
	switch (i){
	case '1': j = faceMain1(); break;
	case '2': j = faceMain2(); break;
	case '3': j = faceMain3(); break;
	case '4': j = 4; break;
	case '5': cleanScreen(); helpMeFile(); printHelpMe(); cout<<endl<<"                           �����������"<<endl;
    j=0; char flog; flog=getch(); break;
	case '6': systemExit(0); break;
	default: j=0; break;
	}
	}while(j == 0);
	brain(j);
	return j;
}

void CRMenu::cleanScreen()
{
	system("cls");
	printHeader();
}

void CRMenu::systemExit(int i)
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout<<"                        ******************"<<endl;
	cout<<"                        *                *"<<endl;
	cout<<"                        *    Bye Bye!    *"<<endl;
	cout<<"                        *                *"<<endl;
    cout<<"                        ******************"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout<<"                                                          By ���� ��˧ ������"<<endl;
	cout<<"                           ��������˳�"<<endl;
	char a;
	a = getch();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE|FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	exit(i);
	
}

int CRMenu::faceMain1()
{
	char i;
	int j;
	do{
	cleanScreen();
	j = -1;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"                          1���鿴�����ձ�"<<endl;
    cout<<"                          2���༭һ�������ձ�"<<endl;
   	cout<<"                          3���������ձ����"<<endl;
   	cout<<"                          4�����ܼ��"<<endl;
	cout<<"                          5������"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"��������Ҫ���еĲ������[1-5]: ";
	cin>>i;
	switch(i){
	case '1': j = 11; break;
	case '2': j = faceMain12(); break;
	case '3': j = 13; break;
	case '4': j = 14; break;
	case '5': j = 0; break;
	default: j=10; break;
	}
	}while ( j == 10);
	return j;
}

int CRMenu::faceMain2()
{
	char i;
	int j;
	do{
	j = -1;
	cleanScreen();
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"                          1����ȷ����"<<endl;
    cout<<"                          2����ȷ��Сʱ"<<endl;
   	cout<<"                          3����ȷ����"<<endl;
   	cout<<"                          4�����ܼ��"<<endl;
	cout<<"                          5������"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"��������Ҫ���еĲ������[1-6]: ";
	cin>>i;
	switch(i){
	case '1': j = 21; break;
	case '2': j = 22; break;
	case '3': j = 23; break;
	case '4': cout<<"-------------------------------------------------------------------------------"<<endl;
		      cout<<"           ͨ�������ܣ������Լ����������ڣ����ӣ�Сʱ֮�����е�����"<<endl;
              j=20; char flog; cout<<"                                �����������"<<endl;flog=getch(); break;
	case '5': j = 0; break;
	default: j=20; break;
	}
	}while(j == 20);
	return j;
}

int CRMenu::faceMain3()
{
	char i;
	int j;
	do{
	j = -1;
	cleanScreen();
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"                          1����ǰ������(��������Ϊ���)"<<endl;
    cout<<"                          2����������"<<endl;
   	cout<<"                          3�����ܼ��"<<endl;
	cout<<"                          4������"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"��������Ҫ���еĲ������[1-4]: ";
	cin>>i;
	switch(i){
	case '1': j = 30; break;
	case '2': j = 32; break;
	case '3': cout<<"-------------------------------------------------------------------------------"<<endl;
		      cout<<endl<<"           ͨ�������ܣ������Լ����ĳ�����ڿ�ʼ������������"<<endl<<endl;
              j=30; char flog; cout<<"                               �����������"<<endl;flog=getch(); break;
	case '4': j = 0; break;
	default: j=30; break;
	}
	}while (j == 30);
	return j;
}

int CRMenu::faceMain12()
{
	char i;
	int j;
	do{
	j = -1;
	cleanScreen();
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"                          1������һ��������"<<endl;
    cout<<"                          2��ɾ��һ��������"<<endl;
   	cout<<"                          3���ı�һ������������"<<endl;
    cout<<"                          4���Ե�������������"<<endl;
	cout<<"                          5������"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"��������Ҫ���еĲ������[1-5]: ";
	cin>>i;
	switch(i){
	case '1': j = 121; break;
	case '2': j = 122; break;
	case '3': j = faceMain123(); break;
	case '4': j = faceMain124(); break;
	case '5': j = 10; break;
	default: j=120; break;
	}
	}while ( j==120);
	return j;
}

int CRMenu::faceMain123()
{
	char i;
	int j;
	do{
	j=-1;
	cleanScreen();
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"                          1������"<<endl;
    cout<<"                          2��������"<<endl;
   	cout<<"                          3������"<<endl;
	cout<<"                          4������"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"��������Ҫ���еĲ������[1-4]: ";
	cin>>i;
	switch (i){
	case '1': j=1231; break;
	case '2': j=1232; break;
	case '3': j=1233; break;
	case '4': j=120; break;
	default: j=1230; break;
	}
	}while (j == 1230);
	return j;
}

int CRMenu::faceMain124()
{
	char i;
	int j;
	do{
	j = -1;
	cleanScreen();
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"                          1������ʣ��ʱ���Դ���С����"<<endl;
    cout<<"                          2������ʣ��ʱ����С��������"<<endl;
	cout<<"                          3������"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"��������Ҫ���еĲ������[1-3]: ";
	cin>>i;
	switch(i){
	case '1': j = 1241; break;
	case '2': j = 1242; break;
	case '3': j = 120; break;
	default: j=1240; break;
	}
	}while (j == 1240);
	return j;
}

void CRMenu::brain(int i)
{
	cleanScreen();
	LDay theNumberOfDays;
	Date date1={0}, date2={0};
    CRNumberShow showANumber;
    CSGetseconds aSecond;
	daoShuRi aDay[21], newDaoShuRi;
	today newToday[TODAYNUMBER];
	int jishu = 0, j=0, flog=0;
	char xuan;
	char diZhi[80];
	LPaiXu paiXu;
	CSRiqi aNewFeatureRiQi;
	ofstream daymatter;
	ofstream deleteDaysMatter;
	ofstream saveDaysMatter;
	fstream daysMatter;
	fstream todayTxt("today.txt",ios::app||ios::out);
	switch(i)
	{
	case 21:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"          �������������ڣ���������\"-\" ��������ڼ��Կո�����"<<endl;
		cout<<"                 ���� \"1992-09-12 2012-6-14\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d%d-%d-%d",&date1.year,&date1.month,&date1.day,&date2.year,&date2.month,&date2.day);
		theNumberOfDays.setDay(date1, date2);
		aSecond.setAllSecond(date1,date2);
		if(theNumberOfDays.showDay()>=0&&theNumberOfDays.showDay()<=99999999)
		{
			showANumber.setShowNumber(theNumberOfDays.showDay());
			cout<<endl<<"                  ���������ڼ��  (��)"<<endl<<endl;
			showANumber.show();
			cout<<endl;
			cout<<"                �ܹ�"<<aSecond.getZonghours()<<"Сʱ"<<endl;
			cout<<"                �ܹ�"<<aSecond.getZongminutes()<<"����"<<endl;
			cout<<"                �ܹ�"<<aSecond.getZongseconds()<<"��"<<endl;
		}else
			cout<<endl<<"������ֳ���Ԥ��"<<endl;
		break;
	case 22:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             ����������ʱ��"<<endl;
		cout<<"               ��������\"-\" �����ʱ����\",\"��������ڼ��Կո���"<<endl;
		cout<<"                 ���� \"1992-09-12,8 2012-6-14,16\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d%,%d%d-%d-%d,%d",&date1.year,&date1.month,&date1.day,&date1.hour,&date2.year,&date2.month,&date2.day,&date2.hour);
        theNumberOfDays.setDay(date1, date2);
		aSecond.setAllSecond(date1,date2);
		cout<<endl<<"                           ���������ڼ��"<<endl<<endl;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
        cout<<"                *********************************"<<endl;
     	cout<<"                                        "<<endl;
	    cout<<"                            �ܹ�"<<theNumberOfDays.showDay()<<"��"<<endl;
	    cout<<"                                        "<<endl;
        cout<<"                *********************************"<<endl;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		cout<<endl;
		cout<<"                �ܹ�"<<aSecond.getZonghours()<<"Сʱ"<<endl;
		cout<<"                �ܹ�"<<aSecond.getZongminutes()<<"����"<<endl;
		cout<<"                �ܹ�"<<aSecond.getZongseconds()<<"��"<<endl;
		break;
	case 23:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             ����������ʱ��"<<endl;
		cout<<"               ��������\"-\" �����ʱ����\",\"��\":\"��������ڼ��Կո���"<<endl;
		cout<<"                 ���� \"1992-09-12,8:13 2012-6-14,16:53\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d%,%d:%d%d-%d-%d,%d:%d",&date1.year,&date1.month,&date1.day,&date1.hour,&date1.minute,&date2.year,&date2.month,&date2.day,&date2.hour,&date2.minute);
        theNumberOfDays.setDay(date1, date2);
		aSecond.setAllSecond(date1,date2);
		cout<<endl<<"                           ���������ڼ��"<<endl<<endl;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
        cout<<"                *********************************"<<endl;
     	cout<<"                                        "<<endl;
	    cout<<"                            �ܹ�"<<theNumberOfDays.showDay()<<"��"<<endl;
	    cout<<"                                        "<<endl;
        cout<<"                *********************************"<<endl;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		cout<<endl;
		cout<<"                �ܹ�"<<aSecond.getZonghours()<<"Сʱ"<<endl;
		cout<<"                �ܹ�"<<aSecond.getZongminutes()<<"����"<<endl;
		cout<<"                �ܹ�"<<aSecond.getZongseconds()<<"��"<<endl;
		break;
	case 11:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             ����������"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
    	daysMatter.open("DaysMatter.txt",ios::app||ios::out);
		if (daysMatter.is_open())
		{
			jishu=0;
			do
			{
				daysMatter>>aDay[jishu].shuXing;
				daysMatter>>aDay[jishu].name;
				daysMatter>>aDay[jishu].aNewDate.year;
				daysMatter>>aDay[jishu].aNewDate.month;
				daysMatter>>aDay[jishu].aNewDate.day;
				daysMatter>>aDay[jishu].day;
				jishu++;

			}while(jishu<20&&aDay[jishu-1].aNewDate.day>0);
			for(j = 0; j<jishu-1; j++)
			{
				cout<<"-------------------------------------------------------------------------------"<<endl;
				cout<<"  ���� "<<aDay[j].shuXing<<"  "<<aDay[j].name<<"  "<<aDay[j].aNewDate.year<<"-"<<aDay[j].aNewDate.month<<"-"<<aDay[j].aNewDate.day<<" ����(��)"<<endl;
				CRNumberShow ashowANumber;
				ashowANumber.setShowNumber(aDay[j].day);
				ashowANumber.show();
				cout<<"-------------------------------------------------------------------------------"<<endl;
			}

		}
		if(!daysMatter.is_open()||j == 0)
			cout<<"                  ����û�е������������ȴ���������"<<endl;
		break;
	case 121:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             ����һ������������"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"                       ������һ�������ڣ���������\"-\" ���"<<endl;
		cout<<"                            ���� \"1992-09-12\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d",&date1.year,&date1.month,&date1.day);
		getSystemTimeAndDate();
		cout<<"                             ��ѡ�����յ�����"<<endl;
		cout<<"                         1������ 2�������� 3������"<<endl;

		do{
		cin>>xuan;
		switch(xuan){
		case '1': newDaoShuRi.shuXing="����"; break;
    	case '2': newDaoShuRi.shuXing="������"; break;
		case '3': newDaoShuRi.shuXing="����"; break;
		default : cout<<"               ���벻��ȷ������������"<<endl; j=-121; break;
		}
		}while(j==-121);
		theNumberOfDays.setDay(date1,nowTime);
		newDaoShuRi.day=theNumberOfDays.showDay();
		newDaoShuRi.aNewDate=date1;
		cout<<"�����뵹���յ�����"<<endl;
		cin>>newDaoShuRi.name;
		daymatter.open("DaysMatter.txt",ios::app|ios::out);
		if(daymatter.is_open())
		{
			daymatter<<newDaoShuRi.shuXing;
			daymatter<<" ";
			daymatter<<newDaoShuRi.name;
			daymatter<<" ";
			daymatter<<newDaoShuRi.aNewDate.year;
			daymatter<<" ";
			daymatter<<newDaoShuRi.aNewDate.month;
			daymatter<<" ";
			daymatter<<newDaoShuRi.aNewDate.day;
			daymatter<<" ";
			daymatter<<newDaoShuRi.day;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			cout<<"                              ����ɹ���"<<endl<<"�ɹ���Ӵ�����"<<endl;
			cout<<"  ���� "<<newDaoShuRi.shuXing<<"  "<<newDaoShuRi.name<<"  "<<newDaoShuRi.aNewDate.year<<"-"<<newDaoShuRi.aNewDate.month<<"-"<<newDaoShuRi.aNewDate.day<<" ����(��)"<<endl;
			showANumber.setShowNumber(newDaoShuRi.day);
			showANumber.show();
			daymatter<<"\n";
		}
		
		break;
	case 14:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                                  ������"<<endl;
		cout<<"                ��ģ�������������һ�������������鿴���༭����"<<endl;
		cout<<"          ��Ҳ����ͨ��ѡ����е����յ����򣬲���浽����λ�ã�����ķ�������ˡ�"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		break;
	case 4:
		
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                                ��ʷ�ϵĽ���"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		if(todayTxt.is_open())
		{
			jishu = 0;
			do
			{
				todayTxt>>newToday[jishu].day.year;
				todayTxt>>newToday[jishu].day.month;
				todayTxt>>newToday[jishu].day.day;
				todayTxt>>newToday[jishu].thing;
				jishu++;
			}while(jishu<TODAYNUMBER);
			getSystemTimeAndDate();
			for(j = 0; j <TODAYNUMBER; j++)
			{
				if(newToday[j].day.month == nowTime.month&&newToday[j].day.day == nowTime.day)
				{
					cout<<"      "<<newToday[j].day.year<<"�� "<<newToday[j].day.month<<"�� "<<newToday[j].day.day<<"��   "<<newToday[j].thing<<endl;
					flog=1;
				}
			}
			if(flog == 0)cout<<"���ݿ���û�б����ڵ�����"<<endl;

		}else cout<<"                            ���ݿ��ļ�δ������"<<endl;
		todayTxt.close();
		break;
	case 32:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             ����һ������������"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"                       ������һ�������ڣ���������\"-\" ���"<<endl;
		cout<<"                            ���� \"1992-09-12\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d",&date1.year,&date1.month,&date1.day);
		cout<<"                             �������������:";
		cin>>j;
		aNewFeatureRiQi.getdate(date1.year, date1.month, date1.day, j);
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"  ����"<<date1.year<<"-"<<date1.month<<"-"<<date1.day<<"  "<<j<<"���������  "<<aNewFeatureRiQi.getyear()<<"-"<<aNewFeatureRiQi.getmonth()<<"-"<<aNewFeatureRiQi.getday()<<endl;
		cout<<endl;
		break;
	case 122:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             ����������"<<endl;
		daysMatter.open("DaysMatter.txt",ios::app||ios::out);
    	if (daysMatter.is_open())
		{
			jishu=0;
			do
			{
				daysMatter>>aDay[jishu].shuXing;
				daysMatter>>aDay[jishu].name;
				daysMatter>>aDay[jishu].aNewDate.year;
				daysMatter>>aDay[jishu].aNewDate.month;
				daysMatter>>aDay[jishu].aNewDate.day;
				daysMatter>>aDay[jishu].day;
				jishu++;
			}while(jishu<20&&aDay[jishu-1].aNewDate.day>0);
			for(j = 0; j<jishu-1; j++)
			{
				cout<<"-------------------------------------------------------------------------------"<<endl;
				cout<<"                               ��"<<j+1<<"��"<<endl;
				cout<<"                ���� "<<aDay[j].shuXing<<"  "<<aDay[j].name<<"  "<<aDay[j].aNewDate.year<<"-"<<aDay[j].aNewDate.month<<"-"<<aDay[j].aNewDate.day<<" ����"<<aDay[j].day<<"��"<<endl;
			}
		}
		if(!daysMatter.is_open()||j == 0)
			cout<<"                  ����û�е������������ȴ���������"<<endl;
		else
		{
			cout<<"-------------------------------------------------------------------------------"<<endl;
			cout<<"������Ҫɾ������Ŀ��: ";
			cin>>flog;
			if(flog>jishu-1||flog<0) cout<<endl<<"������Ŀ������"<<endl;
			deleteDaysMatter.open("DaysMatter.txt", ios::trunc);
			if(deleteDaysMatter.is_open())
			{
				for(j=flog-1; j<jishu-2; j++)
					aDay[j]=aDay[j+1];
				for(j=0; j<jishu-2; j++)
				{
					deleteDaysMatter<<aDay[j].shuXing;
			        deleteDaysMatter<<" ";
			        deleteDaysMatter<<aDay[j].name;
			        deleteDaysMatter<<" ";
			        deleteDaysMatter<<aDay[j].aNewDate.year;
			        deleteDaysMatter<<" ";
			        deleteDaysMatter<<aDay[j].aNewDate.month;
			        deleteDaysMatter<<" ";
			        deleteDaysMatter<<aDay[j].aNewDate.day;
			        deleteDaysMatter<<" ";
			    	deleteDaysMatter<<aDay[j].day;
					deleteDaysMatter<<"\n";
				}
				cout<<"                         ɾ���ɹ�"<<endl;
			}
		}
		break;
	case 13:
		daysMatter.open("DaysMatter.txt",ios::app||ios::out);
    	if (daysMatter.is_open())
		{
			jishu=0;
			do
			{
				daysMatter>>aDay[jishu].shuXing;
				daysMatter>>aDay[jishu].name;
				daysMatter>>aDay[jishu].aNewDate.year;
				daysMatter>>aDay[jishu].aNewDate.month;
				daysMatter>>aDay[jishu].aNewDate.day;
				daysMatter>>aDay[jishu].day;
				jishu++;
			}while(jishu<20&&aDay[jishu-1].aNewDate.day>0);
		}
	if(!daysMatter.is_open()||jishu-1 == 0)
		cout<<"                  ����û�е������������ȴ���������"<<endl;
	else
	{
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                         ������Ҫ��浹��������ĵ�ַ(.txt)"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cin>>diZhi;
		saveDaysMatter.open(diZhi, ios::trunc);
		if(saveDaysMatter.is_open())
		{
			for(j=0; j<jishu-1; j++)
			{
				saveDaysMatter<<aDay[j].shuXing;
			    saveDaysMatter<<" ";
			    saveDaysMatter<<aDay[j].name;
			    saveDaysMatter<<" ";
			    saveDaysMatter<<aDay[j].aNewDate.year;
			    saveDaysMatter<<" ";
			    saveDaysMatter<<aDay[j].aNewDate.month;
			    saveDaysMatter<<" ";
			    saveDaysMatter<<aDay[j].aNewDate.day;
			    saveDaysMatter<<" ";
			    saveDaysMatter<<aDay[j].day;
			    saveDaysMatter<<"\n";
			}
			cout<<"����ɹ�����"<<endl;
		}else cout<<"Ŀ¼�����ڣ����߿ռ䲻��"<<endl;
	}
		break;
	case 1231:
	case 1232:
	case 1233: 
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             ����������"<<endl;
		daysMatter.open("DaysMatter.txt",ios::app||ios::out);
    	if (daysMatter.is_open())
		{
			jishu=0;
			do
			{
				daysMatter>>aDay[jishu].shuXing;
				daysMatter>>aDay[jishu].name;
				daysMatter>>aDay[jishu].aNewDate.year;
				daysMatter>>aDay[jishu].aNewDate.month;
				daysMatter>>aDay[jishu].aNewDate.day;
				daysMatter>>aDay[jishu].day;
				jishu++;
			}while(jishu<20&&aDay[jishu-1].aNewDate.day>0);
			for(j = 0; j<jishu-1; j++)
			{
				cout<<"-------------------------------------------------------------------------------"<<endl;
				cout<<"                               ��"<<j+1<<"��"<<endl;
				cout<<"                ���� "<<aDay[j].shuXing<<"  "<<aDay[j].name<<"  "<<aDay[j].aNewDate.year<<"-"<<aDay[j].aNewDate.month<<"-"<<aDay[j].aNewDate.day<<" ����"<<aDay[j].day<<"��"<<endl;
			}
		}
		if(!daysMatter.is_open()||j == 0)
			cout<<"                  ����û�е������������ȴ���������"<<endl;
		else
		{
			cout<<"-------------------------------------------------------------------------------"<<endl;
			cout<<"                       ������Ҫ�ı�ĵ���������: ";
			cin>>flog;
			switch(i){
			case 1231: aDay[flog-1].shuXing = "����"; break;
			case 1232: aDay[flog-1].shuXing = "������"; break;
			case 1233: aDay[flog-1].shuXing = "����"; break; 
			}
			saveDaysMatter.open("DaysMatter.txt", ios::trunc);
	    	if(saveDaysMatter.is_open())
			{
				for(j=0; j<jishu-1; j++)
				{
					saveDaysMatter<<aDay[j].shuXing;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].name;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].aNewDate.year;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].aNewDate.month;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].aNewDate.day;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].day;
			        saveDaysMatter<<"\n";
				}
			}
			cout<<"����ɹ�����"<<endl;
		}
		break;
	case 1241:
		daysMatter.open("DaysMatter.txt",ios::app||ios::out);
    	if (daysMatter.is_open())
		{
			jishu=0;
			do
			{
				daysMatter>>aDay[jishu].shuXing;
				daysMatter>>aDay[jishu].name;
				daysMatter>>aDay[jishu].aNewDate.year;
				daysMatter>>aDay[jishu].aNewDate.month;
				daysMatter>>aDay[jishu].aNewDate.day;
				daysMatter>>aDay[jishu].day;
				jishu++;
			}while(jishu<20&&aDay[jishu-1].aNewDate.day>0);
		}
		if(!daysMatter.is_open()||jishu-1==0)
			cout<<"                  ����û�е������������ȴ���������"<<endl;
		else
		{
			for(j = 0; j < 20; j++)
			{
				paiXu.setShuZu(aDay[j], j);
				paiXu.setSize(jishu-1);
			}
			paiXu.paiXuDaDaoXiao();
			for(j=0; j<jishu-1; j++)
				aDay[j] = paiXu.putpaiXu(j);
			saveDaysMatter.open("DaysMatter.txt", ios::trunc);
	    	if(saveDaysMatter.is_open())
			{
				for(j=0; j<jishu-1; j++)
				{
					saveDaysMatter<<aDay[j].shuXing;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].name;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].aNewDate.year;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].aNewDate.month;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].aNewDate.day;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].day;
			        saveDaysMatter<<"\n";
				}
			}
			cout<<"                      ����������,���ɵ������Դ���С����ɹ�����   "<<endl;
		}
		break;
	case 1242:
		daysMatter.open("DaysMatter.txt",ios::app||ios::out);
    	if (daysMatter.is_open())
		{
			jishu=0;
			do
			{
				daysMatter>>aDay[jishu].shuXing;
				daysMatter>>aDay[jishu].name;
				daysMatter>>aDay[jishu].aNewDate.year;
				daysMatter>>aDay[jishu].aNewDate.month;
				daysMatter>>aDay[jishu].aNewDate.day;
				daysMatter>>aDay[jishu].day;
				jishu++;
			}while(jishu<20&&aDay[jishu-1].aNewDate.day>0);
		}
		if(!daysMatter.is_open()||jishu-1==0)
			cout<<"                  ����û�е������������ȴ���������"<<endl;
		else
		{
			for(j = 0; j < 20; j++)
			{
				paiXu.setShuZu(aDay[j], j);
				paiXu.setSize(jishu-1);
			}
			paiXu.paiXuDaDaoXiao();
			for(j=0; j<jishu-1; j++)
				aDay[jishu-2-j] = paiXu.putpaiXu(j);
			saveDaysMatter.open("DaysMatter.txt", ios::trunc);
	    	if(saveDaysMatter.is_open())
			{
				for(j=0; j<jishu-1; j++)
				{
					saveDaysMatter<<aDay[j].shuXing;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].name;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].aNewDate.year;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].aNewDate.month;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].aNewDate.day;
			        saveDaysMatter<<" ";
			        saveDaysMatter<<aDay[j].day;
			        saveDaysMatter<<"\n";
				}
			}
			cout<<"                      ����������,���ɵ������Դ���С����ɹ�����   "<<endl;
		}
		break;


	}
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"                        ��h�����˵������������˳�"<<endl;
	daysMatter.close();
	daymatter.close();
	deleteDaysMatter.close();
	saveDaysMatter.close();
	char fanhui;
	fanhui=getch();
	switch (fanhui){
	case 'h': faceMain(); break;
	default: systemExit(0); break;
	}
	
}
