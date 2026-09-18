/*
Đề bài: Viết chương trình C nhập một mảng số nguyên từ bàn phím.

KQ:
Nhap so phan tu cua mang: 3
Nhap cac phan tu cua mang:
a[0] = 1
a[1] = 3
a[2] = 7
Cac phan tu cua mang:
1 3 7
*/

#include <stdio.h>
#include <stdlib.h>

//#define STATIC

int main()
{
    int i, n;

    do{
        printf("Nhap so phan tu cua mang: ");
        scanf("%d", &n);
    }while(n <= 0);

    #ifdef STATIC   //Static Allocation
    
    int arr[n];

    printf("Nhap cac phan tu cua mang:\n");
    
    for(i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Cac phan tu cua mang:\n");
    
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    #else   //Dynamic Allocation
    
    int* arr_ptr;

    arr_ptr = (int*) malloc(n * sizeof(int));

    printf("Nhap cac phan tu cua mang: \n");
    
    for(i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &arr_ptr[i]);
    }

    printf("Cac phan tu cua mang:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr_ptr[i]);
    }
    free(arr_ptr);

    #endif

    return 0;
}