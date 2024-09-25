#Useful string methods
import string

name: string = "jose gregorio"
upper_name: string = name.upper()
numbers: string = "1234"

def main() -> None:
    print(len(name))
    print(name.find("g"))
    print(name.capitalize())
    print(name.upper())
    print(upper_name.lower())
    print(name.isdigit())
    print(numbers.isdigit())
    print(name.isalpha()) #False if there are any characters that are not letters
    print(name.count("o"))
    print(upper_name.replace("O", "A"))
    print(name*3) #Prints x times the string
    
if __name__ == "__main__":
    main()