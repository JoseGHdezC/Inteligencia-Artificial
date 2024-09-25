# tuple = collection ordered and unchangeable
# Similar a un std::tuple en C++
student: tuple = ("Jose", 20, "male")

def main() -> None:
    print(student.count("Jose"))
    print(student.index("male"))
    
    # Display content
    for x in student:
        print(x)
    
    # Search in tuple
    if "Jose" in student:
        print("Jose is here")

if __name__ == "__main__":
    main()