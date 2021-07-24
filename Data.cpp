// Header
#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <ctime>

using namespace std;

// Set local time
time_t now = time(0);
tm *ltm = localtime(&now);

void time(){
    cout << "[" << 1900 + ltm->tm_year << "/";
    cout << 1+ltm->tm_mon << "/" << ltm->tm_mday << "] ";
}

string time1 = "• 07:30 - 07:55\n• 07:55 - 08:20\n";
string time2 = "• 08:20 - 08:45\n• 08:45 - 09:10\n";
string time3 = "• 09:10 - 09:35\n• 09:35 - 10:00\n";
string time4 = "• 10:00 - 10:25\n• 10:25 - 10:50\n";

using namespace std;

//Compiler version g++ 6.3.0

// Class Student
class Student{
  public:
    string name;
    string mobile_phone_number;
        Student(string name, string noHp);
        void call_student();
};

// Class Teacher
class Teacher{
    public:
        string name;
        string study_course;
        string mobile_phone_number;
        Teacher(string study_course, string name, string noHP);
            void call_teacher();
            void show_maple(string &container);
};

// Class Lesson
class Lesson{
    public:
        string days;
        Lesson(string days);
            void call_lesson();
};

// Class Homework
class Homework{
    public:
        string number;
        string date;
        string study_course;
        Homework(string number, string date, string study_course);
};

// container Student
string code_01 = "Aldi Ananda Prasetya";
string code_02 = "Andre Sudarjo";
string code_03 = "Chairul Anwar Pane";
string code_04 = "Danda Rizky Febrian";
string code_05 = "Muchtar Lutfi Saragih";

/*Where to create student classes:
example: Student *class_name* ("no","name","noHp");
note: any added class or
deducted will apply to the calling function
the class itself.*/
Student A (code_01,"00000000000");
Student B (code_02,"00000000000");
Student C (code_03,"00000000000");
Student D (code_04,"80000000000");
Student E (code_05,"00000000000");

// container Teacher
string code06 = "Endah Nurhidayanti,S.Th.I";
string code12 = "Wa Ode Chamidah,S.Pd";
string code14 = "Linda Rusmawati,S.PD";
string code16 = "Ibal Maulana,S.T";
string code17 = "Ardiansyah,S.T";

string code12A = "Mathematics";
string code14A = "English";
string code14B = "Indonesian";
string code16E = "Network Service Technology";
string code17A = "Network Infrastructure Administration";
string code17B = "Network System Administration";

/*Where to create a teacher class:
example: Teacher (class name) ({map},{name},{mobile number})
note: any added class or
deducted will apply to the calling function
the class itself.
*/
Teacher F (code14B,code14,"00000000000");
Teacher G (code14A,code14,"00000000000");
Teacher H (code16E,code16,"00000000000");
Teacher I (code17B,code16,"00000000000");
Teacher J (code12A,code12,"00000000000");
Teacher K (code17A,code17,"00000000000");
        
// Class Student dalam Array 
array < string,5 > student_name
{A.name,B.name,C.name,D.name,E.name};  
array < string,5 > student_noHp
{A.mobile_phone_number,B.mobile_phone_number,C.mobile_phone_number,D.mobile_phone_number,E.mobile_phone_number};

// Class Teacher dalam Array
array <string,6> study_course
{F.study_course,G.study_course,H.study_course,I.study_course,J.study_course,K.study_course};
array <string,6> teacher_name
{F.name,G.name,H.name,I.name,J.name,K.name};
array <string,6> teacher_noHp
{F.mobile_phone_number,G.mobile_phone_number,H.mobile_phone_number,I.mobile_phone_number,J.mobile_phone_number,K.mobile_phone_number};

// Menu Student
void student_menu();

// Menu Teacher
void teacher_menu();

// Menu - GetOptionMenu
int getOption();

// Prototype_Call_Function for Homework
void call_function_of_homework(){
    Lesson days("Tuesday");
    cout << "\nLOG ONLINE HOMEWORK\n------------------------";
    cout << "---------------------------------\n";
    Homework ke1 ("01","2021 JULY 23","PKK");
    Homework ke2 ("02","2021 JULY 24","ING");
}

