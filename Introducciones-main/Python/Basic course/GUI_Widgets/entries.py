from tkinter import *

def Entries(window):
    entry = Entry(master=window,
                  font=("Arial",50),
                  fg="#00ff00",
                  bg="black")
                  #show="*")
    
    entry.insert(0, "Insert name")
    entry.pack(side=LEFT)
    
    def Submit():
        # Get value
        username = entry.get()
        print("Hello " + username)
        entry.config(state=DISABLED)
        
    summit_button = Button(master=window,
                           text="submit",
                           command=Submit)
    
    summit_button.pack(side=RIGHT)
    
    def Delete():
        entry.delete(0, END)
        
    delete_button = Button(master=window,
                           text="delete",
                           command=Delete)
    
    delete_button.pack(side=RIGHT)
    
    def BackSpace():
        entry.delete(len(entry.get()) - 1, END)
        
    backspace_button = Button(master=window,
                           text="backspace",
                           command=BackSpace)
    
    backspace_button.pack(side=RIGHT)
    
def CreateWindow():
    window = Tk()
    
    window.title("Entries test")
    window.geometry("1024x1024")
    icon = PhotoImage(file="Images\\lobo.png")
    moon_photo = PhotoImage(file="Images\\luna.png")
    Entries(window=window)
    window.mainloop()

def main():
    CreateWindow()

if __name__ == '__main__':
    main()
    