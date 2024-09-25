# functions

from unittest.util import strclass


name: str = "Gregorio"

def Hello(name: str) -> None:
    print("Hello " + name)
    print("Have a nice day!")
    
def FullName(first_name: str, last_name: str) -> None:
    print("Hello " + first_name + " " + last_name)
    
def HappyBday(name: str, age: int) -> None:
    print("Happy Bday " + name)
    print("You are " + str(age + 1) + " years old!")
    
# Return values
def Multiply(number_1: int, number_2: int) -> int:
    return number_1 * number_2

# Key arguments = preceded by an identifier
def HelloThere(first: str, middle: str, last: str) -> None:
    print("Hello " + first + " " + middle + " " + last)

# Nested function calls
def Nested() -> None:
    number: int = int(input("Enter a whole number: "))
    number = float(number)
    number = abs(number)
    number = round(number)
    print(number)
    print("Now make it nested...")
    print(round(abs(float(input("Enter a whole number: ")))))
    
# Variable scope
def Display() -> None:
    name = "Jose" # It is a local variable
    print(name) # The local version will be used first
    # Local -> Enclosing -> Global -> Built-in

# *args = parameter that will pack all arguments into a tuple
#           useful so that a function can accept a varying amount of arguments
def Add(*stuff: int) -> int:
    sum: int = 0
    stuff = list(stuff) # If we need to change an element we have to type cast it
    stuff[0] = 0
    for x in stuff:
        sum += x
    return sum

# **kwargs = parameter that will pack all arguments into a dictionary
#               varying amount of keyword arguments
def HelloKey(**kwargs: str) -> None:
    print("Hello " + kwargs["first"] + " " + kwargs["last"])
    print(kwargs.items())
    print("Hello ", end = "")
    for key, value in kwargs.items():
        print(value + " ", end = "")
    
def main() -> None:
    Hello("Jose")
    FullName("Lucas", "Gil")
    HappyBday("Lidia", 19)
    print("---------Return values---------")
    print(Multiply(6, 8))
    x: int = Multiply(4, 8)
    print(x)
    print("---------Key values---------")
    HelloThere("Gregorio", "Cruz", "Jose")
    HelloThere(middle = "Gregorio", last = "Cruz", first = "Jose")
    print("---------Nested---------")
    #Nested()
    print("---------Scope---------")
    Display()
    print(name)
    print("---------Args----------")
    print(Add(96, 14))
    print(Add(1, 2, 3, 4, 5, 6, 7))
    print("---------Kwargs--------------")
    print(HelloKey(title = "Mr.", first = "Jose", middle = "Gregorio", last = "Cruz"))
    
if __name__ == '__main__':
    main()