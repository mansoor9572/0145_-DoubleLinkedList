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
// Method to check whether the list is empty
bool listEmpty() {
    return (START == NULL);
}

// Function to search for a node by roll number
bool search(int rollNo, Node** previous, Node** current) {
    *previous = NULL;     // Initialize previous to NULL
    *current = START;     // Start from the beginning of the list

    // Traverse the list until roll number is found or end of list is reached
    while (*current != NULL && (*current)->noMhs != rollNo) {
        *previous = *current;        // Move previous to current
        *current = (*current)->next; // Move current to the next node
    }

    return (*current != NULL);       // Return true if roll number is found
}
// Procedure to add a new node to the list
void addNode() {
    // Create a new node
    Node* newNode = new Node();

    // Input student roll number and name
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;

    // Validate roll number input
    if (cin.fail()) {
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid roll number input.\n";
        delete newNode;
        return;
    }

    cout << "Enter the name of the student: ";
    cin >> newNode->name;

    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty or the new roll number should be at the beginning
    if (START == NULL || newNode->noMhs <= START->noMhs) {
        // If the list is not empty and the roll number already exists
        if (START != NULL && newNode->noMhs == START->noMhs) {
            cout << "\033[31mDuplicate roll numbers are not allowed\033[0m" << endl;
            delete newNode;
            return;
        }

        // Insert the new node at the beginning
        newNode->next = START;

        if (START != NULL)
            START->prev = newNode;

        START = newNode;
    } else {
        // Insert the new node in the middle or at the end
        Node* current = START;   // Start from the first node
        Node* previous = NULL;   // Previous node is NULL

        // Loop through the list to find the correct position
        while (current != NULL && current->noMhs < newNode->noMhs) {
            previous = current;      // Move previous to current node
            current = current->next; // Move current to the next node
        }

        // Check for duplicate roll number
        if (current != NULL && current->noMhs == newNode->noMhs) {
            cout << "\033[31mDuplicate roll numbers are not allowed\033[0m" << endl;
            delete newNode;
            return;
        }

        // Insert the node between previous and current
        newNode->next = current;
        newNode->prev = previous;

        if (current != NULL)
            current->prev = newNode;

        if (previous != NULL)
            previous->next = newNode;
    }
}
// Procedure to delete a node by roll number
void deleteNode() {
    // If the list is empty, display message
    if (listEmpty()) {
        cout << "List is empty.\n";
        return;
    }

    int rollNo;
    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;

    Node *current = START;
    Node *previous = NULL;

    // Locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo) {
        previous = current;
        current = current->next;
    }

    // If node with given roll number is not found
    if (current == NULL) {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
        return;
    }
