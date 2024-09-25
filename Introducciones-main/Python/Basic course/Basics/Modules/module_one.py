# if the initial module is being run

def Hello():
    print("Hello")

def main():
    print("I have a module!!!")
    Hello()
    
if __name__ == '__main__':
    main()