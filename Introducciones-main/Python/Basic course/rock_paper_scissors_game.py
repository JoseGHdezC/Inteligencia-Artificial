import random

choices: list[str] = ["rock", "paper", "scissors"]

def RockPaperScissors() -> str:
    return (random.choice(choices))

def PrintChoices(user_choice: str, cpu_choice: str) -> None:
    print("Player: " + user_choice)
    print("Computer: " + cpu_choice)
    
def main() -> None:
    quit: bool = False
    while (not(quit)):
        computer: str = RockPaperScissors()
        user: str = ""
        while (user not in choices):
            user = input("rock, paper or scissors?: ").lower()
            if (not(user in choices)):
                print("No cheating!")
        if (user == computer):
            PrintChoices(user_choice = user, cpu_choice = computer)
            print("It's a tie.")
        elif (user == "rock"):
            if (computer == "paper"):
                PrintChoices(user_choice = user, cpu_choice = computer)
                print("You lose.")
            if (computer == "scissors"):
                PrintChoices(user_choice = user, cpu_choice = computer)
                print("You win!")
        elif (user == "paper"):
            if (computer == "scissors"):
                PrintChoices(user_choice = user, cpu_choice = computer)
                print("You lose.")
            if (computer == "rock"):
                PrintChoices(user_choice = user, cpu_choice = computer)
                print("You win!")
        elif (user == "scissors"):
            if (computer == "rock"):
                PrintChoices(user_choice = user, cpu_choice = computer)
                print("You lose.")
            if (computer == "paper"):
                PrintChoices(user_choice = user, cpu_choice = computer)
                print("You win!")
        play_again: str = input("Play again? (yes/no): ").lower()
        if (not(play_again == "yes")):
            quit = True
        print()
    print("Thanks for playing! <3")
        
if __name__ == '__main__':
    main()
    