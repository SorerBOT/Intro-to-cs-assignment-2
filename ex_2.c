#include<stdio.h>

int scanNumberVerbose();
int isPrime(int number);
int playGame();
int validateQuestNumber(int chosenQuestNumber);
void printError(int numRequired);
int firstQuest();
int secondQuest();
int thirdQuest();
int fourthQuest();
int fifthQuest();

int main() {
	int hasUserQuit = 0;
	while (!hasUserQuit) hasUserQuit = playGame();
	return 0;
}
int isPrime(int number) {
	if (number == 2) return 1;
	if (number % 2 == 0) return 0;
	for (int i = 3; i <= number/2; i += 2) {
		if (number % i == 0) return 0;
	}

	return 1;
}
int scanNumberVerbose() {
	int number;
	printf("Enter a number: ");
	scanf("%d", &number);

	return number;
}
int playGame() {
	int chosenQuestNumber;
	printf("Welcome to Thanos's playground.\n");
	printf("Choose your adventure:\n");
	printf("1. Revealing the Hidden Code\n");
	printf("2. Thanos' numeric mayhem\n");
	printf("3. Thanos' Maze System\n");
	printf("4. The Sorcery of Thanos\n");
	printf("5. Quit the quest\n");
	printf("\n");
	scanf("%d", &chosenQuestNumber);

	if (!validateQuestNumber(chosenQuestNumber)) return 0;
	if (chosenQuestNumber == 1) return firstQuest();
	if (chosenQuestNumber == 2) return secondQuest();
	if (chosenQuestNumber == 3) return thirdQuest();
	if (chosenQuestNumber == 4) return fourthQuest();
	if (chosenQuestNumber == 5) return fifthQuest();
	return 0;
}

int validateQuestNumber(int chosenQuestNumber) {
	if (chosenQuestNumber < 1 || chosenQuestNumber > 5) {
		printf("Thanos is mad! You are playing his game and this is not an option. Choose again, wisely.\n");
		printf("\n");
		return 0;
	}
	return 1;
}
void printError(int numRequired) {
	printf("Foolish mortal! You cannot solve Thanos's quest with an input that isn't a number bigger than %d\n", numRequired);
	printf("\n");
}
int firstQuest() {
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
	int n = scanNumberVerbose();
	if (n <= 0) {
		printError(0);
		return 0;
	}
	int current = 1, previous = 0;
	
	for (int i = 1; i <= n; i++) {
		printf("%d", previous);
		current += previous;
		previous = current - previous;
		if (i == n) printf("\n");
		else printf(" ");
	}
	printf("\n");
	return 0;
}

int thirdQuest() {
	int n = scanNumberVerbose();
	if (n <= 1) {
		printError(1);
		return 0;
	}
	
	int sum = 0;
	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) sum += i;
	}
	printf("%d\n", sum);
	printf("\n");
	return 0;
}

int fourthQuest() {
	int n = scanNumberVerbose();
	if (n <= 0) {
		printError(0);
		return 0;
	}
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) sum += i;
	}

	if (sum == n) printf("Perfect!\n");
	else printf("Not Perfect!\n");
	
	printf("\n");
	return 0;
}

int fifthQuest() {
	printf("Congratulations! You finished the quest and managed to defeat Thanos\n");
	return 1;
}
