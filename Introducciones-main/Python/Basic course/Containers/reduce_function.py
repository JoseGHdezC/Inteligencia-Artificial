# reduce = apply a function to an iterable and reduce it to a single cumulative value
#           performs function on first two elements and repeats process until 1 element remains
#
# reduce(function, iterable)

import functools

letters = ["H", "E", "L", "L", "O"]

combine = lambda x, y: x + y

factorial = [5, 4, 3, 2, 1]

def main():
    word = functools.reduce(combine, letters)
    print(word)
    
    result = functools.reduce(lambda x, y: x * y, factorial)
    print(result)

if __name__ == '__main__':
    main()
    