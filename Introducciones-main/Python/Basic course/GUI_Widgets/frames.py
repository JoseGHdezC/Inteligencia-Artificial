#frame = rectangular container
from tkinter import *

def Window():
    window = Tk()
    
    frame = Frame(window, bg = "pink", bd = 5, relief = RAISED)
    #frame.pack(side = BOTTOM)
    frame.place(x = 100, y = 100)
    
    Button(frame, text = "W", font = ("Consolas", 25), width = 3).pack(side = TOP)
    Button(frame, text = "A", font = ("Consolas", 25), width = 3).pack(side = LEFT)
    Button(frame, text = "S", font = ("Consolas", 25), width = 3).pack(side = LEFT)
    Button(frame, text = "D", font = ("Consolas", 25), width = 3).pack(side = LEFT)
    
    window.mainloop()

def main():
    Window()
    
if __name__ == '__main__':
    main()
    