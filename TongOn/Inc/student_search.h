#ifndef STUDENT_SEARCH_H
#define STUDENT_SEARCH_H

#include "student.h"

Student* findStudentById(Student *list[], int count, const char *id);

void timSV(Student* listPtr, int* count);

#endif