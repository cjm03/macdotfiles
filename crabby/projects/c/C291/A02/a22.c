#include <stdio.h>

// Function to print instructions
void printInstructions() {
    printf("Enter payroll data using the following format:\n");
    printf("A <salary> - Administrator\n");
    printf("S <salary> <overtime_hours> - Staff\n");
    printf("R <salary> <overload_credits> - Faculty\n");
    printf("J <credit_hours> - Adjunct\n");
    printf("T <courses> <hours_worked> - Teaching Assistant\n");
    printf("H <hourly_rate> <hours_worked> - Hourly Employee\n");
    printf("? - Display these instructions\n");
    printf("Q - Quit the program\n");
}

int main() {
    char type;

    printInstructions();

    while (scanf(" %c", &type) == 1) {
        if (type == 'q' || type == 'Q') {
            break;  // Quit the program
        } else if (type == '?') {
            printInstructions();
            continue;
        }

        double salary, overtime_hours, overload_credits, credit_hours;
        double courses, hours_worked, hourly_rate;
        double avg_salary = 0, avg_pay = 0;
        char emp_type[15];

        switch (type) {
            case 'A': // Administrator
                scanf("%lf", &salary);
                printf("EMPLOYEE_TYPE     AVG_SALARY       AVG_PAY\n");
                printf("Administrator     %.2f          %.2f\n", salary / 12, salary / 12);
                break;

            case 'S': // Staff
                scanf("%lf %lf", &salary, &overtime_hours);
                avg_salary = salary / 12;
                avg_pay = avg_salary + (overtime_hours * (salary / 2080) * 1.5);
                printf("EMPLOYEE_TYPE     AVG_SALARY       AVG_PAY\n");
                printf("Staff             %.2f          %.2f\n", avg_salary, avg_pay);
                break;

            case 'R': // Faculty
                scanf("%lf %lf", &salary, &overload_credits);
                avg_salary = salary / 12;
                avg_pay = avg_salary + (overload_credits * 500);
                printf("EMPLOYEE_TYPE     AVG_SALARY       AVG_PAY\n");
                printf("Faculty           %.2f          %.2f\n", avg_salary, avg_pay);
                break;

            case 'J': // Adjunct
                scanf("%lf", &credit_hours);
                avg_salary = credit_hours * 850;
                printf("EMPLOYEE_TYPE     AVG_SALARY       AVG_PAY\n");
                printf("Adjunct           %.2f          %.2f\n", avg_salary, avg_salary);
                break;

            case 'T': // Teaching Assistant
                scanf("%lf %lf", &courses, &hours_worked);
                avg_salary = (1250 * courses) / 2;
                printf("EMPLOYEE_TYPE     AVG_SALARY       AVG_PAY\n");
                printf("TA                %.2f          %.2f\n", avg_salary, avg_salary);
                break;

            case 'H': // Hourly
                scanf("%lf %lf", &hourly_rate, &hours_worked);
                avg_salary = hourly_rate * 80;
                avg_pay = hourly_rate * hours_worked;
                printf("EMPLOYEE_TYPE     AVG_SALARY       AVG_PAY\n");
                printf("Hourly            %.2f          %.2f\n", avg_salary, avg_pay);
                break;

            default:
                printf("Invalid input. Use '?' for instructions.\n");
                break;
        }
    }

    return 0;
}

