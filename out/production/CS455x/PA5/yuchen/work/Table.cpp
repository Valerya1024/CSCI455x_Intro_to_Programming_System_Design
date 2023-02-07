// Name: Yuchen Peng
// USC NetID: yuchenpe
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
   hashTable = new ListType[hashSize]();
   numEntry = 0;
}


Table::Table(unsigned int hSize) {
   hashSize = hSize;
   hashTable = new ListType[hashSize]();
   numEntry = 0;
}


int * Table::lookup(const string &key) {
   return lookupKey(hashTable[hashCode(key)], key);
}


bool Table::remove(const string &key) {
   bool result = listRemove(hashTable[hashCode(key)], key);
   if (result) { --numEntry; }   // removed successfully
   return result;
}


bool Table::insert(const string &key, int value) {
   bool result = insertNode(hashTable[hashCode(key)], key, value);
   if (result) { ++numEntry; }   // inserted successfully
   return result;
}


int Table::numEntries() const {
   return numEntry;
}


void Table::printAll() const {
   for (unsigned int i = 0 ; i < hashSize ; ++i) {
      printList(hashTable[i]);
   }
}


void Table::hashStats(ostream &out) const {
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numEntry << endl;
   
   int nonEmpty = 0;
   int maxLength = 0;
   
   for (unsigned int i = 0 ; i < hashSize ; ++i) {
      if (hashTable[i]) {
         ++nonEmpty;
         int currLength = listLength(hashTable[i]);
         if (currLength > maxLength) {
            maxLength = currLength;
         }
      }
   }
   
   out << "number of non-empty buckets: " << nonEmpty << endl;
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

