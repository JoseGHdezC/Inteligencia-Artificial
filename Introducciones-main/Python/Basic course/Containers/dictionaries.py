# dictionary = collection of key:value. Usehashing

capitals: dict[str, str] = {"USA" : "Washington DC",
                            "India" : "New Dehli",
                            "China" : "Beijing",
                            "Russia" : "Moscow"}

def PrintDictionary() -> None:
    for key, value in capitals.items():
        print(key, value)
    
def Dictionary() -> None:
    print(capitals["Russia"])
    #print(capitals["Germany"])
    print(capitals.get("Germany")) # Safer way to check the elements
    print(capitals.keys()) # Prints stored keys
    print(capitals.values()) # Prints stored values
    print(capitals.items()) # Prints all
    PrintDictionary() # Another way to print
    print("Adding new keys")
    capitals.update({"Germany" : "Berlin"})
    print(capitals.items())
    capitals.update({"USA" : "Las Vegas"})
    print(capitals.items())
    # Remove elements
    capitals.pop("China")
    print(capitals.items())
    capitals.clear()
    print(capitals.items())
    
def main() -> None:
    Dictionary()
    
if __name__ == '__main__':
    main()
    