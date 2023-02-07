// Name: Qichen Wang
// USC NetID: qichenwa
// CSCI 455 PA5
// Fall 2022


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

int* listSearch(ListType list, const std::string & target) {
   Node* current = list;
   while (current != NULL) {
      if (current -> key == target) {
         return & (current -> value);
      }
      current = current -> next;
   }
   return NULL;
}

bool listAppend(ListType & list, const std::string & theKey, int theValue) {
   if (list == NULL) {
      list = new Node(theKey, theValue);
      return true;
   }
   if (listSearch(list, theKey) != NULL) {
      return false;
   }
   Node* last = list;
   while (last -> next != NULL) {
      last = last -> next;
   }
   last -> next = new Node(theKey, theValue);
   return true;
}

bool listRemove(ListType & list, const std::string & target) {
   if (list == NULL) {
      return false;
   }
   Node* current = list;
   if (current -> key == target) {
      Node* unwanted = list;
      list = list -> next;
      delete unwanted;
      return true;
   }
   current = list -> next;
   Node* previous = list;
   while (current != NULL) {
      if (current -> key == target) {
         previous -> next = current -> next;
         delete current;
         return true;
      }
      previous = current;
      current = current -> next;
   }
   return false;
}

void printList(ListType list) {
   Node* current = list;
   while (current != NULL) {
      cout << current -> key << " " << current -> value << endl;
      current = current -> next;
   }
}