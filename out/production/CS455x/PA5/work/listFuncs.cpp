// Name: Xinyu Wu
// USC NetID: xwu26173
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

int * listLookUp(ListType list, const string & target) {
   while(list != NULL) {
      if (list->key == target) {
         return & list->value;
      }
      list = list->next;
   }
   return NULL;
}


bool listRemove(ListType & list, const string & target) {
   if (list->key == target) {
      list = list->next;
      return true;
   }
   Node * temp1 = list->next;
   Node * temp2 = list;
   while(temp1!=NULL) {
      if (temp1->key == target) {
         temp2->next = temp1->next;
         delete temp1;
         return true;
      }
      temp1 = temp1->next;
      temp2 = temp2->next;
   }
   return false;
}

bool listInsert(ListType & list, const string & key, const int value) {
   Node * temp = list;
   while(temp != NULL) {
      if (temp->key == key) {
         return false;
      }
      temp = temp->next;
   }
   Node * newNode = new Node(key, value, list);
   list = newNode;
   return true;
}

void listPrintAll(ListType list) {
   while(list!=NULL) {
      cout << list->key << " " << list->value;
      list = list->next;
   }
   cout << endl;
}

int listLength(ListType list) {
   int len = 0;
   while(list!=NULL) {
      len++;
      list = list->next;
   }
   return len;
}