#include <stdio.h>
int main()
{
    char full_name[50];
    char single;

    printf("Enter Your FULL Name: ");

    fgets(full_name, sizeof(full_name), stdin);
    printf("Your Good Name is ");
    puts(full_name);

    //for single character
    printf("\nEnter any Single Letter");
    scanf("%c", &single );
    printf("Your selected Leteer is %c", single);
}
