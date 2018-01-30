//#include <stddef.h>
//#include <stdlib.h>
#include <iostream>
#define MAX 6

using namespace std;

int queue[MAX];
int front = 0;
int rear = 0;

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

void display() {
	cout << "The contents of your queue from left to right:\n";
	if (rear == 0) {
		cout << "Your queue is empty.";
	}
	else {
		for (int i = front; i < rear; i++) {
			cout << queue[i] << " ";
		}
		cout << endl;
	}
}

void enqueue() {
	int data;
	if (rear == MAX) {
		cout << "Queue overflow; no more elements can be added.\n";
		return;
	}
	else {
		cin.clear();
		cout << "Enter data: ";
		cin >> data;
		queue[rear] = data;
		rear++;
		cout << "Data added.\n";
	}
}

void dequeue() {
	if (rear == 0) {
		cout << "Your queue is empty.";
	}
	else {
		cout << "The first element, " << queue[front] << ", has been deleted.\n";
		queue[front] = 0;
		front++;
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









