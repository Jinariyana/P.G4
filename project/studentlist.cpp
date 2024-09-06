#include <iostream>
#include <string>

using namespace std;

// Constants
const int MAX_STUDENTS = 100;

// Structure to hold student information
struct Student {
    string name;
    int id;
    float grade;
};

// Function prototypes
void addStudent(Student students[], int &count);
void viewStudents(const Student students[], int count);
void updateStudent(Student students[], int count);
void deleteStudent(Student students[], int &count);
void displayMenu();

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();  // To clear the newline character from the buffer

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                viewStudents(students, studentCount);
                break;
            case 3:
                updateStudent(students, studentCount);
                break;
            case 4:
                deleteStudent(students, studentCount);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

void addStudent(Student students[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "Student list is full!" << endl;
        return;
    }

    Student newStudent;
    cout << "Enter student name: ";
    getline(cin, newStudent.name);
    cout << "Enter student ID: ";
    cin >> newStudent.id;
    cout << "Enter student grade: ";
    cin >> newStudent.grade;
    cin.ignore();  // To clear the newline character from the buffer

    students[count] = newStudent;
    count++;
    cout << "Student added successfully." << endl;
}

void viewStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "No students to display." << endl;
        return;
    }

    cout << "Student List:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Name: " << students[i].name
             << ", ID: " << students[i].id
             << ", Grade: " << students[i].grade << endl;
    }
}

void updateStudent(Student students[], int count) {
    int id;
    cout << "Enter the ID of the student to update: ";
    cin >> id;
    cin.ignore();  // To clear the newline character from the buffer

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Current details of student with ID " << id << ":" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Grade: " << students[i].grade << endl;

            cout << "Enter new name: ";
            getline(cin, students[i].name);
            cout << "Enter new grade: ";
            cin >> students[i].grade;
            cin.ignore();  // To clear the newline character from the buffer

            cout << "Student updated successfully." << endl;
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}

void deleteStudent(Student students[], int &count) {
    int id;
    cout << "Enter the ID of the student to delete: ";
    cin >> id;
    cin.ignore();  // To clear the newline character from the buffer

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student deleted successfully." << endl;
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}

void displayMenu() {
    cout << "\nStudent Management System" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. View Students" << endl;
    cout << "3. Update Student" << endl;
    cout << "4. Delete Student" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

