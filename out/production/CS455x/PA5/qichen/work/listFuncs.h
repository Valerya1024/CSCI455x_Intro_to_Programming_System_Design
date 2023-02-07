// Name: Qichen Wang
// USC NetID: qichenwa
// CSCI 455 PA5
// Fall 2022


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


// Search for a key in a given list. Returns a reference to the value, or NULL if the key is not present.
int* listSearch(ListType list, const std::string & target);

// Add a key and a corresponding value to the end of the list. If the value is present, does not perform the insertion and
// returns false. 
bool listAppend(ListType & list, const std::string & theKey, int theValue);

// Remove a key from the list. If the key is present, returns true; If not, make no changes to the list and returns false.
bool listRemove(ListType & list, const std::string & target);

// Prints the key and the value of every node in the list, one per line.
void printList(ListType list);


// keep the following line at the end of the file
#endif
