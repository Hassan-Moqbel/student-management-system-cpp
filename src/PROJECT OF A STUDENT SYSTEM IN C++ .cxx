#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>

#include <fstream>
using namespace std;

struct students {
    int id{};
    string first_name{};
    string last_name{};
    char gender{};
    string phone_number{};
    string department{};
    float marks[7] {};
} student;


//add/insert function
void add() {

    ofstream file("student.txt", ios::out | ios::app);

    if (file)
    {
        cout << "Enter student id: ";
        cin >> student.id;

        cin.ignore(100, '\n');
        cout << "Enter student first_name: ";
        cin >> student.first_name;

        cin.ignore(100, '\n');
        cout << "Enter student last_name: ";
        cin >> student.last_name;

    gender:
        cin.ignore(100, '\n');
        cout << "Enter student gender: ";
        cin >> student.gender;
        while (student.gender != 'M' && student.gender != 'm' && student.gender != 'F' && student.gender != 'f')
        {
            cout << "Please enter M/F: ";
            cin >> student.gender;
        }

    number:
        cin.ignore(100, '\n');
        cout << "Enter student phone_number: ";
        cin >> student.phone_number;
        string size = student.phone_number;
        if (size.length() != 9) {
            cout << "The four number must contain nine digit...\n";
            goto number;
        }
        if ((size[0] != '7' && size[1] != '7') || (size[0] != '7' && size[1] != '3') || (size[0] != '7' && size[1] != '1'))
        {
            cout << "The First tow number must be 77, 73, or 71...\n";
            goto number;
        }
        
        
        for (size_t i = 0; i < size.length(); i++)
        {
            while (size[i] != '1' && size[i] != '2' && size[i] != '3' && size[i] != '4' && size[i] != '5' && size[i] != '6' && size[i] != '7' && size[i] != '8' && size[i] != '9' && size[i] != '0' && size[i] != ' ') {
                cout << "Please enter the phone_number with only numbers...\n";
                goto number;
            }
        }

    dept:
        cin.ignore(100, '\n');
                    cout << "The First tow number must be 77, 73, or 71...\n";

        if (student.department != "IT" && student.department != "IS" && student.department != "CS") {
            cout << "The department MUST be(IT, IS OR CS)....\n";
		    goto dept;
	    }


        for (size_t i = 0; i < 7; i++)
        {
        grade:
            cout << "Enter student grade " << i + 1 << ": ";
            cin >> student.marks[i];
            if (student.marks[i] < 0 || student.marks[i] > 100)
            {
                cout << "Enter valid grade please,....\n";
                goto grade;
            }
        }

        file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' '
            << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';

        for (size_t i = 0; i < 7; i++)
        {
            file << student.marks[i] << ' ';
        }

        file.close();
    }
    else {
        cout << "We can't open the file....!!" << endl;
    }

}

/*search function*/ 
void search() {
    ifstream file("student.txt", ios::in);

    /*search key variables */
    int id_key{};
    string fname_key{};
    string lname_key{};
    int op{};

    /*search key option*/
search:
    cout << "You want to search by\n1- ID\n2- first_name\n3- last_name\n";
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "Enter the ID you Search for: ";
        cin >> id_key;
        break;
    case 2:
        cout << "Enter the first_name you Search for: ";
        cin >> fname_key;
        break;
    case 3:
        cout << "Enter the first_name you Search for: ";
        cin >> lname_key;
        break;
    default:
        cout << "Invalid Option....\n";
        goto search;
        break;
    }

    /*saerch in the file*/
    if (file)
    {

        while (file >> student.id >> student.first_name >> student.last_name >> student.gender >> student.phone_number >> student.department)
        {
            for (size_t i = 0; i < 7; i++)
            {
                file >> student.marks[i];
            }


            if (student.id == id_key || fname_key == student.first_name || lname_key == student.last_name)
            {
                cout << "Student id: " << student.id << endl;
                cout << "Student first name: " << student.first_name << endl;
                cout << "Student last name: " << student.last_name << endl;
                cout << "Student gender: " << student.gender << endl;
                cout << "Student phone number: " << student.phone_number << endl;
                cout << "Student department: " << student.department << endl;
                for (size_t i = 0; i < 7; i++)
                {
                    cout << "\nStudent mark " << i + 1 << " is: " << student.marks[i];
                    if (student.marks[i] < 50) {
                        cout << "  Student is failed in this subject....):";
                    }
                }
            }
        }

        file.close();
    }
    else {
        cout << "We can't open the file....!!" << endl;
    }
}

