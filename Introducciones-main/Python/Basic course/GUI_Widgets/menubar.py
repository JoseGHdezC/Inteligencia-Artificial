from tkinter import *

def OpenFile():
    print("File has been opened")
    
def SaveFile():
    print("File has been saved")
    
def CopyFile():
    print("File has been copied")
    
def CutFile():
    print("File has been cut")
    
def PasteFile():
    print("File has been pasted")
    
def Window():
    window = Tk()
    
    window.geometry("1024x1024")
    
    cut_image = PhotoImage(file = "Images\\cut.png", width = 100, height = 100)
    copy_image = PhotoImage(file = "Images\\copy.png", width = 100, height = 100)
    paste_image = PhotoImage(file = "Images\\paste.png", width = 100, height = 100)
    
    menubar = Menu(window)
    window.config(menu = menubar)
    
    file_menu = Menu(menubar, tearoff = 0, font = ("MV Boli", 15))
    menubar.add_cascade(label = "File",
                        menu = file_menu)
    
    file_menu.add_command(label = "Open", command = OpenFile)
    file_menu.add_command(label = "Save", command = SaveFile)
    file_menu.add_separator()
    file_menu.add_command(label = "Help")
    file_menu.add_command(label = "Exit", command = quit)
    
    edit_menu = Menu(menubar, tearoff = 0, font = ("MV Boli", 15))
    menubar.add_cascade(label = "Edit", menu = edit_menu)
    
    edit_menu.add_command(label = "Copy", command = CopyFile, image = copy_image, compound = "left")
    edit_menu.add_command(label = "Cut", command = CutFile, image = cut_image, compound = "left")
    edit_menu.add_command(label = "Paste", command = PasteFile, image = paste_image, compound = "left")
    
    window.mainloop()
def main():
    Window()
    
if __name__ == '__main__':
    main()
    