/*
Viết chương trình c tìm n số Fibonacci đầu tiên.

Quy luật của dãy số Fibonacci: số tiếp theo bằng tổng của 2 số trước, 2 số đầu tiên của dãy số là 0, 1.
Ví dụ: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...

Kết quả:
10 số đầu tiên của dãy số fibonacci: 
0 1 1 2 3 5 8 13 21 34 
*/

#include <stdio.h>

int main()
{   
    int n;
    int a = 0, b = 1, c; 
    int dem = 0;

    do{
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }while(n <= 0);

    printf("%d so dau tien cua day so Fibonacci:\n", n);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", a);
        
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}