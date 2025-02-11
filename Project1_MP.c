// --------------------------------------------------------------------------------
// Name: Mitch Puma
// Class: SET 151
// Abstract: Project1_MP
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// User Defined Types (UDT)
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void ValidateIntegerAsZeroOrOne(int* pintUserInput);
void ValidateInteger(int* pintUserInput);
void ValidateFloat(float* psngUserInput);
float CalculateEmployeeDiscount(int intYears, int intManager);
float CalculateDiscountTotal(float sngPurchaseTotal, float sngEmployeeDiscountDecimal, float sngYTDAmountDiscount);

// --------------------------------------------------------------------------------
// Name: main
// Abstract: main program
// --------------------------------------------------------------------------------
int main()
{
	float sngDailyPurchaseNoDiscount = 0;
	float sngDailyTotalWithDiscount = 0;
	int intProgramRunning = 1;

	while (intProgramRunning != 0)
	{
		int intYears = 0;
		float sngYTDAmount = 0;
		int intManager = 0;
		float sngPurchaseTotal = 0;
		float sngEmployeeDiscountPercentage = 0;
		float sngEmployeeDiscountDecimal = 0;
		float sngYTDAmountDiscount = 0;
		float sngDiscountAllowed = 0;
		float sngTotalWithDiscount = 0;
		printf("Enter the number of years as an integer.\n");
		ValidateInteger(&intYears);
		printf("Enter the total amount of money spent this year.\n");
		ValidateFloat(&sngYTDAmount);
		printf("Enter type of Employee 0 = Employee 1 = Manager\n");
		ValidateIntegerAsZeroOrOne(&intManager);
		printf("Enter today's purchase total.\n");
		ValidateFloat(&sngPurchaseTotal);

		sngEmployeeDiscountDecimal = CalculateEmployeeDiscount(intYears, intManager);
		sngEmployeeDiscountPercentage = sngEmployeeDiscountDecimal * 100;
		sngYTDAmountDiscount = sngYTDAmount * sngEmployeeDiscountDecimal;
		sngDiscountAllowed = CalculateDiscountTotal(sngPurchaseTotal, sngEmployeeDiscountDecimal, sngYTDAmountDiscount);
		sngTotalWithDiscount = sngPurchaseTotal - sngDiscountAllowed;

		//Add purchase to daily total
		sngDailyPurchaseNoDiscount += sngPurchaseTotal;
		sngDailyTotalWithDiscount += sngTotalWithDiscount;

		printf("a. Employee discount percentage %f\n", sngEmployeeDiscountPercentage);
		printf("b. YTD Amount of discount in dollars %f\n", sngYTDAmountDiscount);
		printf("c. Total purchase today before discount %f\n", sngPurchaseTotal);
		printf("d. Employee discount this purchase %f\n", sngDiscountAllowed);
		printf("e. Total with discount %f\n", sngTotalWithDiscount);
		printf("Would you like to exit the program? 0 = Exit 1 = Continue\n");
		ValidateIntegerAsZeroOrOne(&intProgramRunning);
	}
	printf("(All Employee Summary) Calculate the total for all employees for today:\n");
	printf("a. Total before discount for the day %f\n", sngDailyPurchaseNoDiscount);
	printf("b. Total after discounts applied %f\n", sngDailyTotalWithDiscount);
	system("pause");
	return 0;
}



// --------------------------------------------------------------------------------
// Name: ValidateIntegerAsZeroOrOne
// Abstract: Validate that the user input was 0 (false) or 1 (true)
// --------------------------------------------------------------------------------
void ValidateIntegerAsZeroOrOne(int* pintUserInput)
{
	bool blnValidation = false;
	while (blnValidation != true)
	{
		scanf("%d", pintUserInput);
		if (*pintUserInput >= 0 && *pintUserInput <= 1)
		{
			blnValidation = true;
		}
		else
		{
			printf("Input must be 0 or 1.\n");
		}
	}
}



// --------------------------------------------------------------------------------
// Name: ValidateUserInteger
// Abstract: Validate an integer from 1 to 1,000,000
// --------------------------------------------------------------------------------
void ValidateInteger(int* pintUserInput)
{
	bool blnValidation = false;
	while (blnValidation != true)
	{
		scanf("%d", pintUserInput);
		if (*pintUserInput > 0 && *pintUserInput <= 1000000)
		{
			blnValidation = true;
		}
		else
		{
			printf("Input must be between 1 & 1,000,000.\n");
		}
	}
}



// --------------------------------------------------------------------------------
// Name: ValidateUserFloat
// Abstract: Validate a float from 1 to 1,000,000
// --------------------------------------------------------------------------------
void ValidateFloat(float* psngUserInput)
{
	bool blnValidation = false;
	while (blnValidation != true)
	{
		scanf("%f", psngUserInput);
		if (*psngUserInput >= 0 && *psngUserInput <= 1000000)
		{
			blnValidation = true;
		}
		else
		{
			printf("Input must be between 0 & 1,000,000.\n");
		}
	}
}



// --------------------------------------------------------------------------------
// Name: CalculateEmployeeDiscount
// Abstract: Calculate the employee's discount.
// --------------------------------------------------------------------------------
float CalculateEmployeeDiscount(int intYears, int intManager)
{
	float sngDiscount = 0;
	if (intManager == 1)
	{
		sngDiscount += 0.1;
	}
	if (intYears >= 16)
	{
		sngDiscount += 0.3;
	}
	else if (intYears >= 11)
	{
		sngDiscount += 0.25;
	}
	else if (intYears >= 7)
	{
		sngDiscount += 0.2;
	}
	else if (intYears >= 4)
	{
		sngDiscount += 0.14;
	}
	else
	{
		sngDiscount += 0.1;
	}
	return sngDiscount;

}



// --------------------------------------------------------------------------------
// Name: CalculateDiscountTotal
// Abstract: Calculate the amount of money the employee is able to use from discount on final purchase.
// --------------------------------------------------------------------------------
float CalculateDiscountTotal(float sngPurchaseTotal, float sngEmployeeDiscountDecimal, float sngYTDAmountDiscount)
{
	float sngDiscountAllowed = 0;
	float sngSubtotal = 0;
	if (sngYTDAmountDiscount >= 200)
	{
		sngDiscountAllowed = 0;
	}
	else
	{
		sngSubtotal = sngPurchaseTotal - (sngPurchaseTotal * sngEmployeeDiscountDecimal);
		if (sngYTDAmountDiscount + sngSubtotal < 200)
		{
			sngDiscountAllowed = sngPurchaseTotal * sngEmployeeDiscountDecimal;
		}
		if (sngYTDAmountDiscount + sngSubtotal >= 200)
		{
			sngDiscountAllowed = 200 - sngYTDAmountDiscount;
		}
	}
	return sngDiscountAllowed;
}