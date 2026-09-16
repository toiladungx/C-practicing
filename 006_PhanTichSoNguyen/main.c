/*Đề bài:
Viết chương trình C phân tích số nguyên n thành các thừa số nguyên tố. 
Ví dụ:  12 = 2 x 2 x 3
       100 = 2 x 2 x 5 x 5

Kết quả:
Nhap so nguyen duong n = 120
2 x 2 x 2 x 3 x 5 */

#include <stdio.h>

int main()
{
    int n, i;

    do{
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }while(n <= 0);

    printf("%d = ", n);

    i = 2;

    while(n > 1)
    {
        if(n % i == 0)
        {
            printf("%d", i);
            n = n / i;

            if(n > 1)
            {
                printf(" x ");
            }
        }
        else
        {
            i++;
        }
    }

    return 0;
}