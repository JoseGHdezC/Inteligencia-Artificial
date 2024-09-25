#Basic user input program

import string

def main() -> None:
    name: string = input("What is your name?: ")
    #Input receives a string type
    age = int(input("How old are you?: "))
    height = float(input("How tall are you?: "))
    age = age + 1
    print("Hello " + name)
    print("You are " + str(age) + " years old.")
    print("You are " + str(height) + " cm tall.")
    
if __name__ == "__main__":
    main()