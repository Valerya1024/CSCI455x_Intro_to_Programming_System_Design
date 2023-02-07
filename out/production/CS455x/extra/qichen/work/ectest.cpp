/*  Name: Qichen Wang
 *  USC NetID: qichenwa
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

/*
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

/
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
/*
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
/*
ListType buildList(const string & listString);


// Does a test on the numAdjDupes method, with given input and expected result.
void testNumAdjDupes(string listStr, int exp);

// Does a test on the removeDiv method.
void testRemoveDiv(string listStr, int k, string exp);

// Does a test on the splitAtLoc method.
void testSplitAtLoc(string listStr, int loc, string expA, string expB);

int main ()
{

   cout << "Testing numAdjDupes..." << endl;
   testNumAdjDupes("", 0);
   testNumAdjDupes("1", 0);
   testNumAdjDupes("2 2", 1);
   testNumAdjDupes("3 3 4 5", 1);
   testNumAdjDupes("1 2 3 4", 0);
   testNumAdjDupes("7 7 6 7 7", 2);
   testNumAdjDupes("3 3 3 4 4 4 4 5 5 7", 3);
   
   cout << "Testing removeDiv..." << endl;
   
   testRemoveDiv("", 2, "()");
   testRemoveDiv("3", 2, "(3)");
   testRemoveDiv("3", 3, "()");
   testRemoveDiv("1 3 5", 2, "(1 3 5)");
   testRemoveDiv("3 6 9 18", 3, "()");
   testRemoveDiv("3 5 8 12 15", 5, "(3 8 12)");
   testRemoveDiv("3 5 8 12 15", 4, "(3 5 15)");
   testRemoveDiv("3 5 8 12 15", 1, "()");
   
   cout << "Testing splitAtLoc..." << endl;
   testSplitAtLoc("", 1, "()", "()");
   testSplitAtLoc("", -1, "()", "()");
   testSplitAtLoc("3", 0, "()", "()");
   testSplitAtLoc("3", 1, "(3)", "()");
   testSplitAtLoc("3 5 8 12 15", 2, "(3 5)", "(12 15)");
   testSplitAtLoc("3 5 8 12 15", 0, "()", "(5 8 12 15)");
   testSplitAtLoc("3 5 8 12 15", 4, "(3 5 8 12)", "()");
   testSplitAtLoc("3 5 8 12 15", -2, "()", "(3 5 8 12 15)");
   testSplitAtLoc("3 5 8 12 15", 9, "(3 5 8 12 15)", "()");
   
   return 0;
}



/*********************************************************
 * Utility function definitions
 *
 */
/*
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


void testNumAdjDupes(string listStr, int exp) {
   cout << "list: (" << listStr << ")" << endl;
   int result = numAdjDupes(buildList(listStr));
   cout << "Return value: " << result << " [exp: " << exp << "]" << endl;
   if (result != exp) {
      cout << "FAILED" << endl;
   }
   cout << endl;
}

void testRemoveDiv(string listStr, int k, string exp) {
   cout << "list: (" << listStr << ")" << endl;
   cout << "k: " << k << endl;
   ListType list = buildList(listStr);
   removeDiv(list, k);
   cout << "list after function call: " << listToString(list) << " [exp: " << exp << "]" << endl;
   if (listToString(list) != exp) {
      cout << "FAILED" << endl;
   }
   cout << endl;
}

void testSplitAtLoc(string listStr, int loc, string expA, string expB) {
   cout << "list: (" << listStr << ")" << endl;
   cout << "loc:" << loc << endl;
   ListType list = buildList(listStr);
   ListType a = NULL;
   ListType b = NULL;
   splitAtLoc(list, loc, a, b);
   cout << "list after the call: " << listToString(list) << endl;
   string aStr = listToString(a);
   string bStr = listToString(b);
   cout << "a: " << aStr << " [exp: " << expA << "]" << endl;
   cout << "b: " << bStr << " [exp: " << expB << "]" << endl;
   if (!(listToString(list) == "()" && aStr == expA && bStr == expB)) {
      cout << "FAILED" << endl;
   }
   cout << endl;
}*/

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

bool equalList(ListType a, ListType b);

void numAdjDupesTester(string input, int expect);

void removeDivTester(string input, int k, string expect);

void splitAtLocTester(string input, int index, string expect1, string expect2, string expect3 );


int main ()
{
   cout << "Test numAdjDupes()" << endl;
   numAdjDupesTester("", 0);
   numAdjDupesTester("2 8 3", 0);
   numAdjDupesTester("4 4 7 3", 1);
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

bool equalList(ListType a, ListType b) {
   string strA = listToString(a);
   string strB = listToString(b);
   return strA == strB;
}

void numAdjDupesTester(string input, int expect) {
   ListType list = buildList(input);
   int res = numAdjDupes(list);
   string pass = "failed";
   if (res==expect) {
      pass = "passed";
   }
   cout << "Input: " << input << " Output: " << res << " Expected: " << expect << " Pass: " << pass << endl;
}

void removeDivTester(string input, int k, string expect) {
   ListType list = buildList(input);
   removeDiv(list, k);
   string res = listToString(list);
   string pass = "failed";
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
   string pass = "failed";
   if (res1==expect1 && res2==expect2 && listToString(list)==expect3) {
      pass = "passed";
   }
   cout << "Input: list " << input << " index: " << index << " Output: " << res1 << "; " << res2 << "; " << listToString(list) << " Expected: " << expect1  << "; " << expect2 << "; " << expect3 << " Pass: " << pass << endl;

}