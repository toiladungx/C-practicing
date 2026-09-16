/*
Đề bài: Viết chương trình C tính tổng các chữ số của một số nguyên n.
Ví dụ: 1234 = 1 + 2 + 3 + 4 = 10.

Kết quả:
Nhap so nguyen duong n = 1234
Tong cac chu so cua 1234 la: 10
*/

#include <stdio.h>

int main()
{
    int n;
    int tong = 0;

    do{
        printf("Nhap so nguyen duong n: ");
        scanf("%d",&n);
    }while(n <= 0);

    printf("Tong cac chu so cua %d la: ", n);

    do{
        tong = tong + (n % 10);
        n = n / 10;
    }while(n > 0);

    printf("%d", tong);

    return 0;
}