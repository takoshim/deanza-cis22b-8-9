// Implementation file for the Student List class
// Modified by: Takeo Shimazu
// IDE: Visual Studio Code

#include <iostream>         // For cout  and NULL
#include "StudentList.h"
using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
StudentList::StudentList()
{
    head = new ListNode; // head points to the sentinel node
    head->stu.setGpa(-1);
    head->stu.setName("");
    head->next = NULL;
    count = 0;
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.
//**************************************************
void StudentList::displayList() const
{
    ListNode *pCur = head->next;
    while (pCur) {
        cout << pCur->stu.getGpa() << " " << pCur->stu.getName() << endl;
        pCur = pCur->next;
    }
    cout << endl;
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// if the length of name of a node matches the
// passed int value. If none is found display "None!"
//**************************************************
void StudentList::displayList(size_t n) const
{
    ListNode *pCur = head->next;
    int counter {0};

    while (pCur)
    {
        if (pCur->stu.getName().length() == n)
        {
            cout << pCur->stu.getGpa() << " " << pCur->stu.getName() << endl;
            counter++;
        }
        pCur = pCur->next;
    }
    if (!counter)
    {
        cout << "None!";
    }
    cout << endl;
}

//**************************************************
// The insertNode function inserts a node with
// stu copied to its value member.
//**************************************************
void StudentList::insertNode(Student dataIn)
{
    ListNode *pNew = new ListNode;
    pNew->stu = dataIn;
    ListNode *pPre = head;
    ListNode *pCur = head->next;

    while (pCur != NULL && pCur->stu.getName() < dataIn.getName())
    {
        pCur = pCur->next;
        pPre = pPre->next;
    }
    pPre->next = pNew;
    pNew->next = pCur;

    count++;
}

//**************************************************
// The deleteNode function searches for a node
// with num as its value. The node, if found, is
// deleted from the list and from memory.
//**************************************************
bool StudentList::deleteNode(string target)
{
    ListNode *pCur = head->next;       // To traverse the list
    ListNode *pPre = head;        // To point to the previous node
    bool deleted = false;

    while (pCur != NULL && pCur->stu.getName() != target)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pCur != NULL && pCur->stu.getName() == target)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        count--;
    }
    return deleted;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
StudentList::~StudentList()
{
    ListNode *pCur;   // To traverse the list
    ListNode *pNext;  // To point to the next node
    
    // Position nodePtr at the head of the list.
    pCur = head->next;
    
    // While pCur is not at the end of the list...
    while (pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;
        
        // Delete the current node.
        cout << "DEBUG - Destructor: Now deleting " << pCur->stu.getName() << endl;
        delete pCur;
        
        // Position pCur at the next node.
        pCur = pNext;
    }
    cout << "DEBUG - Destructor: Now deleting the sentinel node gpa = " << head->stu.getGpa() << endl;
    delete head; // delete the sentinel node
}
