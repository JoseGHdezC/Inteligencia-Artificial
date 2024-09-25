from tkinter import *
from tkinter import filedialog

#---------Opening file--------------
def OpenFile():
    '''Opening a file with a window'''
    filepath = filedialog.askopenfilename(initialdir = "C:\\Users\\Jose\\Desktop\\Introducciones\\Python", 
                                          title = "Open file",
                                          filetypes = (("text files", "*.txt"), ("all files", "*.*")))    
    #print(filepath)
    file = open(filepath, "r")
    if file is None:
        return
    print(file.read())
    file.close()
    
    #try:
    #    file = open(filepath, "r")
    #    print(file.read())
    #    file.close()
    #except FileNotFoundError:
    #    print("File was not found")
#-----------------------------------
    

    
def Window():
    window = Tk()
    
    window.geometry("1024x1024")   
        
    button = Button(window, text = "Open", command = OpenFile)
    button.pack()
    
    def SaveFile():
        file = filedialog.asksaveasfile(initialdir = "C:\\Users\\Jose\\Desktop\\Introducciones\\Python\\Basic course\\GUI_Widgets",
                                        defaultextension = ".txt",
                                        filetypes = [
                                            ("Text file", ".txt"), 
                                            ("HTML file", ".html"),
                                            ("All files", ".*")
                                        ])
        if file is None:
            return
        filetext = str(text.get("1.0", END))
        #filetext = input("Enter some text: ")
        file.write(filetext)
        file.close()
        
    save_button = Button(window, text = "Save", command = SaveFile)
    save_button.pack()
    
    text = Text(window)
    text.pack()
    
    
    
    window.mainloop()
    
def main():
    Window()
    
if __name__ == '__main__':
    main()
    