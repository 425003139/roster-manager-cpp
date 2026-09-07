#include <iostream>
#include <string>
// Here be functions

using namespace std;

const int MAX_CAPACITY = 50; // self-explanatory

struct Student {
    int id;
    string name;
};

// find a student by ID
int findStudentById(const Student roster[], int count, int targetId, int &comparisons) {
    for (int i = 0; i < count; i++) {
        comparisons++;
        if (roster[i].id == targetId) {
            return i;
        }
    }
    return -1; // Standard C++ flag for "not found"
}

// adding a student to the roster
bool addStudent(Student roster[], int &count, int id, const string &name) {
    if (count >= MAX_CAPACITY) {
        return false;
    }

    // check for duplicates
    int dummyComparisons = 0;
    if (findStudentById(roster, count, id, dummyComparisons) != -1) {
        return false;
    }

    roster[count].id = id;
    roster[count].name = name;
    count++;
    return true;
}

// remove a student by ID
bool removeStudentById(Student roster[], int &count, int targetId) {
    int dummyComparisons = 0;
    int index = findStudentById(roster, count, targetId, dummyComparisons);

    if (index == -1) {
        return false;
    }

    // shift elements left to fill the gap
    for (int i = index; i < count - 1; i++) {
        roster[i] = roster[i + 1];
    }
    count--;
    return true;
}

// retrieve a student record
bool safeGetRecord(const Student roster[], int count, int index, Student &outStudent) {
    if (index < 0 || index >= count) {
        return false;
    }
    outStudent = roster[index];
    return true;
}

// print roster
void printRoster(const Student roster[], int count) {
    if (count == 0) {
        cout << "Roster is currently empty.\n";
        return;
    }

    cout << "\nCURRENT ROSTER (" << count << "/" << MAX_CAPACITY << "):\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". ID: " << roster[i].id << " | Name: " << roster[i].name << "\n";
    }
}
