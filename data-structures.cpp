#include <stddef.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//TO DO: combine all into one program, add comments
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