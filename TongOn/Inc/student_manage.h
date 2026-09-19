#include "student.h"

Student* createStudent(const char *id, const char *name, int age, float gpa);
int      addStudent(Student *list[], int *count, Student *s);
int      deleteStudentById(Student *list[], int *count, const char *id);
void     freeAllStudents(Student *list[], int count);      // Tránh memory leak