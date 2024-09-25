# str.format = more control when displaying output

def CowMoon() -> None:
    animal: str = "cow"
    item: str = "moon"
    
    print("The " + animal + " jumped over the " + item)
    print("The {} jumped over the {}".format(animal, item))
    print("The {1} jumped over the {1}".format(animal, item)) # positional argument
    print("The {item1} jumped over the {animal1}".format(animal1 = "cow", item1 = "moon")) # key word argument
    text = "The {} jumped over the {}"
    print(text.format(animal, item))
    
def FormatPadding() -> None:
    name: str = "Jose"
    
    print("Hello, my name is {}".format(name))
    print("Hello, my name is {:10}. Nice to meet you".format(name)) # left alignment by default
    print("Hello, my name is {:<10}. Nice to meet you".format(name)) # left alignment
    print("Hello, my name is {:>10}. Nice to meet you".format(name)) # right alignment
    print("Hello, my name is {:^10}. Nice to meet you".format(name)) # center alignment
    
def NumberFormatting() -> None:
    number: float = 3.141592
    other_number: int = 1000
    
    print("The number pi is {:.3f}".format(number)) # it rounds the number
    print("The number is {:,}".format(other_number))
    print("The number is {:_}".format(other_number))
    print("The number is {:b}".format(other_number))
    print("The number is {:o}".format(other_number))
    print("The number is {:X}".format(other_number))
    print("The number is {:e}".format(other_number))
    
def main() -> None:
   CowMoon()
   print("----------------")
   FormatPadding()
   print("----------------")
   NumberFormatting()
    
if __name__ == '__main__':
    main()