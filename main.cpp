#include <iostream>
using namespace std;

class School {
public:
    string name;
    string srcode;
    string subject;
    string profname;
    string sched;
    School* next;

    School() {
        next = nullptr;
    }
};

class StudentDatabase {
private:
    School* head;
    int numStudents;

public:
    StudentDatabase() {
        head = nullptr;
        numStudents = 0;
    }

    void addStudent() {
        int num;
        cout << "\t\t\t\tEnter the number of students to add: ";
        cin >> num;
        if (num <= 0) {
            cout << "\t\t\t\tInvalid number of students." << endl;
            return;
        }

        for (int i = 0; i < num; i++) {
            School* newStudent = new School();
            cout << "\t\t\t\t=====================================\n";
            cout << "\t\t\t\tEnter Name of student No. " << i + 1 << ": ";
            cin >> newStudent->name;
            cout << "\t\t\t\tEnter SR-code of student No. " << i + 1 << ": ";
            cin >> newStudent->srcode;
            cout << "\t\t\t\tEnter subject of student No. " << i + 1 << ": ";
            cin >> newStudent->subject;
            cout << "\t\t\t\tEnter professor of student No. " << i + 1 << ": ";
            cin >> newStudent->profname;
            cout << "\t\t\t\tEnter schedule of student No. " << i + 1 << ": ";
            cin >> newStudent->sched;
            newStudent->next = head;
            head = newStudent;
            numStudents++;
        }
    }

    void displayStudents() {
        School* current = head;
        if (current == nullptr) {
            cout << "\t\t\t\tNo students in the database." << endl;
            return;
        }
        cout << "\t\t\t\tList of all students:" << endl;
        while (current != nullptr) {
            cout << "\t\t\t\tStudent name: " << current->name << " || (" << current->srcode << ")"
                << " || Subject: " << current->subject << " || Prof.: " << current->profname << " || Schedule: " << current->sched << endl;
            current = current->next;
        }
    }

    void searchStudent() {
        string srcode;
        cout << "\t\t\t\tEnter SR-code to view student's details (Enter 'N' to stop): ";
        cin >> srcode;
        cout << endl;
        if (srcode == "n" || srcode == "N") {
            return;
        }
        School* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->srcode == srcode) {
                cout << "\t\t\t\tStudent name: " << current->name << " || (" << current->srcode << ")"
                    << " || Subject: " << current->subject << " || Prof.: " << current->profname << " || Schedule: " << current->sched << endl;
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found) {
            cout << "\t\t\t\tSR-code does not exist." << endl;
        }
    }

    void deleteStudent() {
        string srcode;
        cout << "\t\t\t\tEnter SR-code of the student to be deleted: ";
        cin >> srcode;
        School* current = head;
        School* prev = nullptr;
        bool found = false;
        while (current != nullptr) {
            if (current->srcode == srcode) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                numStudents--;
                cout << "\t\t\t\tStudent with SR-code " << srcode << " deleted successfully." << endl;
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        }
        if (!found) {
            cout << "\t\t\t\tSR-code does not exist." << endl;
        }
    }

    int getNumStudents() {
        return numStudents;
    }
};

int main() {
    char back, choice;

    StudentDatabase database;

    do {
        system("cls");
        cout << "\t\t\t\t=====================================\n";
        cout << "\t\t\t\t\t|Student Database.|" << endl;
        cout << "\t\t\t\t=====================================\n";
        cout << "\t\t\t\t[1] Input Student Details." << endl;
        cout << "\t\t\t\t[2] Display list of all Students." << endl;
        cout << "\t\t\t\t[3] Search for a student via SR-code." << endl;
        cout << "\t\t\t\t[4] Delete a student via SR-code." << endl;
        cout << "\t\t\t\t[5] Quit." << endl;
        cout << "\t\t\t\tYour choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                database.addStudent();
                break;
            case '2':
                database.displayStudents();
                break;
            case '3':
                database.searchStudent();
                break;
            case '4':
                database.deleteStudent();
                break;
            case '5':
                return 0;
            default:
                cout << "\t\t\t\tInvalid choice." << endl;
        }

        do {
            cout << "\t\t\t\tContinue? [Y/N]: ";
            cin >> back;
            cout << endl;

            if (back == 'Y' || back == 'y' || back == 'N' || back == 'n') {
                break;
            } else {
                cout << "\t\t\t\tInvalid input. Try again." << endl;
            }
        } while (true);

    } while (back == 'Y' || back == 'y');

    return 0;
}
