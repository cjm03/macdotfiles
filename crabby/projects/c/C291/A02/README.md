Specifications:
    Administrators 'A'
        - Paid their salary in equal portions 1x/month. 
        **INPUT SALARY AS ANNUAL SALARY**
    Staff 'S'
        - Paid as administrators, but can also work up to 10 hours paid overtime each month for 150% of their normal hourly salary for each hour of overtime worked. 
        **INPUT ANNUAL SALARY AND NUMBER OF OVERTIME HOURS WORKED FOR THE MONTH**
    Hourly 'H'
        - Paid by the hour, up to 20 hours/week, where they receive 100% of their paycheck, but can also work up to 20hrs of overtime per month and will be paid 125% of their wage.
        **INPUT HOURLY PAY RATE AND TOTAL HOURS WORKED PER MONTH**
    Adjunct Faculty 'J'
        - Paid $8500 over 5 months for each 3 credit hours they teach, and are paid for a maximum of 9 ($25500) credit hours
        **INPUT NUMBER OF CREDITS TEACHING EACH MONTH**
    Regular Faculty 'R'
        - Paid salary over 10 months. Can take an overload and are paid overtime. Overload rate: same as adjunct ($8500/sem per 3 credit), overload pay is adjusted proportionally, 1 credit = $2833.33
        **INPUT ANNUAL SALARY AND NUMBER OF OVERLOAD CREDITS PER SEMESTER**
    Teaching Assistants 'T'
        - Paid $2500 per course and work 10hrs/week. May work 2 hours overtime per week at normal pay rate. Course is 5 months long. TA ONLY RECEIVES THE FULL $2500 IF THEY WORK THE 10hrs/week AS EXPECTED.
        **INPUT NUMBER OF COURSES THE TA ASSISTS WITH AND TOTAL HOURS WORKED THIS MONTH**
    ** You can also assume:
     - 40 hours/week
     - 4 weeks per month
     - All data the clerk enters is for a month during a semester
     - Program should allow clerk to enter monthly payroll info for each employee
     - Some workers have maximum time they can be paid for, and any time worked above that should print a warning to the clerk then be discarded from any further calculations

Need to create program that takes in a payroll code to specify type of employee, and then takes in a value representing that employee's salary. The value will be added to the payroll code's running total, and the quantity of
employees sharing that same payroll code will be incremented accordingly. 

Pseudocode:

instruction set for user
    detail what information must be supplied to each case for valid interpretation of data

variables: salary, hours, overtime hours, credits, overload credits, courses, hourly rate
variables per case: average salary and average pay
    some cases will need overtime hours, overtime rate

counter for each case

Loop to keep the switch statement alive
    each switch statement should use scanf to take in appropriate data for each case
    each switch statement will have to perform the correct calculations for each case
    Administrators: salary / 12  - for both avg salary and avg pay
    Staff: avg salary = salary / 12
        avg pay = avg salary + (overtime hours * (overtime rate * 1.5))
    Hourly: avg salary = hourly rate * 80
        avg pay (dependent upon overtime or lack of) = (hourly rate * hours worked) + (overtime rate * overtime hours)
    Adjunct: avg salary = (credits * 2833.33) / 5  - for both avg salary and avg pay
    Regular: avg salary = salary / 10
        avg pay = avg salary + (overload(2833.33) * 2) / 10
    TA: avg salary if under required hours = (hours / (40 * # of courses)) * (# of courses * 500)  - avg pay would be the same
        avg salary if at or above hours = (# of courses * 500)
            avg pay = avg salary + (overtime hrs * (500 / 40))

Print and format all avg salaries and avg pays when user quits
