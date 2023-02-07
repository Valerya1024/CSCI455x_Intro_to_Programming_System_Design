// Name: Xinyu Wu
// USC NetID: xwu26173
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
   data = new ListType[HASH_SIZE];
   hashSize = HASH_SIZE;
   for (int i = 0; i < hashSize; i++) {
      data[i] = NULL;
   }
}


Table::Table(unsigned int hSize) {
   data = new ListType[hSize];
   hashSize = hSize;
   for (int i = 0; i < hashSize; i++) {
      data[i] = NULL;
   }
}


int * Table::lookup(const string &key) {
   unsigned int address = hashCode(key);
   return listLookUp(data[address], key);
}


bool Table::remove(const string &key) {
   unsigned int address = hashCode(key);
   return listRemove(data[address], key);
}


bool Table::insert(const string &key, int value) {
   unsigned int address = hashCode(key);
   return listInsert(data[address], key, value);
}


int Table::numEntries() const {
   int num = 0;
   for (int i = 0; i < hashSize; i++) {
      if (data[i] != NULL) {
         num += listLength(data[i]);
      }
   }
   return num;
}


void Table::printAll() const {
   for (int i = 0; i < hashSize; i++) {
      if (data[i] != NULL) {
         listPrintAll(data[i]);
      }
   }
}


void Table::hashStats(ostream &out) const {
   int numNonEmptyBucket = 0;
   int numEntry = 0;
   int lenLongestChain = 0;
   for (int i = 0; i < hashSize; i++) {
      if (data[i] != NULL) {
         numNonEmptyBucket++;
         int len = listLength(data[i]);
         numEntry += len;
         if (len > lenLongestChain) {
            lenLongestChain = len;
         }
      }
   }
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numEntry << endl;
   out << "number of non-empty buckets: " << numNonEmptyBucket << endl;
   out << "longest chain: " << lenLongestChain << endl;
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

