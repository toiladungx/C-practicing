/*Đề bài: Viết chương trình liệt kê tất cả các số nguyên tố nhỏ hơn n.

Định nghĩa: Số nguyên tố là số lớn hơn 1 và chỉ chia hết cho 1 và chính nó.
Ví dụ: 2, 3, 5, 7, 11, 13, 17, … là những số nguyên tố.
Chú ý: Số 0 và 1 không phải là số nguyên tố. Chỉ có số 2 là số nguyên tố chẵn, 
tất cả các số chẵn khác không phải là số nguyên tố vì chúng chia hết cho 2.

Kết quả:
Nhập n = 100
Tat ca cac so nguyen to nho hon 100 la: 
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
*/

#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int dem;

    do{
        printf("Nhap so n (>0): ");
        scanf("%d", &n);
    }while(n <= 0);
 
    printf("Tat ca cac so nguyen to nho hon %d la:\n", n);

    for(i = 2; i < n; i++)
    {
        dem = 0;
        for(j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                dem++;
            }
        }

        if(dem == 2)
        {
            printf("%d ",i);
        }
    }

    return 0;
}