//dispaly function
void display() {
    ifstream file("student.txt", ios::in);

    int count{};

    /*display from the files*/
    if (file)
    {

        while (file >> student.id >> student.first_name >> student.last_name >> student.gender >> student.phone_number >> student.department)
        {
            
            for (size_t i = 0; i < 7; i++)
            {
                file >> student.marks[i];
            }




            count++;

            cout << "\t\t\tInformation about student " << count 
                << "\nid:" << student.id
                << "\nfirst_name: " << student.first_name
                << "\nlast_name: " << student.last_name
                << "\ngender: " << student.gender
                << "\nphone_number: " << student.phone_number
                << "\ndepartment: " << student.department;
            for (size_t i = 0; i < 7; i++)
            {
                cout << "\nmark " << i + 1 << ": " << student.marks[i];
                if (student.marks[i] < 50) {
                    cout << "  Student is failed in this subject....):";
                }
            }
            cout << endl << endl;
            
        }

        file.close();
    }
    else {
        cout << "We can't open the file....!!" << endl;
    }


}

/*Delete function*/
void delete_student() {
    ifstream file("student.txt", ios::in);
    ofstream copy_file("copy_student.txt", ios::out | ios::app);

    int delete_id{};
    bool find = false;

    /*select and delete from the file*/
    if (file)
    {
        cout << "Enter The student ID that you want to delete: ";
        cin >> delete_id;
        while (file >> student.id >> student.first_name >> student.last_name >> student.gender >> student.phone_number >> student.department)
        {
            for (size_t i = 0; i < 7; i++)
            {
                file >> student.marks[i];
            }

            if (student.id != delete_id)
            {
                copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                for (size_t i = 0; i < 7; i++)
                {
                    copy_file << student.marks[i] << ' ';
                }
            }
            else {
                find = true;
                cout << "Student delete seccessfuly.....\n";
            }
        }

        if (!find)
        {
            cout << "Student Not Find....." << endl;
        }

        file.close();
        copy_file.close();

        remove("student.txt");
        rename("copy_student.txt", "student.txt");
    }
    else {
        cout << "We can't open the file....!!" << endl;
    }
}

