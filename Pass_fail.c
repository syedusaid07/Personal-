#include <stdio.h>
int main()
{
    int marks;

    printf("Enter MArks of One Subject: ");
    scanf("%d", &marks);

    if (marks >= 50) {
    printf("\nResult = Pass");
    } else {
    printf("\nResult = Fail");
    }
}
