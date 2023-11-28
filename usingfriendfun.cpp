#include <iostream>

using namespace std;

class Student;

void entry(Student &student);
void display(const Student &student);

class Student {
private:
    char name[50];
    int status;

public:
    friend void entry(Student &student);
    friend void display(const Student &student);
};

void entry(Student &student) {
    cout << "Enter name of student: ";
    cin >> student.name;

    cout << "Enter pass status (1 for pass, 0 for fail) for " << student.name << ": ";
    cin >> student.status;
}

void display(const Student &student) {
    cout << "Name: " << student.name << ", Status: ";
    if (student.status == 1) {
        cout << "Pass" << endl;
    } else if (student.status == 0) {
        cout << "Fail" << endl;
    }
}

int main() {
    const int num_s = 10;
    Student students[num_s];
    int p_count = 0;
    int f_count = 0;

    for (int i = 0; i < num_s; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        entry(students[i]);

        if (students[i].status == 1) {
            p_count++;
        } else if (students[i].status == 0) {
            f_count++;
        }
    }

    cout << endl;
    cout << "Student Summary:" << endl;
    for (int i = 0; i < num_s; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        display(students[i]);
    }

    cout << "Number of Pass Candidates: " << p_count << endl;
    cout << "Number of Fail Candidates: " << f_count << endl;

    return 0;
}
