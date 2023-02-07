/*  Name: Qichen Wang
 *  USC NetID: qichenwa
 *  CS 455 Fall 2022
 *
 *  See ecListFuncs.h for specification of each function.
 */

#include <string>
#include <cassert>

#include "ecListFuncs.h"

using namespace std;

// *********************************************************
// Node constructors: do not change
Node::Node(int item) { 
   data = item;
   next = NULL;
}

Node::Node(int item, Node *n) {
   data = item;
   next = n;
}
// *********************************************************


int numAdjDupes(ListType list) {
   
   int count = 0;
   if (list == NULL) {
      return count;
   }
   Node* curr = list;
   Node* prev = NULL;
   while (curr -> next != NULL) {
      if ((prev == NULL || prev -> data != curr -> data) && curr -> data == curr -> next -> data) {
         count++;
      }
      prev = curr;
      curr = curr -> next;
   }
   return count;
   
}



void removeDiv(ListType & list, int k) {
   
   while (list != NULL && list -> data % k == 0) {
      Node* unwanted = list;
      list = list -> next;
      delete unwanted;
   }
   if (list == NULL) {
      return;
   }
   Node* curr = list;
   while (curr -> next != NULL) { // The first node of the list now cannot have data divisible by k.
      if (curr -> next -> data % k == 0) {
         Node* unwanted = curr -> next;
         curr -> next = curr -> next -> next;
         delete unwanted;
      }
      else {
         curr = curr -> next;
      }
   }
   
}



void splitAtLoc(ListType &list, int index, ListType &a, ListType &b) {

   a = NULL;
   b = NULL;
   if (index < 0) {
      b = list;
      list = NULL;
      return;
   }
   if (list == NULL) {
      return;
   }
   Node* unwanted = list;
   int i = 0;
   Node* prev = NULL;
   while (unwanted != NULL && i < index) {
      prev = unwanted;
      unwanted = unwanted -> next;
      i++;
   }
   if (prev == NULL) { // unwanted points to the first node
      list = NULL;
      b = unwanted -> next;
      delete unwanted;
      return;
   }
   if (unwanted != NULL) {
      prev -> next = NULL;
      a = list;
      b = unwanted -> next;
      delete unwanted;
      list = NULL;
      return;
   }
   a = list;
   list = NULL;
   
}
/*
#include <string>
#include <cassert>

#include "ecListFuncs.h"

using namespace std;

// *********************************************************
// Node constructors: do not change
Node::Node(int item) {
   data = item;
   next = NULL;
}

Node::Node(int item, Node *n) {
   data = item;
   next = n;
}
// *********************************************************


int numAdjDupes(ListType list) {
   int numAd = 0;
   bool ad = false;
   if (!list) {
      return numAd;
   }
   while (list->next) {
      if (list->data == list->next->data) {
         if (!ad) {
            numAd += 1;
            ad = true;
         }
      } else {
         ad = false;
      }
      list = list->next;
   }
   return numAd;
}

void removeDiv(ListType & list, int k) {
   while (list && list->data % k == 0) {
      list = list->next;
   }
   if (!list) {
      return;
   }
   ListType next = list->next;
   ListType prev = list;
   while(next!=NULL) {
      if (next->data % k == 0) {
         prev->next = next->next;
         delete next;
         next = prev->next;
      } else {
         prev = prev->next;
         next = next->next;
      }
   }
}



void splitAtLoc(ListType &list, int index, ListType &a, ListType &b) {
   if (!list) {
      return;
   }
   if (index == 0) {
      b = list->next;
      delete list;
      list = nullptr;
      return;
   } else if (index < 0){
      b = list;
      list = nullptr;
      return;
   }
   int idx = 1;
   a = list;
   while (list->next && idx < index) {
      idx++;
      list = list->next;
   }
   ListType node = list->next;
   if (node) {
      b = node->next;
      delete node;
   } else {
      b = nullptr;
   }
   list->next = nullptr;
   list = list->next;

}*/



