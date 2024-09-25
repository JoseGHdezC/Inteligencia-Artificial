#Comments
#Try to put the variable type explicitly
#Program that contains the bases of basic data types
import string

#String data type
first_name: string = "Jose"
last_name: string = "Cruz"
full_name: string = first_name + " " + last_name

#Int data type for arithmetic purpose
age: int = 20
age = age + 1
#++age NO FUNCIONA
#age += 1

tuple_curiosity: float = 1,65,25,"gol" #Esto es raro
#Float data type for decimal precision
height: float = 165.4

#Bool data type 
human: bool = True
alien: bool = False

def main() -> None:
    print("---String related stuff---")
    print(first_name)
    print("Hello " + first_name)
    print("Hello " + full_name)
    print(type(first_name)) #Check variable data type 
    print("--------------")
    print()
    print("---Int related stuff---")
    print(age)
    print(type(age))
    print("Your age is: " + str(age)) #Type casting
    print("--------------")
    print()
    print("---Float related stuff---")
    print(height)
    print(type(height))
    print("Your height is: " + str(height) + "cm") #Type casting
    print("--------------")
    print()
    print("---Bool related stuff---")
    print(human)
    print(type(human))
    print("Are you a human?: " + str(human)) #Type casting
    print("--------------")
    
if __name__ == "__main__":
    main()