from tkinter import *
from tkinter import messagebox #Imports messagebox library

def Window():
    window = Tk()
    
    window.geometry("1024x1024")
    
    def Click():
        #messagebox.showinfo(title = "This is an info message box", message = "You are a person")
        #messagebox.showwarning(title = "WARNING", message = "You have a virus")
        #messagebox.showerror(title = "Error", message = "Something went wrong")
        
        #if messagebox.askokcancel(title = "ask ok cancel", message = "Do you want to do something"):
        #    print("You did a thing!")
        #else:
        #    print("You cancel a thing")
        
        #if messagebox.askretrycancel(title = "ask retry cancel", message = "Do you want to retry a thing?"):
        #    print("You retried a thing!")
        #else:
        #    print("You canceled a thing")
        
        #if messagebox.askyesno(title = "ask yes no", message = "Do you like cake?"):
        #    print("You like cake! :)")
        #else:
        #    print("Why not? :(")
        
        #answer = messagebox.askquestion(title = "ask question", message = "Do you like pie?")
        #
        #if (answer == "yes"):
        #    print("Yeesss")
        #else:
        #    print("Noooo")
        
        answer = messagebox.askyesnocancel(title = "yes no cancel", message = "Do you like to code?", icon = "warning") #"info" | "error"
        
        if (answer == True):
            print("You like to code :)")
        elif (answer == False):
            print("Why not?")
        else:
            print("You have dodged the question")
        
        
    button = Button(window, command = Click, text = "Click me")
    button.pack()
    
    window.mainloop()
    
def main():
    Window()
    
if __name__ == '__main__':
    main()
    