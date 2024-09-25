# random
import random

x = random.randint(1, 6)
y = random.random()

my_list = ["rock", "paper", "scissors"]
z = random.choice(my_list)

cards = ["A", 2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K"]

print(x)
print(y)
print(z)
print(cards)

random.shuffle(cards)

print(cards)