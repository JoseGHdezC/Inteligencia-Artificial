# thread = flow of execution. Each one with a separate order of instructions.
#           GIL = (global interpreter lock)
#           

# cpu bound = waits for internal events -> multiprocessing
# io bound = waits for external events -> multithreading
from multiprocessing import Process, cpu_count
import threading # DO NOT CALL YOUR FILE AS A MODULE
import time

def CountThreads():
    print(threading.active_count()) 
    print(threading.enumerate())
    
def EatBreakfast():
    time.sleep(3)
    print("You eat breakfast")
    
def DrinkCoffee():
    time.sleep(4)
    print("You drink coffee")
    
def Study():
    time.sleep(5)
    print("You finished studying")

def Threading():
    x = threading.Thread(target=EatBreakfast) # args=
    x.start()
    y = threading.Thread(target=DrinkCoffee) # args=
    y.start()
    z = threading.Thread(target=Study) # args=
    z.start()
    
def JoiningThreads():
    x = threading.Thread(target=EatBreakfast) # args=
    x.start()
    y = threading.Thread(target=DrinkCoffee) # args=
    y.start()
    z = threading.Thread(target=Study) # args=
    z.start()
    x.join()
    y.join()
    z.join()
    
# daemon thread = thread that runs in the background, the program will not wait
# All daemons will be killed when exiting the program
# e.g.: background tasks, garbage collection, etc.
def Timer():
    print()
    count = 0
    while True:
        time.sleep(1)
        count += 1
        print("logged in for: ", count, " seconds")
        
def DaemonThreads():
    x = threading.Thread(target=Timer, daemon=True)
    # x.setDaemon()
    x.start()
    #print(x.isDaemon())
    answer = input("Do you wish to exit?: ")

# multiprocessing = running tasks on different cpu cores, bypasses GIL
#                   multiprocessing = better for cpu bound (heavy cpu usage)
#                   multitasking = better for io bound
def Counter(num):
    count = 0
    while count < num:
        count += 1
    
def Multiprocessing():
    print(cpu_count())
    
    a = Process(target=Counter, args=(250000000,)) # As a fork() in C++ 
    b = Process(target=Counter, args=(250000000,)) # As a fork() in C++
    #c = Process(target=Counter, args=(250000000,)) # To many hinder the cpu performance 
    #d = Process(target=Counter, args=(250000000,))
    a.start()
    b.start()
    #c.start()
    #d.start()
    a.join()
    b.join()
    #c.join()
    #d.join()
    print("finished in: ", time.perf_counter(), " seconds")

def main():
    # -----Sequencially-----
    #EatBreakfast()
    #DrinkCoffee()
    #Study()
    # -----Multitasking-----
    #Threading()
    #JoiningThreads()
    # -----daemon threads-----
    #DaemonThreads()
    # ------Multiprocessing
    Multiprocessing()
    CountThreads()
    print(time.perf_counter()) # Says when the main thread has finished

if __name__ == '__main__':
    main()