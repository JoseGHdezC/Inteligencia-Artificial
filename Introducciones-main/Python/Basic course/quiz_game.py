
questions: dict[str, str] = {"Who created Python?: " : "A",
                             "What year was Python created?: " : "B",
                             "Python is tributed to which comedy group?: " : "C",
                             "Is the Earth round?: " : "A"}

options: list[list[str]] = [["A. Guido van Rossum", "B. Elon Musk", "C. Bill Gates", "D. Mark Zuckerburg"],
                            ["A. 1989", "B. 1991", "C. 2000", "D. 2016"], 
                            ["A. Lonely Island", "B. Smosh", "C. Monty Python", "D. SNL"],
                            ["A. True", "B. False", "C. Sometimes", "D. What is Earth?"]]

#-------------------
def NewGame() -> None:
    guesses: list[str] = []
    correct_guesses: int = 0
    question_number: int = 1
    
    for key in questions.keys():
        print("--------------")
        print("Question {}".format(question_number))
        print(key)
        for i in options[question_number - 1]:
            print(i)
        guess: str = input("Enter A, B, C or D: ").upper()
        guesses.append(guess)
        
        correct_guesses += CheckAnswer(questions.get(key), guess)
        
        question_number += 1
    DisplayScore(correct_guesses, guesses)

#-------------------
def CheckAnswer(answer: str, guess: str) -> int:
    if (answer == guess):
        print("Correct")
        return 1
    else:
        print("Wrong")
        return 0

#-------------------
def DisplayScore(correct_guesses: int, guesses: list[str]) -> None:
    print("------------------")
    print("Results")
    print("------------------")
    print("Answers: ", end = "")
    for i in questions:
        print(questions.get(i) + " ", end = "")
    print()
    print("Guesses: ", end = "")
    for i in guesses:
        print(i + " ", end = "")
    print()
    
    score = (correct_guesses / len(questions)) * 100
    print("Your score is: {} %".format(score))

#-------------------
def PlayAgain() -> bool:
    response: str = input("Do you want to play again? (yes/no): ").lower()
    if (response == "yes"):
        return True
    else: 
        return False

#-------------------
def main() -> None:
    NewGame()
    while (PlayAgain()):
        NewGame()
    print()
    print("Byeeee! Thanks for playing!")

if __name__ == '__main__':
    main()
    