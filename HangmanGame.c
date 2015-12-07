/*
Long Term Assignment #1
Due 4/23/14
Nicholas Golini

What this code does:
Has a user choose a word from a file with n number of encrypted words.
The word the user asks to use is then decrypted. 
The decrypted word is then used as the secret word in a game of hangman, in which the user
enters letters, and if the letter is in the word, the program will put the correct letter
in the correct part of the word. If the letter is wrong, the computer will count how many
wrong guesses there were, and make the user lose if they get to 10 guesses. 

Functions used:
wordCounter - counts how many words there are in the file
letterShifter - decrypts each letter of the word
upperToLower - if the user guesses a letter that is upper case, it will convert that to the lower case equivalence
makeASpace - converts the characters after the backslash to spaces
main - plays the game, calling each function when needed 

************************* BUGS IN THIS CODE *********************
1. wordCounter() started printing out the wrong number of words in the file for some reason. It was working perfectly right after I made the function, 
so I never touched it, and now, it is printing 286 instead of 9.
2. Once the user starts playing the game, underscores are filled into the word display so there are 10 characters, which shouldn't be happening -- If you don't understand 
what this means, you'll see when you start playing the game. 
*/

#include <stdio.h>
char letterShift(char c, int shift);
int wordCounter(void);
char upperToLower(char guess1);
char makeASpace(char space);

