#include "student_manage.h"

/* Definitions for globals declared in the header */
Student* studentList[MAX_STUDENTS];
int currentTotal = 0;

extern void themSV()
{
    Student* new_student;

    char mssv[ID_LEN];
    char ten[NAME_LEN];
    int  tuoi;
    float gpa;

    printf("Nhap ma SV: ");
    scanf("%s", &mssv);

    printf("Nhap ho ten: ");
    scanf("%s", &ten);

    printf("Nhap tuoi: ");
    scanf("%d", &tuoi);
    
    printf("Nhap GPA: ");
    scanf("%f", &gpa);

    // tao 1 new student
    new_student = createStudent(mssv, ten, tuoi, gpa);

    // ok roi thi add vao global list
    int ret = addStudent(new_student);

    if(ret == -1){
        printf("[Error] Danh sach FULL, khong the them!\n");
        exit(1);
    }else{
        printf("Da them thanh cong!\n\n");
    }
    
}

static Student* createStudent(const char *id, const char *name, int age, float gpa){

    // dynamic 1 hoc sinh tren HEAP
    Student* new_student = (Student*)malloc(sizeof(Student)*1);
    if(new_student == NULL)
    {
       // tao khong thanh cong -> thoat chuong trinh
       exit(1); 
    }
    else
    {
        // neu tao thanh cong thi set value cho student do
        memcpy(new_student->id, id, ID_LEN);
        memcpy(new_student->name, name, NAME_LEN);
        new_student->age = age;
        new_student->gpa = gpa;
    }

}

static int addStudent(Student *s){

    if(currentTotal == MAX_STUDENTS)
    return -1;

    // contro phan tu thu currentTotal tro den HEAP chung voi s
    studentList[currentTotal] = s;
    currentTotal++;

    return 0;
}

static int deleteStudentById(Student *list[], int *count, const char *id){

}


static void freeAllStudents(Student *list[], int count){

}
