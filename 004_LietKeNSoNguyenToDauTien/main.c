/*Đề bài
Viết chương trình C liệt kê n số nguyên tố đầu tiên.

Định nghĩa: Số nguyên tố là số lớn hơn 1 và chỉ chia hết cho 1 và chính nó.
Ví dụ: 2, 3, 5, 7, 11, 13, 17, … là những số nguyên tố.
Chú ý: Số 0 và 1 không phải là số nguyên tố. Chỉ có số 2 là số nguyên tố chẵn, 
tất cả các số chẵn khác không phải là số nguyên tố vì chúng chia hết cho 2.

Kết quả:
Nhập n = 10
10 so nguyen to dau tien la: 
2 3 5 7 11 13 17 19 23 29 
*/

#include <stdio.h>

int main()
{
    int n, i, j;
    int uoc, dem;
    
    dem = 0;
    
    do{
    printf("Nhap so n (>0): ");
    scanf("%d", &n);
    }while(n <= 0);

    printf("%d so nguyen to dau tien la:\n", n);

    for(i = 2; dem < n; i++)
    {
        uoc = 0;
        for(j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                uoc++;
            }
        }
        
        if(uoc == 2)
        {
            printf("%d ", i);
            dem++;
        }
    }
    return 0;
}