/* Name: Charles Moye
 *
 * Program Desc: This program will take up to 5 pairs of values representing employee sales for the month and their current tenure, and will return a report statement with the provided date that contains the total monthly sales,
 * total monthly profit, each individual employees commission, bonus, federal withholdings, state withholdings, social security contributions, and net pay. The report will also contain the total of each of the previously mentioned
 * employee calculations and the net profit of the company.
 *
 * Basic Flow: First, program must be compiled with "gcc payroll.c -o <output file> -lm". This ensures the math header is explicitly linked when compiling. When running the program, the first inputs to be processed
 * will be the month and the year, provided as integers, and the month integer will be converted into a string from an array of all months. The next 5 and final inputs will be entered as <employee sales> <employee tenure>, and each will be placed 
 * in one of two arrays: employee_sales_array[5] or employee_tenure_array[5]. If less than 5 employees are desired, the user may enter 0 0, which will terminate the inputting and auto populate the rest of the array with 0's if need be.
 * A multitude of functions will then be called to perform the required calculations to populate the report statement.
 *
 * 
 *
 *
 */

// includes & defines
#include <stdio.h>
#include <math.h>
#define EMPLOYEE_COMMISSION 0.125
#define COMPANY_TOTAL_PROFIT 0.45
#define EMPLOYEE_STANDARD_BONUS 0.10
#define EMPLOYEE_TENURE_BONUS 0.05
#define FEDERAL_TAX 0.15
#define STATE_TAX 0.05
#define SOC_SEC_TAX 0.075

/*
 * ARRAYS
 */

char month_strings[12][10] = {
    "JANUARY",
    "FEBRUARY",
    "MARCH",
    "APRIL",
    "MAY",
    "JUNE",
    "JULY",
    "AUGUST",
    "SEPTEMBER",
    "OCTOBER",
    "NOVEMBER",
    "DECEMBER"
};

// Array storing employee sales
int employee_sales_array[5];
// Array storing employee tenure
int employee_tenure_array[5];




/*
 * FUNCTIONS
 */

// Function to calculate sum of employee sales. Input should be employee_sales_array (integers) and output will be the sum (integer).
int sum_employee_sales(int arr[5]) {
    int monthly_sales = 0;
    for (int i = 0; i < 5; i++) {
        monthly_sales += arr[i];
    }
    return monthly_sales;
}

// Function to calculate monthly profit. Input should be employee_sales_array (integers) and a float representing the profit %. Output will be a float result of input 1 * input 2.
float calculate_monthly_profit(int arr[5], float profit) {
    int sales = sum_employee_sales(arr);
    float monthly_profit = sales * profit;
    return monthly_profit;
}

// Function to calculate an employee's commission from sales amount. Input should be one integer value from employee_sales_array and a float representing commission rate. Output will be a float of the result of the two inputs.
float calculate_employee_commission(int sales, float commission_rate) {
    return sales * commission_rate;
}

// Function to calculate total employee commission. Input should be employee_sales_array and a float representing commission rate. Output will be a sum of each value in the array * commission rate.
float calculate_total_commission(int sales[5], float commission_rate) {
    float total_commission = 0;
    for (int i = 0; i < 5; i++) {
        total_commission += sales[i] * commission_rate;
    }
    return total_commission;
}

// Function to calculate an employee's bonus using monthly profit, tenure array, standard bonus, and tenure bonus. Output will be the tenure value converted into a single digit integer representing 10 years per * the tenure bonus rate, added to the 
// standard calculation of monthly profit * standard bonus rate.
float calculate_employee_bonus(int profit, int sales, int tenure, float std_bonus, float tenure_bonus) {
    float total_bonus;
    int usable_tenure = 0;
    int non_employee = 0;
    if (sales == 0 && tenure == 0) {
        return non_employee;
    }
    // Determine the number of tenure bonus increments an employee will receive
    if (tenure < 10) {
        usable_tenure = 0;
    } else if ((tenure % 10) != 0) {
        usable_tenure = ((tenure - (tenure % 10)) / 10);
    } else {
        usable_tenure = tenure / 10;
    }
    // Calculate total bonus percentage as a decimal
    if (usable_tenure != 0) {
        total_bonus = std_bonus + (usable_tenure * tenure_bonus); 
    } else {
        total_bonus = std_bonus;
    }
    
    return total_bonus * profit;
}

