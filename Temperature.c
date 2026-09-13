#include <stdio.h>
int main()
{
    float clesius, farenhite;

    printf("Enter Temp in Celcius: ");
    scanf("%f", &clesius);

    farenhite = (clesius * 9/5) + 32;

    printf("\nTemperature in Farenhie is %.1F ", farenhite);

}
