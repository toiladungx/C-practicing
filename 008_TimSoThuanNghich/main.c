/*
Đề bài: Viết chương trình C tìm các số thuận nghịch có 6 chữ số.

Một số được gọi là số thuận nghịch nếu ta đọc từ trái sang phải hay từ phải sang trái số đó ta vẫn nhận được một số giống nhau.
Ví dụ 123321 là một số thuận nghịch. Hãy liệt kê tất cả các số thuận nghịch có 6 chữa số.

Kết quả:
100001
101101
102201
...
997799
998899
999999
Tong cac so thuan nghich co 6 chu so la: 900
*/

#include <stdio.h>

int main()
{
    int i, n, dao;
    int dem = 0;

    for(i = 100000; i <= 999999; i++)
    {
        n = i;
        dao = 0;

        while(n > 0)
        {
            dao = (dao * 10) + (n % 10);
            n = n / 10; 
        }

        if(i == dao)
        {
            printf("%d ", i);
            dem++;
        }
    }

    printf("\nTong cac so thuan nghich co 6 chu so la: %d", dem);
    return 0;
}