// Main
int main(){
    
    int choice = getOption();
    
    char isContinue; 

    enum option {STUDENT = 1, TEACHER, HOMEWORK, FINISH};

    while(choice != FINISH){

        switch(choice){
            case STUDENT :
                cout << endl;
                student_menu();
                break;
            case TEACHER :
                cout << endl;
                teacher_menu();
                break;
            case HOMEWORK :
                cout << endl;
                call_function_of_homework();
                break;
            default :
                try{
                  cout << "Options Could not be found\t" ;
                  throw 505;
                }
                catch(short num){
                  cout << "Error " << num ;
                }
                break;
        }
        label_continue:
        cout << "\nContinue? (Y/N) : "; cin >> isContinue;
        if(isContinue == 'y' | isContinue == 'Y'){
            // system("cls");
            choice = getOption();
        }else if(isContinue == 'n' | isContinue == 'N'){
            break;
        }else{
            goto label_continue;
        }
    }    
    
    return 0;
    cin.get();
}

// Student's Prototype
Student::Student(string name, string mobile_phone_number){
    Student::name = name;
    Student::mobile_phone_number = mobile_phone_number;
}

// Student's Prototype Call Function
void Student::call_student(){
    cout << ". " << name << "\n" << mobile_phone_number;
}

// Menu Siswa
void student_menu(){
    int hadir, tidak_hadir, option, pil; 
    cout << "Please choose one !\n";
    cout << "1. Student info | 2. Student attendance : ";
    cin >> option;
    
    if(option == 1){ 
        cout << "\nNumber of students in Class : \n\n";
        cout << "NO | NAME\n" << "------------------------------\n";
        for(int index = 0; index < 5; index++){
            if(student_name[index].empty()){break;}
            if(index < 5){cout << "0"; }
            cout << index + 1 << " | " << student_name[index] << endl;
            cout << "HP : +628" << student_noHp[index] << "\n------------------------------\n" ;
        }     
    }

    if(option == 2){
        cout << "\nNumber of students in Class : \n\n";
        cout << "NO | NAME\n" << "------------------------------\n";
        for(int index = 0; index < 5; index++){
            if(student_name[index].empty()){break;};
            if( index < 5){cout << "0";};
            cout << index + 1 << " | " << student_name[index] ;
            cout << "\n------------------------------\n";
        }

        // Kehadiran Sorting
        array <string, 5> attendance;
        cout << "\nHow many students are Attendance today : "; cin >> hadir;
        for(int i = 0; i < hadir; i++){
            cout << i + 1 <<". Choose No Attendance : ";cin >> pil;
            attendance[i] = student_name[pil-1];
        }
            
        // Ketidakhadiran Sorting
        array <string, 5> absence;
        cout << "\nHow many students are Absence today : ";
        cin >> tidak_hadir;
        for(int i = 0; i < tidak_hadir; i++){
            cout << i+1 <<". Choose No Absence : ";cin >> pil;
            absence[i] = student_name[pil-1];
        }

        cout << "\n\n\nToday's student\nattendance and absence : ";
        time();
        
        // Kehadiran after sorting
        cout << "\nToday's Attendance :" << endl;
        for(int i = 0; i < hadir; i++){
            if(attendance[i].empty()){break;}
            if(i <= 9){cout << "0";}
            cout << i + 1 << ". " << attendance[i] << endl;
        }  
            
        // Ketidakhadiran after sorting
        cout << "\nToday's Absence :" << endl;
        for(int i = 0; i < tidak_hadir; i++){
            if(absence[i].empty()){break;}
            if(i <= 9){cout << "0";}
            cout << i + 1 << ". " << absence[i] << endl;
        } 
    }
}

// Teacher's Prototype
Teacher::Teacher(string study_course, string name, string mobile_phone_number){
    Teacher::study_course = study_course;
    Teacher::name = name;
    Teacher::mobile_phone_number = mobile_phone_number;
}

