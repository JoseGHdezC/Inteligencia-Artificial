# sort() method = used with lists
# sort() function = used with iterable

students = ["Squidward", "Sandy", "Patrick", "Spongebob", "Mr.Krabs"]
foods = ("pizza", "hotdog", "cake", "water", "spaguetti")
too_students = [("Squidward", "F", 60), 
                 ("Sandy", "A", 33),
                 ("Patrick", "D", 36),
                 ("Spongebob", "B", 20),
                 ("Mr.Krabs", "C", 78)]
tuple_students = (("Squidward", "F", 60), 
                 ("Sandy", "A", 33),
                 ("Patrick", "D", 36),
                 ("Spongebob", "B", 20),
                 ("Mr.Krabs", "C", 78))

def main():
    students.sort(reverse=True)
    for i in students:
        print(i)
        
    print("------------")  
    sorted_foods = sorted(foods, reverse=True)
    for i in sorted_foods:
        print(i)
        
    print("------------")
    too_students.sort()
    for i in too_students:
        print(i)
        
    print("------------")
    grade = lambda grades:grades[1]
    too_students.sort(key=grade, reverse=True)
    for i in too_students:
        print(i)
        
    print("------------")
    age = lambda ages:ages[2]
    too_students.sort(key=age, reverse=True)
    for i in too_students:
        print(i)
        
    print("------------")
    age = lambda ages:ages[2]
    sorted_students = sorted(tuple_students,key=age)
    for i in sorted_students:
        print(i)

if __name__ == '__main__':
    main()
    