//1. 
    #include <iostream>
    #include <string.h>
    using namespace std;
    class CCourse
    {
    private:
        long no;
        char *p_name;
        float credit;
    public:
        CCourse(long no_val, char *p_val, float credit_val);
        CCourse(const CCourse &r_course);
        ~CCourse() { delete p_name; }
        void print() const;
    };

    CCourse::CCourse(long no_val, char *p_val, float credit_val)
    {
        no = no_val;
        p_name = new char[strlen(p_val)+1];
        strcpy(p_name, p_val);
        credit = credit_val;
    }

    CCourse::CCourse(const CCourse &r_course)
    {
        no = r_course.no;
        p_name = new char[strlen(r_course.p_name)+1];
        strcpy(p_name, r_course.p_name);
        credit = r_course.credit;
    }

    void CCourse::print() const
    {
        cout << "Course number: " << no << endl;
        cout << "Course name: " << p_name << endl;
        cout << "Course credit: " << credit << endl;
    }

//   2.在class CCourse定义中增加一条：
       private:
           static int total_course;

//     在类外部增加一条：
       int CCourse::total_course = 0;

//     在CCourse类的构造函数中增加一条：
       total_course++;

//     在CCourse类的拷贝构造函数中增加一条：
       total_course++;

//     在CCourse类的析构函数中增加一条：
       total_course--;

//     在class CCourse定义中增加一条：
       public:
           static getTotalCourse() { return total_course; }

//     在class CCourse定义中增加一条：
         friend char *getCourseName(const CCourse &r_course);

//     在类外部定义：
         char *getCourseName(const CCourse &r_course)
         {
              return r_course.p_name;
         }

//   3.在class CCourse定义中增加一条：
       public:
           bool operator <(const CCourse &r_course);
//     在类外部定义：
        bool CCourse::operator <(const CCourse &r_course)
        {
            if (credit < r_course.credit)
                return true;
            else
                return false;
        }

//     在class CCourse定义中增加一条：
       public:
           bool operator >=(const CCourse &r_course);

//     在类外部定义：
        bool CCourse::operator >=(const CCourse &r_course)
        {
            if (credit >= r_course.credit)
                return true;
            else
                return false;
        }

//4.
    class CHLP : public CCourse
    {
    private:
        char *p_openby;
    public:
        CHLP(long no_val, char *p_val, float credit_val, char *p_open) : CCourse(no_val, p_val, credit_val)
        { 
            p_openby = new char[strlen(p_open)+1];
            strcpy(p_openby, p_open);
        }
        ~CHLP() { delete p_openby; }
        void studyFor() { cout << "Study for structured programming" << endl; }
    };
    
    class COOP : public CCourse
    {
    private:
        char *p_openby;
    public:
        COOP(long no_val, char *p_val, float credit_val, char *p_open) : CCourse(no_val, p_val, credit_val)
        { 
            p_openby = new char[strlen(p_open)+1];
            strcpy(p_openby, p_open);
        }
        ~COOP() { delete p_openby; }
        void studyFor() { cout << "Study for object oriented programming" << endl; }
    };