// Menu Guru
void teacher_menu(){
    int option,pil;
    cout << "Please choose one !\n";
    cout << "1. Teacher (all) | 2. Teacher (selected) : ";
    cin >> option;
    cout << "\nNew Academic Year 2021/2022\nXII Computer network Engineering\n\n";
    if(option == 1){
        for(int i = 0; i < 6; i++){
            cout << "Study Course        | " << study_course[i] << endl;
            cout << "Teacher Name        | " << teacher_name[i] << endl;
            cout << "Mobile Phone Number | +628" << teacher_noHp[i] << endl << endl;
        }      
    }
    if(option == 2){
        for(int i = 0; i < 6; i++){
            if(i < 9){cout << "0";}
            cout << i+1 << ". " << study_course[i] << endl;
        }
        cout << "Choose Study Course : "; cin >> pil;
        cout << "\nStudy Course        | " << study_course[pil-1] << endl;
        cout << "Teacher Name        | " << teacher_name[pil-1] << endl;
        cout << "Mobile Phone Number | +628" << teacher_noHp[pil-1] << endl ;
    }
}

// Teacher's Prototype Call Function
void Teacher::call_teacher(){
    cout << "Nama Mapel : " << study_course << endl;
    cout << "Nama Teacher  : " << name << endl;
    cout << "No Hp : " << "+62" << mobile_phone_number << endl;
}

// Teacher's Prototype Call Function
void Teacher::show_maple(string &container){
    cout << study_course << "\n" << container ;
}

// Lesson's Prototype
Lesson::Lesson(string days){
    Lesson::days = days;
    cout << "Today "; time();
    cout << Lesson::days << endl;
    cout << "Lesson : \n";
    if(days=="Monday"|days=="monday"){
        K.show_maple(time1); // 07:30-07:55|MTK|07:55-08:20
        H.show_maple(time2); // 08:20-08:45|PKK|08:45-09:10 
        J.show_maple(time3); // 09:10-09:35|ASJ|09:35-10:00 
        H.show_maple(time4); // 10:00-10:25|PKK|10:25-10:50 
    }else if(days=="Tuesday"|days=="tuesday"){
        F.show_maple(time1); // 07:30-07:55|IDN|07:55-08:20  
        H.show_maple(time2); // 08:20-08:45|PKK|08:45-09:10 
        J.show_maple(time3); // 09:10-09:35|ASJ|09:35-10:00
        I.show_maple(time4); // 10:00-10:25|TLJ|10:25-10:50
    }else if(days=="Wednesday"|days=="wednesday"){
        J.show_maple(time1); // 07:30-07:55|ASJ|07:55-08:20
        K.show_maple(time2); // 08:20-08:45|MTK|08:45-09:10
        G.show_maple(time3); // 09:10-09:35|ING|09:35-10:00
        I.show_maple(time4); // 10:00-10:25|TLJ|10:25-10:50
    }else if(days=="Thursday"|days=="thursday"){
        K.show_maple(time1); // 07:30-07:55|MTK|07:55-08:20
        I.show_maple(time2); // 08:20-08:45|TLJ|08:45-09:10
        J.show_maple(time3); // 09:10-09:35|ASJ|09:35-10:00 
        I.show_maple(time4); // 10:00-10:25|TLJ|10:25-10:50
    }else if(days=="Friday"|days=="friday"){
        K.show_maple(time1); // 07:30-07:55|MTK|07:55-08:20
        I.show_maple(time2); // 08:20-08:45|TLJ|08:45-09:10
        H.show_maple(time3); // 09:10-09:35|PKK|09:35-10:00
    }else if(days=="Saturday"|days=="saturday"){
        G.show_maple(time1); // 07:30-07:55|ING|07:55-08:20
        F.show_maple(time2); // 08:20-08:45|IDN|08:45-09:10
    }else{
        try{
            throw days;
        }
        catch(string days){
           cout << "ERROR EXCEPTION : " << days << endl;
        }
    }
}

// Homework's Prototype
Homework::Homework(string number, string date, string study_course){
    Homework::number = number;
    Homework::study_course = study_course;
    Homework::date = date;
    cout << number << ". [" << date << "] " << study_course << "\n";
}

// getOption Call Function
int getOption(){
    int pil;
    cout << "Welcome Developer\n";
    cout << "1. Student | 2. Teacher | 3.Timetable\n";
    cout << "Please select menu : "; cin >> pil;
    return pil; 
}