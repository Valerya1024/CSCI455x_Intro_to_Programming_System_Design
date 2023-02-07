// Name: Xinyu Wu
// USC NetID: xwu26173
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

// remove a key value pair from a linked list given its key
// return false iff key wasn't present
//         (and no change made to table)
// Param list: target linked list
// Param target: key string to be removed
bool listRemove(ListType & list, const std::string & target);
// insert a new key value pair into the linked list
// return false if this key was already present
//         (and no change made to table)
// Param list: target linked list
// Param key: key string to be inserted
// Param value: value to be inserted
bool listInsert(ListType & list, const std::string & key, const int value);
// returns the address of the value that goes with this key
//    or NULL if key is not present.
// Param list: target linked list
// Param target: target key string
int * listLookUp(ListType list, const std::string & target);
// print out all the entries in the linked list, one key value pair per line,
//    separated by a space.
// Param list: target linked list
void listPrintAll(ListType list);
// Iterate through a linked list and return the length if the linked list
// Param list: target linked list
// Return: length of the linked list
int listLength(ListType list);







// keep the following line at the end of the file
#endif
