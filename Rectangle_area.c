#include <stdio.h>
int main()
{
    float length, width, area;

    printf("Enter Length of Rectangle: ");
    scanf("%f", &length );

    printf("\nEnter Width Of Rectangle: ");
    scanf("%f", &width );
    area = width * length;
    printf("\nThe Area Of Rectangle is %.2f cm: ", area );

}
