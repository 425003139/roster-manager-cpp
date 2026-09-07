#include <limits>
#include <iostream>
#include <string>
#include "include/functions.h"

using namespace std;

const int MAX_CAPACITY = 50;
int id;
string name;

// Function prototypes
int findStudentById(const Student roster[], int count, int targetId, int &comparisons);
bool addStudent(Student roster[], int &count, int id, const string &name);
bool removeStudentById(Student roster[], int &count, int targetId);
bool safeGetRecord(const Student roster[], int count, int index, Student &outStudent);
void printRoster(const Student roster[], int count);

int main() {
    Student roster[MAX_CAPACITY];
    int currentCount = 0;
    int choice = 0;

do {
        cout << "\n=========================================\n" << endl;
        cout << "    NTC CC105: STUDENT ROSTER MANAGER \n" << endl;
        cout << "=========================================\n" << endl;
        cout << "1. Add Student Record\n" << endl;
        cout << "2. Search Student by ID\n" << endl;
        cout << "3. Remove Student by ID\n" << endl;
        cout << "4. Safe Inspect Record by Index\n" << endl;
        cout << "5. Display Full Roster\n" << endl;
        cout << "6. Exit\n" << endl;
        cout << "Enter selection [1-6]: " << endl;

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int id;
                string name;
                cout << "Enter Student ID: " << endl;
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline
                cout << "Enter Student Name: " << endl;
                getline(cin, name);

                if (addStudent(roster, currentCount, id, name)) {
                    cout << "Student added successfully.\n" << endl;
                } else {
                    cout << "Failed to add student (Roster full or ID duplicate).\n" << endl;
                }
                break;
            }
            case 2: {
                int targetId, comparisons = 0;
                cout << "Enter ID to search: " << endl;
                cin >> targetId;

                int index = findStudentById(roster, currentCount, targetId, comparisons);
                if (index != -1) {
                    cout << "Student Found at index " << index << ": " << roster[index].name;
                    cout << " (" << comparisons << " comparisons made).\n" << endl;
                } else {
                    cout << "Student with ID " << targetId << " not found.\n" << endl;
                }
                break;
            }
            case 3: {
                int targetId;
                cout << "Enter ID to remove: " << endl;
                cin >> targetId;

                if (removeStudentById(roster, currentCount, targetId)) {
                    cout << "Student removed successfully.\n" << endl;
                } else {
                    cout << "Student ID not found.\n" << endl;
                }
                break;
            }
            case 4: {
                int index;
                Student foundStudent;
                cout << "Enter index to inspect: " << endl;
                cin >> index;

                if (safeGetRecord(roster, currentCount, index, foundStudent)) {
                    cout << "Record Valid -> ID: " << foundStudent.id << ", Name: " << foundStudent.name << "\n";
                } else {
                    cout << "Index out of bounds or invalid.\n" << endl;
                }
                break;
            }
            case 5:
                printRoster(roster, currentCount);
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice. Please pick between 1 and 6.\n" << endl;
                break;
        }
    } while (choice != 6);

    cout << "Exiting system. Memory cleaned successfully.\n" << endl;
    cin.ignore();
    cin.get();
    return 0;
}
// TODO: Implement important missing functions via a separate file

