// 4NIMBelakang_DoubleLinkList
#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedlist
struct Node
{
    // deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    
    // deklarasi pointer next dan prev untuk penunjukan data sebelum dan sesudah
    Node *next;
    Node *prev;
};

// deklarasi pointer START dan pemberian nilai
Node *START = NULL;