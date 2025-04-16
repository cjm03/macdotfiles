import hashlib
import getpass

password_manager = {}

def create_account():
    username = input("Enter your new username: ")
    password = getpass.getpass("Enter your new password: ")
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    password_manager[username] = hashed_password
    print("Account created successfully!")


def login():
    username = input("Enter your username\n")
    password = getpass.getpass("Enter your password\n")
    hashed_password = hashlib.sha256(password.encode()).hexdigest()
    if username in password_manager.keys() and password_manager[username] == hashed_password:
        print("Login successful!")
    else:
        print("Authentication failed")

def main():
    while True:
        print("1. Create an account\n2. Login\n3. Exit")
        choice = input("Selection: ")
        if choice == "1":
            create_account()
        elif choice == "2":
            login()
        elif choice == "3":
            break
        else:
            print("Invalid option")


if __name__ == "__main__":
    main()