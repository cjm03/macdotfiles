#include <stdio.h>

#define MAX_EMPLOYEES 100

// Structure to store employee payroll data
typedef struct {
    char type[15];
    double avg_salary;
    double avg_pay;
} Employee;

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
    printf("Q - Quit and display the payroll report\n");
}

// Function to print payroll report
void printReport(Employee employees[], int count) {
    printf("\n%-15s %-15s %s\n", "EMPLOYEE_TYPE", "AVG_SALARY", "AVG_PAY");
    
    for (int i = 0; i < count; i++) {
        printf("%-15s %-15.2f %.2f\n", employees[i].type, employees[i].avg_salary, employees[i].avg_pay);
    }
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    char type;

    printInstructions();

    while (scanf(" %c", &type) == 1) {
        if (type == 'q' || type == 'Q') {
            printReport(employees, count);
            break;
        } else if (type == '?') {
            printInstructions();
            continue;
        }

        double salary, overtime_hours, overload_credits, credit_hours;
        double courses, hours_worked, hourly_rate;

        char emp_type[15];
        double avg_salary = 0, avg_pay = 0;

        switch (type) {
            case 'A': // Administrator
                scanf("%lf", &salary);
                sprintf(emp_type, "Administrator");
                avg_salary = salary / 12;
                avg_pay = avg_salary;
                break;

            case 'S': // Staff
                scanf("%lf %lf", &salary, &overtime_hours);
                sprintf(emp_type, "Staff");
                avg_salary = salary / 12;
                avg_pay = avg_salary + (overtime_hours * (salary / 2080) * 1.5);
                break;

            case 'R': // Faculty
                scanf("%lf %lf", &salary, &overload_credits);
                sprintf(emp_type, "Faculty");
                avg_salary = salary / 12;
                avg_pay = avg_salary + (overload_credits * 500);
                break;

            case 'J': // Adjunct
                scanf("%lf", &credit_hours);
                sprintf(emp_type, "Adjunct");
                avg_salary = credit_hours * 850;
                avg_pay = avg_salary;
                break;

            case 'T': // Teaching Assistant
                scanf("%lf %lf", &courses, &hours_worked);
                sprintf(emp_type, "TA");
                avg_salary = (1250 * courses) / 2;
                avg_pay = avg_salary;
                break;

            case 'H': // Hourly
                scanf("%lf %lf", &hourly_rate, &hours_worked);
                sprintf(emp_type, "Hourly");
                avg_salary = hourly_rate * 80;
                avg_pay = hourly_rate * hours_worked;
                break;

            default:
                printf("Invalid input. Use '?' for instructions.\n");
                continue;
        }

        // Store employee data
        if (count < MAX_EMPLOYEES) {
            Employee e;
            sprintf(e.type, "%s", emp_type);
            e.avg_salary = avg_salary;
            e.avg_pay = avg_pay;
            employees[count++] = e;
        }
    }

    return 0;
}

