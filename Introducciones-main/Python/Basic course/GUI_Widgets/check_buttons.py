from tkinter import *
           
def CheckButton(window, moon_picture):
    x = IntVar() # BoolVar(), StrVar()
    def Display():
        if (x.get() == 1):
            print("You agree!")
        else:
            print("You don't agree :(")
            
    check_button = Checkbutton(master=window,
                               text="I agree to something",
                               variable=x, # It has to be the correct data type
                               onvalue=1, # It could be True
                               offvalue=0,
                               command=Display,
                               font=("Ariel", 20),
                               fg="#00ff00",
                               bg="black",
                               activebackground="black",
                               activeforeground="#00ff00",
                               padx=25,
                               pady=10,
                               image=moon_picture,
                               compound="left")
    
    check_button.pack()
    
def CreateWindow():
    window = Tk()
    
    window.title("Check button test")
    window.config(background="yellow")
    window.geometry("1024x1024")
    
    icon = PhotoImage(file="Images\\lobo.png")
    
    window.iconphoto(True, icon)
    moon_picture = PhotoImage(file="Images\\luna.png", height=50, width=50)
    CheckButton(window=window, moon_picture=moon_picture)
               
    window.mainloop()
    
def main():
    CreateWindow()

if __name__ == '__main__':
    main()
    