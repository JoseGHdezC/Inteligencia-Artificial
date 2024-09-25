# set = collection unordered, unindexed. No duplicated values
# Similar a un std::unordered_set en C++
utensils: set = {"fork", "spoon", "knife", "knife"}
dishes: set = {"bowl", "plate", "cup", "knife"}

def PrintSet() -> None:
    for x in utensils:
        print(x + " ", end = "")
    print()


def main() -> None:
    PrintSet()
    utensils.add("napkin")
    PrintSet()
    utensils.remove("fork")
    PrintSet()
    #utensils.clear()
    #PrintSet()
    #utensils.update(dishes)
    #PrintSet()
    #print(dishes)
    #dishes.update(utensils)
    #print(dishes)
    #dinner_table = utensils.union(dishes)
    #print(dinner_table)
    print(utensils.difference(dishes))
    print(utensils.intersection(dishes))

if __name__ == "__main__":
    main()