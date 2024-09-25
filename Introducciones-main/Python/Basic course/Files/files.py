import os
import shutil # copyfile() -> copies content of a file / 
#               copy() -> copyfile() + permission mode + destination can be a directory /
#               copy2() -> copy() + copies metadata

path: str = "C:\\Users\\joseg\\Desktop\\Programas\\Python\\Basic course\\Files\\test.txt"
source: str = "C:\\Users\\joseg\\Desktop\\Programas\\Python\\Basic course\\Files\\copy.txt"
delete_path: str = "C:\\Users\\joseg\\Desktop\\Programas\\Python\\Basic course\\Files\\Prueba\\copy.txt"
folder_path: str = "C:\\Users\\joseg\\Desktop\\Programas\\Python\\Basic course\\Files\\Test"

def FileDetection() -> None:
    if (os.path.exists(path = path)):
        print("That location exists.")
        if (os.path.isfile(path)):
            print("That is a file.")
        if (os.path.isdir(path)):
            print("That is a directory.")
    else:
        print("That location doesn't exist.")
    
def ReadFile() -> None:
    try:
        with open(path) as file:
            print(file.read())
    except FileNotFoundError as e:
        print(e)
        print("That file was not found")

def WriteFile() -> None:
    text: str = "\nLo de antes se borró"
    with open(path, mode = "a") as file:
        file.write(text)
        
def CopyFile() -> None:
    destination: str =  "C:\\Users\\joseg\\Desktop\\Programas\\Python\\Basic course\\Files\\copy.txt"
    shutil.copyfile(path, destination) # src -> dst
    #shutil.copy(path, destination)
    
def MoveFile() -> None:
    destination: str = "C:\\Users\\joseg\\Desktop\\Programas\\Python\\Basic course\\Files\\Prueba\\copy.txt"
    try:
        if (os.path.exists(destination)):
            print("There is already a file there")
        else:
            os.replace(source, destination)
            print(source + " was moved.")
    except FileNotFoundError as e:
        print(e)
        print("File was not found")
        
def DeleteFile() -> None:
    try:
        os.remove(delete_path)     
    except FileNotFoundError as e:
        print(e)
        print("File was not found")
    except PermissionError as e:
        print(e)
        print("You do not have permission to delete that")
    else:
        print(delete_path + " was deleted.")
    
    if (not(os.path.exists(folder_path))):
        os.mkdir(folder_path)
    try:
        os.rmdir(folder_path) 
        #shutil.rmtree(folder_path) # Deletes a directory and all the files inside
    except FileNotFoundError as e:
        print(e)
        print("File was not found")
    except PermissionError as e:
        print(e)
        print("You do not have permission to delete that")
    except OSError as e:
        print(e)
        print("You cannot delete that using that function")
    else:
        print(folder_path + " was deleted.")

def main() -> None:
    print("---------File detection----------")
    FileDetection()
    print("---------Reading file----------")
    ReadFile()
    print("---------Writing file----------")
    WriteFile()
    print("---------Copying file----------")
    CopyFile()
    print("---------Moving file----------")
    MoveFile()
    print("---------Deleting file----------")
    DeleteFile()
        
if __name__ == '__main__':
    main()