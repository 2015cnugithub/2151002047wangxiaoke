#include <iostream.h>
const int r=1;
const int w=0;        //���峣��
int isleap(int year)           //����isleap()�ж�ĳ���ǲ�������
{
	int leap=w;
	if(year%4==0&&year%100!=0||year%400==0)
		leap=r;
	return leap;
}
int f(int year)             //����f()�ж�ÿ��Ԫ�������ڼ�
{
	int n=year-1900;
	n=n+(n-1)/4+1;
	n=n%7;
	return n;
}
int main()                   //������
{
	int year,month,monnth,day,weekday,monthday,i;
	cout<<"������Ҫ��ѯ�����:";
	cin>>year;
	//cout<<"\n"<<year<<endl;
	cout<<"������Ҫ��ѯ���·�:";
	cin>>monnth;
	cout<<"\n"<<year<<"��"<<monnth<<"��"<<endl;
	weekday=f(year);
	for(month=1;month<=12;month++)
	{
		if(month==monnth)
		{
			cout<<"\n"<<month<<endl;
			cout<<"****************************"<<endl;
			cout<<"sun mon tue wed thu fri sat"<<endl;
			cout<<"****************************"<<endl;
			for(i=0;i<weekday;i=i+1)           //�ҵ�ÿ��1�����ڵ�λ��,��ռ�Ŀո���
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
				if(weekday==7)          //��һ�����ڻ���
				{
					weekday=0;
					cout<<endl;
				}
			}
			cout<<endl;             //�����һ���»���
		}
		else continue;
	}
	return 0;
}