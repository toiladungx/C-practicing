/*Đề bài: Viết chương trình C liệt kê tất cả số nguyên tố có 5 chữ số.

Kết quả:
Liet ke tat ca cac so co 5 chu so:
10007
10009
10037
...
99971
99989
99991
Tong cac so nguyen to co 5 chu so la: 8363*/

#include <stdio.h>

int main()
{
    int i, j;
    int uoc, dem;
    
    dem = 0;

    printf("Liet ke tat ca cac so nguyen to co 5 chu so:\n");

    for(i = 10000; i <= 99999; i++)
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
    printf("\nTong cac so nguyen to co 5 chu so la: %d",dem);
    
    return 0;
}