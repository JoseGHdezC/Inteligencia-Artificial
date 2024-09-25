# 2D list = a list of lists

drinks: list = ["coffee", "soda", "tea"]
dinner: list = ["pizza", "hamburger", "hotdog"]
dessert: list = ["cake", "ice cream"]

food: list = [drinks, dinner, dessert]

def main() -> None:
    print(food)
    print(food[0])
    print(food[0][0])
    print(food[1][2])
    food[2].clear()
    print(food)

if __name__ == "__main__":
    main()