#include <stdio.h>
#include <conio.h>
void main()
{
    int a[10], i;

    clrscr();

    printf("Enter array");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("array");
    for (i = 0; i < 9; i++) 
    {
        printf("%d", a[i]);
    }
    
    getch();
}