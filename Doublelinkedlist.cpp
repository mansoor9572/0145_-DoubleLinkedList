#include <iostream>
using namespace std;

// Define a structure for a node in a doubly linked list
struct Node
{
    // Declare noMhs and name to store student data
    int noMhs;
    string name;

    // Declare next and prev pointers to point to the next and previous nodes
    Node *next;
    Node *prev;
};
// Declare a pointer named START and initialize it to NULL
Node *START = NULL;
// Procedure to add a new node to the list
void addNode()
{
    // Create a new node
    Node* newNode = new Node();

    // Input student roll number and name
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;
     // If list is empty or the new roll number should be at the beginning
    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // If the list is not empty and the roll number already exists
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers are not allowed\033[0m" << endl;
            return;
        }

        // Insert the new node at the beginning
        newNode->next = START;

        if (START != NULL)
        {
            START->prev = newNode;
        }

        START = newNode;
        return;
    }

    // You can continue the rest of the insertion logic here...
}

