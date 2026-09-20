#include "student_io.h"

// void printAllStudents(Student *list[], int count){

// }

void inDanhSachSV(Student* listPtr, int* count)
{
    
    printf("ID\tName\t\t\t\tAge\tGPA\n");
    printf("----------------------------------------------------\n");

    for(int i = 0; i < (*count); i++)
    {   
        printf("%s\t", listPtr[i].id);
        printf("%s\t\t\t", listPtr[i].name);
        printf("%d\t", listPtr[i].age);
        printf("%.2f\n", listPtr[i].gpa);
    }
    
    printf("----------------------------------------------------\n");
    printf("Tong so sinh vien: %d\n", (*count));
}

/*
// ((listPtr[*currentIdx]).id) // 1 mang id[10]

    // memcpy(*dst_ptr1, *src_ptr2, size ); copy 1 lượng data = size từ 2 -> 1
    // dua du lieu vao list

    memcpy(listPtr[*currentIdx].id, maSV, ID_LEN);
    memcpy(listPtr[*currentIdx].name, tenSV, NAME_LEN);
    listPtr[*currentIdx].age = tuoiSV;
    listPtr[*currentIdx].gpa = gpa;
*/