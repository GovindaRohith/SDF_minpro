/*
Code by
Govinda Rohith Y
CS21BTECH11062
SDF Project


*/

//#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include <chrono>
#include<windows.h>
#include<conio.h>
using namespace std;
//Abstraction
void inter();
void intiation();
void adminhome();
void student_ra(string studata);
void facultyhome(int facno);
void studenthome(int stuno);
void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}
//Abstraction end
class Courses 
{
    public:
    string course_finder(string datname)
    {
        string temp;
        int i;
        fstream file;
        file.open(datname,ios::in);
        if(file.is_open())
        {
            getline(file,temp);
            if(temp[0]=='1')
            {
                getline(file,temp);
            }
            else
            {
                temp[0]='0';
            }
        }
        file.close();
        return temp;
    }
    void view_courses(int stu,int admin,int faculty)
    {
        if(admin==1||admin==2)
        {
            string temp;
            int tool=0;
            string counter;
            cout<<"\n\nAvailable Courses:"<<endl;
            cout<<"Code    Name"<<endl;
            fstream file;
            file.open("main.dat",ios::in);
            getline(file,temp);
            while(getline(file,temp))
            {
                tool=0;
                if(file.is_open())
                {
                if(course_finder(temp)[0]=='0')
                {}
                else
                {
                    counter=course_finder(temp);
                    for(int i=0;i<100;i++)
                    {
                        if(counter[i]==' ')
                        {
                            if(tool==1)
                            {
                            cout<<"\n";
                            break;
                            }
                            else
                            {
                                tool=1;
                                cout<<"  ";
                            }
                        }
                        else if(counter[i]=='_')
                        {
                            cout<<" ";
                        }
                        else
                        {
                            cout<<counter[i];
                        }
                    }
                }
                }
                else
                {
                    break;
                }
            }
            if(admin==10)
            {}
            else if(admin==2)
            {}
            else
            {
            file.close();
            cout<<"Press 1 to edit the courses"<<endl;
            cout<<"Press 2 to go back admin home page"<<endl;
            cout<<"Press 0 to LOGOUT"<<endl;
            cout<<"Please enter your choice  ";
            cin>>counter;
            if(counter[0]=='1')
            {
                edit_courses();
            }
            else if(counter[0]=='2')
            {
                adminhome();
            }
            else
            {
                inter();
            }
            }
        }
        if(faculty>=1)
        {
            int i,tool=0,repo=0;
            string temp;
            string cour;
            fstream file;
            cout<<"\n\nAvailable Courses:"<<endl;
            cout<<"Code    Name"<<endl;
            file.open("main.dat",ios::in);
            if(file.is_open())
            {
                getline(file,temp);
                while(!file.eof())
                {
                    repo=0;
                    fstream tempi;
                    getline(file,temp);
                    tempi.open(temp,ios::in);
                    if(tempi.is_open())
                    {
                        getline(tempi,cour);
                        if(cour[0]=='1')
                        {
                            getline(tempi,cour);
                            for(i=0;i<cour.length();i++)
                            {
                                if(cour[i]=='f'&&cour[i+1]=='a'&&cour[i+2]=='c'&&cour[i+3]==48+faculty)
                                {
                                    tool=1;
                                    cour=course_finder(temp);
                                    if(cour[0]!='0')
                                    {
                                    for(i=0;i<temp.length();i++)
                                    {
                                        if(cour[i]==' ')
                                        {
                                        if(repo==1)
                                        {
                                        
                                        repo=0;
                                        break;
                                        }
                                        else
                                        {
                                        repo=1;
                                        cout<<"  ";
                                        }
                                        }
                                        else if(cour[i]=='_')
                                        {
                                            cout<<" ";
                                        }
                                        else
                                        {
                                            cout<<cour[i];
                                        }
                                    }
                                    cout<<endl;
                                    break;
                                    }
                                
                                }
                            }
                        }
                    tempi.close();
                    }
                }
            if(tool==0) 
            {
                cout<<"You are not registered for any running courses contact admin"<<endl;
            }
            file.close();
            }
            
        }
        if(stu>=1)
        {
            cout<<"\n\nMy Courses  Name   Grade\n"<<endl;
            int i,start=0,counter=0,repo=0;
            string temp;
            string user;
            fstream file;
            file.open("main.dat",ios::in);
            if(file.is_open())
            {
                getline(file,temp);
                while(!file.eof())
                {
                    getline(file,temp);
                    user=course_finder(temp);
                    if(user[0]!=0)
                    {
                    for(i=0;i<user.length();i++)
                    {
                        if(user[i]=='f'&&user[i+1]=='a'&&user[i+2]=='c')
                        {
                            break;
                        }
                    }
                    start=i+5;
                    if(user[start+4*(stu-1)]=='1')
                    {
                        counter=1;
                        for(i=0;i<user.length();i++)
                        {
                            // for editing
                            if(user[i]==' ')
                            {
                            if(repo==1)
                            {
                            repo=0;
                            break;
                            }
                            else
                            {
                            repo=1;
                            cout<<"      ";
                            }
                            }
                            else if(user[i]=='_')
                            {
                            cout<<" ";
                            }   
                            else
                            {
                            cout<<user[i];
                            }
                            //for editing
                        }
                        cout<<"       "<<user[start+4*(stu-1)+1];
                        if(user[start+4*(stu-1)+2]=='N')
                        {}
                        else
                        {
                            cout<<user[start+4*(stu-1)+2]<<endl;
                        }
                    }
                    }
                }
                if(counter==0)
                {
                    cout<<"Not Registered for any course"<<endl;
                    cout<<"Press 1 to register for a course"<<endl;
                    cout<<"Press 2 to go back to home page"<<endl;
                    cout<<"Press 0 to LOGOUT"<<endl;
                    cout<<"Please Enter your choice  ";
                    cin>>temp;
                    file.close();
                    if(temp[0]=='1')
                    {
                        reg(stu,1);
                    }
                    else if(temp[0]=='2')
                    {
                        studenthome(stu);
                    }
                    else
                    {
                        inter(); 
                    }
                }
                else
                {
                    int k;
                    cout<<"Press 1 to go back student home page"<<endl;
                cout<<"Press 0 to LOGOUT"<<endl;
                cout<<"Plese enter your choice  ";
                cin>>k;
                if(k==1)
                {
                    studenthome(stu);
                }
                else inter();
                }
                
            }
        }
    }
    void edit_courses()
    {
        int i=0;
        string temp;
        cout<<"\n\nPress 1 to add a course"<<endl;
        cout<<"Press 2 to Remove a course"<<endl;
        cout<<"Press 3 to go back to admin home page"<<endl;
        cout<<"Press 4 to LOGOUT"<<endl;
        cout<<"Enter your choice  ";
        cin>>i;
        if(i==1)
        {
            fstream file,coursefile;
            file.open("main.dat",ios::app);
            if(file.is_open())
            {
                cout<<"\n\n\nEnter the course code  ";
                cin>>temp;
            }
            file<<temp+".dat\n";
            file.close();
            coursefile.open(temp+".dat",ios::out);
                coursefile<<"1\n";
                coursefile<<temp;
                cout<<"Enter the course name  ";
                fflush(stdin);
                getline(cin,temp);
                for(i=0;i<temp.length();i++)
                {
                    if(temp[i]==' ')
                    {
                        temp[i]='_';
                    }
                }
                fflush(stdin);
                coursefile<<' '+temp+' ';
                cout<<"Enter no of credits to the course  ";
                cin>>temp;
                coursefile<<temp[0];
                cout<<"Assign Faculty member to the course"<<endl;
                cout<<"Available faculty are "<<endl;
                cout<<"Faculty_1"<<endl;
                cout<<"Faculty_2"<<endl;
                cout<<"Faculty_3"<<endl;
                cout<<"Faculty_4"<<endl;
                cout<<"Faculty_5"<<endl;
                cout<<"Enter the Faculty number(For Ex Faculty_3's number is 3)  ";
                cin>>temp;
                if(temp[0]=='1') coursefile<<" fac1";
                if(temp[0]=='2') coursefile<<" fac2";
                if(temp[0]=='3') coursefile<<" fac3";
                if(temp[0]=='4') coursefile<<" fac4";
                if(temp[0]=='5') coursefile<<" fac5";
                for(i=0;i<20;i++)
                {
                    coursefile<<" 0NA";
                }
                cout<<"Course added succesfully!!"<<endl;
                Sleep(1000);
                fflush(stdout);
            coursefile.close();
            adminhome();
        }
        else if(i==2)
        {
            fstream remove;
            view_courses(0,10,0);
            cout<<"\nEnter the course code(AB****) which has to be removed"<<endl;
            cin>>temp;
            for(i=0;i<temp.length();i++)
            {
                if(temp[i]>=97&&temp[i]<=122)
                {
                    temp[i]=temp[i]-32;
                }
            }
            remove.open(temp+".dat",ios::out);
            if(remove.is_open())
            {
                remove<<0;
                cout<<"Course removed succesfully!!"<<endl;
                Sleep(1000);
                fflush(stdout);
                adminhome();
            }
            else
            {
                cout<<"Course not found"<<endl;
                adminhome();
            }
        }
        else if(i==3)
        {
            adminhome();
        }
        else
        {
            inter();
        }
    }
    void submit_grades(int facno)
    {
        int i,start,counter=0,counter1=0,counter2=0,number=0,tool=0;
        fstream file;
        string temp;
        string rolls;
        string grades;
        string course;
        string old;
        cout<<"My Courses"<<endl;
        view_courses(0,0,facno);
        cout<<"Enter the Course ID from above list for which grades has to be submitted(AB****) ";
        cin>>temp;
        for(i=0;i<temp.length();i++)
        {
            if(temp[i]>=97&&temp[i]<=122)
            {
                temp[i]=temp[i]-32;
            }
        }
        course=temp;
        file.open(temp+".dat",ios::in);
        if(file.is_open())
        {
            getline(file,temp);
            if(temp[0]=='1')
            {
                getline(file,temp);
                old=temp;
                for(i=0;i<temp.length();i++)
                {
                if(temp[i]=='f'&&temp[i+1]=='a'&&temp[i+2]=='c')
                {
                    break;
                }
                }
                start=i+5;
                for(i=start;i<temp.length();i=i+4)
                {
                    if(temp[i]=='1'&&temp[i+1]=='N'&&temp[i+2]=='A')
                    {
                        if(counter==0) 
                        {
                            cout<<"This is list of students whose grades are not yet submitted\n";
                            counter++;
                        }
                        cout<<"Student"<<(i-start)/4+1<<endl;
                    }
                }
                if(counter==0) 
                {
                    int k;
                    cout<<"All the students were assigned grades/No student has registered for this course"<<endl;
                    cout<<"Press 1 to go back to faculty home page"<<endl;
                    cout<<"Press 0 to LOGOUT"<<endl;
                    cout<<"Please enter your choice  ";
                    cin>>k;
                    if(k==1) facultyhome(facno);
                    else inter();
                    file.close();
                }
                else
                {
                    cout<<"Available Grades:A+(10pt),A(10pt),A-(9pt),B+(8pt),B(7pt),B-(6pt),C(5pt),F(0)"<<endl;
                    cout<<"Enter the roll no's(Student5 roll no is 5) of students followed by commas to assign grades:";
                    cin>>rolls;
                    cout<<"\nType Grades to them respectively followed by comma:";
                    cin>>grades;
                    for(i=0;i<rolls.length();i++)
                    {
                        if(rolls[i]==',') counter1++;
                    }
                    for(i=0;i<grades.length();i++)
                    {
                        if(grades[i]==',') counter2++;
                    }
                    if(counter1==counter2)
                    {
                    file.close();
                    file.open(course+".dat",ios::out);
                    file<<"1\n";
                    int j=0,index=0;
                    string store="NN";
                    for(i=0;i<rolls.length();i++)
                    {
                        store="NN";
                        if(rolls[i]==',')
                        {
                            number=0;
                            number=number+rolls[i-1]-48;
                            if(rolls[i-2]>=49&&rolls[i-2]<=51)
                            {
                                number=number+(rolls[i-2]-48)*10;
                            }
                            for(j=index;j<=grades.length();j++)
                            {
                                if(grades[j]==',')
                                {
                                    if(grades[j-1]=='+'||grades[j-1]=='-')
                                    {
                                        store[1]=grades[j-1];
                                        store[0]=grades[j-2];
                                    }
                                    else
                                    {
                                        store[0]=grades[j-1];
                                    }
                                    index=j+1;
                                    break;
                                }
                            }
                            old[start+(number-1)*4+1]=store[0];
                            old[start+(number-1)*4+2]=store[1];
                        }
                    }
                    number=0;
                    number=number+rolls[rolls.length()-1]-48;
                    if(rolls[rolls.length()-2]>=48&&rolls[rolls.length()-2]<=51)
                    {
                        number=number+(rolls[rolls.length()-2]-48)*10;
                    }
                    if(grades[grades.length()-1]=='+'||grades[grades.length()-1]=='-')
                    {
                    store[1]=grades[grades.length()-1];
                    store[0]=grades[grades.length()-2];
                    }
                    else
                    {
                    store[0]=grades[grades.length()-1];
                    }
                    old[start+(number-1)*4+1]=store[0];
                    old[start+(number-1)*4+2]=store[1];
                    file<<old;
                    file.close();
                    cout<<"Grades Assigned Succesfully!!"<<endl;
                    Sleep(1000);
                    fflush(stdout);
                    facultyhome(facno);
                    }
                    else
                    {
                        cout<<"The entered format is not proper try again"<<endl;
                        facultyhome(facno);
                    }
                }
            }
            
        }
    }
    void courstu_remove(string id,string stulist)
    {
        int i,start,counter=0,start2;
        string temp;
        fstream file;
        for(i=0;i<id.length();i++)
        {
            if(id[i]>=97&&id[i]<=122)
            {
                id[i]=id[i]-32;
            }
        }
        cout<<"Available students in the selected course "<<id<<endl;
        file.open(id+".dat",ios::in);
        if(file.is_open())
        {
            getline(file,temp);
            getline(file,temp);
            for(i=0;i<200;i++)
            {
                if(temp[i]=='f'&&temp[i+1]=='a'&&temp[i+2]=='c')
                {
                    break;
                }
            }
            start=i+5;
            start2=start;
            for(i=0;i<20;i++)
            {
                if(stulist[i]=='1'&&temp[start]=='1')
                {
                    cout<<"Student "<<i+1<<endl;
                }
                else
                {
                    counter++;
                }
            start=start+4;
            }
            if(counter==20) 
            {
                cout<<"No students have registered this course"<<endl;
                Sleep(1000);
                fflush(stdout);
                adminhome();
            }
            else
            {
                cout<<"Enter the student roll number(Ex roll no for Student15 is 15) to add/remove"<<endl;
                cin>>i;
                if(temp[start2+4*(i-1)]=='1')
                {
                    temp[start2+4*(i-1)]='0';
                    cout<<"Student removed successfully from course"<<id<<endl;
                    Sleep(1000);
                    fflush(stdout);
                }
                else
                {
                    temp[start2+4*(i-1)]='1';
                    cout<<"Student added successfully in to the course"<<id<<endl;
                    Sleep(1000);
                    fflush(stdout);
                }
            }
            file.close();
            file.open(id+".dat",ios::out);
            file<<"1\n";
            file<<temp+'\n';
            file.close();
            adminhome();
        }
    }
    void edit_student()
    {
        string temp;
        int i,counter=0,joke=0;
        cout<<"\n\nAvailable students in IITH"<<endl;
        fstream sfile;
        sfile.open("main.dat",ios::in);
        if(sfile.is_open())
        {
            getline(sfile,temp);
            for(i=0;i<20;i++)
            {
                if(temp[i]=='1')
                {
                    counter++;
                    cout<<"Student "<<i+1<<endl;
                }
            }
            i=0;
            if(counter<20)
            {
                cout<<"Press 1 to add a student to IITH "<<endl;
            }
            cout<<"Press 2 to remove a student from IITH"<<endl;
            cout<<"Press 3 to go back to admin home page"<<endl;
            cout<<"Press 0 to LOGOUT"<<endl;
            cout<<"Enter your choice"<<endl;
            cin>>i;
            if(i==1)
            {
                cout<<"\nEnter the roll no of student for new admission(For Ex:Student 15 roll no is 15)";
                cin>>i;
                temp[i-1]='1';
                student_ra(temp);
                cout<<"Student added succesfully!!"<<endl;
                Sleep(1000);
                fflush(stdout);
                sfile.close();
                adminhome();
            }
            else if(i==2)
            {
                cout<<"\nEnter the roll no of student for who has to be removed(For Ex:Student 15 roll no is 15)";
                cin>>i;
                temp[i-1]='0';
                student_ra(temp);
                cout<<"Student removed :( !!"<<endl;
                Sleep(1000);
                fflush(stdout);
                sfile.close();
                adminhome();
            }
            else if(i==3)
            {
                adminhome();
                sfile.close();
            }
            else
            {
                inter();
                sfile.close();
            }
        }
        
    }
    void reg(int stuno,int reg)
    {
        //reg=1 to register reg=0 deregister
        int i,start,tool=0,joke=0;
        if(reg==1)
        {
            cout<<"\nAvailable courses for regsitration\n";
        }
        else
        {
            cout<<"\nSelect the courses from the list to deregister"<<endl;
        }
        string temp;
        string name;
        fstream file;
        file.open("main.dat",ios::in);
        if(file.is_open())
        {
        getline(file,temp);
        while(!file.eof())
        {
            getline(file,temp);
            name=course_finder(temp);
            if(name[0]!='0')
            {
                for(i=0;i<name.length();i++)
                {
                    if(name[i]=='f'&&name[i+1]=='a'&&name[i+2]=='c') break;
                }   
                start=i+5;
                if(reg==1)
                {
                if(name[start+(stuno-1)*4]=='0')
                {
                    int counter=0;
                    joke=1;
                    for(i=0;i<name.length();i++)
                    {
                        if(name[i]=='_') cout<<' ';
                        else cout<<name[i];
                        if(name[i]==' ') counter++;
                        if(counter==2)
                        {
                            cout<<"\n";
                            break;
                        }
                    }
                }
                }
                else
                {
                    if(name[start+(stuno-1)*4]=='1'&&name[start+(stuno-1)*4+1]=='N'&&name[start+(stuno-1)*4+2]=='A')
                    {
                        tool=1;
                    int counter=0;
                    for(i=0;i<name.length();i++)
                    {
                        if(name[i]=='_') cout<<' ';
                        else cout<<name[i];
                        if(name[i]==' ') counter++;
                        if(counter==2)
                        {
                            cout<<"\n";
                            break;
                        }
                    }  
                    }
                }
            }
        }
        string id;
        string old;
        if(tool==0&&reg==0)
        {
            int k;
            cout<<"You cannot deregister for a course"<<endl;
            cout<<"Press 1 to go back student home page"<<endl;
            cout<<"Press 0 to LOGOUT"<<endl;
                cout<<"Plese enter your choice  ";
                cin>>k;
                if(k==1)
                {
                    studenthome(stuno);
                }
                else inter();
        }
        else
        {
            if((joke==1&&reg==1)||reg==0)
            {
            cout<<"Enter the Course ID(AB****) to modify ";
            }
            if(joke==0&&reg==1)
            {
                int k;
                cout<<"No available courses for Registration"<<endl;
                cout<<"Press 1 to go back student home page"<<endl;
                cout<<"Press 0 to LOGOUT"<<endl;
                cout<<"Plese enter your choice  ";
                cin>>k;
                if(k==1)
                {
                    studenthome(stuno);
                }
                else inter();
            }
        }
        if((joke==1&&reg==1)||reg==0) cin>>id;
        for(i=0;i<id.length();i++)
        {
            if(id[i]>=97&&id[i]<=122)
            {
                id[i]=id[i]-32;
            }
        }
        file.close();
        fstream key;
        id=id+".dat";
        old=course_finder(id);
        key.open(id,ios::out);
        if(old[0]!=0)
        {
        if(key.is_open())
        {
            key<<"1\n";
            for(i=0;i<old.length();i++)
            {
                if(old[i]=='f'&&old[i+1]=='a'&&old[i+2]=='c') break;
            }
            start=i+5;
            if(old[start+(stuno-1)*4]=='1') 
            {
                old[start+(stuno-1)*4]='0';
            }
            else
            {
                old[start+(stuno-1)*4]='1';
            }
            key<<old+'\n';
            
            if(reg==1) 
            {
                int k;
                if(joke==1)cout<<"Regsitered Succesfully"<<endl;
                
                cout<<"Press 1 to go back student home page"<<endl;
                cout<<"Press 0 to LOGOUT"<<endl;
                cout<<"Plese enter your choice  ";
                cin>>k;
                if(k==1)
                {
                    key.close();
                    studenthome(stuno);
                }
                else inter();
            }
            else
            {
                int k;
                cout<<"Successfully removed course from my courses"<<endl;
                cout<<"Press 1 to go back student home page"<<endl;
                cout<<"Press 0 to LOGOUT"<<endl;
                cout<<"Plese enter your choice  ";
                cin>>k;
                if(k==1)
                {
                    key.close();
                    studenthome(stuno);
                }
                else inter();
            }
            
        }
        }
        else
        {
            cout<<"Course not found"<<endl;
            studenthome(stuno);
        }
        }
    }
};
void adminhome()
    {
        string user;
        cout<<"\n\n";
        Clear();
        cout<<"Logged in as ADMIN"<<endl;
        cout<<"Press 1 to view and edit courses"<<endl;
        cout<<"Press 2 to view and edit student's list"<<endl;
        cout<<"Press 3 to add or remove student to a course"<<endl;
        cout<<"Press 0 to LOG OUT"<<endl;
        cout<<"Please enter your choice  ";
        cin>>user;
        if(user[0]=='1')
        {
            Courses c1;
            Clear();
            c1.view_courses(0,1,0);
        }
        else if(user[0]=='2')
        {
            Courses c1;
            Clear();
            c1.edit_student();
        }
        else if(user[0]=='3')
        {
            string temp;
            Courses c1;
            fstream verify;
            Clear();
            verify.open("main.dat",ios::in);
            if(verify.is_open())
            {
                getline(verify,temp);
            }
            verify.close();
            cout<<"\n\n";
            c1.view_courses(0,2,0);
            cout<<"Enter the Course id from above list(AB****)  ";
            cin>>user;
            c1.courstu_remove(user,temp);
        }
        else
        {
            inter();
        }
    }
