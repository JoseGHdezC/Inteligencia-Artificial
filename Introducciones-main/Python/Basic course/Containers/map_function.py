# map() = applies a function to each item in the iterable
#
# map(function, iterable)

store = [("shirt", 20.00),
         ("pants", 25.00),
         ("jacket", 50.00),
         ("socks", 10.00)]

to_euros = lambda data: (data[0],data[1] * 0.82)
to_dollar = lambda data: (data[0],data[1] / 0.82)

def main():
    store_euros = list(map(to_euros, store))
    for i in store_euros:
        print(i)
    store_dollars = list(map(to_dollar, store))
    for i in store_dollars:
        print(i)
if __name__ == '__main__':
    main()
    
