/*

  CSCI 455 C String lab

  See lab description for what it should do.  
  C++ tools allowed: cout, call by reference, ostream output, new / delete

*/


// for C input functions (e.g., fgets used here)
#include <cstdio>

// C string functions
#include <cstring>

#include <iostream>


using namespace std;

const char NAME_DELIM = ':';
const int AREA_CODE_SIZE = 3;
const int PREFIX_SIZE = 3;
const int LINE_NO_SIZE = 4;
const int MAX_LINE_SIZE = 1024;  // including newline and terminating null char

//void readNumber(char* buffer);

void readField(char* buffer, int & start, int length, char* destination) {
    int pos = 0;
    while (pos < length) {
        destination[pos] = buffer[start];
        pos++;
        start++;
    }
    start++;
    destination[length] = '\0';
}


int main() {

   char buffer[MAX_LINE_SIZE];



   while (fgets(buffer, sizeof(buffer), stdin)) {
       //readNumber(buffer);
       cout << "LINE READ: " << buffer;

       int nameLength = 0;
       while (buffer[nameLength] != NAME_DELIM) {
           nameLength++;
       }
      int start = 0;
       char* name = new char [nameLength + 1];
       readField(buffer, start, nameLength, name);
       cout << "name read: '" << name << "'" << endl;
       delete[] name;

       char areaCode [AREA_CODE_SIZE + 1];
       char prefix [PREFIX_SIZE + 1];
       char lineNumber[LINE_NO_SIZE + 1];
       readField(buffer, start, AREA_CODE_SIZE, areaCode);
       readField(buffer, start, PREFIX_SIZE, prefix);
       readField(buffer, start, LINE_NO_SIZE, lineNumber);

       cout << "area code: '"  << areaCode << "' " << endl;
       cout << "prefix: '"  << prefix << "' " << endl;
       cout << "line number: '"  << lineNumber << "'" << endl;
       cout << endl;
       delete[] areaCode;
       delete[] prefix;
       delete[] lineNumber;
   }


}


