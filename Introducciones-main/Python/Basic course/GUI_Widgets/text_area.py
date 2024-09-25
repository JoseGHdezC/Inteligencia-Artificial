#text widget
from tkinter import *

def Window():
    window = Tk()
    
    text = Text(window, 
                bg = "light yellow", 
                font = ("Ink Free", 25), 
                height = 8, 
                width = 20, 
                padx = 20,
                pady = 20,
                fg = "purple")
    text.pack()
    
    def Submit():
        input_text = text.get("1.0", END)
        print(input_text)
        
    button = Button(window, text = "Submit", command = Submit)
    button.pack()
    
    window.mainloop()
    
def main():
    Window()
    
if __name__ == '__main__':
    main()
    