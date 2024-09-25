# super() = function to give access to the methods of a parent class
#           Returns temporary object of a parent class when used

class Rectangle:
    
    def __init__(self, length, width) -> None:
        self.length = length
        self.width = width

class Square(Rectangle):
    
    def __init__(self, length, width) -> None:
        super().__init__(length=length, width=width) #Access to the parent class
        
    def Area(self):
        return self.length * self.width

class Cube(Rectangle):
    
    def __init__(self, length, width, height) -> None:
        super().__init__(length = length, width=width)
        self.height = height
        
    def Volume(self):
        return self.length * self.width * self.height