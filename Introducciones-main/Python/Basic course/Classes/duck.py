# duck typing = the class is less important than the methods

class Duck:
    
    def Walk(self):
        print("This duck is walking")
        
    def Talk(self):
        print("This duck is qwacking")
        
class Chicken:
    
    def Walk(self):
        print("This chicken is walking")
        
    def Talk(self):
        print("This chicken is clucking")
        
class Person:
    
    def Catch(self, duck):
        duck.Walk()
        duck.Talk()
        print("You caught the critter!")