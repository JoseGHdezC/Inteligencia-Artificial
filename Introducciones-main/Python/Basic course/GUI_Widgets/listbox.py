from tkinter import *


def Window():
    window = Tk()
    window.geometry("1024x1024")
    
    listbox = Listbox(window,
                      bg = "#f7ffdd",
                      font = ("Constantia", 35),
                      width = 12,
                      selectmode=MULTIPLE
                      )
    
    listbox.pack()
           
    listbox.insert(1, "pizza")
    listbox.insert(2, "pasta")
    listbox.insert(3, "garlic bread")
    listbox.insert(4, "soup")
    listbox.insert(5, "salad")
    
    listbox.config(height = listbox.size())
    
    entrybox = Entry(window)
    entrybox.pack()
    
    def Add():
        listbox.insert(listbox.size(), entrybox.get())
        listbox.config(height = listbox.size())

    add_button = Button(window, 
                           text = "Add", 
                           command = Add)
    add_button.pack()
    
    def Delete():
        #If only deleting one
        #listbox.delete(listbox.curselection())
        
        for index in reversed(listbox.curselection()):
            listbox.delete(index)
            
        listbox.config(height = listbox.size())
        
    delete_button = Button(window, 
                           text = "Delete", 
                           command = Delete)
    delete_button.pack()
    
    def Submit():
        
        food = []
        
        for index in listbox.curselection():
            food.insert(index, listbox.get(index))
                       
        print("You have ordered: ", end = "")
        for index in food:
            print(index + ", ", end = "")
            
        print()
        
        #If item selection is set to one item at a time
        #print(listbox.get(listbox.curselection()))
    
    submit_button = Button(window, 
                           text = "Submit", 
                           command = Submit)
    submit_button.pack()
    
    window.mainloop()
    
def main():
    Window()
    
if __name__ == '__main__':
    main()
    