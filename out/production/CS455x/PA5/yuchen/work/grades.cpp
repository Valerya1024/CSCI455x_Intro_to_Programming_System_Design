// Name: Yuchen Peng
// USC NetID: yuchenpe
// CSCI 455 PA5
// Fall 2022

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

#include <string>
#include <sstream>

using namespace std;

int main(int argc, char * argv[]) {


   Table * grades;  // Table is dynamically allocated below, so we can call
                     // different constructors depending on input from the user.
   
   // optionally gets the hash table size from the command line
   if (argc > 1) {
      int hashSize = atoi(argv[1]);  // atoi converts c-string to int
      
      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   string restLine;
   string cmd;
   string name;
   
   cout << "cmd> ";
   cin >> cmd;
   
   while (cmd != "quit") {
      getline(cin, restLine);
      stringstream str(restLine);
      
      if (cmd == "insert") {
         str >> name;
         int score;
         str >> score;
         if (!grades->insert(name, score)) {
            cout << "This name is already present in the grade table." << endl;
         }
      }
      
      else if (cmd == "change") {
         str >> name;
         int * score = grades->lookup(name);
         if (score) {
            str >> *score;
         }
         else {
            cout << "This name isn't present in the grade table." << endl;
         }
      }
      
      else if (cmd == "lookup") {
         str >> name;
         int * score = grades->lookup(name);
         if (score) {
            cout << *score << endl;
         }
         else {
            cout << "This name isn't present in the grade table." << endl;
         }
      }
      
      else if (cmd == "remove") {
         str >> name;
         if (!grades->remove(name)) {
            cout << "This name isn't present in the grade table." << endl;
         }
      }
      
      else if (cmd == "print") {
         grades->printAll();
      }
      
      else if (cmd == "size") {
         cout << grades->numEntries() << endl;
      }
      
      else if (cmd == "stats") {
         grades->hashStats(cout);
      }
      
      else {
         if (cmd != "help") {
            cout << "ERROR: invalid command" << endl;
         }
         cout << "Valid commands: insert [name] [score], change [name] [newscore]," << endl;
         cout << "lookup [name], remove [name], print, size, stats, help, quit" << endl;
      }
      
      cout << "cmd> ";
      cin >> cmd;
   }

   return 0;
}