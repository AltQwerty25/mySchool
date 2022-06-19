// Header
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <ctime>

using namespace std;

// Set local time
string today = "Tuesday";
string year = "2022";
string month = "00";
string date = "00";

void time(string day = "") {
    cout << "*[" << year << "|";
    cout << month << "|" << date << "] " << day;
}

string time1 = "• 07:30 - 08:00"; string time2 = "\n• 08:00 - 08:30\n";
string time3 = "• 08:30 - 09:00"; string time4 = "\n• 09:00 - 09:30\n";
string time5 = "• 10:00 - 10:30"; string time6 = "\n• 10:30 - 11:00\n";
string time7 = "• 11:00 - 11:30"; string time8 = "\n• 11:30 - 12:00\n";

// Class Student
class Student {
public:
    string name;
    string mobile_phone_number;

    Student(string name, string mobile_phone_number) {
        Student::name = name;
        Student::mobile_phone_number = mobile_phone_number;
    }

    short total_cash;
    vector <short> cash;

    void CoC(string name, short total){
        cout << name + "\nJust donated the money : ";
        cout << "Rp." << total << ".00\n\n";
    }

    void call_student() {
        cout << ". " << name << "\n" << mobile_phone_number;
    }

    short get_sum_kas() {
        for (int how_many : cash) {
            total_cash += how_many;
        }
        return total_cash;
    }

    void add_kas(short input) {
        cash.push_back(input);
    }

    string stringify() {
        return name + "\n";
    }

};

// Class Teacher
class Teacher {
public:
    string name;
    string study_course;
    string mobile_phone_number;

    Teacher(string study_course, string name, string mobile_phone_number) {
        Teacher::study_course = study_course;
        Teacher::name = name;
        Teacher::mobile_phone_number = mobile_phone_number;
    }

    void call_teacher() {
        cout << "Nama Mapel : " << study_course << endl;
        cout << "Nama Teacher  : " << name << endl;
        cout << "No Hp : " << "+62" << mobile_phone_number << endl;
    }

    void show_maple(string container) {
        cout << study_course << "\n" << container;
    }

};

// Class Lesson
class Lesson {
public:
    string days;
    Lesson(string days);
};

// Class Homework
class Homework {
public:
    string number;
    string date;
    string study_course;

    Homework(string number, string date, string study_course) {
        Homework::number = number;
        Homework::study_course = study_course;
        Homework::date = date;
        cout << number << ". [" << date << "] " << study_course << "\n";
    }

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
Student A(code_01, "00000000000");
Student B(code_02, "00000000000");
Student C(code_03, "00000000000");
Student D(code_04, "80000000000");
Student E(code_05, "00000000000");

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
the class itself.*/
Teacher F(code14B, code14, "00000000000");
Teacher G(code14A, code14, "00000000000");
Teacher H(code16E, code16, "00000000000");
Teacher I(code17B, code16, "00000000000");
Teacher J(code12A, code12, "00000000000");
Teacher K(code17A, code17, "00000000000");

// Class Student dalam Array 
vector < string > student_name
{ A.name,B.name,C.name,D.name,E.name };
array < string, 5 > student_noHp
{ A.mobile_phone_number,B.mobile_phone_number,C.mobile_phone_number,D.mobile_phone_number,E.mobile_phone_number };

// Class Teacher dalam Array
array <string, 6> study_course
{ F.study_course,G.study_course,H.study_course,I.study_course,J.study_course,K.study_course };
array <string, 6> teacher_name
{ F.name,G.name,H.name,I.name,J.name,K.name };
array <string, 6> teacher_noHp
{ F.mobile_phone_number,G.mobile_phone_number,H.mobile_phone_number,I.mobile_phone_number,J.mobile_phone_number,K.mobile_phone_number };

// To call array member
void call_array(vector <string> name, string mobile_phone_number[]) {
    for (short a = 0; a < 13; a++) {
        if (name[a].empty()) { break; }
        if (a < 9) { cout << "0"; }
        cout << a + 1 << " | " << name[a] << "\n";
        cout << "HP : +62" << mobile_phone_number[a] << "\n\n";
    }
}

void call_array(vector <string> name, short total) {
    sort(begin(name), end(name));
    for (short a = 0; a < total; a++) {
        if (name[a].empty()) { break; }
        if (a < 9) { cout << "0"; }
        cout << a + 1 << ". " << name[a] << endl;
    }
}

void call_array(vector <string> name) {
    sort(begin(name), end(name));
    for (short a = 0; a < name.size(); a++) {
        if (name[a].empty()) { break; }
        if (a < 9) { cout << "0"; }
        cout << a + 1 << " | " << name[a] << endl;
    }
}

class DBase {
public:
    ifstream in;
    ofstream out;
    string filename;

