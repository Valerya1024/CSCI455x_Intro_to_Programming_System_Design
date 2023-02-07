// Name: Qichen Wang
// USC NetID: qichenwa
// CSCI 455 PA5
// Fall 2022

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   hashSize = HASH_SIZE;
   numEnt = 0;
   table = new ListType[hashSize];
}


Table::Table(unsigned int hSize) {
   hashSize = hSize;
   numEnt = 0;
   table = new ListType[hashSize];
}


int * Table::lookup(const string &key) {
   unsigned int code = hashCode(key);
   return listSearch(table[code], key);
}


bool Table::remove(const string &key) {
   unsigned int code = hashCode(key);
   bool outcome = listRemove(table[code], key);
   if (outcome) {
      numEnt--;
   }
   return outcome;
}


bool Table::insert(const string &key, int value) {
   unsigned int code = hashCode(key);
   bool outcome = listAppend(table[code], key, value);
   if (outcome) {
      numEnt++;
   }
   return outcome;
}


int Table::numEntries() const {
   return numEnt;
}


void Table::printAll() const {
   for (int i = 0; i < hashSize; i++) {
      printList(table[i]);
   }
}


void Table::hashStats(ostream &out) const {
   int numNonEmpty = 0;
   int maxLength = -1;
   for (int i = 0; i < hashSize; i++) {
      if (table[i] != NULL) {
         numNonEmpty++;
      }
      int length = 0;
      Node* nodePtr = table[i];
      while (nodePtr != NULL) {
         length++;
         nodePtr = nodePtr -> next;
      }
      if (length > maxLength) {
         maxLength = length;
      }      
   }
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numEnt << endl;
   out << "number of non-empty buckets: " << numNonEmpty << endl;
   out << "longest chain: " << maxLength << endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here

