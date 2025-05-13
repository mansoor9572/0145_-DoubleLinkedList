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