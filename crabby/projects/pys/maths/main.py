

def gb_to_mb(num):
    return (num * 1024)

def mb_to_kb(num):
    return (num * 1024)

def kb_to_by(num):
    return (num * 1024)

def by_to_bit(num):
    return (num * 8)

def main():
    num = input("Enter your number as an integer (ex: 500)")
    gb = num
    mb = gb_to_mb(gb)
    kb = mb_to_kb(mb)
    by = kb_to_by(kb)
    bits = by_to_bit(by)
    print(f"Your {num}gb device can hold {bits}bits")


if __name__ == "__main__":
    main()