// Function to calculate total of all employee bonuses. This function references calculate_employee_bonus and returns the sum.
float total_employee_bonus(int sales[5], int tenure[5]) {
    float bonuses = 0;
    for (int i = 0; i < 5; i++) {
        bonuses += calculate_employee_bonus(calculate_monthly_profit(sales, COMPANY_TOTAL_PROFIT), sales[i], tenure[i], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS);
    }
    return bonuses;
}

// Function to calculate monthly net profit. Inputs will be employee sales array and employee tenure array. output will utilize functions calculate_monthly_profit and total_employee_bonus to return the result of calculate_monthly_profit - 
// total_employee_bonus.
float calculate_net_profit(int sales[5], int tenure[5]) {
    float profit = calculate_monthly_profit(sales, COMPANY_TOTAL_PROFIT);
    float net_profit = profit - total_employee_bonus(sales, tenure);
    return net_profit;
}   

// Function to calculate employee gross pay. Inputs will be float representations of the functions calculate_employee_commission and calculate_employee_bonus. Output will be the sum of the two.
float calculate_employee_gross(float commission, float bonus) {
    return commission + bonus;
}

// Function to calculate federal withholdings. Inputs will be the result of calculate_employee_gross and the global federal rate. Output will be the two multiplied.
float calculate_federal(float gross, float federal) {
    return gross * federal;
}

// Function to calculate state withholdings. Same as calculate_federal, but with state rate.
float calculate_state(float gross, float state) {
    return gross * state;
}

// Function to calculate social security contributions. Same as calculate_federal and calculate_state, but with the social security rate.
float calculate_soc_sec(float gross, float soc_sec) {
    return gross * soc_sec;
}

// Function to calculate employee net pay. Takes values calculated by the previous four functions and subtracts the values sequentially.
float calculate_employee_net(float gross, float fed, float state, float soc_sec) {
    return gross - fed - state - soc_sec;
}

// Function to scale and round values. Simply provide a float value, and it will be scaled by 100, rounded, and then scaled down by 100.
float s_r(float value) {
    return round(value * 100) / 100;
}

/*
 * MAIN
 */

// Initialize date variables
int report_month_int, report_year_int;

