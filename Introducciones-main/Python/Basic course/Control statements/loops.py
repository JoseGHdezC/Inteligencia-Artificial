#Loop basics

import time #Used for waiting

#while loop
def WhileLoop() -> None:
    name = ""
    while (not(name)): #while (len(name) == 0)
        name = input("Enter your name: ")
    print("Hello " + name)

#for loop
def ForLoop() -> None:
    for i in range(10):
        print(i + 1)
    print("Range for")
    for i in range(50, 101, 2): # for (int i = 50; i < 101; i = i + 2)
        print(i)
    print("Iterating a string")
    for i in "Jose Gregorio":
        print(i)

def CountDown(top_number: int) -> None:
    for seconds in range(top_number, -1, -1):
        print(seconds)
        time.sleep(1)
    print("Ignition!")

def main() -> None:
    mode = int(input("Select mode (0 -> while, 1 -> for, 2 -> countdown): "))
    if (mode == 0):
        WhileLoop()
    elif (mode == 1):
        ForLoop()
    elif (mode == 2):
        CountDown(10)
    else:
        print("Not a valid mode")

if __name__ == "__main__":
    main()