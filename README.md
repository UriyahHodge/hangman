# hangman
Repo for hangman game written in c++

If you are unfamiliar with the rules of
the game, read
http://en.wikipedia.org/wiki/Hangman_(game) .

Here is the general behavior we want to implement:
1. The computer must select a word at random from the list of available words that was provided in words.txt
_Note that words.txt contains words in all lowercase letters._
2. The user is given 6 guesses at the beginning.
3. The game is interactive; the user inputs their guess and the computer either:
  a. reveals the letter if it exists in the secret word
  b. penalize the user and updates the number of guesses remaining
4. The game ends when either the user guesses the secret word, or the user runs out of guesses.

**--Game Rules--**
1. The user starts with 3 warnings.
2. If the user inputs anything besides an alphabet (symbols, numbers), tell the user that they can only input an alphabet.
  a. If the user has one or more warning left, the user should lose one warning. Tell the user the number of remaining warnings.
  b. If the user has no remaining warnings, they should lose one guess.
3. If the user inputs a letter that has already been guessed, print a message telling the user the letter has already been guessed before.
  a. If the user has one or more warning left, the user should lose one warning. Tell the user the number of remaining warnings.
  b. If the user has no warnings, they should lose one guess.
4. If the user inputs a letter that hasn’t been guessed before and the letter is in the secret word, the user loses no guesses.
5. Consonants: If the user inputs a consonant that hasn’t been guessed and the consonant is not in the secret word, the user loses one guess if it’s a consonant.
6. Vowels: If the vowel hasn’t been guessed and the vowel is not in the secret word, the user loses two guesses. Vowels are a, e, i , o, and u. y does not count as a vowel.

**--Game Termination--**
1. The game should end when the user constructs the full word or runs out of guesses.
2. If the player runs out of guesses before completing the word, tell them they lost and reveal the word
to the user when the game ends.
3. If the user wins, print a congratulatory message and tell the user their score.
4. The total score is the number of guesses_remaining once the user has guessed the secret_word times
the number of unique letters in secret_word .
Total score = guesses_remaining* number unique letters in secret_word

**--Game Requirements--**
A. Game Architecture:
1. The computer must select a word at random from the list of available words that was provided in words.txt.
2. Users start with 6 guesses.
3. At the start of the game, let the user know how many letters the computer's word contains and how many guesses they start with.
4. The computer keeps track of all the letters the user has not guessed so far and before each turn shows the user the “remaining letters”

B. User-Computer Interaction:
The game must be interactive and flow as follows:
1. Before each guess, you should display to the user:
  a. Remind the user of how many guesses s/he has left after each guess.
  b. all the letters the user has not yet guessed
2. Ask the user to supply one guess at a time. (Look at the user input requirements below to see what types of inputs you can expect from the user)
3. Immediately after each guess, the user should be told whether the letter is in the computer’s word.
4. After each guess, you should also display to the user the computer’s word, with guessed letters displayed and unguessed letters replaced with an underscore and space (_ )
5. At the end of the guess, print some dashes () to help separate individual guesses from each other

C. User Input Requirements:
1. You may assume that the user will only guess one character at a time, but the user can choose any number, symbol or letter. Your code should accept capital and lowercase letters as valid guesses!
2. If the user inputs anything besides an alphabet (symbols, numbers), tell the user that they can only input an alphabet. Because the user might do this by accident, they should get 3 warnings at the beginning of the game. Each time they enter an invalid input, or a letter they have already guessed, they should lose a warning. If the user has no warnings left and enters an invalid input, they should lose a guess.
  _Hint: Since the words in words.txt are lowercase, it might be easier to convert the user input to lowercase at all times and have your game only handle lowercase._

**--General Hints--**
1. Consider writing additional helper functions if you need them.
2. There are four important pieces of information you may wish to store:
  a. secret_word : The word to guess. This is already used as the parameter name for the hangman function.
  b. letters_guessed : The letters that have been guessed so far. If they guess a letter that is already in letters_guessed , you should print a message telling them they've already guessed that but do not penalize them for it.
  c. guesses_remaining : The number of guesses the user has left. Note that in our example game, the penalty for choosing an incorrect vowel is different than the penalty for choosing an incorrect consonant.
  d. warnings_remaining : The number of warnings the user has left. Note that a user only loses a warning for inputting either a symbol or a letter that has already been guessed.
