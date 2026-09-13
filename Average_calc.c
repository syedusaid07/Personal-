#include <stdio.h>
int main()
{
    float NUM1, NUM2, NUM3, AVG;

    printf("Enter Marks of Subject: ");
    scanf("%f %f %f", &NUM1, &NUM2, &NUM3);

    AVG = (NUM1 + NUM2 + NUM3)/3;

    printf("\nAverage marks of Three subject : %.1f ", AVG);

}
