class Animal:
    alive_: bool = True
    
    def Eat(self):
        return "This animal is eating"
        
    def Sleep(self):
        return "This animal is sleeping"
        
class Prey:
    def Flee(self):
        return "This animal flees"
    
class Predator:
    def Hunt(self):
        return "This animal is hunting"
    
class Rabbit(Animal, Prey): # Multiple inheritance
    def Eat(self): # The object will try to use the closest method related to it
        return "This rabbit is eating a carrot"
    
    def Run(self):
        return "This rabbit is running"

class Fish(Animal, Prey, Predator): # Multiple inheritance
    def Swim(self):
        return "This fish is swimming"

class Hawk(Animal, Predator): # Multiple inheritance
    def Fly(self):
        return "This hawk is flying"