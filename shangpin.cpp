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

//   2.��class CCourse����������һ����
       private:
           static int total_course;

//     �����ⲿ����һ����
       int CCourse::total_course = 0;

//     ��CCourse��Ĺ��캯��������һ����
       total_course++;

//     ��CCourse��Ŀ������캯��������һ����
       total_course++;

//     ��CCourse�����������������һ����
       total_course--;

//     ��class CCourse����������һ����
       public:
           static getTotalCourse() { return total_course; }

//     ��class CCourse����������һ����
         friend char *getCourseName(const CCourse &r_course);

//     �����ⲿ���壺
         char *getCourseName(const CCourse &r_course)
         {
              return r_course.p_name;
         }

//   3.��class CCourse����������һ����
       public:
           bool operator <(const CCourse &r_course);
//     �����ⲿ���壺
        bool CCourse::operator <(const CCourse &r_course)
        {
            if (credit < r_course.credit)
                return true;
            else
                return false;
        }

//     ��class CCourse����������һ����
       public:
           bool operator >=(const CCourse &r_course);

//     �����ⲿ���壺
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
