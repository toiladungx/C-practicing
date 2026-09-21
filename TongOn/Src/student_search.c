#include <string.h>
#include <stddef.h>
#include "student_search.h"

Student* findStudentById(Student *list[], int count, const char *id){

}

void timSV(Student* listPtr, int* count)
{
    char MSSV[ID_LEN];

    printf("Nhap ma SV can tim: ");
    scanf("%s", MSSV);

    for(int i = 0; i < (*count); i++)
    {
        if(strcmp(listPtr[i].id, MSSV) == 0)
        {
            printf("Tim thay:\n");
            printf("%s - ", listPtr[i].id);
            printf("%s - ", listPtr[i].name);
            printf("%d tuoi - ", listPtr[i].age);
            printf("GPA %.2f\n", listPtr[i].gpa);
            return;
        }
    }
    
    printf("Khong tim thay sinh vien!\n");
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