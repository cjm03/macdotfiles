/*
 * salary.c
 *
 * Programmer: Charles Moye
 *
 * Program to return the averagy salary and average pay of different types of employees based on input values from user
 *
 * A02
 */

#include <stdio.h>

// Function to print instructions to user
void PRINT_INSTRUCTIONS() {
    printf("Enter data using the following formats:\n");
    printf("Administrator:   A <salary>\n");
    printf("Staff:           S <salary> <overtime_hours>\n");
    printf("Hourly:          H <hourly_rate> <hours_worked>\n");
    printf("Adjunct Faculty: J <credits>\n");
    printf("Regular Faculty: R <salary> <overload_credits>\n");
    printf("TAs:             T <courses> <hours_worked>\n");
    printf("Help:            ?\n");
    printf("Quit & Print:    Q\n");
}

int main() {
    // Initialize all variables and print the instructions for the user
    char type;

    PRINT_INSTRUCTIONS();
    // Variables for use with scanf
    float salary, hourly_rate;
    float overtime_hours, hours_worked, credits, overload_credits, courses;
    
    // Administrator variables
    float ADM_AVG_SALARY = 0, ADM_AVG_PAY = 0;

    // Staff variables
    float STAFF_AVG_SALARY = 0, STAFF_OVERTIME_RATE = 0, STAFF_OT_HOURS = 0, STAFF_AVG_PAY = 0;
    
    // Hourly variables
    float HOURLY_AVG_SALARY = 0, HOURLY_HOURS_WORKED = 0, HOURLY_OVERTIME_RATE = 0, HOURLY_OT_HOURS = 0, HOURLY_AVG_PAY = 0;
    
    // Adjunct Faculty variables
    float ADJ_AVG_SALARY = 0, ADJ_AVG_PAY = 0;
    
    // Regular Faculty variables
    float REGF_AVG_SALARY = 0, REGF_AVG_PAY = 0;
    
    // TA variables
    float TA_HOURS_VALIDATION = 0, TA_BASE = 0, TA_ADJUSTED = 0, TA_OT_HOURS = 0, TA_OT_PAY = 0, TA_AVG_SALARY = 0, TA_AVG_PAY = 0;

    // Variables to increment in order to omit unused fields when printing table
    int ADM_COUNT = 0, STAFF_COUNT = 0, HOURLY_COUNT = 0, ADJ_COUNT = 0, REGF_COUNT = 0, TA_COUNT = 0;
    // Loop user input to allow for inputs until user uses 'Q' to quit program
    while (scanf(" %c", &type) == 1) {
        if (type == 'Q') {
            break;
        } else if (type == '?') {
            PRINT_INSTRUCTIONS();
            continue;
        }

        // Switch statement to handle employee_types
        switch (type) {
// 'A' vars: ADM_AVG_SALARY, ADM_AVG_PAY
            case 'A':
                scanf("%f", &salary);
                ADM_AVG_SALARY += salary / 12;
                ADM_AVG_PAY += salary / 12;
                ADM_COUNT++;
                break;
// 'S' vars: STAFF_AVG_SALARY, STAFF_OVERTIME_RATE, STAFF_OT_HOURS, STAFF_AVG_PAY
            case 'S':
                scanf("%f %f", &salary, &overtime_hours);
                STAFF_AVG_SALARY += salary / 12;
                STAFF_OVERTIME_RATE = (salary / 12) / 160;
                // Unnecessary, but functional. Keep?
                STAFF_OT_HOURS = overtime_hours;
                // Handle overtime hours above the maximum
                if (STAFF_OT_HOURS > 10) {
                    STAFF_OT_HOURS = 10;
                    printf("Warning: maximum overtime exceeded limit and was disregarded\n");
                }

                STAFF_AVG_PAY += (salary / 12) + (STAFF_OT_HOURS * STAFF_OVERTIME_RATE * 1.5);
                STAFF_COUNT++;
                break;
// 'H' vars: HOURLY_AVG_SALARY, HOURLY_HOURS_WORKED, HOURLY_OVERTIME_RATE, HOURLY_OT_HOURS, HOURLY_AVG_PAY
            case 'H':
                scanf("%f %f", &hourly_rate, &hours_worked);
                HOURLY_AVG_SALARY += hourly_rate * 80;
                HOURLY_HOURS_WORKED = hours_worked;
                HOURLY_OVERTIME_RATE = hourly_rate * 1.25;
                HOURLY_OT_HOURS = 0;
                // Handle overtime hours above the maximum, handle valid overtime hours, handle no overtime hours
                if (HOURLY_HOURS_WORKED >= 100) {
                    HOURLY_AVG_PAY += hourly_rate * 80 + (HOURLY_OVERTIME_RATE * 20);
                    printf("Warning: maximum overtime exceeded limit and was disregarded\n");
                } else if (HOURLY_HOURS_WORKED > 80) {
                    HOURLY_OT_HOURS = HOURLY_HOURS_WORKED - 80;
                    HOURLY_AVG_PAY += hourly_rate * 80 + (HOURLY_OVERTIME_RATE * HOURLY_OT_HOURS);
                } else {
                    HOURLY_AVG_PAY += hourly_rate * HOURLY_HOURS_WORKED;
                }
                HOURLY_COUNT++;
                break;
// 'J' vars: ADJ_AVG_SALARY, ADJ_AVG_PAY
            case 'J':
                scanf("%f", &credits);
                ADJ_AVG_SALARY += ((credits * 2833.33) / 5);
                ADJ_AVG_PAY += ADJ_AVG_SALARY;
                ADJ_COUNT++;
                break;
// 'R' vars: REGF_AVG_SALARY, REGF_AVG_PAY
            case 'R':
                scanf("%f %f", &salary, &overload_credits);
                REGF_AVG_SALARY += salary / 10;
                REGF_AVG_PAY += REGF_AVG_SALARY + (((overload_credits * 2833.33) * 2) / 10);
                REGF_COUNT++;
                break;
// 'T' vars: TA_HOURS_VALIDATION, TA_BASE, TA_ADJUSTED, TA_OT_HOURS, TA_OT_PAY, TA_AVG_SALARY, TA_AVG_PAY
            case 'T':
                scanf("%f %f", &courses, &hours_worked);
                TA_HOURS_VALIDATION = courses * 40;
                TA_BASE = courses * 500;
                TA_ADJUSTED = 0;
                // Handle overtime hours above the maximum
                if (hours_worked > TA_HOURS_VALIDATION) {
                    TA_OT_HOURS = hours_worked - TA_HOURS_VALIDATION;
                    if (TA_OT_HOURS > courses * 8) {
                        TA_OT_HOURS = courses * 8;
                        printf("Warning: maximum overtime exceeded limit and was disregarded\n");
                    }
                }
                // Calculate pay for TA overtime hours
                TA_OT_PAY = TA_OT_HOURS * (500 / 40);
                // Set avg salary and pay if TA worked 40 hours/month/course
                if (hours_worked >= TA_HOURS_VALIDATION) {
                    TA_ADJUSTED = TA_BASE + TA_OT_PAY;
                    TA_AVG_SALARY += TA_BASE;
                    TA_AVG_PAY += TA_ADJUSTED;
                } else {
                    // Set avg salary and pay if TA did NOT work 40 hours/month/course
                    TA_ADJUSTED = (hours_worked / TA_HOURS_VALIDATION) * TA_BASE;
                    TA_AVG_SALARY += TA_ADJUSTED;
                    TA_AVG_PAY += TA_ADJUSTED;
                }
                
                TA_COUNT++;
                break;
        }
    }
    // Print the results
    printf("EMPLOYEE_TYPE   AVG_SALARY      AVG_PAY         \n");
    if (ADM_COUNT > 0) {
        printf("Administrator   %.2f       %.2f\n", ADM_AVG_SALARY /= ADM_COUNT, ADM_AVG_PAY /= ADM_COUNT);
    }
    if (STAFF_COUNT > 0) {
        printf("Staff           %.2f       %.2f\n", STAFF_AVG_SALARY /= STAFF_COUNT, STAFF_AVG_PAY /= STAFF_COUNT);
    }
    if (HOURLY_COUNT > 0) {
        printf("Hourly          %.2f       %.2f\n", HOURLY_AVG_SALARY /= HOURLY_COUNT, HOURLY_AVG_PAY /= HOURLY_COUNT);
    }
    if (ADJ_COUNT > 0) {
        printf("Adjunct Faculty %.2f       %.2f\n", ADJ_AVG_SALARY /= ADJ_COUNT, ADJ_AVG_PAY /= ADJ_COUNT);
    }
    if (REGF_COUNT > 0) {
        printf("Regular Faculty %.2f       %.2f\n", REGF_AVG_SALARY /= REGF_COUNT, REGF_AVG_PAY /= REGF_COUNT);
    }
    if (TA_COUNT > 0) {
        printf("TA              %.2f       %.2f\n", TA_AVG_SALARY /= TA_COUNT, TA_AVG_PAY /= TA_COUNT);
    }

    return 0;
}
