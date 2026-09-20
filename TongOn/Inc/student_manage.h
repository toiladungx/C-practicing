#ifndef STUDENT_MANAGE_H
#define STUDENT_MANAGE_H

#include "student.h"




// static bool createStudent(const char *id, const char *name, int age, float gpa);
// int      addStudent(Student *list[], int *count, Student *s);
// int      deleteStudentById(Student *list[], int *count, const char *id);
// // void     freeAllStudents(Student *list[], int count);      // Tránh memory leak

void themSV(Student* listPtr, int* count, int* currentIdx);

// static void printAskForSVInfo();

#endif