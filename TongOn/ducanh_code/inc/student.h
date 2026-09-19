#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define ID_LEN 10

typedef struct {
    char id[ID_LEN];
    char name[NAME_LEN];
    int age;
    float gpa;
} Student;

#endif
