#include "student_manage.h"

void themSV(Student* listPtr, int* count, int* currentIdx){

    char maSV[ID_LEN], tenSV[NAME_LEN];
    int tuoiSV;
    float gpa;

    printf("Nhap ma SV: ");
    scanf("%s", &maSV);
    printf("Nhap ho ten: ");
    scanf("%s", &tenSV);
    printf("Nhap tuoi: ");
    scanf("%d", &tuoiSV);
    printf("Nhap GPA: ");
    scanf("%f", &gpa);

    // ((listPtr[*currentIdx]).id) // 1 mang id[10]

    // memcpy(*dst_ptr1, *src_ptr2, size ); copy 1 lượng data = size từ 2 -> 1
    // dua du lieu vao list

    memcpy(listPtr[*currentIdx].id, maSV, ID_LEN);
    memcpy(listPtr[*currentIdx].name, tenSV, NAME_LEN);
    listPtr[*currentIdx].age = tuoiSV;
    listPtr[*currentIdx].gpa = gpa;
    (*count)++;
    (*currentIdx)++;

    printf("Them thanh cong!\n");
}

