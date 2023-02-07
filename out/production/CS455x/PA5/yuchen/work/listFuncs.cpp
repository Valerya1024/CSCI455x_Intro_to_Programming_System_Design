// Name: Yuchen Peng
// USC NetID: yuchenpe
// CSCI 455 PA5
// Fall 2022

// listFuncs.cpp  linked list functions implementation


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

bool insertNode(ListType & list, const std::string &key, int value) {
   if (!list) {   // empty list
      list = new Node(key, value);
      return true;
   }
   
   ListType p;
   
   for (p = list ; p->next ; p = p->next) {
      // current Node has the same key
      if (p->key == key) { return false; }
   }
   
   if (p->key == key) {   // last Node
      return false;
   }
   else {   // no Nodes with same key
      p->next = new Node(key, value);
      return true;
   }
}


int *lookupKey(ListType list, const std::string &key) {
   for (ListType p = list ; p ; p = p->next) {
      if (p->key == key) { return &p->value; }   // present
   }
   return NULL;   // NOT present
}


bool listRemove(ListType & list, const std::string &key) {
   if (!list) { return false; }   // empty list
   
   ListType p = list;
   
   if (p->key == key) {   // list has only 1 Node
      list = list->next;
      delete p;
      return true;
   }
   
   // list has 2+ Nodes, check the next Node to the current
   for ( ; p->next ; p = p->next) {
      if (p->next->key == key) {
         ListType temp = p->next;
         p->next = p->next->next;
         delete temp;
         return true;
      }
   }
   
   return false;   // NOT present
}


void printList(ListType list) {
   for (ListType p = list ; p ; p = p->next) {
      cout << p->key << " " << p->value << endl;
   }
}


int listLength(ListType list) {
   int length = 0;
   for (ListType p = list ; p ; p = p->next) {
      ++length;
   }
   return length;
}