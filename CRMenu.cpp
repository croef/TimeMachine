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
		help<<"The software copyright belongs to 畅嵘 陈帅 刘建波!\n";
		help.close();
	}
}

void CRMenu::printHelpMe()
{
	cout<<"Time machine\n";
	cout<<"Hello, welcome to time machine. This software can compute anything of this time to another time.\n";
	cout<<"Please do with screen, and enjoy it!\n";
	cout<<"The software copyright belongs to 畅嵘 陈帅 刘建波!\n";
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
	cout<<"                                  时光胶囊"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout<<"                    欢迎使用本系统，请按照屏幕提示进行操作。"<<endl;
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
	cout<<"                          1、倒数日"<<endl;
	cout<<"                          2、计算两个日期的差"<<endl;
	cout<<"                          3、计算从某天起距离某个天书的日期"<<endl;
	cout<<"                          4、历史上的今天"<<endl;
	cout<<"                          5、关于"<<endl;
	cout<<"                          6、退出"<<endl;
	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
	cout<<"请输入需要运行的操作编号[1-6]: ";
    cin>>i;
	switch (i){
	case '1': j = faceMain1(); break;
	case '2': j = faceMain2(); break;
	case '3': j = faceMain3(); break;
	case '4': j = 4; break;
	case '5': cleanScreen(); helpMeFile(); printHelpMe(); cout<<endl<<"                           按任意键返回"<<endl;
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
	cout<<"                                                          By 畅嵘 陈帅 刘建波"<<endl;
	cout<<"                           按任意键退出"<<endl;
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
    cout<<"                          1、查看倒数日表"<<endl;
    cout<<"                          2、编辑一个倒数日表"<<endl;
   	cout<<"                          3、将倒数日表另存"<<endl;
   	cout<<"                          4、功能简介"<<endl;
	cout<<"                          5、返回"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"请输入需要运行的操作编号[1-5]: ";
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
    cout<<"                          1、精确到天"<<endl;
    cout<<"                          2、精确到小时"<<endl;
   	cout<<"                          3、精确到分"<<endl;
   	cout<<"                          4、功能简介"<<endl;
	cout<<"                          5、返回"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"请输入需要运行的操作编号[1-6]: ";
	cin>>i;
	switch(i){
	case '1': j = 21; break;
	case '2': j = 22; break;
	case '3': j = 23; break;
	case '4': cout<<"-------------------------------------------------------------------------------"<<endl;
		      cout<<"           通过本功能，您可以计算两个日期，分钟，小时之间所有的详情"<<endl;
              j=20; char flog; cout<<"                                按任意键返回"<<endl;flog=getch(); break;
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
    cout<<"                          1、向前的日期(本功能暂为完成)"<<endl;
    cout<<"                          2、向后的日期"<<endl;
   	cout<<"                          3、功能简介"<<endl;
	cout<<"                          4、返回"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"请输入需要运行的操作编号[1-4]: ";
	cin>>i;
	switch(i){
	case '1': j = 30; break;
	case '2': j = 32; break;
	case '3': cout<<"-------------------------------------------------------------------------------"<<endl;
		      cout<<endl<<"           通过本功能，您可以计算从某个日期开始相隔几天的日期"<<endl<<endl;
              j=30; char flog; cout<<"                               按任意键返回"<<endl;flog=getch(); break;
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
    cout<<"                          1、增加一个倒数日"<<endl;
    cout<<"                          2、删除一个倒数日"<<endl;
   	cout<<"                          3、改变一个倒数日属性"<<endl;
    cout<<"                          4、对倒数日重新排序"<<endl;
	cout<<"                          5、返回"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"请输入需要运行的操作编号[1-5]: ";
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
    cout<<"                          1、工作"<<endl;
    cout<<"                          2、纪念日"<<endl;
   	cout<<"                          3、生活"<<endl;
	cout<<"                          4、返回"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"请输入需要运行的操作编号[1-4]: ";
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
    cout<<"                          1、按照剩余时间自大至小排序"<<endl;
    cout<<"                          2、按照剩余时间自小至大排序"<<endl;
	cout<<"                          3、返回"<<endl;
   	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   	cout<<"请输入需要运行的操作编号[1-3]: ";
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
		cout<<"          请输入两个日期，年月日以\"-\" 间隔，日期间以空格间隔。"<<endl;
		cout<<"                 例如 \"1992-09-12 2012-6-14\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d%d-%d-%d",&date1.year,&date1.month,&date1.day,&date2.year,&date2.month,&date2.day);
		theNumberOfDays.setDay(date1, date2);
		aSecond.setAllSecond(date1,date2);
		if(theNumberOfDays.showDay()>=0&&theNumberOfDays.showDay()<=99999999)
		{
			showANumber.setShowNumber(theNumberOfDays.showDay());
			cout<<endl<<"                  这两个日期间隔  (天)"<<endl<<endl;
			showANumber.show();
			cout<<endl;
			cout<<"                总共"<<aSecond.getZonghours()<<"小时"<<endl;
			cout<<"                总共"<<aSecond.getZongminutes()<<"分钟"<<endl;
			cout<<"                总共"<<aSecond.getZongseconds()<<"秒"<<endl;
		}else
			cout<<endl<<"输出数字超出预期"<<endl;
		break;
	case 22:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             请输入两个时间"<<endl;
		cout<<"               年月日以\"-\" 间隔，时间以\",\"间隔，日期间以空格间隔"<<endl;
		cout<<"                 例如 \"1992-09-12,8 2012-6-14,16\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d%,%d%d-%d-%d,%d",&date1.year,&date1.month,&date1.day,&date1.hour,&date2.year,&date2.month,&date2.day,&date2.hour);
        theNumberOfDays.setDay(date1, date2);
		aSecond.setAllSecond(date1,date2);
		cout<<endl<<"                           这两个日期间隔"<<endl<<endl;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
        cout<<"                *********************************"<<endl;
     	cout<<"                                        "<<endl;
	    cout<<"                            总共"<<theNumberOfDays.showDay()<<"天"<<endl;
	    cout<<"                                        "<<endl;
        cout<<"                *********************************"<<endl;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		cout<<endl;
		cout<<"                总共"<<aSecond.getZonghours()<<"小时"<<endl;
		cout<<"                总共"<<aSecond.getZongminutes()<<"分钟"<<endl;
		cout<<"                总共"<<aSecond.getZongseconds()<<"秒"<<endl;
		break;
	case 23:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             请输入两个时间"<<endl;
		cout<<"               年月日以\"-\" 间隔，时间以\",\"和\":\"间隔，日期间以空格间隔"<<endl;
		cout<<"                 例如 \"1992-09-12,8:13 2012-6-14,16:53\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d%,%d:%d%d-%d-%d,%d:%d",&date1.year,&date1.month,&date1.day,&date1.hour,&date1.minute,&date2.year,&date2.month,&date2.day,&date2.hour,&date2.minute);
        theNumberOfDays.setDay(date1, date2);
		aSecond.setAllSecond(date1,date2);
		cout<<endl<<"                           这两个日期间隔"<<endl<<endl;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
        cout<<"                *********************************"<<endl;
     	cout<<"                                        "<<endl;
	    cout<<"                            总共"<<theNumberOfDays.showDay()<<"天"<<endl;
	    cout<<"                                        "<<endl;
        cout<<"                *********************************"<<endl;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		cout<<endl;
		cout<<"                总共"<<aSecond.getZonghours()<<"小时"<<endl;
		cout<<"                总共"<<aSecond.getZongminutes()<<"分钟"<<endl;
		cout<<"                总共"<<aSecond.getZongseconds()<<"秒"<<endl;
		break;
	case 11:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             倒数日历表"<<endl;
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
				cout<<"  距离 "<<aDay[j].shuXing<<"  "<<aDay[j].name<<"  "<<aDay[j].aNewDate.year<<"-"<<aDay[j].aNewDate.month<<"-"<<aDay[j].aNewDate.day<<" 还有(天)"<<endl;
				CRNumberShow ashowANumber;
				ashowANumber.setShowNumber(aDay[j].day);
				ashowANumber.show();
				cout<<"-------------------------------------------------------------------------------"<<endl;
			}

		}
		if(!daysMatter.is_open()||j == 0)
			cout<<"                  您还没有倒数日历表，请先创建倒数日"<<endl;
		break;
	case 121:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             增加一个倒数日历表"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"                       请输入一个个日期，年月日以\"-\" 间隔"<<endl;
		cout<<"                            例如 \"1992-09-12\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d",&date1.year,&date1.month,&date1.day);
		getSystemTimeAndDate();
		cout<<"                             请选择倒数日的属性"<<endl;
		cout<<"                         1、工作 2、纪念日 3、生活"<<endl;

		do{
		cin>>xuan;
		switch(xuan){
		case '1': newDaoShuRi.shuXing="工作"; break;
    	case '2': newDaoShuRi.shuXing="纪念日"; break;
		case '3': newDaoShuRi.shuXing="生活"; break;
		default : cout<<"               输入不正确，请重新输入"<<endl; j=-121; break;
		}
		}while(j==-121);
		theNumberOfDays.setDay(date1,nowTime);
		newDaoShuRi.day=theNumberOfDays.showDay();
		newDaoShuRi.aNewDate=date1;
		cout<<"请输入倒数日的名称"<<endl;
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
			cout<<"                              输入成功！"<<endl<<"成功添加词条："<<endl;
			cout<<"  距离 "<<newDaoShuRi.shuXing<<"  "<<newDaoShuRi.name<<"  "<<newDaoShuRi.aNewDate.year<<"-"<<newDaoShuRi.aNewDate.month<<"-"<<newDaoShuRi.aNewDate.day<<" 还有(天)"<<endl;
			showANumber.setShowNumber(newDaoShuRi.day);
			showANumber.show();
			daymatter<<"\n";
		}
		
		break;
	case 14:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                                  倒数日"<<endl;
		cout<<"                本模块可以让您创建一个倒数日历，查看并编辑它。"<<endl;
		cout<<"          您也可以通过选项进行倒数日的排序，并另存到其他位置，方便的分享给他人。"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		break;
	case 4:
		
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                                历史上的今天"<<endl;
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
					cout<<"      "<<newToday[j].day.year<<"年 "<<newToday[j].day.month<<"月 "<<newToday[j].day.day<<"日   "<<newToday[j].thing<<endl;
					flog=1;
				}
			}
			if(flog == 0)cout<<"数据库中没有本日期的内容"<<endl;

		}else cout<<"                            数据库文件未正常打开"<<endl;
		todayTxt.close();
		break;
	case 32:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             增加一个倒数日历表"<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"                       请输入一个个日期，年月日以\"-\" 间隔"<<endl;
		cout<<"                            例如 \"1992-09-12\""<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		scanf("%d-%d-%d",&date1.year,&date1.month,&date1.day);
		cout<<"                             请输入相隔天数:";
		cin>>j;
		aNewFeatureRiQi.getdate(date1.year, date1.month, date1.day, j);
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"  距离"<<date1.year<<"-"<<date1.month<<"-"<<date1.day<<"  "<<j<<"天的日期是  "<<aNewFeatureRiQi.getyear()<<"-"<<aNewFeatureRiQi.getmonth()<<"-"<<aNewFeatureRiQi.getday()<<endl;
		cout<<endl;
		break;
	case 122:
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             倒数日历表"<<endl;
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
				cout<<"                               第"<<j+1<<"条"<<endl;
				cout<<"                距离 "<<aDay[j].shuXing<<"  "<<aDay[j].name<<"  "<<aDay[j].aNewDate.year<<"-"<<aDay[j].aNewDate.month<<"-"<<aDay[j].aNewDate.day<<" 还有"<<aDay[j].day<<"天"<<endl;
			}
		}
		if(!daysMatter.is_open()||j == 0)
			cout<<"                  您还没有倒数日历表，请先创建倒数日"<<endl;
		else
		{
			cout<<"-------------------------------------------------------------------------------"<<endl;
			cout<<"请输入要删除的条目数: ";
			cin>>flog;
			if(flog>jishu-1||flog<0) cout<<endl<<"输入条目数错误"<<endl;
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
				cout<<"                         删除成功"<<endl;
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
		cout<<"                  您还没有倒数日历表，请先创建倒数日"<<endl;
	else
	{
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                         请输入要另存倒数日历表的地址(.txt)"<<endl;
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
			cout<<"保存成功！！"<<endl;
		}else cout<<"目录不存在，或者空间不够"<<endl;
	}
		break;
	case 1231:
	case 1232:
	case 1233: 
		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
		cout<<"                             倒数日历表"<<endl;
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
				cout<<"                               第"<<j+1<<"条"<<endl;
				cout<<"                距离 "<<aDay[j].shuXing<<"  "<<aDay[j].name<<"  "<<aDay[j].aNewDate.year<<"-"<<aDay[j].aNewDate.month<<"-"<<aDay[j].aNewDate.day<<" 还有"<<aDay[j].day<<"天"<<endl;
			}
		}
		if(!daysMatter.is_open()||j == 0)
			cout<<"                  您还没有倒数日历表，请先创建倒数日"<<endl;
		else
		{
			cout<<"-------------------------------------------------------------------------------"<<endl;
			cout<<"                       请输入要改变的倒数日条数: ";
			cin>>flog;
			switch(i){
			case 1231: aDay[flog-1].shuXing = "工作"; break;
			case 1232: aDay[flog-1].shuXing = "纪念日"; break;
			case 1233: aDay[flog-1].shuXing = "生活"; break; 
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
			cout<<"保存成功！！"<<endl;
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
			cout<<"                  您还没有倒数日历表，请先创建倒数日"<<endl;
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
			cout<<"                      倒数日历表,已由倒数日自大至小保存成功！！   "<<endl;
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
			cout<<"                  您还没有倒数日历表，请先创建倒数日"<<endl;
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
			cout<<"                      倒数日历表,已由倒数日自大至小保存成功！！   "<<endl;
		}
		break;


	}
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"                        按h回主菜单，其它按键退出"<<endl;
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
