#include <stddef.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

node* start = NULL;

node* setNode() {
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	cout << "Enter data: ";
	int temp;
	cin >> temp;
	newNode->data = temp;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void createList(int n) {
	int i;
	node *newNode;
	node *temp;
	for (i = 0; i < n; i++) {
		newNode = setNode();
		if (start == NULL) {
			start = newNode;
		}
		else {
			temp = start;
			while (temp->right)
				temp = temp->right;
			temp->right = newNode;
			newNode->left = temp;
		}
	} 
}

void displayList() {
	node *temp;
	temp = start;
	cout << "The contents of your list from left to right:\n";
	if (start == NULL) {
		cout << "Empty list.";
	}
	else {
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->right;
		}// end while
		cout << endl;
		system("pause");
	}
}

int countNode() {
	node *temp = start;
	int result = 0;
	
	while (temp != NULL) {
		result += 1;
		temp = temp->right;
	}
	
	return result;
}

void deleteAtEnd() {
	node *temp;
	if (start == NULL) {
		cout << "Empty list.\n";
	}
	else {
		temp = start;
		while (temp->right) {
			temp = temp->right;
		}
		temp->left->right = NULL;
		free(temp);
	}
}

void insertAtBeginning() {
	node *newNode;
	newNode = setNode();
	if (start == NULL) {
		start = newNode;
	}
	else {
		newNode->right = start;
		start->left = newNode;
		start = newNode;
	}
}

int main()
{
	bool exit = false;
	int choice, n;
	while (exit == false) {
		system("CLS");
		cout << "What would you like to do?\n"
			<< "---------------------------------\n"
			<< "1. Create a new list\n"
			<< "2. Display list\n"
			<< "3. Delete a node from the end\n"
			<< "4. Insert a node in the beginning\n"
			<< "5. Exit program\n"
			<< "---------------------------------\n"
			<< "Enter choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "How many items in your list? ";
			cin >> n;
			createList(n);
			cout << "Your list has been created.\n";
			system("pause");
			break;
		case 2:
			displayList();
			break;
		case 3:
			deleteAtEnd();
			system("pause");
			break;
		case 4:
			insertAtBeginning();
			system("pause");
			break;
		case 5:
			exit = true;
			break;
		default:
			cout << "Invalid choice. Enter a number from 1 to 5.\n";
			system("pause");
		}//end switch
	}//end main while
	return 0;
}









