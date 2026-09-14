#include <stdio.h>
int main()
{
    char vehicle, member, disabled, station;
    float battery, required, hours, time;
    float chargeCost, parkCost, total, rate;

    printf("Vehicle Type (E/H): ");
    scanf(" %c", &vehicle);

    printf("Battery Level: ");
    scanf("%f", &battery);

    printf("Required Level: ");
    scanf("%f", &required);

    printf("Parking Hours: ");
    scanf("%f", &hours);

    printf("Current Time: ");
    scanf("%f", &time);

    printf("Member? (Y/N): ");
    scanf(" %c", &member);

    printf("Disabled? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Station Available? (Y/N): ");
    scanf(" %c", &station);

    /* Station check */
    if(station == 'N' || station == 'n')
    {
        printf("Charging unavailable.\n");
        return 0;
    }

    /* Vehicle check */
    if(vehicle == 'H' || vehicle == 'h')
    {
        if(battery >= 40)
        {
            printf("Hybrid vehicle does not qualify for charging.\n");
            return 0;
        }
    }
    else if(vehicle != 'E' && vehicle != 'e')
    {
        printf("Invalid vehicle type.\n");
        return 0;
    }

    /* Charging */
    if(required <= battery)
    {
        printf("No charging required.\n");
        return 0;
    }

    required = required - battery;

    if(time >= 17 && time <= 22)
    {
        rate = 50;
        chargeCost = required * rate;
        chargeCost *= 0.90;
        printf("\nPeak Time\n");
    }
    else
    {
        rate = 35;
        chargeCost = required * rate;

        if(member == 'Y' || member == 'y')
            chargeCost *= 0.80;

        printf("\nOff-Peak Time\n");
    }

    /* Parking */
    if(hours <= 2)
        parkCost = 200;
    else if(hours <= 5)
        parkCost = 400;
    else
        parkCost = 700;

    if(disabled == 'Y' || disabled == 'y')
        parkCost = 0;
    else if(member == 'Y' || member == 'y')
        parkCost *= 0.80;

    total = chargeCost + parkCost;

    printf("Required Charging: %.2f%%\n", required);
    printf("Charging Cost: Rs. %.2f\n", chargeCost);
    printf("Parking Cost: Rs. %.2f\n", parkCost);
    printf("Final Amount: Rs. %.2f\n", total);

    if(hours > 8)
        printf("Warning: Long parking stay.\n");

    return 0;
}
