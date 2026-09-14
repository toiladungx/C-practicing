//Viết chương trình giải phương trình bậc 2 trong C. Phương trình bậc 2 có dạng:
//ax^2 + bx + c = 0

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float delta, x1, x2;

    do{
    printf("Nhap he so bac 2: a = ");
    scanf("%f", &a);
    }while(a == 0);
    
    printf("Nhap he so bac 1: b = ");
    scanf("%f", &b);
    printf("Nhap he so tu do: c = ");
    scanf("%f", &c);

    delta = (b*b - 4*a*c);
    printf("Delta = %.2f\n", delta);

    if(delta < 0)
    {
        printf("Phuong trinh vo nghiem.\n");
    }
    else if(delta == 0)
    {
        printf("Phuong trinh co nghiem kep.\n");
        x1 = x2 = -b / (2*a);
        printf("x1 = x2 = %f", x1);
    }
    else if(delta > 0)
    {
        printf("Phuong trinh co 2 nghiem phan biet.\n");
        x1 = ((-b + sqrt(delta)) / (2*a));
        x2 = ((-b - sqrt(delta)) / (2*a));
        printf("x1 = %.2f\nx2 = %.2f\n", x1, x2);
    }
    return 0;
}