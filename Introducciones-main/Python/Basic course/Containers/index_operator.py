# index operator [] = gives access to a sequence's element (str, list, tuple)

name: str = "jose Gregorio!"

if (name[0].islower()):
    name = name.capitalize()
    
print(name)

def main() -> None:
    first_name = name[:4].upper()
    print(first_name)
    last_name = name[5:].upper()
    print(last_name)
    last_character = name[-2]
    print(last_character)
    
    
if __name__ == '__main__':
    main()
    