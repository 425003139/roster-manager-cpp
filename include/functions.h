#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

struct Student {
    int id;
    std::string name;
};

int findStudentById(const Student roster[], int count, int targetId, int &comparisons);
bool addStudent(Student roster[], int &count, int id, const std::string &name);
bool removeStudentById(Student roster[], int &count, int targetId);
bool safeGetRecord(const Student roster[], int count, int index, Student &outStudent);
void printRoster(const Student roster[], int count);

#endif // FUNCTIONS_H
