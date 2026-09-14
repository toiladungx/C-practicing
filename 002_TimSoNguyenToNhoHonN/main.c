// Viết chương trình liệt kê tất cả các số nguyên tố nhỏ hơn n.

// Định nghĩa: Số nguyên tố là số lớn hơn 1 và chỉ chia hết cho 1 và chính nó.
// Ví dụ: 2, 3, 5, 7, 11, 13, 17, … là những số nguyên tố.
// Chú ý: Số 0 và 1 không phải là số nguyên tố. Chỉ có số 2 là số nguyên tố chẵn, 
//tất cả các số chẵn khác không phải là số nguyên tố vì chúng chia hết cho 2.

//2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

#include <stdio.h>

void main()
{
    int n, i;

    printf("Nhap so N:");
    scanf("%d", &n);

    printf("Tat ca so nguyen to nho hon %d la: ", n);

    for(i = 0; i <= n; i++)
    {
        if( (i > 1) && ((i % 1) == 0) && ((i % i) == 0) )
        {
            printf("%d, ", i);
        }
    }
}