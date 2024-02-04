/***********************
 * Alon Filler
 * 216872374
 * Assignment 2
***********************/

#include<stdio.h>

int scanNumberVerbose();
int isPrime(int number);
int playGame();
int validateQuestNumber(int chosenQuestNumber, double remainder);
void printError(int numRequired);
int firstQuest();
int secondQuest();
int thirdQuest();
int fourthQuest();
int fifthQuest();

int main() {
	/*
		Calls the playGame function until it returns 1
	*/
	int hasUserQuit = 0;
	while (!hasUserQuit) hasUserQuit = playGame();
	return 0;
}
int isPrime(int number) {
	/*
		Input: integer number
		Output: 1 if the number is a prime number and 0 otherwise
	*/
	if (number == 2) return 1;
	if (number % 2 == 0) return 0;
	for (int i = 3; i <= (number/2) + 1; i += 2) {
		if (number % i == 0) return 0;
	}

	return 1;
}
int scanNumberVerbose() {
	/*
		User Input: An integer number
		Output: the number
	*/
	double number, remainder;
	printf("Enter a number: ");
	scanf("%lf", &number);
	remainder = number - (int) number;
	// if the input was a number like 1.123
	if (remainder != 0.0) return -1;

	return (int) number;
}
int playGame() {
	/*
		Starts the game
		Output: returns 1 if the user quit and 0 otherwise
	*/
	double chosenQuestNumberAsDouble, remainder;
	int chosenQuestNumber;
	printf("Welcome to Thanos's playground.\n");
	printf("Choose your adventure:\n");
	printf("1. Revealing the Hidden Code\n");
	printf("2. Thanos' numeric mayhem\n");
	printf("3. Thanos' Maze System\n");
	printf("4. The Sorcery of Thanos\n");
	printf("5. Quit the quest\n");
	printf("\n");
	scanf("%lf", &chosenQuestNumberAsDouble);
	chosenQuestNumber = (int) chosenQuestNumberAsDouble;
	
	remainder = chosenQuestNumberAsDouble - chosenQuestNumber;

	if (!validateQuestNumber(chosenQuestNumber, remainder)) return 0;
	if (chosenQuestNumber == 1) return firstQuest();
	if (chosenQuestNumber == 2) return secondQuest();
	if (chosenQuestNumber == 3) return thirdQuest();
	if (chosenQuestNumber == 4) return fourthQuest();
	if (chosenQuestNumber == 5) return fifthQuest();
	return 0;
}

int validateQuestNumber(int chosenQuestNumber, double remainder) {
	/*
		Validates that the quest exists
		Output: returns 0 if the quest does not exist, and 1 if it does
	*/
	if (chosenQuestNumber < 1 || chosenQuestNumber > 5) {
		printf("Thanos is mad! You are playing his game and this is not an option. Choose again, wisely.\n");
		printf("\n");
		return 0;
	}
	// If the input was a number of the likes of 1.1, 1.232323323, etc.:
	if (remainder != 0.0) {
		printf("Thanos is mad! You are playing his game and this is not an option. Choose again, wisely.\n");
		printf("\n");
		return 0;

	}
	return 1;
}
void printError(int numRequired) {
	/*
		Input: integer numRequired, which indicates what is the minimum input possible 
		Prints: A generic error message which entails the numRequired variable integrated in to it
	*/
	printf("Foolish mortal! You cannot solve Thanos's quest with an input that isn't a number bigger than %d\n", numRequired);
	printf("\n");
}
int firstQuest() {
	/*
		Runs the first quest (FizzBuzz game)
		User Input: a number
		Validation: ensures that the number is greater than 1
		Prints: FizzBuzz until the input number
		Output: returns 0, user did not quit
	*/
	int number = scanNumberVerbose();
	if (number <= 1) {
		printError(1);
		return 0;
	}
	
	for (int i = 1; i <= number; i++) {
		if (i % 3 == 0) printf("Fizz");
		if (i % 5 == 0) printf("Buzz");
		if (i % 5 && i % 3) printf("%d", i);
		printf("\n");
	}
	printf("\n");
	return 0;
}

int secondQuest() {
	/*
		Runs the second quest (Prints fibonacci numbers)
		User Input: a number: n
		Validation: ensures that the number is greater than 0
		Prints: First n elements of the fibonacci sequence
		Output: returns 0, user did not quit
	*/
	int n = scanNumberVerbose();
	if (n <= 0) {
		printError(0);
		return 0;
	}
	unsigned long long int current = 1, previous = 0;
	
	for (int i = 1; i <= n; i++) {
		printf("%llu", previous);
		current += previous;
		previous = current - previous;
		if (i == n) printf("\n");
		else printf(" ");
	}
	printf("\n");
	return 0;
}

int thirdQuest() {
	/*
		Runs the third quest (Finds the sum of all the prime numbers up until and including n)
		User Input: a number: n
		Validation: ensures that the number is greater than 1
		Prints: The sum of all prime numbers smaller or equal to n
		Output: returns 0, user did not quit
	*/
	int n = scanNumberVerbose();
	if (n <= 1) {
		printError(1);
		return 0;
	}
	
	unsigned long long int sum = 0;
	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) sum += i;
	}
	printf("%llu\n", sum);
	printf("\n");
	return 0;
}

int fourthQuest() {
	/*
		Runs the fourth quest (Checks whether the number is perfect)
		User Input: a number: n
		Validation: ensures that the number is greater than 0
		Prints: Whether the number is perfect or not
		Output: returns 0, user did not quit
	*/
	int n = scanNumberVerbose();
	if (n <= 0) {
		printError(0);
		return 0;
	}
	unsigned long long int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) sum += i;
	}

	if (sum == n) printf("Perfect!\n");
	else printf("Not Perfect!\n");
	
	printf("\n");
	return 0;
}

int fifthQuest() {
	/*
		Exits the game
		Prints: Congratulations dialogue message
		Output: returns 1, user quit
	*/
	printf("Congratulations! You finished the quest and managed to defeat Thanos\n");
	return 1;
}
