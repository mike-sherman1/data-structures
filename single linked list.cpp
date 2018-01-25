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

void createList(int n) {
	int i;
	node *newNode;
	node *temp;
	for (i = 0; i < n; i++) {
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
			temp = temp->next;
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
		temp = temp->next;
	}
	
	return result;
}

int countNode2() {
	int ctr;
	node *X = start;
	for (ctr = 1; X != NULL; ctr++)
	{
		X = X->next
	}
	return ctr;
}

int countNode3() {
	int ctr;
	node *X = start;
	for (ctr = 1; X->next != NULL; ctr++)
	{
		X = X->next
	}
	return ctr;
}

void deleteAtMid() {
	int ctr = 1;
	int pos, nodeCtr;
	node *temp, *prev;
	if (start == NULL) {
		cout << "Empty list.\n";
		return;
	}
	else {
		cout << "Enter position of the node you wish to delete: ";
		cin >> pos;
		nodeCtr = countNode();
		if (pos > 1 && pos < nodeCtr) {
			temp = prev = start;
			while (ctr < pos) {
				prev = temp;
				temp = temp->next;
				ctr++;
			}//end while
			prev->next = temp->next;
			free(temp);
			cout << "Node deleted.\n";
		}//end if
		else {
			cout << "Invalid position.\nIt may be out of the bounds of the list or not in the middle.\n";
		}//end else
	}//end else
}

void insertAtMid() {
	node *newNode, *temp, *prev;
	int pos, nodeCtr;
	int ctr = 1;
	newNode = getNode();
	cout << "Enter the position where you would like to insert the node: ";
	cin >> pos;
	nodeCtr = countNode();
	if (pos > 1 && pos < nodeCtr) {
		temp = prev = start;
		while (ctr < pos) {
			prev = temp;
			temp = temp->next;
			ctr++;
		}//end while
		prev->next = newNode;
		newNode->next = temp;
	}
	else {
		cout << "Invalid position.\nIt may be out of the bounds of the list or not in the middle.\n";
	}

}

int main()
{
	bool exit = false;
	int choice, n;
	while (exit == false) {
		system("CLS");
		cout << "Number of nodes: " << countNode() << "\n";
		cout << "Number of nodes 2: " << countNode2() << endl;
		cout << "Number of nodes 3: " << countNode3() << "\n";
		cout << "What would you like to do?\n"
			<< "--------------------------------\n"
			<< "1. Create a new list\n"
			<< "2. Display list\n"
			<< "3. Delete a node from the middle\n"
			<< "4. Insert a node into the middle\n"
			<< "5. Exit program\n"
			<< "--------------------------------\n"
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
			deleteAtMid();
			system("pause");
			break;
		case 4:
			insertAtMid();
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









