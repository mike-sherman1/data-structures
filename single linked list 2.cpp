#include <stddef.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

struct slinklist {
	int data;
	struct slinklist* next;
	struct slinklist* start;
};

typedef struct slinklist node;

node *start = NULL;

node *getNode() {
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	cout << "Enter data: ";
	int temp;
	cin >> temp;
	newNode->data = temp;
	newNode->next = NULL;
	return newNode;
}

void display() {
	node *temp;
	temp = start;
	cout << "The contents of your queue from left to right:\n";
	if (start == NULL) {
		cout << "Empty list.";
	}
	else {
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}// end while
		cout << endl;
	}
}

int mainMenu() {
	int choice;
	cout << "What would you like to do?\n"
		<< "--------------------------------------\n"
		<< "1. Enqueue (insert element at the end)\n"
		<< "2. Dequeue (delete element from start)\n"
		<< "3. Display queue\n"
		<< "4. Exit program\n"
		<< "--------------------------------------\n"
		<< "Enter choice: ";
	cin >> choice;
	return choice;
}

void enqueue() {
	node *newNode, *temp;
	newNode = getNode();
	if (start == NULL) {
		start = newNode;
	}
	else {
		temp = start;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	cout << "Data added.\n";
}

void dequeue() {
	node *temp;
	if (start == NULL) {
		cout << "Empty queue.\n";
	}
	else {
		temp = start;
		cout << "The first element, " << temp->data << ", has been deleted.\n";
		start = temp->next;
		free(temp);
	}
}

int main()
{
	int choice;
	while (1) {
		system("CLS");
		choice = mainMenu();
		switch (choice) {
		case 1:
			enqueue();
			system("pause");
			break;
		case 2:
			dequeue();
			system("pause");
			break;
		case 3:
			display();
			system("pause");
			break;
		case 4:
			return 0;
		default:
			cout << "Invalid choice. Enter a number from 1 to 4.\n";
			system("pause");
		}//end switch
	}
}









