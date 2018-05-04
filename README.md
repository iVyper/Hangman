# Hangman Game in C

This is a simple, console-based Hangman game written in C. The game randomly selects a word from a predefined list, and the player must guess the letters until they either reveal the word or run out of tries.

## Features

- **Random Word Selection:** The game picks a random word from an array of possible words.
- **Interactive Gameplay:** Prompts the user to guess letters while displaying the current state of the word.
- **Input Validation:** Checks for duplicate guesses and handles incorrect inputs gracefully.
- **Limited Tries:** The player has a fixed number of wrong guesses before the game ends.

## Requirements

- A C compiler (such as `gcc`)
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `time.h`)

## How to Compile and Run

1. **Clone the Repository or Download the Files:**

   ```bash
   git clone https://github.com/yourusername/hangman-c.git
   cd hangman-c

2. **Compile the Program:**

    ```bash
    gcc -o hangman hangman.c

3. **Run the Executable:**

    ```bash
    ./hangman

## Code Overview

- **Main Function:** Initializes the game, seeds the random number generator, selects a random word, and runs the game loop.
- **Game Loop:** Handles user input, checks guesses, and updates the display until the player wins or loses.
- **User Feedback:** Provides clear messages after each guess, informing the player if they have guessed correctly or if the guess was wrong.

## License

This project is open-source and available under the MIT License.