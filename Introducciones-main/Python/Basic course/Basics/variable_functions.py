def HelloThere():
    print("Hello")
    
def FunctionsAsVariables():
    print(HelloThere)
    hi = HelloThere
    print("Hi {}".format(hi))
    hi() # It works as an alias for a function
    
    say = print
    say("Whoa! I can't believe this worked!")
    
#------------------------
def Loud(text):
    return text.upper()

def Quiet(text: str):
    return text.lower()

def Hello(func):
    text = func("Hello")
    print(text)
    
def Divisor(x):
    def Dividend(y):
        return y / x
    return Dividend

# Higher Order Functions = a function that:
#                           1. accepts a funtion as an argument
#                               or
#                           2. returns a function
def HigherOrderFunction():
    Hello(Loud)
    Hello(Quiet)
    
    divide = Divisor(2) # x will remain 2 until it is changed
    print(divide(10)) # It is accessing to the inner function
    
#-----------------
def Double(x):
    return x * 2

double_lambda = lambda x:x * 2
multiply = lambda x, y: x * y
add = lambda x, y, z: x + y + z
full_name = lambda first_name, last_name: first_name + " " + last_name
age_check = lambda age:True if age >= 18 else False

# lambda function = function written in 1 line
# accepts any number of parameters, but only has one expression
# labda parameters:expression
def LambdaFunctions():
    print(Double(5))
    print(double_lambda(5))
    print(multiply(5, 6))
    print(add(5, 6, 7))
    print(full_name("Jose", "Cruz"))
    print(age_check(18))
    
def main():
    #FunctionsAsVariables()
    #HigherOrderFunction()
    LambdaFunctions()
   
if __name__ == '__main__':
    main()
    