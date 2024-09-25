#Basic if statements

def IfStatement() -> None:
    age = int(input("How old are you?: "))

    if age == 100:
        print("You are a century old")
    elif age >= 18:
        print("You are an adult") 
    elif age < 0:
        print("You haven't been born yet")
    else:
        print("You are a child")

#Inclusion of logical operators (and, or, not)
def LogicalOperators() -> None:
    temp = int(input("What is the temperature outside?: "))
    if (temp >= 0 and temp <= 30):
        print("It's perfect outside")
        print("Go outside")
    elif (temp < 0 or temp > 30):
        print("The temperature is bad today")
        print("Stay inside")
    elif (not(temp == 15)):
        print("Temperature is not balanced")
    
def main() -> None:
    mode: int = int(input("Which mode do you want?: "))
    if (mode == 0):
        IfStatement()
    elif (mode == 1):
        LogicalOperators() 
    else:
        print("Not a valid mode")
        
if __name__ == "__main__":
    main()