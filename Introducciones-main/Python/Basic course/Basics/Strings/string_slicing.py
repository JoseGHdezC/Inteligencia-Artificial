#Basics of slicing string
# indexing or slice() [start:stop:step]

slice = slice(7, -4) #start, stop, step

def main() -> None:
    name = "Jose Gregorio"
    first_letter = name[0]
    first_name = name[0:4] #The stop index is exclusive
    last_name = name[5:14] # [5:]
    funky_name = name[0:14:3] #[::3] -> Same effect
    reversed_name = name[::-1]
    
    print(first_letter)
    print(first_name)
    print(last_name)
    print(funky_name)
    print(reversed_name)
    
    #Slice function
    website1 = "http://google.com"
    website2 = "http://wikipedia.com"
    
    print(website1[slice])
    print(website2[slice])
    
if __name__ == "__main__":
    main()