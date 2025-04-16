# The Bloomington Skating Company

Five employees paid by monthly sales commission.
An employee earns 12.5% of their total sales for the month.
Each employee gets a bonus based on total company profit each month.
The company has a profit of 45% of total sales.
Each employee earns 10% of monthly profit + an additional 5% of monthly profit per 10 years of tenure

### Calculation of Withholdings

Calculate the Federal and State tax withholdings and Social Security contributions.
Flat rate:
    - 15% Federal withholding
    - 5% State withholding
    - 7.5% Social Security contribution
Withholdings are based on the employee's TOTAL pay.
Sales commission + total bonus = pay * withholding rate = total withholdings

### Calculation of Net Profit

Net profit is the profit minus the total bonuses paid to the employees.



# PSEUDOCODE

### high level

1. Prompt user input for month and year for report (MM) (YYYY)
2. Prompt user input for employee sales and employee tenure (x5)
3. Calculate monthly sales from sum of each employee
4. Calculate monthly profit from ^ multiplied by 0.45
5. Calculate each employee's commission (sales * 0.125)
6. Calculate each employee's bonus ((monthly profit * .1) + (monthly profit * tenure(.05)))
7. Calculate each employee's federal withholding (gross * 0.15)
8. Calculate each employee's state withholding (gross * 0.05)
9. Calculate each employee's social security contributions (gross * 0.075)
10. Calculate each employee's net pay (gross - step7 - step8 - step9)
11. Calculate the total of each employee in steps 5-10
12. Calculate company net profit (step 3 - the total of all employee bonuses)
13. Format and print all calculations in report statement



