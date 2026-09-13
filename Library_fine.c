#include <stdio.h>
int main()
{
    int late_days;

    printf("Enter Number of late days: ");
    scanf("%d", &late_days);

    //condition for fine
    if(late_days == 0)
    {
        printf("\nNo Fine for you");
    }
    else if(late_days <= 5) {
        printf("\nYour Fine: 50 Rs");
    }
    else if(late_days <= 10) {
        printf("\nYour Fine: 100 Rs");
    }
    else {
        printf("\nYour Fine now: 200 Rs");
    }
}
