# list comprehension = way to create a new list with less syntax
#                       can mimic certain functions, easier to read
#                       list = [expresion (if/else) for item in variable (if condition)]
#                       list = [expresion for item in variable (if condition)]
#                       list = [expresion for item in variable]

def BasicWay():
    squares = []
    for i in range(1, 11): # 1-10
        squares.append(i * i)
    print(squares)
    
def ComprehensionWay():
    squares = [i * i for i in range(1, 11)]
    print(squares)

def FilteringList():
    students = [100, 90, 80, 70, 60, 50, 40, 30, 0]
    
    passed_students = list(filter(lambda x:x >= 60, students))
    print(passed_students)
    print("-----With comprehensions-----")
    #passed_students = [i for i in students if i >= 60]
    passed_students = [i if i >= 60 else "Failed" for i in students]
    print(passed_students)

# dictionary comprehension = create dictionaries using an expression
#                               can replace for loops and certain lambda functions
# dictionary = {key: expression for (key, value) in iterable}
# dictionary = {key: expression for (key, value) in iterable if conditional}
# dictionary = {key: (if/else) for (key, value) in iterable}
# dictionary = {key: function(value) for (key, value) in iterable}

def CheckTemp(value):
    if (value >= 70):
        return "Hot"
    elif (69 >= value >= 40):
        return "Warm"
    else:
        return "Cold"
    
def DictComprehension():
    cities_in_F = {"New York": 32, "Boston": 75, "Los Angeles": 100, "Chicago": 50}
    cities_in_C = {key: round((value - 32) * (5/9)) for key, value in cities_in_F.items()}
    
    print(cities_in_F)
    print(cities_in_C)
    print("-----Weather-----")
    weather = {"New York": "snowing", "Boston": "sunny", "Los Angeles": "sunny", "Chicago": "cloudy"}
    sunny_weather = {key: value for (key, value) in weather.items() if (value == "sunny")}
    print(sunny_weather)
    print("-----Temperature feel-----")
    desc_cities = {key: ("Warm" if value >= 40 else "Cold") for (key, value) in cities_in_F.items()}
    print(desc_cities)
    print("-----Temperature function-----")
    func_cities = {key: CheckTemp(value) for (key, value) in cities_in_F.items()}
    print(func_cities)
    
    
def main():
    #BasicWay()
    #ComprehensionWay()
    #FilteringList()
    DictComprehension()
    
if __name__ == '__main__':
    main()
    