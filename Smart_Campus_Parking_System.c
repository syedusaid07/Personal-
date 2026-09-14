#include <stdio.h>
#include <ctype.h>

int main()
{
    int A = 0, B = 0, C = 0;
    int cars = 0, bikes = 0, vans = 0, rejected = 0;
    int total, i;
    char type, category, permit, emergency;

    printf("Enter total vehicles: ");
    scanf("%d", &total);

    for(i = 1; i <= total; i++)
    {
        printf("\nVehicle %d\n", i);

        printf("Vehicle Type (C=Car, B=Bike, V=Van): ");
        scanf(" %c", &type);
        type = toupper(type);

        printf("Category (F=Faculty, S=Student, G=Visitor): ");
        scanf(" %c", &category);
        category = toupper(category);

        printf("Valid Permit? (Y/N): ");
        scanf(" %c", &permit);
        permit = toupper(permit);

        /* Permit check */
        if(permit == 'N')
        {
            printf("Emergency Vehicle? (Y/N): ");
            scanf(" %c", &emergency);
            emergency = toupper(emergency);

            if(emergency == 'N')
            {
                printf("REJECTED: Invalid Permit\n");
                rejected++;
                continue;
            }
        }

        /* Parking assignment */
        if(category == 'F')
        {
            if(A < 20)
            {
                A++;
                printf("Assigned: Zone A (Faculty)\n");
            }
            else
            {
                printf("REJECTED: Zone A Full\n");
                rejected++;
                continue;
            }
        }

        else if(category == 'S')
        {
            if(type == 'V')
            {
                if(C <= 13)
                {
                    C += 2;
                    printf("Assigned: Zone C (Student Van)\n");
                }
                else
                {
                    printf("REJECTED: Zone C Full\n");
                    rejected++;
                    continue;
                }
            }
            else
            {
                if(B < 40)
                {
                    B++;
                    printf("Assigned: Zone B (Student)\n");
                }
                else
                {
                    printf("REJECTED: Zone B Full\n");
                    rejected++;
                    continue;
                }
            }
        }

        else if(category == 'G')
        {
            if(type == 'V')
            {
                if(C <= 13)
                    C += 2;
                else
                {
                    printf("REJECTED: Zone C Full\n");
                    rejected++;
                    continue;
                }
            }
            else
            {
                if(C < 15)
                    C++;
                else
                {
                    printf("REJECTED: Zone C Full\n");
                    rejected++;
                    continue;
                }
            }

            printf("Assigned: Zone C (Visitor)\n");
        }

        /* Count vehicles */
        if(type == 'C')
            cars++;
        else if(type == 'B')
            bikes++;
        else if(type == 'V')
            vans++;

        printf("Remaining: A=%d, B=%d, C=%d\n",
               20-A, 40-B, 15-C);
    }

    printf("\n--- FINAL REPORT ---\n");
    printf("Cars Parked: %d\n", cars);
    printf("Bikes Parked: %d\n", bikes);
    printf("Vans Parked: %d\n", vans);
    printf("Total Rejections: %d\n", rejected);

    return 0;
}
