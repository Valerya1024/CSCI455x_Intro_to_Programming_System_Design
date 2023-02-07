//
// Created by 13588 on 12/8/2022.
//
// returns a list made from the string whose format is a space-separ// list of numbers. E.g, makeList("1 2 3") returns a list of three n// where the first node is 1
struct Node {
    int data;
    Node *next;

    Node(int item);
    Node(int item, Node *n);

};
Node::Node(int item) {
   data = item;
   next = nullptr;
}

Node::Node(int item, Node *n) {
   data = item;
   next = n;
}

typedef Node * ListType;

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

ListType makeList(const string & listString) {
   ListType nums = nullptr;

   istringstream istr(listString);  // similar to a Java Scanner over a String

   int num;

   if (istr >> num) { // is there one value there?
      nums = new Node(num);
   }
   else {
      return nullptr;
   }

   Node *last = nums;

   while (istr >> num) {
      last->next = new Node(num);
      last = last->next;
   }

   return nums;
}

ListType makeCircList(const string & listString) {
   ListType nums = nullptr;

   istringstream istr(listString);  // similar to a Java Scanner over a String

   int num;

   if (istr >> num) { // is there one value there?
      nums = new Node(num);
   }
   else {
      return nullptr;
   }

   Node *last = nums;
   Node * lastNode = nums;
   while (istr >> num) {
      last->next = new Node(num);
      last = last->next;
   }
   lastNode->next = nums;
   return nums;
}
// prints out the list as a space separated list of numbers
// surrounded by parentheses: e.g. (1 2 3)
void printList(ListType list) {
   string listString = "(";

   if (list == nullptr) {
      listString += ")";
      cout << listString << endl;
      return;
   }

   Node *p = list;
   while (p->next != NULL) {
      listString += to_string(p->data) + " ";
      p = p->next;
   }

   // print last one with no trailing space
   listString += to_string(p->data) + ")";

   cout << listString << endl;
}
void func1(ListType &list) {
   delete list;
   printList(list);
   list = nullptr;
}

void insert0Between(ListType & list) {
   if (!list) {
      return;
   }
   if (!list->next){
      return;
   }
   ListType fast = list->next;
   ListType slow = list;
   while (fast) {
      slow->next = new Node(0, fast);
      fast = fast->next;
      slow = slow->next->next;
   }
}

void removeUntil7(ListType & list) {
   while (list) {
      ListType tmp = list;
      if (list->data == 7) {
         return;
      }
      list = list->next;
      delete tmp;
      cout << tmp->data << endl;
   }
}

void compress(ListType & list){
   if (!list) {
      return;
   }
   if (!list->next) {
      return;
   }
   ListType slow = list;
   ListType fast = list->next;
   while (fast) {
      if (fast->data == slow->data) {
         ListType rmv = fast;
         fast = fast->next;
         slow->next = fast;
         delete rmv;
      } else {
         slow = slow->next;
         fast = fast->next;
      }
   }
}
bool isCircularList(Node * list) {
   if (!list) {
      return false;
   }
   ListType head = list;
   while (list->next) {
      if (list->next == head) {
         return true;
      }
      list = list->next;
   }
   return false;
}

void gut(ListType & list) {
   if (!list) {
      return;
   }
   if (!list->next) {
      return;
   }
   ListType fast = list->next;
   while (fast->next) {
      ListType rmv = fast;
      fast = fast->next;
      list->next = fast;
      delete rmv;
   }
}
/*
void test(string input) {
   ListType list = makeList(input);
   string circ = "no";
   if (isCircularList(list)) {
      circ = "yes";
   }
   cout << circ << " ";
   list = makeCircList(input);
   circ = "no";
   if (isCircularList(list)) {
      circ = "yes";
   }
   cout << circ << endl;
}*/

void removeEveryOther(ListType & list) {
   if (!list) {
      return;
   }
   ListType slow = list;
   ListType fast = list;
   while (fast->next) {
      fast = fast->next;
      ListType rmv = fast;
      fast = fast->next;
      slow->next = fast;
      delete rmv;
      s
   }
}

void test(string input) {
   ListType list = makeList(input);
   gut(list);
   printList(list);
}

int main() {
   test("3 7 7 7 4 7");
   test("12 5 9 9");
   test("0 0 0 7");
   test("7");
   test("3 3");
   test("");
   /*
   ListType myList = makeList("6 5 4");
   ListType n = myList->next;
   func1(myList->next);
   printList(myList);
   printList(n);
   delete myList;
   printList(myList);
   return 0;*/
}