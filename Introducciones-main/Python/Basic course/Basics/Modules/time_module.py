import time

def main():
    print(time.ctime(0)) # Convert a time since epoch to a string
    
    print(time.time()) # returns current seconds since epoch
    
    print(time.ctime(time.time())) # prints current time in string
    
    time_object = time.localtime()
    time_object = time.gmtime()
    
    print(time_object)
    
    local_time = time.strftime("%B %d %Y %H:%M:%S", time_object)
    print(local_time)
    
    time_string = "20 April, 2020"
    time_object = time.strptime(time_string, "%d %B, %Y")
    print(time_object)
    
    # (year, month, day, hours, minutes, secs, day of the week, day of the year, dst)
    time_tuple = (2020, 4, 20, 4, 20, 0, 0, 0, 0)
    time_string = time.asctime(time_tuple)
    print(time_string)
    
    time_tuple = (2020, 4, 20, 4, 20, 0, 0, 0, 0)
    time_string = time.mktime(time_tuple) # seconds since epoch
    print(time_string)

if __name__ == '__main__':
    main()
    
