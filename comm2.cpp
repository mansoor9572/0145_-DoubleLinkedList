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
//declartion prosedur oddnode
void addNode()
{
    Node* newNode = new Node ();
    COUT<< "\, ENTER  the rool number of the student :";
    cin>> newNode->noMhs;
    cout<<"\n enter the name of the student :";
    cin>>newNode->name;
      
    if (START==Null || newNode->noMhs<= START->noMhs)
    {
        //step 2 input the new node at the beggining 
        // kondid=si jika staar tidak kosong dan noMhs node baru sama dengan 
        if (START!=Null || newNode->noMhs<= START->noMhs)
        {
            cout<<"\033[31mDuplicate rool numbers not allowed\033[0m"<<endl;
            return;
        }
        
        newNode->next = START;

        if (START != Null)
        {
            START->prev= newNode; //step 4 make the first node point to the 

        }
    }  
}