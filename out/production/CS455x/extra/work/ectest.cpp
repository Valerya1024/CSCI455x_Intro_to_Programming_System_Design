/*  Name: Xinyu Wu
 *  USC NetID: xwu26173
 *  CS 455 Fall 2022
 *  Extra credit assignment
 *
 *  ectest.cpp
 *
 *  a non-interactive test program to test the functions described in ecListFuncs.h
 *
 *    to run it use the command:   ectest
 *
 *  Note: this uses separate compilation.  You put your list code ecListFuncs.cpp
 *  Code in this file should call those functions.
 */


#include <iostream>
#include <string>

// for istringstream used in buildList (defined below)
#include <sstream>

#include "ecListFuncs.h"

using namespace std;


// You may use the following two utility functions that will make it easier to
// test your list functions on hard-coded list data and compare it to expected
// output:
// (function definitions for them appear at the bottom of this file)


/*
 * listToString
 *
 * PRE: list is a well-formed list.
 *
 * converts the list to a string form that has the following format shown by example.
 * the list is unchanged by the function.
 *
 *   string format:
 *
 *   "()"        an empty list
 *   "(3)        a list with one element, 3
 *   "(3 4 5)"   a list with multiple elements: 3 followed by 4 followed by 5
 *
 */
string listToString(ListType list);


/*
 * buildList
 * 
 * PRE: listString only contains numbers (valid integer format) and spaces
 *
 * creates and returns a linked list from a string of space separated numbers
 * 
 *
 * Examples:
 *  listString         return value of buildList(listString)
 *
 *    ""               ()
 *    "-32"            (-32)
 *    "     -32   "    (-32)
 *    "1 3 2"          (1 3 2)
 *    "  1 3 2"        (1 3 2)
 *
 */
ListType buildList(const string & listString);

void numAdjDupesTester(string input, int expect);

void removeDivTester(string input, int k, string expect);

void splitAtLocTester(string input, int index, string expect1, string expect2, string expect3 );

void printList(ListType list) {
   while (list) {
      cout << list->data;
      list = list->next;
   }
   cout << endl;
}

void printLast(ListType list) {
   if (!list) {
      cout << "<empty>" << endl;
      return;
   }
   while (list->next) {
      list = list->next;
   }
   cout << list->data << endl;
}

void insertFront(ListType &list, int val) {
   //ListType node = new Node(val, list);
   ListType node = new Node(val);
   node->next = list;
   list = node;
}

void removeFront(ListType &list) {
   if (!list) {
      return;
   }
   ListType removed = list;
   list = list->next;
   delete removed;
}

void removeLast(ListType &list) {
   if (!list) {
      return;
   }
   if (!list->next) {
      ListType node = list;
      list = nullptr;
      delete node;
      return;
   }
   ListType prev = list;
   ListType node = list->next;
   while (node->next) {
      node = node->next;
      prev = prev->next;
   }
   prev->next = nullptr;
   delete node;
}

void insertLast(ListType &list, int val) {
   ListType insert = new Node(val);
   if (!list) {
      list = insert;
      return;
   }
   if (!list->next) {
      list->next = insert;
      return;
   }
   ListType node = list->next;
   while (node->next) {
      node = node->next;
   }
   node->next = insert;
}


void triSum(ListType &list) {
   if (!list) {
      return;
   }
   ListType node = list;
   ListType res = new Node(0);
   list = res;
   while (node) {
      int i = 0;
      int sum = 0;
      while (i < 3) {
         i++;
         sum += node->data;
         ListType prev = node;
         node = node->next;
         delete prev;
      }
      res->next = new Node(sum);
      res = res->next;
   }
   node = list;
   list = list->next;
   delete node;
}

void clearAfter(ListType &list) {
   ListType node = list->next;
   list->next = nullptr;
   while (node) {
      ListType rmv = node;
      node = node->next;
      delete rmv;
      cout << rmv->data;
   }
}

void tribble(ListType & list, int val) {
   Node * tmpList = list;
   list = NULL;
   Node * newOne = new Node(val);
   newOne->next = tmpList;
   tmpList = newOne;
}

