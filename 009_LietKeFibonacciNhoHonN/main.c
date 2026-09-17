/*
Đề bài: Viết chương trình C liệt kê các số Fibonacci nhỏ hơn n là số nguyên tố.
Số tự nhiên n được nhập từ bàn phím.

Kết quả:
Nhap so nguyen duong = 100
Cac so fibonacci nho hon 100 va la so nguyen to: 2 3 5 13 89
*/

#include <stdio.h>

int main()
{   
    long long n;
    long long a = 0, b = 1, c = a + b;

    do{
        printf("Nhap so nguyen duong n: ");
        scanf("%lld", &n);
    }while(n <= 0);

    printf("Cac so Fibonacci nho hon %lld va la so nguyen to: ", n);

    while (c < n) {
        int uoc = 0;
        int i;
        for(i = 2; i <= c; i++)
        {
            if (c % i == 0) {
                uoc++;
                break;
            }
        }

        if((uoc == 1) && ((c / i) == 1))
        {
            printf("%lld ", c);
        }   

        c = a + b;
        a = b;
        b = c;
    }
    
    return 0;
}