#include "Menu.h"
using namespace std;

void menu(list <Student>& database) {
menustart:
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Add New Student" << endl;
    cout << "\t\t\t 2. Modify Student Information" << endl;
    cout << "\t\t\t 3. Delete Student" << endl;
    cout << "\t\t\t 4. Search Student" << endl;
    cout << "\t\t\t 5. Sort Student" << endl;
    cout << "\t\t\t 6. Print Student List" << endl;
    cout << "\t\t\t 7. Save into database_sv.csv " << endl;
    cout << "\t\t\t 8. Exit" << endl;
    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tPlease Enter Your Choice: ";
    static int choice = 0;
    cin >> choice;

    switch (choice) {
    case 1: // 1. Add New Student
    {
    insert_student:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
        insert(database);

        do {
            cout << "\n\n\t\t\t 1. Continue Adding Another Student Information " << endl;
            cout << "\t\t\t 2. Exit " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
        } while (choice != 1 && choice != 2);

        if (choice == 1) goto insert_student;

        break;
    }

    case 2: // 2. Modify Student Information
    {
    modify_student:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter ID of Student which you want to modify: ";
        short int ID_input = 0; cin >> ID_input;

        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        modify(database, ID_input);
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

        do {
            cout << "\n\n\t\t\t 1. Continue Modifying Another Student Information " << endl;
            cout << "\t\t\t 2. Exit " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
        } while (choice != 1 && choice != 2);

        if (choice == 1) goto modify_student;

        break;
    }

    case 3: // 3. Delete Student
    {
    delete_student:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
        cout << "\nEnter ID of Student which you want to delete: ";
        short int ID_input = 0; cin >> ID_input;
        deletee(database, ID_input);

        do {
            cout << "\n\n\t\t\t 1. Continue Deleting Another Student Information " << endl;
            cout << "\t\t\t 2. Exit " << endl;
            cout << "Please Enter Your Choice: ";
            cin >> choice;
        } while (choice != 1 && choice != 2);

        if (choice == 1) goto delete_student;

        break;
    }

    case 4: // 4. Search Student
    {
    search_student:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;

        do {
            cout << "1, Search By Name" << endl;
            cout << "2, Search By ID" << endl;
            cout << "3, Exit" << endl;
            cout << "Please Enter Your Choice: ";
            cin >> choice;
        } while (choice < 1 && choice >3);

        switch (choice) {
        case 1:
        {
            cout << "\nEnter Name of Student which you want to search: ";
            string name_input; cin >> name_input;

            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            search_by_name(database, name_input);

            break;
        }

        case 2:
        {
            cout << "\nEnter ID of Student which you want to search: ";
            short int ID_input = 0; cin >> ID_input;

            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            search_by_id(database, ID_input);

            break;
        }

        case 3:
            return; // Thoát chương trình 

        default:
            break;
        }

        do {
            cout << "\n\n\t\t\t 1. Continue Searching Another Student Information " << endl;
            cout << "\t\t\t 2. Exit " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
        } while (choice != 1 && choice != 2);

        if (choice == 1) goto search_student;
        break;
    }

    case 5: // 5. Sort Student
    {
    sort_student:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Rank Table --------------------------------------------" << endl;

        do {
            cout << "\n\n\t\t\t 1, Sort by name" << endl;
            cout << "\t\t\t2, Sort by math score" << endl;
            cout << "\t\t\t3, Sort by physic score" << endl;
            cout << "\t\t\t4, Sort by chemical score" << endl;
            cout << "\t\t\t5, Sort by average score" << endl;
            cout << "\t\t\t6, Exit" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
        } while (choice < 1 || choice > 6);

        if (choice == 6) break;
        // sort();

        do {
            cout << "\n\n\t\t\t 1. Continue To Sorting Student Information " << endl;
            cout << "\t\t\t 2. Exit " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
        } while (choice != 1 && choice != 2);

        if (choice == 1) goto search_student;
        break;
    }

    case 6: // 6. Print Student List
    {
        print_list(database);

        do {
            cout << "\n\n\t\t\tPress 0 if you want to exit" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
        } while (choice != 0);

        break;
    }

    case 7: //7. Save into database_sv.csv
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        // save_data();
        saveCSV(database);
        cout << "------------------------------------- Successfully Save Data --------------------------------------------" << endl;

        do {
            cout << "\n\n\t\t\tPress 0 if you want to exit" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
        } while (choice != 0);

        break;
    }

    case 8: // 8. Exit
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
        exit(0);
    }

    default:
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "-------------------------------- Invalid Choice... Please Try Again... --------------------------------" << endl;
        goto menustart;
    }
}

// 1.	Them sinh vien
void insert(list <Student>& database) {
    Student newstudent;
    newstudent.setData();

    database.push_back(newstudent);
}

