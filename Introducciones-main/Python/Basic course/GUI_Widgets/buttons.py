from tkinter import *

count = 0    

def Click():
    global count
    count += 1
    print("You clicked the button")
    print(count)

def ButtonFunction(window, moon_photo):
    
    button = Button(master=window,
                    text="Click me!", 
                    command=Click,
                    font=("Comic Sans", 30),
                    fg="#00ff00",
                    bg="blue",
                    activebackground="black",
                    activeforeground="#00ff00",
                    state=ACTIVE,
                    image=moon_photo,
                    compound="left")
    button.pack()

def Window():
    window = Tk()
    
    window.geometry("1024x1024")
    
    window.title("Buttons test")
    
    icon = PhotoImage(file="Images\\lobo.png")
    window.iconphoto(True, icon)
    window.config(background="#04355a")
    
    moon_photo = PhotoImage(file="Images\\luna.png")
    ButtonFunction(window, moon_photo)
    
    window.mainloop()

def main():
    Window()

if __name__ == '__main__':
    main()