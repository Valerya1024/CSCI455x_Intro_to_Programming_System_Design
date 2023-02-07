/*  Name: Xinyu Wu
 *  USC NetID: xwu26173
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

}

