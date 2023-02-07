// Name: Qichen Wang
// USC NetID: qichenwa
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

using namespace std;

// Reads in the next command and executes it, until the quit command is received.
void execute(Table* grades);

// Performs the insert command.
void doInsert(Table* grades);

// Performs the change command.
void doChange(Table* grades);

// Performs the lookup command.
void doLookup(Table* grades);

// Performs the remove command.
void doRemove(Table* grades);

// Prints out a brief command summary.
void printCommands(); 


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
   
   execute(grades);

   return 0;
}

void execute(Table* grades) {
   bool exit = false;
   while (!exit) {
      cout << "cmd>";
      string command;
      cin >> command;
      if (command == "insert") { doInsert(grades); }
      else if (command == "change") { doChange(grades); }
      else if (command == "lookup") { doLookup(grades); }
      else if (command == "remove") { 
         doRemove(grades); 
         continue; // There might be an unused input.
      }
      else if (command == "print") {
         grades -> printAll();
      }
      else if (command == "size") {
         cout << grades -> numEntries() << endl;
      }
      else if (command == "stats") {
         grades -> hashStats(cout);
      }
      else if (command == "help") { printCommands(); }
      else if (command == "quit") {
         exit = true;
      }
      else {
         cout << "ERROR: invalid command" << endl;
         printCommands();
         continue;
      }
   }
}

void doInsert(Table* grades) {
   string name;
   int score;
   cin >> name;
   cin >> score;
   bool outcome = grades -> insert(name, score);
   if (!outcome) {
      cout << "The student is already present. " << endl;
   }
}

void doChange(Table* grades) {
   string name;
   cin >> name;
   int* scorePtr = grades -> lookup(name);
   if (scorePtr == NULL) {
      cout << "The student is not present. " << endl;
   }
   else {
      cin >> *scorePtr;
   }
}

void doLookup(Table* grades) {
   string name;
   cin >> name;
   int* scorePtr = grades -> lookup(name);
   if (scorePtr == NULL) {
      cout << "The student is not present. " << endl;
   }
   else {
      cout << *scorePtr << endl;
   }
}

void doRemove(Table* grades) {
   string name;
   cin >> name;
   bool outcome = grades -> remove(name);
   if (!outcome) {
      cout << "The student is not present. " << endl;
   }
}

void printCommands() {
   cout << "The following commands are available: " << endl;
   cout << "insert <name> <score>, change <name> <newscore>, lookup <name>, remove <name>, print, size, stats, help, quit" << endl;
}


