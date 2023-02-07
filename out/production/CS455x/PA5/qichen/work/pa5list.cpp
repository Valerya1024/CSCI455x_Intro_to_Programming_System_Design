// Name: Qichen Wang
// USC NetID: qichenwa
// CS 455 PA5
// Fall 2022

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

void testAppend(Node* & list, string aKey, int aValue) {
   cout << "Append " << aKey << " and " << aValue << " to the list. " << endl;
   bool outcome = listAppend(list, aKey, aValue);
   cout << "Successful? " << outcome << endl;
   cout << "Current list: " << endl;
   printList(list);
   cout << endl;
}

void testSearch(Node* & list, string target) {
   cout << "Search for " << target << " in the list. " << endl;
   int* valuePtr = listSearch(list, target);
   if (valuePtr == NULL) {
      cout << "Target not found. " << endl;
   }
   else {
      cout << "The value is " << *valuePtr << endl;
   }
   cout << endl;
}

void testRemove(Node* & list, string target) {
   cout << "Try to remove " << target << " from the list" << endl;
   bool outcome = listRemove(list, target);
   cout << "Successful? " << outcome << endl;
   cout << "Current list: " << endl;
   printList(list);
   cout << endl;
}

int main() {
   
   Node* myList = NULL;
   testAppend(myList, "apple", 1);
   testAppend(myList, "banana", 2);
   testAppend(myList, "cranberry", 3);
   testAppend(myList, "date", 4);
   testAppend(myList, "apple", 1);
   testAppend(myList, "banana", 5);
   
   testSearch(myList, "apple");
   testSearch(myList, "cranberry");
   testSearch(myList, "orange");
   cout << "Current list: " << endl;
   printList(myList);
   cout << endl;
   
   testRemove(myList, "orange");
   testRemove(myList, "date");
   testRemove(myList, "apple");
   
   Node* myList2 = NULL;
   testSearch(myList2, "apple");
   testRemove(myList2, "apple");
   
   testAppend(myList2, "apple", 1);
   testSearch(myList2, "apple");
   testSearch(myList2, "orange");
   testRemove(myList2, "orange");
   testRemove(myList2, "apple");

   return 0;
}
