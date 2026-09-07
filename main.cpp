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
 cout << "\n=========================================\n";
 cout << " NTC CC105: STUDENT ROSTER MANAGER \n";
 cout << "=========================================\n";
 cout << "1. Add Student Record\n";
 cout << "2. Search Student by ID\n";
 cout << "3. Remove Student by ID\n";
 cout << "4. Safe Inspect Record by Index\n";
 cout << "5. Display Full Roster\n";
 cout << "6. Exit\n";
 cout << "Enter selection [1-6]: ";
 cin >> choice;
 // TODO: Implement menu navigation & function calls here
} while (choice != 6);
cout << "Exiting system. Memory cleaned successfully.\n";
return 0
}
// TODO: Implement important missing functions via a separate file

