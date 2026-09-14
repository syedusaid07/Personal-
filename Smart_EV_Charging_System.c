#include <stdio.h>
#include <string.h>

int main()
{
    char vehicle, member, disabled, station;
    float battery, requiredLevel, parkingHours, time;
    float requiredCharging;
    float chargingCost, chargingDiscount;
    float parkingCost, parkingDiscount;
    float finalAmount;
    float rate;

    printf("Enter Vehicle Type (E/H): ");
    scanf(" %c", &vehicle);

    printf("Enter Current Battery Level: ");
    scanf("%f", &battery);

    printf("Enter Required Charging Level: ");
    scanf("%f", &requiredLevel);

    printf("Enter Parking Duration: ");
    scanf("%f", &parkingHours);

    printf("Enter Current Time: ");
    scanf("%f", &time);

    printf("Are you a member? (Y/N): ");
    scanf(" %c", &member);

    printf("Disabled Priority? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Charging Station Available? (Y/N): ");
    scanf(" %c", &station);

    printf("\n--- EV CHARGING SYSTEM ---\n");

    printf("Vehicle Type: %c\n", vehicle);
    printf("Current Battery: %.2f%%\n", battery);
    printf("Required Level: %.2f%%\n", requiredLevel);

    /* Station check */
    if(station == 'N' || station == 'n')
    {
        if(vehicle == 'H' || vehicle == 'h')
            printf("Charging unavailable - Parking only.");
        else
            printf("No charging slot available.");

        return 0;
    }

    /* Vehicle eligibility */
    if(!((vehicle == 'E' || vehicle == 'e') ||
         ((vehicle == 'H' || vehicle == 'h') && battery < 40)))
    {
        printf("Vehicle does not qualify for EV charging.");
        return 0;
    }

    /* Required charging */
    requiredCharging = requiredLevel - battery;

    if(requiredCharging <= 0)
    {
        printf("No charging required.");
        return 0;
    }

    /* Priority */
    if(battery <= 15 && requiredLevel >= 80)
    {
        printf("Priority: Emergency Charging Priority\n");
    }
    else if(disabled == 'Y' || disabled == 'y' ||
            ((member == 'Y' || member == 'y') && battery <= 30))
    {
        printf("Priority: Priority Charging\n");
    }
    else
    {
        printf("Priority: Normal Charging\n");
    }

    /* Peak / Off-Peak */
    if(time < 17 || time > 22)
    {
        printf("Time: Off-Peak\n");

        rate = 35;
        chargingCost = requiredCharging * rate;

        if((member == 'Y' || member == 'y') &&
           !(battery <= 15 && requiredLevel >= 80))
        {
            chargingDiscount = chargingCost * 0.20;
        }
        else
        {
            chargingDiscount = 0;
        }
    }
    else
    {
        printf("Time: Peak\n");

        rate = 50;
        chargingCost = requiredCharging * rate;

        chargingDiscount = chargingCost * 0.10;
    }

    chargingCost = chargingCost - chargingDiscount;

    /* Parking cost */
    if(parkingHours <= 2)
        parkingCost = 200;
    else if(parkingHours <= 5)
        parkingCost = 400;
    else
        parkingCost = 700;

    /* Parking discount */
    if(disabled == 'Y' || disabled == 'y')
    {
        parkingDiscount = parkingCost;
        parkingCost = 0;
    }
    else if(member == 'Y' || member == 'y')
    {
        parkingDiscount = parkingCost * 0.20;
        parkingCost = parkingCost - parkingDiscount;
    }
    else
    {
        parkingDiscount = 0;
    }

    /* Final amount */
    finalAmount = chargingCost + parkingCost;

    printf("\nRequired Charging: %.2f%%\n", requiredCharging);
    printf("Charging Cost: Rs. %.2f\n", chargingCost);
    printf("Parking Cost: Rs. %.2f\n", parkingCost);
    printf("Charging Discount: Rs. %.2f\n", chargingDiscount);
    printf("Parking Discount: Rs. %.2f\n", parkingDiscount);
    printf("Final Payable Amount: Rs. %.2f\n", finalAmount);

    /* Warning */
    if(parkingHours > 8)
        printf("Long-stay warning: Please relocate your vehicle after charging.");
    else
        printf("Standard parking duration.");

    return 0;
}
