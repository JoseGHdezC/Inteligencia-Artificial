from tkinter import *

# windows = serves as a container to hol these widgets
# widgets = GUI elements

# label = an area widget that holds text and/or an image within a window
def Labels(window, icon):

    label = Label(master=window, 
                  text="Hello World!", 
                  font=('Arial', 40, 'bold'), 
                  foreground="#00ff00", 
                  bg="black",
                  relief=RAISED,
                  bd=10,
                  padx=20,
                  pady=20,
                  image=icon,
                  compound="top")
    label.pack() # Top center by default
    
    #label.place(x=0, y=0)

def CreateWindow():
    window = Tk() # instanciate window
    window.geometry("420x420") # dimensions
    window.title("Jose First GUI") # window title
    
    icon = PhotoImage(file="Images\\lobo.png")
    
    window.iconphoto(True, icon)
    window.config(background="#5cfcff") # "Blue"
    
    Labels(window=window, icon=icon)
                 
    window.mainloop() # place window on computer screen, listen for events

def main():
    CreateWindow()

if __name__ == '__main__':
    main()
    