/*Update function*/
void update_student() {

    int update_id{};
    bool find = false;

    ifstream file("student.txt", ios::in);
    ofstream copy_file("copy_student.txt", ios::app | ios::out);

    /*select and update from the file*/
    if (file) {
        cout << "Enter The student ID that you want to update :";
        cin >> update_id;

        while (file >> student.id >> student.first_name >> student.last_name >> student.gender >> student.phone_number >> student.department)
        {
            for (size_t i = 0; i < 7; i++)
            {
                file >> student.marks[i];
            }

            if (student.id != update_id)
            {
                copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                for (size_t i = 0; i < 7; i++)
                {
                    copy_file << student.marks[i] << ' ';
                }
            }
            else 
            {
                int op{};
            update:
                cout << "What you want to update: \n1- ID\n2- First_name\n3- Last_name\n4- Gender\n5- Number\n6- Department\n7- Grade\n8- All\n";
                cin >> op;

                switch (op)
                {
                case 1:
                    cout << "Enter the new ID: ";
                    cin >> student.id;
                    copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                    for (size_t i = 0; i < 7; i++)
                    {
                        copy_file << student.marks[i] << ' ';
                    }
                    break;
                case 2:
                    cout << "Enter the new first name: ";
                    cin >> student.first_name;
                    copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                    for (size_t i = 0; i < 7; i++)
                    {
                        copy_file << student.marks[i] << ' ';
                    }
                    break;
                case 3:
                    cout << "Enter the new last name: ";
                    cin >> student.last_name;
                    copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                    for (size_t i = 0; i < 7; i++)
                    {
                        copy_file << student.marks[i] << ' ';
                    }
                    break;
                case 4:
                    cout << "Enter the new gender: ";
                    cin >> student.gender;
                    copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                    for (size_t i = 0; i < 7; i++)
                    {
                        copy_file << student.marks[i] << ' ';
                    }
                    break;
                case 5:
                    cout << "Enter the new phone number: ";
                    cin >> student.phone_number;
                    copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                    for (size_t i = 0; i < 7; i++)
                    {
                        copy_file << student.marks[i] << ' ';
                    }
                    break;
                case 6:
                    cout << "Enter the new department: ";
                    cin >> student.department;
                    copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                    for (size_t i = 0; i < 7; i++)
                    {
                        copy_file << student.marks[i] << ' ';
                    }
                    break;
                case 7:
                    for (size_t i = 0; i < 7; i++)
                    {
                        cout << "Enter the new grade " << i + 1 << ": ";
                        cin >> student.marks[i];
                    }
                    copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                    for (size_t i = 0; i < 7; i++)
                    {
                        copy_file << student.marks[i] << ' ';
                    }
                    break;
                case 8:
                    cout << "Enter the new ID: ";
                    cin >> student.id;
                    cout << "Enter the new first name: ";
                    cin >> student.first_name;
                    cout << "Enter the new last name: ";
                    cin >> student.last_name;
                    cout << "Enter the new Gender: ";
                    cin >> student.gender;
                    cout << "Enter the new phone number: ";
                    cin >> student.phone_number;
                    cout << "Enter the new department: ";
                    cin >> student.department;
                    for (size_t i = 0; i < 7; i++)
                    {
                        cout << "Enter the new grade " << i + 1 << ": ";
                        cin >> student.marks[i];
                    }

                    copy_file << student.id << ' ' << student.first_name << ' ' << student.last_name << ' ' << student.gender << ' ' << student.phone_number << ' ' << student.department << ' ';
                    for (size_t i = 0; i < 7; i++)
                    {
                        copy_file << student.marks[i] << ' ';
                    }
                    break;
                default:
                    cout << "Invalid Option....\n";
                    goto update;
                    break;
                }
                find = true;
                cout << "Student Updated Seccessfuly.....\n";
            }
        }

        if (!find)
        {
            cout << "Student Not Find....." << endl;
        }

        file.close();
        copy_file.close();

        remove("student.txt");
        rename("copy_student.txt", "student.txt");
    }
    else {
    cout << "We can't open the file....!!" << endl;
    }
    
}

/*Five Top function*/
void fiveTop() {
    ifstream file("student.txt", ios::in);

  
    
      
          if (file)
    {

        /*Five Top variables Help Me With Array*/
        float top[100]{};
        int sum{};
        float avg{};
        int count{};
        int largeIndex{};

        /*Get The Average for each student and add it to the array*/
        while (file >> student.id >> student.first_name >> student.last_name >> student.gender >> student.phone_number >> student.department)
        {
            for (size_t i = 0; i < 7; i++)
            {
                file >> student.marks[i];
                sum += student.marks[i];
            }
            top[count] = sum / 7.0;
            sum = 0;
            count++;
        }


        /*Sort The array with the five top*/
        for (size_t i = 0; i < count - 1; i++)
        {
            largeIndex = i;
            for (size_t j = i + 1; j < count; j++)
            {
                if (top[largeIndex] < top[j]) {
                    largeIndex = j;
                }
            }

            float temp = top[largeIndex];
            top[largeIndex] = top[i];
            top[i] = temp;
        }

        /*Print The Five Top Students*/
        ifstream file("student.txt", ios::in);
        cout << "The First Five Top Students Are: " << endl;
        while (file >> student.id >> student.first_name >> student.last_name >> student.gender >> student.phone_number >> student.department)
        {
            for (size_t i = 0; i < 7; i++)
            {
                file >> student.marks[i];
                sum += student.marks[i];
            }
            avg = sum / 7.0;
            
            if (avg == top[0] || avg == top[1] || avg == top[2] || avg == top[3] || avg == top[4]) {
                cout << "ID: " << student.id 
                    << "\nFirst name: " << student.first_name 
                    << "\nLast name: " << student.last_name 
                    << "\nAVG: " << avg << endl << endl;
            }

            sum = 0;
            avg = 0;

        }
        file.close();
    }
    else
    {
        cout << "We can't open this file....\n";
    }
}

