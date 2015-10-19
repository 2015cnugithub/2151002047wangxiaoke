#include <iostream.h>
const int r=1;
const int w=0;        //定义常量
int isleap(int year)           //函数isleap()判断某年是不是闰年
{
	int leap=w;
	if(year%4==0&&year%100!=0||year%400==0)
		leap=r;
	return leap;
}
int f(int year)             //函数f()判断每年元旦是星期几
{
	int n=year-1900;
	n=n+(n-1)/4+1;
	n=n%7;
	return n;
}
int main()                   //主函数
{
	int year,month,monnth,day,weekday,monthday,i;
	cout<<"请输入要查询的年份:";
	cin>>year;
	//cout<<"\n"<<year<<endl;
	cout<<"请输入要查询的月份:";
	cin>>monnth;
	cout<<"\n"<<year<<"年"<<monnth<<"月"<<endl;
	weekday=f(year);
	for(month=1;month<=12;month++)
	{
		if(month==monnth)
		{
			cout<<"\n"<<month<<endl;
			cout<<"****************************"<<endl;
			cout<<"sun mon tue wed thu fri sat"<<endl;
			cout<<"****************************"<<endl;
			for(i=0;i<weekday;i=i+1)           //找到每月1日所在的位置,所占的空格数
				cout<<"    ";
			if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
				monthday=31;
			else if(month==2)
			{
				if(isleap(year))
					monthday=29;
				else
					monthday=28;
			}
			else
				monthday=30;
			for(day=1;day<=monthday;day++)
			{
				if(day>9)
					cout<<day<<"  ";
				else
					cout<<day<<"   ";
				weekday++;
				if(weekday==7)          //满一个星期换行
				{
					weekday=0;
					cout<<endl;
				}
			}
			cout<<endl;             //输出完一个月换行
		}
		else continue;
	}
	return 0;
}