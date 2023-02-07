// Name: Xinyu Wu
// USC NetID: xwu26173
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

#define QUIT "quit"
#define HELP "help"
#define INSERT "insert"
#define CHANGE "change"
#define LOOKUP "lookup"
#define REMOVE "remove"
#define PRINT "print"
#define SIZE "size"
#define STATS "stats"
#define ERROR "ERROR: invalid command"
#define HELP_MESSAGE "insert name score\nInsert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert.\nchange name newscore\nChange the score for name. Print an appropriate message if this name isn't present.\nlookup name\nLookup the name, and print out his or her score, or a message indicating that student is not in the table.\nremove name\nRemove this student. If this student wasn't in the grade table, print a message to that effect.\nprint\nPrints out all names and scores in the table.\nsize\nPrints out the number of entries in the table.\nstats\nPrints out statistics about the hash table at this point. (Calls hashStats() method)\nhelp\nPrints out a brief command summary.\nquit\nExits the program."
#define NOT_FOUND "This student is not in the table"
#define ALREADY_PRESENT "This name was already present"

using namespace std;

void remove(std::ostream &out, Table * &grades) {
   std::string name;
   cin >> name;
   if (!grades->remove(name)) {
      out << NOT_FOUND << endl;
   }
}

void insert(std::ostream &out, Table * &grades) {
   std::string name;
   int score;
   cin >> name;
   cin >> score;
   if (!grades->insert(name, score)) {
      out << ALREADY_PRESENT << endl;
   }
}

void change(std::ostream &out, Table * &grades) {
   std::string name;
   int score;
   int* value;
   cin >> name;
   cin >> score;
   value = grades->lookup(name);
   if (value) {
      *value = score;
   } else {
      out << NOT_FOUND << endl;
   }
}

void lookup(std::ostream &out, Table * &grades) {
   std::string name;
   int* value;
   cin >> name;
   value = grades->lookup(name);
   if (value) {
      out << *value << endl;
   } else {
      out << NOT_FOUND << endl;
   }
}


bool process(std::ostream &out, Table * &grades) {
   bool endProgram = false;
   std::string command;
   cin >> command;
   if (command == QUIT) {
      endProgram = true;
   } else if (command == HELP){
      out << HELP_MESSAGE << endl;
   } else if (command == PRINT) {
      grades->printAll();
   } else if (command == REMOVE) {
      remove(out, grades);
   } else if (command == INSERT) {
      insert(out, grades);
   } else if (command == CHANGE) {
      change(out, grades);
   } else if (command == LOOKUP) {
      lookup(out, grades);
   } else if (command == SIZE) {
      out << grades->numEntries();
   } else if (command == STATS) {
      grades->hashStats(out);
   } else {
      out << ERROR << endl << HELP_MESSAGE << endl;
   }
   return endProgram;
}

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

   do {
      cout << "cmd>";
   } while (!process(cout, grades));

   return 0;
}
