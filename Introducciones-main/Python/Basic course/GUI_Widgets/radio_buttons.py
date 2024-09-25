#radio button = similar to a checkbox, but you can only select one from group 
from tkinter import *

food = ["pizza", "hamburguer", "hotdog"]

def Window():
    window = Tk()

    window.geometry("1024x912")

    pizza_image = PhotoImage(file="Images\\pizza.png", height=200)
    burger_image = PhotoImage(file="Images\\burger.png", height=200)
    hotdog_image = PhotoImage(file="Images\\hotdog.png", height=200)
    
    food_images = [pizza_image, burger_image, hotdog_image]
    
    x = IntVar()
    
    def Order():
        if(x.get() == 0):
            print("You order a pizza")
        elif (x.get() == 1):
            print("You order a hamburger")
        elif (x.get() == 2):
            print("You order a hotdog")
        else:
            print("Huh -.-")
    
    for index in range(len(food)):
        radiobutton = Radiobutton(window, 
                                  text=food[index], #adds text to radio buttons
                                  variable=x, #groups radiobuttons together if they share the same variable
                                  value=index,
                                  padx=25,
                                  pady=15,
                                  font=("Impact",50),
                                  image=food_images[index],
                                  compound='left', #adds image and text
                                  indicatoron=0, #eliminates circle indicators,
                                  width= 600,
                                  command=Order #set command of radio button to function
                                  )
        radiobutton.pack(anchor=W)
    
    window.mainloop()
    
def main():
    Window()

if __name__ == '__main__':
    main()  