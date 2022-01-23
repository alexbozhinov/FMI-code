#ifndef 3_H_INCLUDED
#define 3_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;


enum CourseType{
   QKN,
   OKN,
   KP,
   M,
   PM,
   S,
   St
};

enum Title{
   honorary,
   chief assistent,
   doctor,
   docent,
   professor
};

enum WordMark{
   Poor,
   Middle,
   Good,
   Very Good,
   Excellent
};

class Person{

public:
    Person();
    Person(string _name);
    string getName()const;

private:

   void setName(string _name);
   string name;
};

class Course{

public:
    Course();
    Course(string _name, CourseType _type, string _code, Teacher _teacher, vector<Student> _students);
    string getName()const;
    CourseType getType()const;
    string getCode()const;
    Teacher getTeacher()const;
    vector<Student> getStudents()const;
    void changeTeacher(Teacher newTeacher);

private:
   void setName(string _name);
   void setType(CourseType _type);
   void setCode(string _code);
   void setTeacher(Teacher _teacher);
   void setStudents(vector<Student> _students);

   string name;
   CourseType type;
   string code;
   Teacher teacher;
   vector<Student> students;
};

class Mark{

public:
    Mark();
    Mark(WordMark, int);

private:
    WordMark markInWords;
    int markInDigit;     ///int because it is a final mark of a course - the final mark is usually 2,3,4,5 or 6 :)
};

class Teacher public : Person{

public:
      Teacher();
      Teacher(string _name, Title _title, vector<Course> _courser)
      : Person(_name)
      {
          /*............*/
      };

      Title getTitle()const;
      vector<Course> getCourse()const;

private:
    void setTitle(Title );
    void setCourser(vector<Course> );

    Title title;
    vector<Course> courses;
};

class Student public : Person{

public:
    Student();
    Student(string _name, string, vector<Course>, vector<pair<Course, Mark> >)
    : Person(_name)
    {
        /*.......*/
    }
    vector<pair<Course, Mark> > getMarks()const;

private:
   void setFN(string );
   void setCourses(vector<Course> );
   void setMarks(vector<pair<Course, Mark> > );

   string fn;
   vector<Course> courses;
   vector<pair<Course, Mark> > marks;
};


#endif // 3_H_INCLUDED