int main(void)
{
	
	char l1, l2, l3, l4, l5, l6, l7, l8, l9, l10; /* Character space for each shifted letter */
	char space, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10; /* Each decoded character from 1-10 */
	int shifter; /* Scans the number of how many places you are shifting each letter in the alphabet */	
	int word_num; /* Getting which word the player wants to use */
	char backslash_num; /* Scans for how many backslash n's there are*/
	int i = 0; /* while loop counter */
	char check; /* Used to count how many letters are in each word before the backslash*/
	int letter_count = 0; /* counts the number of letters in a word - starting at -1 to take into account the backslash n being counted*/
	/* Gameplay variables */
	int miscount, misleft; /* Counters for how many mistakes have been made, and how many mistakes the user has left before game over */
	char guess; /* The user's guess */
	int j, k, m; /* Counters for while loops to display correct amount of underscores and have them terminated*/
	int guess_count = 0; /* counts how many guesses were correct in order to stop the game once the user has gotten all of the letters correct*/
	char blank; /* the blank character displays an underscore */
	char junk; /* stores the backslash the user enters while scanning something */
	int flag1, flag2, flag3, flag4, flag5, flag6, flag7, flag8, flag9, flag10; /* Used for determining if a letter was guessed correctly */
	j = 0; /* While loop counter, used to break the loop */
	
	FILE *ifile; 
	
	ifile = fopen("wordbank.txt", "r");
	printf("There are "); 
	wordCounter();
	printf(" words in the file\n");	/* Ask the user what word out of the number of words in the file they want to play and has them enter a number */
	printf("Which one would you like to play? Enter a number between 1 and ");
	wordCounter();
	printf(": ");
	scanf("%d%c", &word_num, &junk);
	if(word_num > 10){ /* If they enter a number outside the range of how many words there are, it asks them to enter a new number */
		printf("Invalid number. Please enter a number between 1 - 9: ");
		scanf("%d%c", &word_num, &junk);	
	}
	
	/* Gets to the line number that the user wants to play with */
	while(i <= word_num-2){		
		fscanf(ifile, "%c", &backslash_num);
		if(backslash_num == 10){
			i++;
		}
	}
	
	/* Scan the integer, then the space, before the 10 coded characters */
	fscanf(ifile, "%d", &shifter);
	fscanf(ifile, "%c", &space);
	
	/* 	Each letter is beings scanned. If it is not a backslash n, then that letter is being decrypted using the shift letter function.
	*	After the character is converted, the next character is being scanned, it is then going into the letterShift function to be decoded.
	*	The decoded letter is then being assigned, and again, if it is not a backslash n, then the letter gets decrypted using the shift letter function. 
	*	Each time a letter is not a backslash n, letter_count increases by 1, which keeps track of how many letters there are in each word
	*	This keeps happening until one of the characters is a backslash n. Once this is the case, the function makeASpace() takes
	*	the remaining characters and converts them to spaces.  
	*	This is all in a while loop simply so once a character is a backslash n, and after the rest of the letters are converted to spaces, 
	*	the loop will break when it needs to. */
	
	while(letter_count < 10){
		fscanf(ifile, "%c", &c1);
		if(c1 != '\n'){			
			l1 = letterShift(c1, shifter);
			fscanf(ifile, "%c", &c2);		
			letter_count++; 	
		} else{
			makeASpace(l1); makeASpace(l2); makeASpace(l3); makeASpace(l4); makeASpace(l5); makeASpace(l6); makeASpace(l7); makeASpace(l8); makeASpace(l9); makeASpace(l10);
			break;
		}
		if(c2 != '\n'){
			l2 = letterShift(c2, shifter);
			fscanf(ifile, "%c", &c3); 
			letter_count++;	
		} else{
			makeASpace(l2); makeASpace(l3); makeASpace(l4); makeASpace(l5); makeASpace(l6); makeASpace(l7); makeASpace(l8); makeASpace(l9); makeASpace(l10);
			break;
		}
		if(c3 != '\n'){
			l3 = letterShift(c3, shifter);
			fscanf(ifile, "%c", &c4);
			letter_count++;	
		} else{
			makeASpace(l3); makeASpace(l4); makeASpace(l5); makeASpace(l6); makeASpace(l7); makeASpace(l8); makeASpace(l9); makeASpace(l10);	
			break;
		}
		if(c4 != '\n'){
			l4 = letterShift(c4, shifter);
			fscanf(ifile, "%c", &c5); 
			letter_count++;
		} else{
			makeASpace(l4); makeASpace(l5); makeASpace(l6); makeASpace(l7); makeASpace(l8); makeASpace(l9); makeASpace(l10);
			break;
		}
		if(c5 != '\n'){
			l5 = letterShift(c5, shifter);
			fscanf(ifile, "%c", &c6); 
			letter_count++;
		} else{
			makeASpace(l5); makeASpace(l6); makeASpace(l7); makeASpace(l8); makeASpace(l9); makeASpace(l10);
			break;
		}
		if(c6 != '\n'){
			l6 = letterShift(c6, shifter);
			fscanf(ifile, "%c", &c7);
			letter_count++;
		} else{ 
			l6 = 00; makeASpace(l7); makeASpace(l8); makeASpace(l9); makeASpace(l10);
			break;
		}
		if(c7 != '\n'){
			l7 = letterShift(c7, shifter);
			fscanf(ifile, "%c", &c8); 
			letter_count++;
		} else{
			makeASpace(l7); makeASpace(l8); makeASpace(l9); makeASpace(l10);
			break;
		}
		if(c8 != '\n'){
			l8 = letterShift(c8, shifter);
			fscanf(ifile, "%c", &c9); 	
			letter_count++;
		} else{
			makeASpace(l8); makeASpace(l9); makeASpace(l10);
			break;
		}
		if(c9 != '\n'){
			l9 = letterShift(c9, shifter);
			fscanf(ifile, "%c", &c10); 
			letter_count++;
		} else{
			makeASpace(l9); makeASpace(l10);
			break;
		}
		if(c10 == '\n'){
			l10 = letterShift(c10, shifter);
			makeASpace(l10);
			break;
		} else{
			break;
		}
	}

	
	/*
	*
	*
	*
	Starting the gameplay
	*
	*
	*
	*/
	
	blank = '_';
	k = 0;
	m = 0;
	miscount = 0;
	misleft = 10;
	guess_count = 0;
	flag1 = 0; 	flag2 = 0; flag3 = 0; flag4 = 0; flag5 = 0; flag6 = 0; flag7 = 0; flag8 = 0; flag9 = 0; flag10 = 0;
	
	printf("The word has %d letters.\n\n", letter_count);
	printf("You have made 0 mistakes and have 10 mistakes left.\n");
	printf("The word is: ");
	while(k < letter_count){
		printf(" _");
		k++;
	}
	
	/* For example, if the second letter is guessed correctly, flag2 will turn on and the guess counter will increase 
		*	The guess counter is used to kick the user out of the loop once they guess all the characters correctly 
		*	Turn each flag on if their respective letter is guessed correctly 
		*	If the flag's letter has not yet been guessed correctly, it prints an underscore to show it has yet to be guessed 
		*	There is a switch statement for each flag. When one flag is turned on, it prints its respective letter in its proper position within the word 
		*	This scans the file, and when it reads a backslash, it adds 1 to a counter until it reaches the end of the filie, then prints out the number of lines there are which is equal to the number of words */
	
	while((miscount < 10) && (guess_count < letter_count)){		
		printf("\nGuess a letter: ");
		scanf("%c%c", &guess, &junk);
		guess = upperToLower(guess);  /* not working for first guess */
		printf("\n");
		
			if(guess != l1 && guess != l2 && guess != l3 && guess != l4 && guess != l5 && guess != l6 && guess != l7 && guess != l8 && guess != l9 && guess != l10){ 
			 	miscount++;
				misleft--;
			}
			if(guess == l1){	
				flag1 = 1;
				guess_count++;	
			}					
			if(guess == l2){
				flag2 = 1;
				guess_count++;
			}
			if(guess == l3){
				flag3 = 1;
				guess_count++;
			}
			if(guess == l4){	
				flag4 = 1;
				guess_count++;		
			}
			if(guess == l5){	
				flag5 = 1;	
				guess_count++;	
			}
			if(guess == l6){	
				flag6 = 1;
				guess_count++;
			}
			if(guess == l7){	
				flag7 = 1;
				guess_count++;		
			}
			if(guess == l8){	
				flag8 = 1;
				guess_count++;		
			}
			if(guess == l9){	
				flag9 = 1;	
				guess_count++;	
			}
			if(guess == l10){	
				flag10 = 1;			
			}
		printf("\nYou have made %d mistake(s) and have %d mistake(s) left.\n", miscount, misleft); /* These two lines are the line of text that are displayed each guess no matter what*/
		printf("The word is: ");
		
			switch(flag1){
				case 0: printf("_ "); break;	
				case 1: printf("%c", l1); break; 
			}
			switch(flag2){
				case 0: printf("_ "); break;
				case 1: printf("%c", l2); break;
			}
			switch(flag3){
				case 0: printf("_ "); break;
				case 1: printf("%c", l3); break;
			}
			switch(flag4){
				case 0: printf("_ "); break;
				case 1: printf("%c", l4); break;
			}
			switch(flag5){
				case 0: printf("_ "); break;
				case 1: printf("%c", l5); break;
			}
			switch(flag6){
				case 0: printf("_ "); break;
				case 1: printf("%c", l6); break;
			}
			switch(flag7){
				case 0: printf("_ "); break;
				case 1: printf("%c", l7); break;
			}
			switch(flag8){
				case 0: printf("_ "); break;
				case 1: printf("%c", l8); break;
			}
			switch(flag9){
				case 0: printf("_ "); break;
				case 1: printf("%c", l9); break;
			}
			switch(flag10){
				case 0: printf("_ "); break;
				case 1: printf("%c", l10); break;
			}
	}	
		
		if(miscount == 10){
			printf("\nToo many guesses. GAME OVER.\n");
		} 
		if(guess_count == letter_count){
			printf("\nCongratulations! You guessed the word correctly!\n");
			printf("The word was %c%c%c%c%c%c%c%c%c%c\n", l1, l2, l3, l4, l5, l6, l7, l8, l9, l10);

		}
	
	
}
/*
This function counts the number of words in the file
*/
int wordCounter(void)
{

	FILE *ifile;
	int num;
	char word;
	num = 1;
	
	ifile = fopen("wordbank.txt", "r");
	while(fscanf(ifile, "%c", &word) != EOF){
		if(word == 10){
			num++;
		}
	}
	printf(" %d", num);
				
	fclose(ifile);
	
return(0);
}

char makeASpace(char space)
{
	space = space - space;
	return(space);
}

/* Shifts each letter */
char letterShift(char c, int shift)
{
	
	char test; /* Tester variable to see if the shift puts the new letter past the realms of the alphabet */

	while(c != 10){
		test = c - shift; /* Used to test whether the shifted character is outside of the alphabet */
		
		if(test < 97){ /* If it was shifted outside the alphabet, loop it back around */
			c = c + (26 - shift);
		} else{
			c = test; /* if it wasn't shifted outside the alphabet, don't change it */
		}
	
	return(c); 
	
	}
} 

/* Converts any uppercase guesses to the same letter, but lowercase */
char upperToLower(char guess1)
{	
	if((guess1 >= 65) && (guess1 <= 90)){ /* If the guess is out of the realm of lowercase letters, add 32 to get to the same letter but lowercase */
		guess1 = guess1 + 32; 
	} else if((guess1 >= 97) && (guess1 <= 122)){ /* If the guess is already lowercase, keep it like that*/
		guess1 = guess1;
	} else{ /* If the input isn't a letter, make the person input another char*/
		printf("This is an invalid input.\nPlease enter another guess: ");
		scanf("%c ", &guess1);
	}
	
	return(guess1);
}
