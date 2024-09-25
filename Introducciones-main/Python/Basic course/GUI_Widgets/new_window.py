from tkinter import *

def Window():
    old_window = Tk()
    
    def CreateWindow():
        #new_window = Toplevel() #New window linked to a bottom level window
        new_window = Tk()       #Tk() = new independent window
        old_window.destroy()
    
    Button(old_window, text = "Create new window", command = CreateWindow).pack()
    old_window.mainloop()
    
def main():
    Window()
    
if __name__ == '__main__':
    main()
    