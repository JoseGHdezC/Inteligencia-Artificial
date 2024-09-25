# Loop control statements
# break = terminate the loop entirely
# continue = skips to the next iteration
# pass = does nothing, acts as a placeholder

def BreakControl() -> None:
    while (True):
        name = input("Enter your name: ")
        if (name != ""):
            break

def ContinueControl() -> None:
    phone_number = "123-456-7890"
    for i in phone_number:
        if (i == "-"):
            continue
        print(i + " ", end = "")
        
def PassControl() -> None:
    for i in range(1, 21):
        if (i == 13):
            pass
        else:
            print(str(i) + " ", end = "")
            
def main() -> None:
    mode: int = int(input("Enter mode (0 -> Break, 1 -> Continue, 2 -> Pass): "))
    if (mode == 0):
        BreakControl()
    elif (mode == 1):
        ContinueControl()
    elif (mode == 2):
        PassControl()
    else:
        print("Mode not valid")
    
if __name__ == "__main__":
    main()