    DBase(const char* fileName, bool boolean = false) {

        if (boolean == false) {
            DBase::filename = fileName;
            DBase::in.open(DBase::filename, ios::trunc | ios::out);
        }

        else if (boolean == true) {
            DBase::filename = fileName;
        }

    }

    void save(Student data, short index){
        DBase::out.open(DBase::filename, ios::app);
        if (index <= 9) { DBase::out << "0"; }
        DBase::out << index << ". " << data.stringify();
        DBase::out.close();
    }

    template<typename T>
    void save_text(T data){
        DBase::out.open(DBase::filename, ios::app);
        DBase::out << data;
        DBase::out.close();
    }
    
};

// Menu Student
void student_menu(short slc);

// Menu Teacher
void teacher_menu(short slc);

// Menu - GetOptionMenu
int getOption();

// Prototype_Call_Function for Homework
void call_function_of_homework() {
    Lesson days("Tuesday");
    cout << "\nLOG ONLINE HOMEWORK\n------------------------";
    cout << "---------------------------------\n";
    Homework ke1("01", "2021 JULY 23", "PKK");
    Homework ke2("02", "2021 JULY 24", "ING");
    // you can add another homework like above
}

// Main
int main(int argc, const char* argv[]) {

    short slc, option, choice = getOption();

    char isContinue;

    enum option { STUDENT = 1, TEACHER, HOMEWORK, FINISH };

    while (choice != FINISH) {
        switch (choice) {

        case STUDENT:
            //system("cls");
            cout << "\nSELECTED : Student\n";
            cout << "1. Attendance & Absence\n";
            cout << "2. Information of Student\n";
            cout << "3. Cash of Class\n";
            cout << "4. Homework\n";
            cout << "Choose menu : "; cin >> slc;
            student_menu(slc);
            break;

        case TEACHER:
            //system("cls");
            cout << "\nSELECTED : Teacher\n";
            cout << "1. Information of Teacher\n";
            cout << "2. Timetable\n"; 
            cout << "Choose menu : "; cin >> slc;
            teacher_menu(slc);
            break;

        case HOMEWORK:
            cout << endl;
            call_function_of_homework();
            break;

        case FINISH:
        cout << "System is Finnish - sOpen again to start";
        break;

        default:
            cout << "Options Could not be found - Auto Start\t";
            break;
        }

        label_continue:
        if(!choice == 1 or !choice == 2){
            cout << "Invalid input !\n";
        } 
        cout << "Continue (Y/N) ? : "; cin >> isContinue;

        if (isContinue == 'y' or isContinue == 'Y') {
            //system("cls");
            choice = getOption();
        }

        else if (isContinue == 'n' or isContinue == 'N') {
            cout << "System is Finnish - Open again to start";
            break;
        }

        else {
            goto label_continue;
        }

    }

    return 0;
    cin.get();
}

// Menu Siswa
void student_menu(short slc) {
    int hadir, tidak_hadir, option, pil;
    //DBase siswa = DBase("Siswa.txt");

    if(slc == 1){
        cout << "\nNumber of students in Class : \n";
        call_array(student_name);

        short student, present, option;
        vector <string> exist, not_exist;

        //siswa.save_text("At this moment *[" + year + "|" + month + "|" + date + "]* " + today + "\n");
        cout << "Students are : 1.present or 2.absent : "; cin >> option;

        if(option == 1){
            // Students present
            cout << "\nHow many students are Attendance today : "; cin >> present;
            //siswa.save_text("\nStudents present : \n");
            for (short a = 0; a < present; a++) {
                cout << a + 1 << ". Choose number : "; cin >> student;
                exist.push_back(student_name[student - 1]);
                //Student data_siswa = Student(student_name[a], student_noHp[a] + "\n");
                //siswa.save(data_siswa, a + 1);
            }

            // Student absent
            //siswa.save_text("\nStudents who are not present : \n");

            for (short a = 0; a < student_name.size(); a++) {
                short is_exist = 0;
                for (short b = 0; b < exist.size(); b++) {
                    if (student_name[a] == student_name[b]) {
                        is_exist = 1;
                    }
                }

                if (is_exist == 0) {
                    not_exist.push_back(student_name[a]);
                    //Student data_siswa = Student(student_name[a], student_noHp[a] + "\n");
                    //siswa.save(data_siswa, ((a + 1) - present));
                }
            }

        }else if(option == 2){
            cout << "\nHow many students are Absence today : "; cin >> present;
            //siswa.save_text("\nStudents who are not present : \n");
            for (short a = 0; a < present; a++) {
                cout << a + 1 << ". Choose number : "; cin >> student;
                not_exist.push_back(student_name[student - 1]);
                //Student data_siswa = Student(student_name[a], student_noHp[a] + "\n");
                //siswa.save(data_siswa, a + 1);
            }

            // Student absent
            //siswa.save_text("\nStudents present : \n");
            for (short a = 0; a < student_name.size(); a++) {
                short is_exist = 0;
                for (short b = 0; b < not_exist.size(); b++) {
                    if (student_name[a] == student_name[b]) {
                        is_exist = 1;
                    }
                }

                if (is_exist == 0) {
                    exist.push_back(student_name[a]);
                    //Student data_siswa = Student(student_name[a], student_noHp[a] + "\n");
                    //siswa.save(data_siswa, ((a + 1) - present));
                }
            }
        }

        cout << "\n\n\nToday's student\npresent and absence : "; time();
        cout << today << "\n\nStudents present : " << exist.size() << endl;
        call_array(exist, exist.size());
        cout << "\nStudents absent : " << not_exist.size() << endl;
        call_array(not_exist, not_exist.size());
    }

    else if(slc == 2){
        cout << "\nNumber of students in Class : \n";
        cout << "NO | NAME\n" << "------------------------------\n";

        for (int index = 0; index < 5; index++) {
            if (student_name[index].empty()) { break; }
            if (index < 5) { cout << "0"; }
            cout << index + 1 << " | " << student_name[index] << endl;
            cout << "HP : +628" << student_noHp[index] << "\n------------------------------\n";
        }
    }
    else if(slc == 3){
        // [2021-10-11] / Minggu 1 :
        A.add_kas(5000);
        B.add_kas(1000);
        C.add_kas(5000);
        D.add_kas(5000);
        E.add_kas(5000);
        A.CoC(A.name, A.get_sum_kas());
        B.CoC(B.name, A.get_sum_kas());
        C.CoC(C.name, A.get_sum_kas());
        D.CoC(D.name, A.get_sum_kas());
        E.CoC(E.name, A.get_sum_kas());
    }else if(slc == 4){
        cout << "Make some Homework : ";
    }
}

// Menu Guru
void teacher_menu(short slc) {
    int option, pil;

    if(slc == 1){
        cout << "1. Teacher (all) | 2. Teacher (selected) : ";
        cin >> option;
        cout << "\nNew Academic Year 2021/2022\nXII Computer network Engineering\n\n";
        
        if (option == 1) {
            for (short i = 0; i < teacher_name.size(); i++) {
                cout << "Study Course        | " << study_course[i] << endl;
                cout << "Teacher Name        | " << teacher_name[i] << endl;
                cout << "Mobile Phone Number | +628" << teacher_noHp[i] << endl << endl;
            }
        }

        if (option == 2) {
            for (short i = 0; i < teacher_name.size(); i++) {
                if (i < 9) { cout << "0"; }
                cout << i + 1 << ". " << study_course[i] << endl;
            }

            cout << "Choose Study Course : "; cin >> pil;
            cout << "\nStudy Course      | " << study_course[pil - 1] << endl;
            cout << "Teacher Name        | " << teacher_name[pil - 1] << endl;
            cout << "Mobile Phone Number | +628" << teacher_noHp[pil - 1] << endl;
        }

    }else if(slc == 2){
        cout << "1. Timetable now | 2. All Timetable : ";
        cin >> option;

        if(option == 1){
            Lesson now(today);
        }else if(option == 2){
            Lesson day1("Monday");
            Lesson day2("Tuesday");
            Lesson day3("Wednesday");
            Lesson day4("Thursday");
            Lesson day5("Friday");
            Lesson day6("Saturday");
        }
    }
    
}

// Lesson's Prototype
Lesson::Lesson(string days) {
    Lesson::days = days;

    cout << "\nToday "; time();
    cout << Lesson::days << "*\n";
    cout << "The Lesson is : \n";

    if (days == "Monday" or days == "monday") { cout << "Upacara" << endl; }
    else { cout << "Sholat Dhuha" << endl; }

    if (days == "Monday" or days == "monday") {
        K.show_maple(time1 + time2); // 07:30-07:55|MTK|07:55-08:20
        H.show_maple(time3 + time4); // 08:20-08:45|PKK|08:45-09:10 
        J.show_maple(time5 + time6); // 09:10-09:35|ASJ|09:35-10:00 
        H.show_maple(time7 + time8); // 10:00-10:25|PKK|10:25-10:50 
    }
    else if (days == "Tuesday" or days == "tuesday") {
        F.show_maple(time1 + time2); // 07:30-07:55|IDN|07:55-08:20  
        H.show_maple(time3 + time4); // 08:20-08:45|PKK|08:45-09:10 
        J.show_maple(time5 + time6); // 09:10-09:35|ASJ|09:35-10:00
        I.show_maple(time7 + time8); // 10:00-10:25|TLJ|10:25-10:50
    }
    else if (days == "Wednesday" or days == "wednesday") {
        J.show_maple(time1 + time2); // 07:30-07:55|ASJ|07:55-08:20
        K.show_maple(time3 + time4); // 08:20-08:45|MTK|08:45-09:10
        G.show_maple(time5 + time6); // 09:10-09:35|ING|09:35-10:00
        I.show_maple(time7 + time8); // 10:00-10:25|TLJ|10:25-10:50
    }
    else if (days == "Thursday" or days == "thursday") {
        K.show_maple(time1 + time2); // 07:30-07:55|MTK|07:55-08:20
        I.show_maple(time3 + time4); // 08:20-08:45|TLJ|08:45-09:10
        J.show_maple(time5 + time6); // 09:10-09:35|ASJ|09:35-10:00 
        I.show_maple(time7 + time8); // 10:00-10:25|TLJ|10:25-10:50
    }
    else if (days == "Friday" or days == "friday") {
        K.show_maple(time1 + time2); // 07:30-07:55|MTK|07:55-08:20
        I.show_maple(time3 + time4); // 08:20-08:45|TLJ|08:45-09:10
        H.show_maple(time5 + time6); // 09:10-09:35|PKK|09:35-10:00
    }
    else if (days == "Saturday" or days == "saturday") {
        G.show_maple(time1 + time2); // 07:30-07:55|ING|07:55-08:20
        F.show_maple(time3 + time4); // 08:20-08:45|IDN|08:45-09:10
    }
    else {
        try {
            throw days;
        }
        catch (string days) {
            cout << "ERROR EXCEPTION : " << days << endl;
        }
    }
}

// getOption Call Function
int getOption() {
    int pil;
    cout << "Welcome Developer\n";
    cout << "1. Student | 2. Teacher \n";
    cout << "Please select menu : "; cin >> pil;
    return pil;
}
