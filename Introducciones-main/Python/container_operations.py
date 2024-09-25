from operator import index
import string
from traceback import print_list
from turtle import position

element_list: list = []
element_set: set = {}

def ProgramPurpose() -> None:
    print("Basic program that uses simple containers such as lists, sets and dictionaries.")
    
def PrintList() -> None:
    print()
    print("list -> ", end = "")
    for x in element_list:
        print(str(x) + " ", end = "")
    print()
    print()
    
def ListOperation() -> None:
    operation: int = 0
    quit: bool = False
    while (not(quit)):
        operation = int(input("---Menu---\n0 -> Exit\n1 -> Insert element\n2 -> Delete element\n"
                              "3 -> Search element\n6 -> Print list\nEnter mode: "))
        if (operation == 0): 
            quit = True
        elif  (operation == 1): # Append element
            element: string = input("Introduce element to introduce in the list: ")
            position: int = int(input("Select position to store the element (-1 -> Append at the end): "))
            if (position == -1 or len(element_list) == 0):
                element_list.append(element)    
            else:
                if ((position >= 0) and (position < len(element_list))):
                    element_list.insert(position, element)
                else:
                    print("Specified position is not valid.")
        elif (operation == 2): # Deletes elements in the list
            element_list.remove()
            element_list.clear() 
            element_list.pop() # Eliminates the element in the last position
        elif (operation == 3): # Search elements
            element_list.count()
            element_list.index()
        elif (operation == 4): # Reverse list
            element_list.reverse() 
        elif (operation == 5): # Sort list
            element_list.sort() 
        elif (operation == 6):
            PrintList()
        else:
            print("Not a valid operation.")
            #element_list.extend()
            
def SetOperation() -> None:
    operation: int = 0
    if (operation == 0):
        element: string = input("Introduce element to introduce in the set: ")

def DictionaryOperation() -> None:
    #operation: int = 0
    #if (operation == 0):
    #    element: string = input("Introduce element to introduce in the dictionary: ")
    print("Not implemented")
        
def main() -> None:
    ProgramPurpose()
    container: int = int(input("Which container do you want to use (0 -> list, 1 -> set, 2 -> dictionary): "))
    if (container == 0):
        ListOperation()
    elif (container == 1):
        SetOperation()
    elif (container == 2):
        DictionaryOperation()
    else:
        print("Not a valid container.")
    
    print("Program ended.")
    
if __name__ == '__main__':
    main()