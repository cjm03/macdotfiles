import random
import argparse
import string

def generate_password(alphabet, length: int = 10):
    password = ''.join(random.choice(alphabet) for i in range(length))
    return password

def main():
    parser = argparse.ArgumentParser()

    parser.add_argument("--passlen", type=int, help="pass desired password length")

    parser.add_argument("-l", "--letter", action="store_true", help="use letters")
    parser.add_argument("-d", "--digit", action="store_true", help="use digits")
    parser.add_argument("-p", "--punctuation", action="store_true", help="use punctuation")

    args = parser.parse_args()

    alphabet = string.ascii_letters + string.digits + string.punctuation
    if args.letter or args.digit or args.punctuation:
        alphabet = ''
        if args.letter:
            alphabet += string.ascii_letters
        if args.digit:
            alphabet += string.digits
        if args.punctuation:
            alphabet += string.punctuation

    if args.passlen:
        length = args.passlen
    else:
        length = 10
    
    password = generate_password(alphabet, length)
    print(password)

if __name__ == "__main__":
    main()








