while True:
    height_str = input("Height: ")
    if height_str.isdigit():
        height = int(height_str)
        if 1 <= height <= 8:
            break

for i in range(height):
    print(" " * (height - 1 - i), end="")
    print("#" * (i + 1), end="")
    print(" " * 2, end="")
    print("#" * (i + 1), end="")
    print()