int longestRepeats(ListType list) {
   if (!list) {
      return 0;
   }
   int max = 0;
   int num = 1;
   int prev = list->data;
   list = list->next;
   while (list) {
      if (prev==list->data) {
         num++;
      } else {
         prev = list->data;
         if (num > max) {
            max = num;
         }
         num = 1;
      }
      list = list->next;
   }
   if (num > max) {
      return num;
   } return max;
}

struct TreeNode {
    int key;
    TreeNode * left; // this subtree only has values < key
    TreeNode * right; // this subtree only has values > key
    TreeNode(int item) {
       key = item;
       left = nullptr;
       right = nullptr;
    }
};

void printBST(TreeNode * root) {
   if (root == NULL) {
      return;
   } else {
      printBST(root->right);
      cout << root->key << endl;
      printBST(root->left);
   }
}

void foo(ListType & list, int newVal) {
   if (list == NULL) { return; }
   while (list->next != NULL) {
      list = list->next;
   }
   list->data = newVal;
}

ListType reverse(ListType list) {
   if (!list) {
      return list;
   }
   ListType res = nullptr;
   while (list) {
      ListType tmp = new Node(list->data);
      tmp->next = res;
      res = tmp;
      list = list->next;
   }
   return res;
}

void test(string input) {
   ListType list = buildList(input);
   ListType res = reverse(list);
   printList(res);
}

int main ()
{
   //cout << longestRepeats(buildList("5 5 5 8 8 7 7 7 7")) << endl;
   //cout << longestRepeats(buildList("5 5 5 8 8 7")) << endl;
   //cout << longestRepeats(buildList("5 8 7")) << endl;
   //cout << longestRepeats(buildList("5 5 8 8 7 7")) << endl;
   //cout << longestRepeats(buildList("9 9")) << endl;
   //cout << longestRepeats(buildList("9")) << endl;
   //cout << longestRepeats(buildList("")) << endl;
   /*ListType myList = buildList("13 2 7");
   foo(myList, 100);

   printList(myList);
   return 0;*/

   /*
   TreeNode * n3 = new TreeNode(3);
   TreeNode * n2 = new TreeNode(2);
   TreeNode * n1 = new TreeNode(1);
   TreeNode * n0 = new TreeNode(0);
   n1->left = n0;
   n1->right = n2;
   n3->left = n1;
   n2 = new TreeNode(6);
   n1 = new TreeNode(5);
   n0 = new TreeNode(4);
   n1->left = n0;
   n1->right = n2;
   n3->right = n1;

   printBST(n3);
   printBST(n1);
   printBST(n0);
   printBST(nullptr);*/



   test("1 2 3 4 5 6");
   test("1 2 3");
   test("1 2");
   test("1");
   test("");
   /*
   cout << "Test numAdjDupes()" << endl;

   numAdjDupesTester("", 0);
   numAdjDupesTester("2 8 3", 0);
   numAdjDupesTester("4 4 7 3", 1);
   numAdjDupesTester("-2 -1 0 1 2 3 4 5 6", 0);
   numAdjDupesTester("-2 -2 0 0 2 2 4 4 6 6", 5);
   numAdjDupesTester("1 1 1 1 1 1 1 1 1 1 1", 1);
   numAdjDupesTester("5 5 7 5 5 5 5",2);
   numAdjDupesTester("5 7 5 7",0);
   numAdjDupesTester("5 5 5 3 3 3 4 4 4 4",3);

   cout << "Test removeDiv()" << endl;
   removeDivTester("", 3, "()");
   removeDivTester("7 10", 3, "(7 10)");
   removeDivTester("24 12 6 9", 4, "(6 9)");
   removeDivTester("24 12 6 9", 3, "()");
   removeDivTester("3 2 8 4 7", 2, "(3 7)");
   removeDivTester("1 2 3 4 5", 1, "()");
   removeDivTester("1 2 3 4 5 6 7 8 9", 2, "(1 3 5 7 9)");
   removeDivTester("-1 -2 -3 -4 -5 -6 -7 -8 -9", 3, "(-1 -2 -4 -5 -7 -8)");
   cout << "Test splitAtLoc()" << endl;
   splitAtLocTester("7 4 4 3 9", 2, "(7 4)", "(3 9)", "()");
   splitAtLocTester("7 4 2 3 9", 0, "()", "(4 2 3 9)", "()");
   splitAtLocTester("1 2 3 3 2", 4, "(1 2 3 3)", "()", "()");
   splitAtLocTester("", 3, "()", "()", "()");
   splitAtLocTester("8 2 5", 2, "(8 2)", "()", "()");
   splitAtLocTester("8 2 5", 3, "(8 2 5)", "()", "()");
   splitAtLocTester("8 2 5", -3, "()", "(8 2 5)", "()");
   splitAtLocTester("3", 0, "()", "()", "()");
   splitAtLocTester("3 5", 0, "()", "(5)", "()");
   splitAtLocTester("3 5", 1, "(3)", "()", "()");
   splitAtLocTester("1 2 3 4 5 6 7 8 9", -1, "()", "(1 2 3 4 5 6 7 8 9)", "()");
   splitAtLocTester("-3 -2 -1 0 1 2 3 4", 0, "()", "(-2 -1 0 1 2 3 4)", "()");
   splitAtLocTester("9 8 7 6 5 4 3 2 1 0", 1, "(9)", "(7 6 5 4 3 2 1 0)", "()");
   splitAtLocTester("9 8 7 6 5 4 3 2 1 0", 8, "(9 8 7 6 5 4 3 2)", "(0)", "()");
   splitAtLocTester("-3 -2 -1 0 1 2 3 4", 7, "(-3 -2 -1 0 1 2 3)", "()", "()");
   splitAtLocTester("-3 -2 -1 0 1 2 3 4", 8, "(-3 -2 -1 0 1 2 3 4)", "()", "()");*/
   return 0;
}


