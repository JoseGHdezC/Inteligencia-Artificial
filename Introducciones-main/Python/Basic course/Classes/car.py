# abstract class = idea, cannot create an object of the class
# It can also serve to prevent a vehicle to be created as it is not fully implemented

# abstract class

from abc import ABC, abstractmethod

class Vehicle(ABC): # It is now an abstract class
    
    @abstractmethod
    def Go(self): # It is now an abstract method
        pass
    
    @abstractmethod
    def Stop(self):
        pass

class Car(Vehicle):
    
    wheels: int = 4 # class variables (for all instances of the class)
    color = None
    
    # Constructor
    def __init__(self, make, model, year, color):
        self.make = make    # instance variable
        self.model = model  # instance variable
        self.year = year    # instance variable
        self.color = color  # instance variable

    def Drive(self):
        print("This " + self.model + " is driving")
        return self
        
    def Stop(self):
        print("This " + self.model + " is stopped")
        
    def TurnOn(self):
        print("You start the engine")
        return self
        
    def Brake(self):
        print("You step on the brakes")
        return self
        
    def TurnOff(self):
        print("You turn off the engine")
        return self
    
    def Go(self):
        print("You drive the car")
        
class Motorcycle(Vehicle):
    
    color = None
    
    def Go(self):
        print("You ride the motorcycle")
        
    def Stop(self):
        print("This motorcycle is stopped")
        
def ChangeColor(vehicle, color: str):
    
    vehicle.color = color