void facultyhome(int facno)
{
    string user;
    cout<<"\n\n";
    Clear();
    cout<<"Logged in as FACULTY "<<facno<<endl;
    cout<<"Press 1 to view my courses"<<endl;
    cout<<"Press 2 to assign grades"<<endl;
    cout<<"Press 0 to LOGOUT"<<endl;
    cout<<"Please enter your choice  ";
    cin>>user;
    if(user[0]=='1')
    {
        int k;
        Courses c2;
        Clear();
        c2.view_courses(0,0,facno);
        cout<<"Press 1 to go back to faculty home page"<<endl;
        cout<<"Press 0 to LOGOUT"<<endl;
        cout<<"Please enter your choice  ";
        cin>>k;
        if(k==1) facultyhome(facno);
        else inter();
    }
    else if(user[0]=='2')
    {
        Courses c1;
        Clear();
        c1.submit_grades(facno);
    }
    else
    {
        inter();
    }
}
void studenthome(int stuno)
{
    string user;
    string temp;
    cout<<"\n\n";
    Clear();
    cout<<"Logged in as STUDENT "<<stuno<<endl;
    cout<<"Press 1 to view my courses and grades"<<endl;
    cout<<"Press 2 to register (or) deregister for a course"<<endl;
    cout<<"Press 0 to LOGOUT"<<endl;
    cout<<"Please enter your choice  ";
    cin>>user;
    if(user[0]=='1')
    {
        Courses c2;
        Clear();
        c2.view_courses(stuno,0,0);
    }
    else if(user[0]=='2')
    {
        Courses c1;
        Clear();
        cout<<"\nPress 1 to Register for a course"<<endl;
        cout<<"Press 2 to Deregister from a course"<<endl;
        cout<<"Press 3 to go back to student home page"<<endl;
        cout<<"Press 0 to LOGOUT"<<endl;
        cout<<"Enter your choice ";
        cin>>temp;
        if(temp[0]=='1') c1.reg(stuno,1);
        else if(temp[0]=='2') c1.reg(stuno,0);
        else if(temp[0]=='3') studenthome(stuno);
        else inter();
    }
    else
    {
        inter();
    }
}
void student_ra(string studata)
{
    int index=0,i;
    string temp;
    string old[100];
fstream edit;
edit.open("main.dat",ios::in);
if(edit.is_open())
{
getline(edit,temp);
getline(edit,temp);
while(edit.eof()==0)
{
    old[index]=temp;
    index++;
    getline(edit,temp);
    
}
edit.close();
edit.open("main.dat",ios::out);
if(edit.is_open())
{
    edit<<studata+'\n';
    for(i=0;i<=index;i++)
    {
        edit<<old[i]+'\n';
    }
}
}
}
class Admin : public  Courses
{
    public :
    string user,pass;
    Admin(int tool)
    {
        if(tool!=0) Clear();
        cout<<"\nLogged in as admin"<<endl;
        cout<<"Enter username and press enter"<<endl;
        cout<<"Enter your password and press enter"<<endl;
        cout<<"Forgot your password or username press 0"<<endl;
        cin>>user;
        if(user[0]=='0')
        {}
        else 
        {
            cin>>pass;
        }
        if(user[0]=='0'||pass[0]=='0')
        {
            cout<<"username:admin"<<endl;
            cout<<"password:password\n\n\n"<<endl;
            Admin ad1(0);
        }
        else if(user=="admin"&&pass=="password")
        {
            adminhome();
        }
        else
        {
            cout<<"Invalid Credentials\n\n\n"<<endl;
            Admin ad1(0);
        }
    }
};
class Faculty : public  Courses
{
 public :
 Faculty(int tool)
 {
    string user;
    string pass;
    if(tool!=0) Clear();
    cout<<"\nLogged in as FACULTY"<<endl;
    cout<<"Enter username and press enter"<<endl;
    cout<<"Enter your password and press enter"<<endl;
    cout<<"Forgot your password or username press 0"<<endl;
    cin>>user;
    if(user[0]=='0')
    {}
    else 
    {
        cin>>pass;
    }
    if(user[0]=='0'||pass[0]=='0')
    {
        cout<<"\nusername(Ex for faculty4):fac4"<<endl;
        cout<<"password:password\n\n\n"<<endl;
        Faculty ad1(0);
    }
    else if((user=="fac1"||user=="fac2"||user=="fac3"||user=="fac4"||user=="fac5")&&pass=="password")
    {
        if(user=="fac1") 
        {
            facultyhome(1);
        }
        else if(user=="fac2") 
        {
            facultyhome(2);
        }
        else if(user=="fac3") 
        {
            facultyhome(3);
        }
        else if(user=="fac4") 
        {
            facultyhome(4);
        }
        else
        {
            facultyhome(5);
        }
    }
    else
    {
        cout<<"Invalid Credentials\n\n\n"<<endl;
        Faculty f1(0);
    }
 }
};
class Student : public  Courses
{
    public :
    string user,pass,temp;
    int stuno;
    fstream file;
    Student(int tool)
    {
        if(tool!=0) Clear();
        cout<<"\nLogged in as Student"<<endl;
        cout<<"Enter username and press enter"<<endl;
        cout<<"Enter your password and press enter"<<endl;
        cout<<"Forgot your password or username press 0"<<endl;
        cin>>user;
        if(user[0]=='0')
        {}
        else 
        {
            cin>>pass;
        }
        if(user[0]=='0'||pass[0]=='0')
        {
            cout<<"username(For Student15 ):stu15"<<endl;
            cout<<"password:password\n\n\n"<<endl;
            Student ad1(0);
        }
        else if(user[0]=='s'&&user[1]=='t'&&user[2]=='u'&&pass=="password")
        {
            if((user.length()==4&&user[3]>=49&&user[3]<=57)||(user.length()==5&&user[3]>=48&&user[3]<=50&&user[4]>=48&&user[4]<=57))
            {
            stuno=0;
            if(user.length()==4)
            {
                stuno=stuno+user[3]-48;
            }
            else
            {
                stuno=stuno+user[4]-48;
                stuno=stuno+(user[3]-48)*10;
            }
            file.open("main.dat",ios::in);
            if(file.is_open())
            {
                getline(file,temp);
                file.close();
                if(temp[stuno-1]=='1') studenthome(stuno);
                else 
                {
                    cout<<"Message from Admin:"<<endl;
                    cout<<"Congrats,You are removed from IITH"<<endl;
                    cout<<"Reverting back in 10sec"<<endl;
                    Sleep(10000);
                    fflush(stdout);
                    inter();
                }
            }
            
            }
            else
            {
                cout<<"Invalid Credentials\n\n\n"<<endl;
                Student ad1(0);
            }
        }
        else
        {
            cout<<"Invalid Credentials\n\n\n"<<endl;
            Student ad1(0);
        }
    }
};
void intiation()
{
    string temp;
    int i;
    fstream stu1;
    stu1.open("CS1000.dat",ios::out);
    stu1<<"1\n";
    stu1<<"CS1000 ";
    stu1<<"abc ";
    stu1<<"3 ";
    stu1<<"fac1 ";
    for(i=0;i<20;i++)
    {
    stu1<<"0NA ";
    }
    stu1<<"\n";
    stu1.close();
    stu1.open("CS1001.dat",ios::out);
    stu1<<"1\n";
    stu1<<"CS1001 ";
    stu1<<"def ";
    stu1<<"2 ";
    stu1<<"fac2 ";
    for(i=0;i<20;i++)
    {
    stu1<<"0NA ";
    }
    stu1<<"\n";
    stu1.close();
    stu1.open("CS1002.dat",ios::out);
    stu1<<"1\n";
    stu1<<"CS1002 ";
    stu1<<"ghi ";
    stu1<<"1 ";
    stu1<<"fac3 ";
    for(i=0;i<20;i++)
    {
    stu1<<"0NA ";
    }
    stu1<<"\n";
    stu1.close();
    stu1.open("CS1003.dat",ios::out);
    stu1<<"1\n";
    stu1<<"CS1003 ";
    stu1<<"jkl ";
    stu1<<"2 ";
    stu1<<"fac4 ";
    for(i=0;i<20;i++)
    {
    stu1<<"0NA ";
    }
    stu1<<"\n";
    stu1.close();
    stu1.open("CS1004.dat",ios::out);
    stu1<<"1\n";
    stu1<<"CS1004 ";
    stu1<<"mno ";
    stu1<<"3 ";
    stu1<<"fac5 ";
    for(i=0;i<20;i++)
    {
    stu1<<"0NA ";
    }
    stu1<<"\n";
    stu1.close();
    stu1.open("main.dat",ios::out);
    stu1<<"11111111111111111111\n";
    stu1<<"CS1000.dat\n";
    stu1<<"CS1001.dat\n";
    stu1<<"CS1002.dat\n";
    stu1<<"CS1003.dat\n";
    stu1<<"CS1004.dat\n";
    stu1.close();
}
void inter()
{
    int temp=0;
    string credu,credp;
    Clear();
    cout<<"                                           Welcome to AIMS                 "<<endl;
    cout<<"                             ______________________________________________"<<endl;
    cout<<"                           |Press 1 to LOGIN as Admin                     |"<<endl;
    cout<<"                           |Press 2 to LOGIN as Faculty                   |"<<endl;
    cout<<"                           |Press 3 to LOGIN as Student                   |"<<endl;
    cout<<"                           |Press 4 to EXIT                               |"<<endl;
    cout<<"                           |______________________________________________|"<<endl;
    cout<<"Please enter your choice ";
    cin>>temp;
    if(temp==1)
    {
        Admin ad(1);
    }
    else if(temp==2)
    {
        Faculty fa(1);
    }
    else if(temp==3)
    {
        Student s1(1);
    }
    else
    {}
}
int main()
{
    fstream file;
    file.open("main.dat",ios::in);
    
    if(file.is_open())
    {
        file.close();
    }
    else
    {
        intiation();
    }
    inter();
    return 0;
}
