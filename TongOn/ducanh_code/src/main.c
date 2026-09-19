
#include "student_manage.h"
#include "student_io.h"
#include "student_sort.h"

#define SELECTION_THEM_SV 1
#define SELECTION_XOA_SV 2
#define SELECTION_TIM_SV 3
#define SELECTION_SX_GPA_SV 4
#define SELECTION_IN_DS_SV 5
#define SELECTION_THOAT 6

int main(void) {

    int selection = 0;


    while(1)
    {

        do{
            printf("===== QUAN LY SINH VIEN =====\n");
            printf("1. Them sinh vien\n");
            printf("2. Xoa sinh vien theo ma\n");
            printf("3. Tim sinh vien theo ma\n");
            printf("4. Sap xep theo GPA giam dan\n");
            printf("5. In danh sach\n");
            printf("6. Thoat\n");
            
            scanf("%d", &selection);
            if(selection>6 || selection==0){
                printf("Vui long chon lai, chi co 1,2,3,4,5,6 thoi!!!\n\n\n");
            }
        }while (selection>6 || selection==0);
        
        switch (selection)
        {
        case SELECTION_THEM_SV:
            /* code */
            printf("Chon: %d\n", selection);
            themSV();
            break;
        case SELECTION_XOA_SV:
            /* code */
            printf("Chon: %d\n", selection);
            break;
        case SELECTION_TIM_SV:
            /* code */
            printf("Chon: %d\n", selection);
            break;
        case SELECTION_SX_GPA_SV:
            /* code */
            printf("Chon: %d\n", selection);
            break;
        case SELECTION_IN_DS_SV:
            /* code */
            printf("Chon: %d\n", selection);
            break;
        case SELECTION_THOAT:
            /* code */
            printf("Chon: %d\n", selection);
            break;
        default:
            printf("Khong bao gio reached code o day!\n");
            break;
        }
    }


    // ket thuc chuong trinh
    return 0;
}
