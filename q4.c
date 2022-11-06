#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

#define DATE 11
#define LOTTOERY_NUMBER 5
#define MAX_LENGTH 200


typedef struct lotto {
	int lottery;
	char date[DATE];
	struct lotto* next;
	struct lotto* prev;
}lotto;

lotto* head = NULL, * tail = NULL;

int initList();
void addToList(lotto*);
void getDate(int);
void freeList();

int main()
{
	int res = 0, lotteryNumber = 0;
	char userResponse = 0;
	res = initList();
	while(userResponse != 'Q')
	{
		printf("Please pick one of the options:\n1.N - show the date of the lottery\n2.Q - Quit\n");
		scanf(" %c", &userResponse);
		switch (userResponse)
		{
		case 'N':
			printf("Please enter lottery number: ");
			scanf("%d", &lotteryNumber);
			getDate(lotteryNumber);
			break;
		case 'Q': 
			freeList();
			printf("Thanks and good-bye");
			break;
		default:
			printf("No such option");
			break;
		}
	}
}

int initList() {
	lotto* newNode;
	char str[MAX_LENGTH], *token;
	FILE* f = fopen("Lotto.csv", "r");
	if (!f)
	{
		return 1;
	}
	fgets(str, MAX_LENGTH, f);
	while (fgets(str, MAX_LENGTH, f))
	{
		newNode = (lotto*)malloc(sizeof(lotto));
		if (!newNode)
		{
			printf("Allocation Error");
			return 1;
		}
		newNode->next = newNode->prev = NULL;
		token = strtok(str, ",");
		newNode->lottery = atoi(token);
		token = strtok(NULL, ",");
		strcpy(newNode->date, token);
		addToList(newNode);
	}
	fclose(f);
	return 1;
}

void getDate(int lotteryNumber)
{
	lotto* curr = head;
	while (curr)
	{
		if (curr->lottery == lotteryNumber)
		{
			printf("The date was %s\n", curr->date);
			return;
		}
		curr = curr->next;
	}
	printf("No such lottery number\n");
	return;
}

void freeList()
{
	lotto* curr = head;
	while (head)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}

void addToList(lotto* node)
{
	if (!head)
	{
		head = tail = node;
	}
	else
	{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}