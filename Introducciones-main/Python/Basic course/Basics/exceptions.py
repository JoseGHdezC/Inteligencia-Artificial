# exception = event detected during execution that interrupt the flow of the program

def Division(numerator: int, denominator: int) -> float:
    return (numerator / denominator)
    
def main() -> None:
    try:
        numerator: int = int(input("Enter the numerator: "))
        denominator: int = int(input("Enter the denominator: "))
    
        result: float = Division(numerator = numerator, denominator = denominator)
    except ZeroDivisionError as e: # Naming the exception received
        print(e)
        print("You can't divide by zero!")
    except ValueError as e:
        print(e)
        print("Enter only numbers, please")
    except Exception as e: # Handles all exceptions
        print(e)
        print("Something went wrong: ")
    else: # If no exceptions occured
        print(result)
    finally: # Always at the end and it will always be executed 
        print("This will always be executed.")
        
if __name__ == '__main__':
    main()