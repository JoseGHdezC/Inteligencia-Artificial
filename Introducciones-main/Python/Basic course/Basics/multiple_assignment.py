#Basic concept about multiple assignment

import string

#Normal assignment
#name: string = "Jose"
#age = 20
#kind = True

#Multiple assignment
name, age, kind = "Jose", 20, True

#Initialize multiple variable with the same value
#Spongebob = 30
#Patrick = 30
#Squidward = 30
#Sandy = 30

Spongebob = Patrick = Sandy = Squidward = 30

def main() -> None:
    print(name + " " + str(age) + " " + str(kind))
    print(Spongebob)
    print(Patrick)
    print(Squidward)
    print(Sandy)
    
if __name__ == "__main__":
    main()