int main() {
    // Gather user input (month, year, employee info)
    printf("Enter the month for the report as an integer, a space, then the year as an integer: ");
    scanf(" %d %d", &report_month_int, &report_year_int);
    // Test that the month integer correctly translates to its respective string value
//    printf("%s %d\n", month_strings[report_month_int - 1], report_year_int);
    int i;
    printf("\nNow, enter employee's sales followed by their tenure, repeat for up to 5 total employees.");
    // Loop input to gather 5 employee value sets. 
    // If user enters '0 0', then terminate the loop and populate the rest of the arrays with 0's
    for (i = 0; i < 5; i++) {
        printf("\nEmployee %d: ", i + 1);
        scanf(" %d %d", &employee_sales_array[i], &employee_tenure_array[i]);
        if (employee_sales_array[i] == 0 && employee_tenure_array[i] == 0) {
            for (int z = i; z < 5; z++) {
                employee_sales_array[z] = 0;
                employee_tenure_array[z] = 0;
            }
            break;
        } else {
            continue;
        }
    };
    // Set up reference variables to (slightly) shorten the legnth of the report's print statements for readability
    float MONTHLY_SALES = sum_employee_sales(employee_sales_array);
    float MONTHLY_PROFIT = calculate_monthly_profit(employee_sales_array, COMPANY_TOTAL_PROFIT);
    float TOTAL_BONUSES = total_employee_bonus(employee_sales_array, employee_tenure_array);
    float EMPA_GROSS = calculate_employee_gross(calculate_employee_commission(employee_sales_array[0], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[0], employee_tenure_array[0], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS));
    float EMPB_GROSS = calculate_employee_gross(calculate_employee_commission(employee_sales_array[1], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[1], employee_tenure_array[1], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS));
    float EMPC_GROSS = calculate_employee_gross(calculate_employee_commission(employee_sales_array[2], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[2], employee_tenure_array[2], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS));
    float EMPD_GROSS = calculate_employee_gross(calculate_employee_commission(employee_sales_array[3], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[3], employee_tenure_array[3], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS));
    float EMPE_GROSS = calculate_employee_gross(calculate_employee_commission(employee_sales_array[4], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[4], employee_tenure_array[4], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS));
    float EMPA_FED = calculate_federal(EMPA_GROSS, FEDERAL_TAX), EMPA_STATE = calculate_state(EMPA_GROSS, STATE_TAX), EMPA_SOCSEC = calculate_soc_sec(EMPA_GROSS, SOC_SEC_TAX);
    float EMPB_FED = calculate_federal(EMPB_GROSS, FEDERAL_TAX), EMPB_STATE = calculate_state(EMPB_GROSS, STATE_TAX), EMPB_SOCSEC = calculate_soc_sec(EMPB_GROSS, SOC_SEC_TAX);
    float EMPC_FED = calculate_federal(EMPC_GROSS, FEDERAL_TAX), EMPC_STATE = calculate_state(EMPC_GROSS, STATE_TAX), EMPC_SOCSEC = calculate_soc_sec(EMPC_GROSS, SOC_SEC_TAX);
    float EMPD_FED = calculate_federal(EMPD_GROSS, FEDERAL_TAX), EMPD_STATE = calculate_state(EMPD_GROSS, STATE_TAX), EMPD_SOCSEC = calculate_soc_sec(EMPD_GROSS, SOC_SEC_TAX);
    float EMPE_FED = calculate_federal(EMPE_GROSS, FEDERAL_TAX), EMPE_STATE = calculate_state(EMPE_GROSS, STATE_TAX), EMPE_SOCSEC = calculate_soc_sec(EMPE_GROSS, SOC_SEC_TAX);
    float TOTAL_FED = s_r(EMPA_FED) + s_r(EMPB_FED) + s_r(EMPC_FED) + s_r(EMPD_FED) + s_r(EMPE_FED);
    float TOTAL_STATE = s_r(EMPA_STATE) + s_r(EMPB_STATE) + s_r(EMPC_STATE) + s_r(EMPD_STATE) + s_r(EMPE_STATE);
    float TOTAL_SOCSEC = s_r(EMPA_SOCSEC) + s_r(EMPB_SOCSEC) + s_r(EMPC_SOCSEC) + s_r(EMPD_SOCSEC) + s_r(EMPE_SOCSEC);
    float TOTAL_NET = s_r(calculate_employee_net(EMPA_GROSS, EMPA_FED, EMPA_STATE, EMPA_SOCSEC)) + s_r(calculate_employee_net(EMPB_GROSS, EMPB_FED, EMPB_STATE, EMPB_SOCSEC)) + s_r(calculate_employee_net(EMPC_GROSS, EMPC_FED, EMPC_STATE, EMPC_SOCSEC)) + s_r(calculate_employee_net(EMPD_GROSS, EMPD_FED, EMPD_STATE, EMPD_SOCSEC)) + s_r(calculate_employee_net(EMPE_GROSS, EMPE_FED, EMPE_STATE, EMPE_SOCSEC));





    // Report
    // Utilize the user input month integer as an index to the string array to return the string representation of the integer. Ex: user inputs 3, output is "March"
    printf("\nMONTHLY STATEMENT (%s %d)\n", month_strings[report_month_int - 1], report_year_int);
    printf("%79s\n", "Bloomington Skating Company");
    printf("%79s\n", "Bloomington, IN");
    printf("%79s\n", "Phone: (812)-855-0000");

    printf("\nMONTHLY SALES: $%.2f\n", MONTHLY_SALES);
    printf("MONTHLY PROFIT: $%.2f\n", MONTHLY_PROFIT);
    printf("===============================================================================\n");
    printf("%-10s %-12s %-11s %-12s %-11s %-9s %-8s\n", "Name", "Commission", "Bonus", "Fed W.", "ST W.", "FICA", "Net Pay");
    printf("-------------------------------------------------------------------------------\n");
    printf("%-10s %-12.2f %-11.2f %-12.2f %-11.2f %-9.2f %-8.2f\n", "Empl A:", calculate_employee_commission(employee_sales_array[0], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[0], employee_tenure_array[0], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS), EMPA_FED, EMPA_STATE, EMPA_SOCSEC, calculate_employee_net(EMPA_GROSS, EMPA_FED, EMPA_STATE, EMPA_SOCSEC));
    printf("%-10s %-12.2f %-11.2f %-12.2f %-11.2f %-9.2f %-8.2f\n", "Empl B:", calculate_employee_commission(employee_sales_array[1], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[1], employee_tenure_array[1], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS), EMPB_FED, EMPB_STATE, EMPB_SOCSEC, calculate_employee_net(EMPB_GROSS, EMPB_FED, EMPB_STATE, EMPB_SOCSEC));
    printf("%-10s %-12.2f %-11.2f %-12.2f %-11.2f %-9.2f %-8.2f\n", "Empl C:", calculate_employee_commission(employee_sales_array[2], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[2], employee_tenure_array[2], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS), EMPC_FED, EMPC_STATE, EMPC_SOCSEC, calculate_employee_net(EMPC_GROSS, EMPC_FED, EMPC_STATE, EMPC_SOCSEC));
    printf("%-10s %-12.2f %-11.2f %-12.2f %-11.2f %-9.2f %-8.2f\n", "Empl D:", calculate_employee_commission(employee_sales_array[3], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[3], employee_tenure_array[3], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS), EMPD_FED, EMPD_STATE, EMPD_SOCSEC, calculate_employee_net(EMPD_GROSS, EMPD_FED, EMPD_STATE, EMPD_SOCSEC));
    printf("%-10s %-12.2f %-11.2f %-12.2f %-11.2f %-9.2f %-8.2f\n", "Empl E:", calculate_employee_commission(employee_sales_array[4], EMPLOYEE_COMMISSION), calculate_employee_bonus(MONTHLY_PROFIT, employee_sales_array[4], employee_tenure_array[4], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS), EMPE_FED, EMPE_STATE, EMPE_SOCSEC, calculate_employee_net(EMPE_GROSS, EMPE_FED, EMPE_STATE, EMPE_SOCSEC));
    printf("-------------------------------------------------------------------------------\n");
    printf("%-10s %-12.2f %-11.2f %-12.2f %-11.2f %-9.2f %-8.2f\n", "Total", calculate_total_commission(employee_sales_array, EMPLOYEE_COMMISSION), TOTAL_BONUSES, TOTAL_FED, TOTAL_STATE, TOTAL_SOCSEC, TOTAL_NET);
    printf("-------------------------------------------------------------------------------\n");
    printf("Net Profit (Profit - Bonus): %.2f\n", calculate_net_profit(employee_sales_array, employee_tenure_array));
    printf("John Doe, Branch Manager\n");

    // Initial Testing
//    printf("\nCurrent data: ");
//    for (i = 0; i < 5; i++) {
//        printf("\nEmployee %d: %d %d", i + 1, employee_sales_array[i], employee_tenure_array[i]);
//    }
//    printf("\n");
//
//    printf("Sum of employee sales: %d\n", sum_employee_sales(employee_sales_array));
//    printf("Monthly profit: %f\n", calculate_monthly_profit(employee_sales_array, COMPANY_TOTAL_PROFIT));
//    printf("commission emp2: %f\n", calculate_employee_commission(employee_sales_array[1], EMPLOYEE_COMMISSION));
//    printf("commission emp5: %f\n", calculate_employee_commission(employee_sales_array[4], EMPLOYEE_COMMISSION));
//    printf("bonus emp3: %f\n", calculate_employee_bonus(calculate_monthly_profit(employee_sales_array, COMPANY_TOTAL_PROFIT), employee_tenure_array[2], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS));  
//    printf("bonus emp4: %f\n", calculate_employee_bonus(calculate_monthly_profit(employee_sales_array, COMPANY_TOTAL_PROFIT), employee_tenure_array[3], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS));
//    printf("total_employee_bonus: %f\n", total_employee_bonus(employee_sales_array, employee_tenure_array));
//    printf("calculate_net_profit: %f\n", calculate_net_profit(employee_sales_array, employee_tenure_array));
//    printf("emp1 gross: %f\n", calculate_employee_gross(calculate_employee_commission(employee_sales_array[0], EMPLOYEE_COMMISSION), calculate_employee_bonus(calculate_monthly_profit(employee_sales_array, COMPANY_TOTAL_PROFIT), employee_tenure_array[0], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS)));
//    float emp1_gross = calculate_employee_gross(calculate_employee_commission(employee_sales_array[0], EMPLOYEE_COMMISSION), calculate_employee_bonus(calculate_monthly_profit(employee_sales_array, COMPANY_TOTAL_PROFIT), employee_tenure_array[0], EMPLOYEE_STANDARD_BONUS, EMPLOYEE_TENURE_BONUS));
//    float emp1_fed = calculate_federal(emp1_gross, FEDERAL_TAX);
//    float emp1_state = calculate_state(emp1_gross, STATE_TAX);
//    float emp1_socsec = calculate_soc_sec(emp1_gross, SOC_SEC_TAX);
//    printf("emp1 net: %f\n", calculate_employee_net(emp1_gross, emp1_fed, emp1_state, emp1_socsec));
//    return 0;
}
