

alphanum = {
    "a": 0,
    "b": 1,
    "c": 2,
    "d": 3,
    "e": 4,
    "f": 5,
    "g": 6,
    "h": 7,
    "i": 8,
    "j": 9,
    "k": 10,
    "l": 11,
    "m": 12,
    "n": 13,
    "o": 14,
    "p": 15,
    "q": 16,
    "r": 17,
    "s": 18,
    "t": 19,
    "u": 20,
    "v": 21,
    "w": 22,
    "x": 23,
    "y": 24,
    "z": 25
}
numalpha = {
    0: "a",
    1: "b",
    2: "c",
    3: "d",
    4: "e",
    5: "f",
    6: "g",
    7: "h",
    8: "i",
    9: "j",
    10: "k",
    11: "l",
    12: "m",
    13: "n",
    14: "o",
    15: "p",
    16: "q",
    17: "r",
    18: "s",
    19: "t",
    20: "u",
    21: "v",
    22: "w",
    23: "x",
    24: "y",
    25: "z"
}

def init_matrix():
    matrix = []
    for i in range(9):
        temp = input(f"Enter element {i} of the matrix")
        matrix.append(int(temp))
    print(f"Matrix:\n{matrix[0]} {matrix[1]} {matrix[2]}\n{matrix[3]} {matrix[4]} {matrix[5]}\n{matrix[6]} {matrix[7]} {matrix[8]}")
    return matrix

def get_message():
    message = input("Enter message to be encrypted: ")
    enumerated = []
    for letter in range(len(message)):
        enumerated.append(alphanum[message[letter]])
    print(f"{message} -> {enumerated}")
    return enumerated







