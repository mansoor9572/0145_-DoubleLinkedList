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
    Node *newNode = new Node();

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
    else
    {
        // Insert the new node in the middle or at the end
        Node *current = START;   // Start from the first node
        Node *previuos = NULL;   // Previous node is NULL

        // Loop through the list to find the correct position
        while (current != NULL && current->noMhs < newNode->noMhs)
        {
            previuos = current;      // Move previous to current node
            current = current->next; // Move current to the next node
        }

        newNode->next = current;      // Set the next pointer of the new node
        newNode->prev = previuos;     // Set the previous pointer of the new node

        // If current is not NULL, update its previous pointer
        if (current != NULL)
        {
            current->prev = newNode;
        }

        if (previuos != NULL)
        {
            previuos->next = newNode; // Link previous to new node
        }
        else
        {
            // If previous is still null, newNode is the first node
            START = newNode;
        }
    }
}

// Function to search for a node by roll number
bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;     // Initialize previous to NULL
    *current = START;     // Start from the beginning of the list

    // Traverse the list until roll number is found or end of list is reached
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;        // Move previous to current
        *current = (*current)->next; // Move current to the next node
    }

    return (*current != NULL);       // Return true if roll number is found
}

// Procedure to delete a node by roll number
void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START;
    previous = NULL;

    // Locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
        return;
    }

    // Node to be deleted is the first node
    if (current == START)
    {
        START = START->next;
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {
        // Node to be deleted is not the first node
        previous->next = current->next;

        // If there is a successor, update its prev pointer
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
    }

    // Release the memory of the node to be deleted
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\033[0m" << endl;
}

// Method to check whether the list is empty
bool listEmpty()
{
    return (START == NULL);
}

// Procedure to traverse and display the list
void travers()
{
    if (listEmpty())
    {
        cout << "\nList is empty" << endl;
    }
    else
    {
        cout << "\nRecords in ascending order of roll number are:" << endl;
        Node *currentNode = START;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->next; // Use ->next to move forward
        }
    }
}
