#include <stdio.h>

/* Function 1: Calculate Subtotal */
float calculateSubtotal(int q, float p)
{
    return q * p;
}

/* Function 2: Calculate Discounted Amount */
float calculateDiscountedAmount(float s, float d)
{
    return s - (s * d) / 100;
}

/* Function 3: Calculate Final Bill */
float calculateFinalBill(float a, float t)
{
    return a + (a * t) / 100;
}

int main()
{
    int quantity;
    float price, discount, tax;
    float subtotal, discountedAmount, finalBill;

    FILE *billFile;

    /* Input */
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price per item: ");
    scanf("%f", &price);

    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    printf("Enter tax percentage: ");
    scanf("%f", &tax);

    /* Validation */
    if (quantity <= 0)
    {
        printf("Error: Invalid quantity.\n");
        return 0;
    }

    if (price < 0)
    {
        printf("Error: Invalid price.\n");
        return 0;
    }

    if (discount < 0 || discount > 100)
    {
        printf("Error: Invalid discount percentage.\n");
        return 0;
    }

    if (tax < 0 || tax > 100)
    {
        printf("Error: Invalid tax percentage.\n");
        return 0;
    }

    /* Calculations */
    subtotal = calculateSubtotal(quantity, price);

    discountedAmount =
        calculateDiscountedAmount(subtotal, discount);

    finalBill =
        calculateFinalBill(discountedAmount, tax);

    /* Create bill document */
    billFile = fopen("bill.txt", "w");

    if (billFile == NULL)
    {
        printf("Error: Could not create bill document.\n");
        return 0;
    }

    /* Store calculation details in bill.txt */
    fprintf(billFile, "==============================\n");
    fprintf(billFile, "        SHOPPING BILL\n");
    fprintf(billFile, "==============================\n");

    fprintf(billFile, "Quantity          : %d\n", quantity);
    fprintf(billFile, "Price per item    : %.2f\n", price);
    fprintf(billFile, "Subtotal          : %.2f\n", subtotal);
    fprintf(billFile, "Discount          : %.2f%%\n", discount);
    fprintf(billFile, "Discounted Amount : %.2f\n", discountedAmount);
    fprintf(billFile, "Tax               : %.2f%%\n", tax);
    fprintf(billFile, "Final Bill        : %.2f\n", finalBill);

    fprintf(billFile, "==============================\n");

    fclose(billFile);

    /* Display final bill to customer */
    printf("\n==============================\n");
    printf("        SHOPPING BILL\n");
    printf("==============================\n");

    printf("Quantity          : %d\n", quantity);
    printf("Price per item    : %.2f\n", price);
    printf("Subtotal          : %.2f\n", subtotal);
    printf("Discount          : %.2f%%\n", discount);
    printf("Discounted Amount : %.2f\n", discountedAmount);
    printf("Tax               : %.2f%%\n", tax);
    printf("Final Bill        : %.2f\n", finalBill);

    printf("==============================\n");
    printf("Bill saved successfully in bill.txt\n");

    return 0;
}
