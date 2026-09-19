#ifndef STUDENT_MANAGE_H
#define STUDENT_MANAGE_H

#include "student.h"

Student* studentList[MAX_STUDENTS];

extern void themSV();

static Student* createStudent(const char *id, const char *name, int age, float gpa);
static int addStudent(Student *list[], int *count, Student *s);
static int deleteStudentById(Student *list[], int *count, const char *id);
static void freeAllStudents(Student *list[], int count);

#endif
