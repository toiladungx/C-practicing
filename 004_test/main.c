/*
Viết chương trình C tìm ước số chung lớn nhất (USCLN) và bội số chung nhỏ nhất (BSCNN) của hai số nguyên dương a và b.
Kết quả:
Nhap so nguyen duong a = 3
Nhap so nguyen duong b = 4
USCLN cua 3 va 4 la: 1
USCLN cua 3 va 4 la: 12
*/

#include <stdio.h>

int main()
{
    int a, b, a2, b2, du;
    int UCLN, BCNN;

    do{
        printf("Nhap so a: ");
        scanf("%d", &a);
        printf("Nhap so b: ");
        scanf("%d", &b);
    }while(a == 0 || b == 0);

    a2 = a;
    b2 = b;

    while(b != 0)
    {
        du = a % b;
        a = b;
        b = du;
    }    
    UCLN = a;
    printf("UCLN la: %d\n", UCLN);

    BCNN = (a2 * b2) / UCLN;
    printf("BCNN la: %d", BCNN);

    return 0;
}