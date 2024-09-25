# Multiple children
class Organism:
    alive_: bool = True
    
class Animal(Organism):
    def Eat(self):
        return "This animal is eating"
    
class Dog(Animal):
    def Bark(self):
        return "This dog is barking"