// 2. Sua thong tin sinh vien
void edit_detail (list <Student>& database, list<Student>::iterator it) {
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------- What detail you want to edit ---------------------------------------" << endl;
    int _choice = 0;

    do {
        cout << "\n\n\t\t\t1. Name" << endl;
        cout << "\t\t\t2. Age" << endl;
        cout << "\t\t\t3. Gender" << endl;
        cout << "\t\t\t4. Math score" << endl;
        cout << "\t\t\t5. Physics score" << endl;
        cout << "\t\t\t6. Chemical score" << endl;
        cout << "\t\t\t0. Exit" << endl;
        cout << "\t\t\tPlease Enter Your Choice: " << endl;
        cin >> _choice;
    } while (_choice < 0 || _choice > 6);

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

    switch (_choice) {
    case 0:
        break;

    case 1: // set Name
    {
        cout << "\n\n\t\t\tEnter the Name you want to change: " << endl;
        string _name = ""; 
        cin.ignore(); cin >> _name;
        it -> setName(_name);
        break;
    }

    case 2: // set Age
    {
        cout << "\n\n\t\t\tEnter the Age you want to change: " << endl;
        short int _age = 0; 
        cin >> _age;
        it -> setAge(_age);

        break;
    }

    case 3: // set Gender
    {
        int num = 0;
        do {
            cout << "\n\n\t\t\tEnter 1 for male and 2 for female" << endl;
            cout << "\t\t\tEnter Gender: ";
            cin >> num;
        } while (num != 1 && num != 2);

        Gender _gender = Male;
        if (num == 1) _gender = Male;
        else _gender = Female;

        it -> setGender(_gender);

        break;
    }

    case 4: // set Math score
    {
        cout << "\n\n\t\t\tEnter the score of math you want to change: " << endl;
        float _Math_score = 0; 
        cin >> _Math_score;
        it -> setMath(_Math_score);

        break;
    }

    case 5: // set Physic score
    {
        cout << "\n\n\t\t\tEnter the score of physics you want to change: " << endl;
        float _Physic_score = 0;
        cin >> _Physic_score;
        it -> setPhysic(_Physic_score);

        break;
    }

    case 6: // set Chemical score
    {
        cout << "\n\n\t\t\tEnter the score of Chemistry you want to change: " << endl;
        float _Physic_score = 0;
        cin >> _Physic_score;
        it -> setPhysic(_Physic_score);

        break;
    }

    default:
        break;
    }
}

void modify (list <Student>& database, short int ID_input) {
    list<Student>::iterator it;
    for (it = database.begin(); it != database.end(); ++it) {
        if (it->getID() == ID_input) {
            cout << "\n\t\t\tData is founded " << endl;
            it->getData();

            edit_detail(database, it);

            cout << "---------------------------------- After Editting ---------------------------------------" << endl;
            it->getData();

            return;
        }
        cout << "\n\t\t\t No student has this information " << endl;
    }
}

// 3. Xoa sinh vien
void deletee (list <Student>& database, short int ID_input) {
    list<Student>::iterator it;
    for (it = database.begin(); it != database.end(); ++it) {
        if (it->getID() == ID_input) {
            cout << "Data is founded " << endl;
            it->getData();

            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "\n\n\t\t\tAre you sure you want to delete this student detail" << endl;
            int _choice = 0;
            do {
                cout << "\t\t\t1. Yes" << endl;
                cout << "\t\t\t2. No" << endl;
                cout << "\t\t\tPlease Enter Your Choice: " << endl;
                cin >> _choice;
            } while (_choice != 1 && _choice != 2);

            if (_choice == 1) database.erase(it);

            return;
        }
    }
    cout << "\n\t\t\t No student has this information " << endl;
}

// 4. Tim kiem sinh vien
void search_by_id(list <Student> database, short int ID_input) {
    list<Student>::iterator it;
    for (it = database.begin(); it != database.end(); ++it) {
        if (it->getID() == ID_input) {
            cout << "Data is founded " << endl;
            it->getData();
            return;
        }
        cout << "\n\t\t\t No student has this information " << endl;
    }
}

void search_by_name(list <Student> database, string name_input) {
    list<Student>::iterator it;
    for (it = database.begin(); it != database.end(); ++it) {
        if (it->getName() == name_input) {
            cout << "\n\t\t\tData is founded " << endl;
            it->getData();
            return;
        }
        cout << "\n\t\t\t No student has this information " << endl;
    }
}

// 5. Sap xep sinh vien
void sort_by_name() {

}

bool cmpName(const Student &a, const Student &b) {
    return a.getName() < b.getName();
}

bool cmpMath(const Student &a, const Student &b) {
    return a.getMath() < b.getMath();
}

bool cmpPhysic(const Student &a, const Student &b) {
    return a.getPhysic() < b.getPhysic();
}

bool cmpChemical(const Student &a, const Student &b) {
    return a.getChemical() < b.getChemical();
}

bool cmpAverScore(const Student& a, const Student &b) {
    return a.getAverScore() < b.getAverScore();
}

void sort_name(list <Student> &database) {
    database.sort(cmpName);
}
void sort_math_score(list <Student> &database) {
    database.sort(cmpMath);
}

void sort_physic_score(list <Student> &database) {
    database.sort(cmpPhysic);
}

void sort_mechical_score(list <Student> &database) {
    database.sort(cmpChemical);
}

void sort_average_score(list <Student> &database) {
    database.sort(cmpAverScore);
}

// 6. In ra danh sach sinh vien
void print_list(list <Student> database) {
    for (auto x : database) {
        cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
        x.getData();
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    }
}

// 7. Luu vao file “database_sv.csv”
void saveCSV(list <Student> &database) {
    ofstream file;
    file.open("database_sv.csv");

    for (auto &it : database) {
        file << it.getName() << ',' << it.getMath() << "," << it.getPhysic() << ',' << it.getChemical() << ',' << it.getAverScore() << endl;
    }
}

