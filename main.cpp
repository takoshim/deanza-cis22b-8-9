/*
  Student is a class
 
 This program demonstrates the insertNode, deleteNode, getCount(), and displayList member functions.
 It builds and displays a sorted list
 The list is sorted by name
 
 Write a function that displays the name and gpa for students with n-letter names. 
 
 list.displayList(3);  //<===== see line# 47
  
 Run the program once and save the output as a comment at the end of this source file.
 
 Modified by: Takeo Shimazu
 IDE: Takeo Shimazu
 
 */
#include <iostream>
#include "StudentList.h"
using namespace std;

int main()
{
    // Define a StudentList object.
    StudentList list;
    Student s[] = {{2.5, "Paul"}, {3.9, "Katie"}, {3.6, "Bill"}, {2.7, "Ann"}, {3.9, "Tina"}, {3.2, "Andy"}, {0, ""}};
    
    //******************************
    cout << "TESTING INSERT\n";
    // Build List from array (for demonstration purposes only)
    for (int i = 0; i < 6; i++)
    {
        cout << "\tInsert " << s[i].getGpa() << " " << s[i].getName() << endl;
        list.insertNode(s[i]);
        // Display the values in the list.
        // list.displayList();
        // cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    }
    
    //******************************
    cout << "TESTING DISPLAY\n\n";
    list.displayList();
    int n; // number of letters in a studen's name
    cout << "Enter n: ";
    cin >> n;
    cout << "List of students with " << n << " letter names" << endl;
    list.displayList(n);  //<====================================
    
    //******************************
    cout << "TESTING DELETE\n\n";
    string target[] = { "Andy", "Tina", "Katie", "Tim", ""}; // names to test deleteNode with
    
    for (int i = 0; target[i] != ""; i++)
    {
        if( list.deleteNode(target[i]) )
            cout << target[i] << " - Deleted!\n";
        else
            cout << target[i] << " - Not found\n";
    }
    list.displayList();
    
    cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    
    return 0;
}
