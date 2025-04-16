from datetime import datetime, timedelta

def calculate_dates(date_str):
    input_date = datetime.strptime(date_str, "%m/%d")

    date_30_days_later = input_date + timedelta(days=29)
    date_28_days_later = input_date + timedelta(days=27)

    new_date_30 = date_30_days_later.strftime("%m/%d")
    new_date_28 = date_28_days_later.strftime("%m/%d")

    return new_date_30, new_date_28

def main():
    input_date = input("Enter a date (MM/DD): ")
    date_30, date_28 = calculate_dates(input_date)
    print(f"30 days later: {date_30}")
    print(f"28 days later: {date_28}")


if __name__ == "__main__":
    main()
