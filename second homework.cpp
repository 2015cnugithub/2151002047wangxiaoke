#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Worker
{
    protected:
        string name;
        int age;
        string gender;
        double pay_per_hour;
       friend inline ostream& operator<<(ostream& out, Worker& worker)
        {
            out<<"Name:"<<worker.name<<",Age:"<<worker.age<<",Gender:"<<worker.gender
                <<",Pay_per_hour:"<<worker.pay_per_hour<<endl;
            return out;
        }
    public:
        string Name()
        {
            return name;
        }
        virtual void Compute_pay(double hours) = 0;
};



class HourlyWorker : public Worker
{
    public:
         HourlyWorker(string n, int a, string g, double p)
        {
            name = n;
            age = a;
            gender = g;
            pay_per_hour = p;
        }
        void Compute_pay(double hours)
        {
            if(hours <= 40)
                cout<<"Salary for a week:"<<hours*pay_per_hour<<endl;
            else
                cout<<"Salary for a week:"<<pay_per_hour*40 + 1.5*pay_per_hour*(hours-40)<<endl;
        }
};

class SalariedWorker : public Worker
{
    public:
         SalariedWorker(string n, int a, string g, double p)
        {
            name = n;
            age = a;
            gender = g;
            pay_per_hour = p;
        }
        void Compute_pay(double hours)
        {
            if(hours >= 35)
                cout<<"Salary for a week:"<<pay_per_hour*40<<endl;
            else
                cout<<"Salary for a week:"<<pay_per_hour*hours + 0.5*pay_per_hour*(35-hours)<<endl;
        }
};

int main()
{
    int i;
    string name;
    int age;
    string gender;
    int category;
    double pay_per_hour;
    Worker* workers[5];
    double hours;
    for(i=0; i<5; i++)
    {
        cout<<"Input information,worker"<<i+1<<":"<<endl;
        cin>>name;
        cin>>age;
        cin>>gender;
        cin>>category;
        cin>>pay_per_hour;
        if(category == 0) 
            workers[i] = new HourlyWorker(name, age, gender, pay_per_hour);
        else 
            workers[i] = new SalariedWorker(name, age, gender, pay_per_hour);

    }
    cout<<"workers' information:"<<endl;
    for(i=0; i<5; i++)
    {
        cout<<i+1<<": "<<workers[i]->Name()<<endl;
    }

    while(1)
    {
        cout<<"Please choose one to show more information:"<<endl;
        cin>>i;
        if(i>5 || i<1) break;
        cout<<*workers[i-1]<<endl;
        cin>>hours;
        workers[i]->Compute_pay(hours);
    }

    return 0;
}