int main() {
    int option1{};
    int option2{};
    int pass{};
    int trys{};

    
    while (true)
    {
        system("cls");
    privilage:
        system("cls");
        cout << "\n\n------------------------------------------------------------------\n";
        cout << "                       STUDENT SYSTEM                                  \n";
        cout << "------------------------------------------------------------------\n\n\n";

        cout << "What is your privilage: " << endl;
        cout << "1- Teacher..." << endl;
        cout << "2- Student..." << endl;
        cout << "3- Exit..." << endl;
        cin >> option1;

        switch (option1)
        {
        case 1:
        password:
            cout << "What is the password: ";
            cin >> pass;
            if (pass == 1234)
            {
            teacherCase:
                system("cls");
                cout << "\n\n------------------------------------------------------------------\n";
                cout << "                       TEACHER MENUE                                 \n";
                cout << "------------------------------------------------------------------\n\n\n";
                cout << "WELCOME TO THE MENUE WHAT DO YOU WANT TO DO SELECT AN OPTION PLEASE: "
                    << "\n1- Display all students..."
                    << "\n2- Add a student..."
                    << "\n3- Delete a student..."
                    << "\n4- Update a student..."
                    << "\n5- Search for a student..."
                    << "\n6- Find the 5 top students..."
                    << "\n7- Exit.."
                    << "\nYour option please: ";
                cin >> option2;

                switch (option2)
                {
                case 1:
                    system("cls");
                    display();
                    system("pause > 0");
                    goto teacherCase;
                    break;
                case 2:
                    system("cls");
                    add();
                    system("pause > 0");
                    goto teacherCase;
                    break;
                case 3:
                    system("cls");
                    delete_student();
                    system("pause > 0");
                    goto teacherCase;
                    break;
                case 4:
                    system("cls");
                    update_student();
                    system("pause > 0");
                    goto teacherCase;
                    break;
                case 5:
                    system("cls");
                    search();
                    system("pause > 0");
                    goto teacherCase;
                    break;
                case 6:
                    system("cls");
                    fiveTop();
                    system("pause > 0");
                    goto teacherCase;
                    break;
                case 7:
                    cout << "\n\n-----------Good Luck, Baye.....(:" << endl;
                    goto privilage;
                    break;
                default:
                    cout << "Ivalid Input....):" << endl;
                    Sleep(1000);
                    goto teacherCase;
                    break;
                }
            }
            else {
                cout << "Wrong password........\n\n";
                trys++;
                if (trys >= 3)
                {
                    cout << "You have passed the valid tryies...):\n";
                    goto privilage;
                }
                goto password;
            }
            break;
        case 2:
        studentCase:
            system("cls");
            cout << "\n\n------------------------------------------------------------------\n";
            cout << "                       STUDENT MENUE                                  \n";
            cout << "------------------------------------------------------------------\n\n\n";
            cout << "WELCOME TO THE MENUE WHAT DO YOU WANT TO DO SELECT AN OPTION PLEASE: "
                << "\n1- Display all students..."
                << "\n2- Search for a student..."
                << "\n3- Find the 5 top students..."
                << "\n4- Exit.."
                << "\nYour option please: ";
            cin >> option2;

            switch (option2)
            {
            case 1:
                system("cls");
                display();
                system("pause > 0");
                goto teacherCase;
                break;
            case 2:
                system("cls");
                search();
                system("pause > 0");
                goto teacherCase;
                break;
            case 3:
                system("cls");
                fiveTop();
                system("pause > 0");
                goto teacherCase;
                break;
            case 4:
                cout << "\n\n-----------Good Luck, Baye.....(:" << endl;
                goto privilage;
                break;
            default:
                cout << "Ivalid Input....):" << endl;
                Sleep(1000);
                goto studentCase;
                break;
            }
            break;
        case 3:
            cout << "\n\n-----------Good Luck, Baye.....(:" << endl;
            exit(1);
            break;
        default:
            cout << "Ivalid Input....):" << endl;
            Sleep(1000);
            system("cls");
            break;
        }

        
    }


    return 0;
}