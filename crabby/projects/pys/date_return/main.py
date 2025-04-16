



def get_month():
    start_month = input("Enter the month of the start date numerically: ")
    return start_month

def get_day():
    start_day = input("Enter the day of the start date numerically: ")
    return start_day

def determine_days_in_month(month):
    extra_day = [1, 3, 5, 7, 8, 10, 12]
    normal_days = [4, 6, 9, 11]
    oddball = 2
    if month in extra_day:
        return "31"
    elif month in normal_days:
        return "30"
    elif month == oddball:
        return "28"
    else:
        print("Invalid month")

def add_days_in_month(get_day, days):
    added_days = get_day + int(30)
    return added_days

def determine_new_date(days_in_month, added_days):
    new_added_days = (int(added_days) - int(days_in_month))
    return new_added_days


def main():
    start_month = get_month()
    start_day = get_day()
    days_in_month = determine_days_in_month(int(start_month))
    added_days = add_days_in_month(int(start_day), int(days_in_month))
    print(added_days)
    new_date = determine_new_date(days_in_month, added_days)
    print(f"New Date: {int(start_month) + 1}/{int(new_date)}")



if __name__ == "__main__":
    main()
