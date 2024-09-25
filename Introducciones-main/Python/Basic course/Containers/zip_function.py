# zip(*iterables) = aggregate elements from two or more iterables (list, etc.)
#                   creates a zip object with paired elements stored in tuples for each element

usernames: list[str] = ["Jose", "Gregorio", "Hernandez", "Cruz"]
passwords: tuple[str] = ("password", "abc123", "guest", "potome")
login_dates: list[str] = ["1/1/2021", "1/2/2021", "1/3/2021", "1/4/2021"]

def main():
    users = dict(zip(usernames, passwords))
    users_more = list(zip(usernames, passwords, login_dates))
    print(type(users))
    for key, value in users.items():
        print(key + ": " + value)
    print()
    for i in users_more:
        print(i)

    users_more[0] = ("Hola", "que tal", "adios")
    print(users_more)
    
if __name__ == '__main__':
    main()
    