
#include "../Inc/student_manage.h"
#include "../Inc/student_search.h"
#include "../Inc/student_sort.h"
#include "../Inc/student_io.h"

#define THEM_SV_OPTION 1
#define XOA_SV_OPTION 2
#define TIM_SV_OPTION 3
#define SAP_XEP_SV_OPTION 4
#define IN_DS_SV_OPTION 5
#define THOAT_OPTION 6

Student svList[MAX_STUDENTS];
int currentTotalSv = 0;
int currentListIndex = 0;

int main(void) {
    Student *list[MAX_STUDENTS];
    int count = 0;


    int luachon;

    printf("===== QUAN LY SINH VIEN =====\n");
    printf("1. Them sinh vien\n");
    printf("2. Xoa sinh vien theo ma\n");
    printf("3. Tim sinh vien theo ma\n");
    printf("4. Sap xep theo GPA giam dan\n");
    printf("5. In danh sach\n");
    printf("6. Thoat\n");
    
    while(1)
    {
        printf("\nNhap lua chon: ");
        scanf("%d", &luachon);

        switch(luachon)
        {
            case THEM_SV_OPTION:
                themSV(svList, &currentTotalSv, &currentListIndex);
                break;
            case XOA_SV_OPTION:
                break;
            case TIM_SV_OPTION:
                break;
            case SAP_XEP_SV_OPTION:
                break;
            case IN_DS_SV_OPTION:
                inDanhSachSV(svList, &currentTotalSv);
                break;
            case THOAT_OPTION:
                break;
            default:
                printf("Nhap so tu 1 - 6");
        }
    }

    return 0;
}
