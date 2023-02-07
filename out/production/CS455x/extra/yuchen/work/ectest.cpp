/*  Name: Yuchen Peng
 *  USC NetID: yuchenpe
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



void cleanList(ListType list) {
   while (list) {
      ListType temp = list;
      list = list->next;
      delete temp;
   }
}


bool testNumAdjDupes(const string & input, int expected) {
   ListType list = buildList(input);
   int result = numAdjDupes(list);
   bool pass = (result == expected);
   if (!pass) {
      cout << "FAILED" << endl;
      cout << "Input: " << listToString(list) << endl;
      cout << "Output: " << result << endl;
      cout << "Expected: " << expected << endl;
   }
   cleanList(list);
   return pass;
}


bool testRemoveDiv(const string & input, int k, const string & expected) {
   ListType list = buildList(input);
   string inputList = listToString(list);
   removeDiv(list, k);
   string result = listToString(list);
   bool pass = (result == expected);
   if (!pass) {
      cout << "FAILED" << endl;
      cout << "Input: " << inputList << endl;
      cout << "Output: " << result << endl;
      cout << "Expected: " << expected << endl;
   }
   cleanList(list);
   return pass;
}


bool testsplitAtLoc(const string & input, int loc, const string & expectedA, const string & expectedB) {
   ListType list = buildList(input);
   string inputList = listToString(list);
   ListType a, b;
   splitAtLoc(list, loc, a, b);
   string resultA = listToString(a);
   string resultB = listToString(b);
   bool pass = (!list) && (resultA == expectedA) && (resultB == expectedB);
   if (!pass) {
      cout << "FAILED" << endl;
      cout << "Input: " << inputList << endl;
      cout << "Output list: " << listToString(list) << endl;
      cout << "Output of a: " << resultA << endl;
      cout << "Output of b: " << resultB << endl;
      cout << "Expected list: ()" << endl;
      cout << "Expected a: " << expectedA << endl;
      cout << "Expected b: " << expectedB << endl;
   }
   cleanList(list);
   return pass;
}




int main ()
{
   bool pass;
   
   cout << "\nTesting numAdjDupes..." << endl;
   pass = testNumAdjDupes("", 0);
   pass &= testNumAdjDupes("2 8 3", 0);
   pass &= testNumAdjDupes("4 4 7 3", 1);
   pass &= testNumAdjDupes("5 5 7 5 5 5 5", 2);
   pass &= testNumAdjDupes("5 7 5 7", 0);
   pass &= testNumAdjDupes("5 5 5 3 3 3 4 4 4 4", 3);
   if (pass) {
      cout << "All tests PASSED!" << endl;
   }
   
   cout << "\nTesting removeDiv..." << endl;
   pass = testRemoveDiv("", 3, "()");
   pass &= testRemoveDiv("7 10", 3, "(7 10)");
   pass &= testRemoveDiv("24 12 6 9", 4, "(6 9)");
   pass &= testRemoveDiv("24 12 6 9", 3, "()");
   pass &= testRemoveDiv("3 2 8 4 7", 2, "(3 7)");
   pass &= testRemoveDiv("1 2 3 4 5", 1, "()");
   if (pass) {
      cout << "All tests PASSED!" << endl;
   }
   
   cout << "\nTesting splitAtLoc..." << endl;
   pass = testsplitAtLoc("7 4 4 3 9", 2, "(7 4)", "(3 9)");
   pass &= testsplitAtLoc("7 4 2 3 9", 0, "()", "(4 2 3 9)");
   pass &= testsplitAtLoc("1 2 3 3 2", 4, "(1 2 3 3)", "()");
   pass &= testsplitAtLoc("", 3, "()", "()");
   pass &= testsplitAtLoc("8 2 5", 2, "(8 2)", "()");
   pass &= testsplitAtLoc("8 2 5", 3, "(8 2 5)", "()");
   pass &= testsplitAtLoc("8 2 5", -3, "()", "(8 2 5)");
   pass &= testsplitAtLoc("3", 0, "()", "()");
   pass &= testsplitAtLoc("3 5", 0, "()", "(5)");
   pass &= testsplitAtLoc("3 5", 1, "(3)", "()");
   if (pass) {
      cout << "All tests PASSED!" << endl;
   }
   
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
