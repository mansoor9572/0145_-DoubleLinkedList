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

    // Node to be deleted is the first node
    if (current == START) {
        START = START->next;

        if (START != NULL)
            START->prev = NULL;
    } else {
        // Node to be deleted is not the first node
        previous->next = current->next;

        // If there is a successor, update its prev pointer
        if (current->next != NULL)
            current->next->prev = previous;
    }

    // Release the memory of the node to be deleted
    delete current;
    cout << "\033[32mRecord with roll number " << rollNo << " deleted\033[0m" << endl;
}
// Procedure to traverse and display the list in ascending order
void traverse() {
    if (listEmpty()) {
        cout << "\nList is empty\n";
        return;
    }

    cout << "\nRecords in ascending order of roll number:\n";
    Node* current = START;

    while (current != NULL) {
        cout << current->noMhs << " " << current->name << endl;
        current = current->next; // Move forward
    }
}
// Procedure to traverse and display the list in descending order
void reverseTraverse() {
    if (listEmpty()) {
        cout << "\nList is empty\n";
        return;
    }

    cout << "\nRecords in descending order of roll number:\n";

    // Move to the last node
    Node* current = START;
    while (current->next != NULL)
        current = current->next;

    // Traverse backward
    while (current != NULL) {
        cout << current->noMhs << " " << current->name << endl;
        current = current->prev;
    }
}
// Procedure to search and display student data by roll number
void searchData() {
    if (listEmpty()) {
        cout << "\nList is empty\n";
        return;
    }

    int num;
    Node *prev, *curr;
    prev = curr = NULL;

    cout << "\nEnter the roll number of the student whose record you want to search: ";
    cin >> num;

    if (!search(num, &prev, &curr)) {
        cout << "\nRecord not found\n";
    } else {
        cout << "\nRecord found:\n";
        cout << "Roll number: " << curr->noMhs << endl;
        cout << "Name: " << curr->name << endl;
    }
}
// Main function for menu-driven program
int main() {
    // Loop continues until user exits
    while (true) {
        try {
            cout << "\nMenu\n";
            cout << "1. Add a record to the list\n";
            cout << "2. Delete a record from the list\n";
            cout << "3. View all records in ascending order\n";
            cout << "4. View all records in descending order\n";
            cout << "5. Search for a record in the list\n";
            cout << "6. Exit\n";
            cout << "Enter your choice (1-6): ";

            char ch;
            cin >> ch;

            switch (ch) {
                case '1':
                    addNode();
                    break;
                case '2':
                    deleteNode();
                    break;
                case '3':
                    traverse();
                    break;
                case '4':
                    reverseTraverse();
                    break;
                case '5':
                    searchData();
                    break;
                case '6':
                    return 0;
                default:
                    cout << "\nInvalid option. Please choose between 1 and 6.\n";
            }
        } catch (exception& e) {
            cout << "An error occurred. Please check the values you entered.\n";
        }
    }
    
}