from tkinter import *


def Window():
    window = Tk()
    
    window.geometry("1024x1024")
    
    fire_image = PhotoImage(file = "Images\\fire.png", height = 50)
    hot_label = Label(image = fire_image)
    hot_label.pack()
    
    scale = Scale(window, 
                  from_ = 100, 
                  to = 0,
                  length=600, 
                  orient=VERTICAL, #VERTICAL or HORIZONTAL
                  font = ("Consolas",20),
                  tickinterval = 10, #adds numeric indicators for values
                  showvalue = 0, # hide current value
                  troughcolor= "#69EAFF",
                  fg= "#FF1C00",
                  bg = "#111111"
                  )
    
    scale.set((scale['from'] - scale['to']) / 2 + scale["to"])
    
    scale.pack()
    
    ice_image = PhotoImage(file = "Images\\ice.png")
    cold_label = Label(image = ice_image)
    cold_label.pack()
    
    def Submit():
        print("The temperature is: " + str(scale.get()) + " degrees ºC")
        
    button = Button(window, text="submit", command=Submit)
    button.pack()
    
    window.mainloop()

def main():
    Window()
    
if __name__ == '__main__':
    main()
    