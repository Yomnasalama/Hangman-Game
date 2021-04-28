import random
from random import seed
from random import randint
word = " "
words = ["apple","orange","banana","strawberry","grapes","watermelon","pineapple","pear","mango","cherry"]
s = ['-','-','-','-','-','-','-','-','-','-']
x = 0
def clear():
    global x
    global s
    x = 0
    for i in range(len(s)):
        s[i] = '-'

def select_word():
  global word
  n = random.randint(0,8)
  word = words[n]
def put_letters():
    global s
    global word
    for i in range(len(word)):
         print(s[i] , end = ' ')
    print()
def check_right(c):
    global x
    global word
    global s
    b = False
    for i in range(len(word)):
        if(c == word[i]):
            s[i] = c
            b = True
    if(not b):
        x+=1
def print_man():
     global x
     if(x == 0):
        print(" ___________")
        print(" |          ")
        print(" |         ")
        print("_|______________")
        print()
     elif (x == 1):
            print(" ___________")
            print(" |         0")
            print(" |         ")
            print("_|______________")
            print()
     elif(x == 2):
            print(" ___________")
            print(" |         0")
            print(" |       \\  ")
            print("_|______________")
            print()
     elif(x == 3):
            print(" ___________")
            print(" |         0")
            print(" |       \\ | ")
            print("_|______________")
            print()
     elif(x == 4):
            print(" ___________")
            print(" |         0")
            print(" |       \\ | /")
            print( "_|______________")
            print()
     elif(x == 5):
            print(" ___________")
            print( " |         0")
            print(" |       \\ | /" )
            print(" |         |")
            print("_|______________")
            print()
     elif(x == 6):
            print(" ___________")
            print(" |         0")
            print(" |       \\ | /" )
            print(" |         |")
            print(" |        /  ")
            print("_|______________")
            print()
     elif(x == 7):
            print(" ___________")
            print(" |         0")
            print(" |       \\ | /")
            print(" |         |")
            print(" |        / \\ ")
            print("_|______________")
            print()
def win_lose():
    global s
    global word
    if(x == 7):
        print("YOU LOSE :( !")
        print_man()
        return True
    else:
        for i in range(len(word)):
             if s[i] == '-':
                return False
    print("YOU WIN :)")
    print(word)
    return True
def check_input(l):
    if (ord(l) >= 97 and ord(l) <= 122):
        return True
    return False
def read_input():
    print("GUESS A LETTER: " , end = ' ')
    c = str(input())
    while not check_input(c):
        print("Enter a valid input: ")
        c = str(input())
    return c
def play():
    print("Hangman Game.....")
    print("GUESS a fruit name !!")
    while True:
        print_man()
        put_letters()
        c = read_input()
        check_right(c)
        if(win_lose()):
            break
while True:
    clear()
    select_word()
    play()
    c = input('Play Again [Y/N] ')
    if c not in 'yY':
      break
