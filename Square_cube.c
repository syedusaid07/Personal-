#include <stdio.h>
int main()
{
    int num, square, cube;

    printf("Enter Any Integer or Real Number: ");
    scanf("%d", &num );

    square = num * num ;
    cube = num * num * num ;

    printf("\nSquare of your num is %d ", square);
    printf("\nCube oF your Num is %d ", cube );

}
