#Basic concept of type casting

import string

x: int = 1
y: float = 2.1
z: string = "3"

#To make it permanent it has to be reasigned
a: int = int(y)
b: int = int(z)
c: float = float(x)
d: string = str(x)

def main() -> None:
    print(x)
    print(y)
    print(z*3)
    #Type casting
    print(a)
    print(b * 3)
    print(c)
    print(d*3)
    #Useful case
    print("X is " + str(x))
    print("Y is " + str(y))
    print("Z is " + z)
    
if __name__ == "__main__":
    main()