from tkinter import *

#grid = geometry manager

def Window():
    window = Tk()
    
    #first_name_label = Label(window, text = "First name: ").pack() # Locates it in the center
    #first_name_entry = Entry(window).pack()
    
    title_label = Label(window, text = "Enter your info", font = ("Arial", 25)).grid(row = 0, column = 0, columnspan = 2)
    first_name_label = Label(window, text = "First name: ", width = 20, bg = "red").grid(row = 1, column = 0) # cells expand depending on the item containing
    first_name_entry = Entry(window).grid(row = 1, column = 1)
    
    last_name_label = Label(window, text = "Last name: ", bg = "green").grid(row = 2, column = 0)
    last_name_entry = Entry(window).grid(row = 2, column = 1)
    
    email_label = Label(window, text = "Email name: ", bg = "blue", width = 30).grid(row = 3, column = 0)
    email_entry = Entry(window).grid(row = 3, column = 1)
    
    submit_button = Button(window, text = "Submit").grid(row = 4, column = 0, columnspan = 2)
    window.mainloop()
    
def main():
    Window()
    
if __name__ == '__main__':
    main()
    