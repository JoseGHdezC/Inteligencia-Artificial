# walrus operator :=

# Python 3.8
# assigns expression
# assigns values to variables as part of a larger expression

def FoodNoWalrus():
    foods = list()
    while True:
        food = input("What food do you like?: ")
        if food == "quit":
            break
        foods.append(food)
    
def FoodWalrus():
    foods = list()
    while food := input("What food do you like?: ") != "quit":
        foods.append(food)
    
def main():
    #happy = True
    #print(happy)
    #print(happy := True)
    FoodNoWalrus()
    FoodWalrus()

if __name__ == '__main__':
    main()
    