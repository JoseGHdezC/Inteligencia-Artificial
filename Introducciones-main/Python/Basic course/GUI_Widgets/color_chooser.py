from tkinter import *
from tkinter import colorchooser #submodule



def Window():
    window = Tk()
    
    window.geometry("420x420")
    
    def Click():
        #color = colorchooser.askcolor()
        #print(color)
        #colorhex = color[1]
        window.config(bg = colorchooser.askcolor()[1]) #change background color
        
    button = Button(text = "click me", command = Click)
    button.pack()
    window.mainloop()
    
def main():
    Window()
    
if __name__ == '__main__':
    main()
    