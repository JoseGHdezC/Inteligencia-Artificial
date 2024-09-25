# List = store multiple items in a single variable
# Similar a un vector en C++, pero permite meter distintos tipos de datos

food: list = ["pizza", "hamburger", "hotdog", "spaguetti", "pudding"]
drinks: list = ["soda", "water", "juice"]

def PrintList() -> None:
    #Printing the content in the list
    for x in food:
        print(str(x) + " ", end = "")
    print()
        
def main() -> None:
    print(food)
    print(food[4])
    food[0] = "sushi"
    PrintList()
    
    #Functions
    food.append("ice cream")
    PrintList()
    food.remove("hotdog")
    PrintList()
    food.pop()
    PrintList()
    food.insert(0, "cake")
    PrintList()
    food.sort()
    PrintList()
    #food.clear()
    #PrintList()
    food.extend(drinks)
    PrintList()
    
if __name__ == "__main__":
    main()