/*********************************************************
 * Utility function definitions
 *
 */
string listToString(ListType list) {

   string listString = "(";

   if (list == NULL) {
      listString += ")";
      return listString;
   }

   Node *p = list;
   while (p->next != NULL) {
      listString += to_string(p->data) + " ";
      p = p->next;
   }

   // print last one with no trailing space
   listString += to_string(p->data) + ")";

   return listString;

}   


ListType buildList(const string & listString) {

   ListType nums = NULL;

   istringstream istr(listString);  // similar to a Java Scanner over a String

   int num;

   if (istr >> num) { // is there one value there?
      nums = new Node(num);
   }
   else {
      return NULL;
   }

   Node *last = nums;

   while (istr >> num) { 
      last->next = new Node(num);
      last = last->next;
   }

   return nums;
}

void numAdjDupesTester(string input, int expect) {
   ListType list = buildList(input);
   int res = numAdjDupes(list);
   string pass = "FAILED";
   if (res==expect) {
      pass = "passed";
   }
   cout << "Input: " << input << " Output: " << res << " Expected: " << expect << " Pass: " << pass << endl;
}

void removeDivTester(string input, int k, string expect) {
   ListType list = buildList(input);
   removeDiv(list, k);
   string res = listToString(list);
   string pass = "FAILED";
   if (res==expect) {
      pass = "passed";
   }
   cout << "Input: list " << input << " k: " << k << " Output: " << res << " Expected: " << expect << " Pass: " << pass << endl;
}

void splitAtLocTester(string input, int index, string expect1, string expect2, string expect3 ) {
   ListType list = buildList(input);
   ListType a = NULL;
   ListType b = NULL;
   splitAtLoc(list, index, a, b);
   string res1 = listToString(a);
   string res2 = listToString(b);
   string pass = "FAILED";
   if (res1==expect1 && res2==expect2 && listToString(list)==expect3) {
      pass = "passed";
   }
   cout << "Input: list " << input << " index: " << index << " Output: a " << res1 << "; b " << res2 << "; list " << listToString(list) << " Expected: a " << expect1  << "; b " << expect2 << "; list " << expect3 << " Pass: " << pass << endl;

}