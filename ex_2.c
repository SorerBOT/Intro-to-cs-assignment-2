#include<stdio.h>

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

int playGame() {
	int chosenQuestNumber;
	printf("Welcome to Thanos's playground.\n");
	printf("Choose your adventure:\n");
	printf("1. Revealing the Hidden Code\n");
	printf("2. Thanos' numeric mayhem\n");
	printf("3. Thanos' Maze System\n");
	printf("4. The Sorcery of Thanos\n");
	printf("5. Quit the quest\n");

	scanf("%d", &chosenQuestNumber);

	if (!validateQuestNumber(chosenQuestNumber)) return 0;
	if (chosenQuestNumber == 1) return firstQuest();
	return 0;
}

int validateQuestNumber(int chosenQuestNumber) {
	if (chosenQuestNumber < 1 || chosenQuestNumber > 5) {
		printf("Thanos is mad! You are playing his game and this is not an option. Choose again, wisely\n");
		return 0;
	}
	return 1;
}
void printError(int numRequired) {
	printf("Foolish mortal! You cannot solve Thanos's quest with an input that isn't a number bigger than %d\n", numRequired);
}
int firstQuest() {
	int number;
	printf("Enter a number: ");
	scanf("%d", &number);
	
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
	return 0;
}
