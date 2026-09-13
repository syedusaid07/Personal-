#include <stdio.h>
int main()
{
    int obt_marks, fam_income;

    printf("Enter Obtained Marks in exam: ");
    scanf("%d", &obt_marks);

    printf("Enter Family Income: ");
    scanf("%d", &fam_income);

    if(obt_marks>=80 || fam_income<50000)
    {
        printf("\nYou are Eligible for Scholarship");
    }
    else {
        printf("\nYou are not Eligible!");
    }
}
