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

void wadda(char * str) {
   str[0] = 'h';
   char * tmp = new char[strlen(str)+5];
   strcpy(tmp, str);
   strcat(tmp, "shot");
   str = tmp;
}

char * nicknamer(const char * name) {
   const char PREFIX[] = "The ";
   const char SUFFIX[] = "-inator";

   char * nickname = new char[strlen(PREFIX) + strlen(SUFFIX) + strlen(name) + 1];
   strcpy(nickname, PREFIX);
   strcat(nickname, name);
   strcat(nickname, SUFFIX);
   return nickname;
}
int main() {
   cout << nicknamer("Sam");
/*
   char buffer[MAX_LINE_SIZE];


   // fgets reads a line of input and puts it in a C string.  If the line of input
   // is longer than the buffer array only gets enough chars that fit (and ignores the
   // rest); this prevents it from overwriting the end of the array.
   // Unlike Java Scanner nextLine(), fgets also saves the newline in the buffer.
   // So after call, buffer will have 0 or more chars read from the line, 
   // then a newline char ('\n'), and then the null char ('\0')
   // note: the sizeof function below does not work with dynamic arrays.
   // fgets returns 0 (false) when it hits EOF
   // Note: stdin (third paremeter below) is the C version of cin or System.in


   while (fgets(buffer, sizeof(buffer), stdin)) {
       //readNumber(buffer);

       char areaCode [AREA_CODE_SIZE + 1];
       char prefix [PREFIX_SIZE + 1];
       char lineNumber[LINE_NO_SIZE + 1];
       int start = 0;
       readField(buffer, start, AREA_CODE_SIZE, areaCode);
       readField(buffer, start, PREFIX_SIZE, prefix);
       readField(buffer, start, LINE_NO_SIZE, lineNumber);

       cout << "LINE READ: " << buffer;
       cout << "area code: '"  << areaCode << "' " << endl;
       cout << "prefix: '"  << prefix << "' " << endl;
       cout << "line number: '"  << lineNumber << "'" << endl;
       cout << endl;
      delete[] areaCode;
      delete[] prefix;
      delete[] lineNumber;
   }

*/
}


