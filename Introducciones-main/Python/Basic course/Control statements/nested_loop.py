#Nested loops by printing a rectangle

import string

def DrawRectangle(character: string, row_size: int, column_size: int) -> None:
    for i in range(0, row_size):
        for j in range(0, column_size):
            print(character, end = "")
        print()
       
def main() -> None:
    row: int = int(input("How many rows do you want?: "))
    column: int = int(input("How many columns do you want?: ")) 
    userline: string = input("Introduce character to print the rectangle with: ")
    character: string = userline[0]
    DrawRectangle(character = character, row_size = row, column_size = column)

if __name__ == "__main__":
    main()