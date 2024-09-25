# classes = type specified by the user

from car import Car, Vehicle, Motorcycle, ChangeColor
from animals import Rabbit, Hawk, Fish
from organisms import Dog
from rectangle import Square, Cube
from duck import Duck, Chicken, Person

car_1: Car = Car("Chevy", "Corvette", 2021, "blue")
car_2: Car = Car("Ford", "Mustang", 2022, "red")
    
def ClassBasics():
    print(car_1)
    print(car_1.make)
    print(car_1.model)
    print(car_1.year)
    print(car_1.color)
    
    car_1.Drive()
    car_1.Stop()
    car_2.Drive()
    car_2.Stop()
    
def ClassVariables():
    #car_1.wheels = 2
    Car.wheels = 2
    print(car_1.wheels)
    print(car_2.wheels)
    print("Default class has {} wheels".format(Car.wheels))
    
def Inheritance():
    rabbit: Rabbit = Rabbit()
    fish: Fish = Fish()
    hawk: Hawk = Hawk()
    
    print(rabbit.alive_)
    print(fish.Eat())
    print(hawk.Sleep())
    
    print(rabbit.Run())
    print(fish.Swim())
    print(hawk.Fly())
    
def Multilevel():
    dog: Dog = Dog()
    print(dog.alive_)
    print(dog.Eat())
    print(dog.Bark())
    
def MultipleInheritance():
    rabbit = Rabbit()
    fish = Fish()
    hawk = Hawk()
    
    print(rabbit.Flee())
    print(fish.Flee())
    print(fish.Hunt())
    print(hawk.Hunt())

def MethodOverride():
    rabbit: Rabbit = Rabbit()

    print(rabbit.Eat())
    
def MethodChaining():
    #car_1.TurnOn()
    #car_1.Drive()
    car_1.TurnOn().Drive()
    car_1.Brake().TurnOff()
    car_1.TurnOn()\
        .Drive()\
        .Brake()\
        .TurnOff()
    
def SuperMethod():
    square: Square = Square(3, 3)
    cube: Cube = Cube(3, 3, 3)
    
    print(square.Area())
    print(cube.Volume())
    
def AbstractClases():
    #vehicle: Vehicle = Vehicle()
    car: Car = Car("Ford", "Mustang", 2022, "red")
    motorcycle: Motorcycle = Motorcycle()
    
    #vehicle.Go()
    car.Go()
    motorcycle.Go()
    car.Stop()
    motorcycle.Stop()
    
def ObjectsAsArguments():
    motorcycle_1 = Motorcycle()
    motorcycle_2 = Motorcycle()
    motorcycle_3 = Motorcycle()
    
    car: Car = Car("Ford", "Mustang", 2022, "red")
    
    ChangeColor(vehicle=motorcycle_1, color="blue")
    ChangeColor(vehicle=motorcycle_2, color="red")
    ChangeColor(vehicle=motorcycle_3, color="white")
    ChangeColor(vehicle=car, color="black")
    
    print(motorcycle_1.color)
    print(motorcycle_2.color)
    print(motorcycle_3.color)
    print(car.color)
    
def DuckTyping():
    duck = Duck()
    chicken = Chicken()
    person = Person()
    
    person.Catch(chicken) # It will work as both objects have the same methods

def main():
    ClassBasics()
    ClassVariables()
    Inheritance()
    Multilevel()
    MultipleInheritance()
    MethodOverride()
    MethodChaining()
    SuperMethod()
    AbstractClases()
    ObjectsAsArguments()
    DuckTyping()

if __name__ == '__main__':
    main()
    