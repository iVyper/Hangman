/*
 * Hangman Game in C
 * A simple console-based Hangman game.
 * The program randomly selects a word from a predefined list,
 * then prompts the user to guess letters until the word is revealed
 * or the player runs out of tries.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 
 #define MAX_TRIES 6  // Maximum number of wrong guesses allowed
 
 int main(void) {
     // List of possible words for the game
     const char *words[] = { "computer", "programming", "hangman", "cplusplus", "software" };
     int num_words = sizeof(words) / sizeof(words[0]);
 
     // Seed the random number generator using the current time
     srand(time(NULL));
     int random_index = rand() % num_words;
     const char *word = words[random_index];
     
     int word_length = strlen(word);
     char guessed[word_length + 1];  // Array to store current guessed progress
     // Initialize the guessed array with underscores
     for (int i = 0; i < word_length; i++) {
         guessed[i] = '_';
     }
     guessed[word_length] = '\0';  // Null-terminate the string
 
     int tries = 0;
     char guess;
     // Array to track if a letter has been guessed already (26 letters in alphabet)
     int guessed_letters[26] = {0};
 
     printf("Welcome to Hangman!\n");
     printf("You have %d tries to guess the word.\n\n", MAX_TRIES);
 
     // Main game loop
     while (tries < MAX_TRIES) {
         printf("Current word: %s\n", guessed);
         printf("Enter a letter: ");
         scanf(" %c", &guess);
 
         // Convert uppercase input to lowercase
         if (guess >= 'A' && guess <= 'Z') {
             guess = guess - 'A' + 'a';
         }
 
         // Check if the letter has already been guessed
         if (guessed_letters[guess - 'a']) {
             printf("You've already guessed '%c'. Try another letter.\n\n", guess);
             continue;
         }
         // Mark the letter as guessed
         guessed_letters[guess - 'a'] = 1;
 
         // Flag to check if the guess is found in the word
         int found = 0;
         for (int i = 0; i < word_length; i++) {
             if (word[i] == guess) {
                 guessed[i] = guess;  // Reveal the correctly guessed letter
                 found = 1;
             }
         }
 
         // If the guess was wrong, increment the number of tries
         if (!found) {
             tries++;
             printf("Wrong guess! You have %d tries left.\n\n", MAX_TRIES - tries);
         } else {
             printf("Good guess!\n\n");
         }
 
         // Check if the word has been completely guessed
         if (strcmp(guessed, word) == 0) {
             printf("Congratulations! You guessed the word: %s\n", word);
             break;
         }
     }
 
     // If the player used all tries without guessing the word
     if (tries == MAX_TRIES) {
         printf("Game over! The correct word was: %s\n", word);
     }
 
     return 0;
 }
 