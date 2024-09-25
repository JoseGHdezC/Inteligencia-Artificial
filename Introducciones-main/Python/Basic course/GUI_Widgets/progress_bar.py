from tkinter import *
from tkinter.ttk import *
import time

def Window():
    window = Tk()
    
    def Start():
        GB = 100
        download = 0
        speed = 1
        while(download < GB):
            time.sleep(0.05)
            bar['value'] += (speed / GB) * 100
            download += speed
            percent.set(str(int((download / GB) * 100)) + "%")
            task.set(str(download) + "/" + str(GB) + " GB completed")
            window.update_idletasks()
        
    percent = StringVar()
    task = StringVar()
        
    bar = Progressbar(window, orient = HORIZONTAL, length = 300)
    bar.pack(pady = 10)
    
    percent_label = Label(window, textvariable = percent).pack()
    task_label = Label(window, textvariable = task).pack()
    
    button = Button(window, text = "download", command = Start).pack()
    
    window.mainloop()
    
def main():
    Window()
    
if __name__ == '__main__':
    main()
    