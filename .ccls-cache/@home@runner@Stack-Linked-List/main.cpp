#include <iostream>
#include <string>

using namespace std;

struct Node{
  string data;
  Node* next;
};

class Stack{

  public:
    Node* top = new Node;
    Node* bottom = new Node;
    int length;

  Stack() {
    top->data = "";
    top->next = NULL;
    bottom->data = "";
    bottom->next = NULL;
    length = 0;
  }

  void peek(){
    cout << "Top Peek: " << top->data << endl;
    cout << "Length: " << length << endl;
  }

  void print() {
    cout << "\nTop Data: " << top->data << endl;
  
    if(top->next != NULL) {
        Node* temp = top->next;
        cout << "Top->next: " << temp->data << endl;
    }

    cout << "Bottom Value: " << bottom->data << endl;
    cout << "Bottom->next: " << bottom->next << endl;
    cout << "\nLength: " << length << endl;
  }

  void push(string value){
    if(top->data == "") {
      top->data = value;
      length++;
    }

    else if(length == 1) {
      bottom = top;
      Node* temp = new Node;
      temp->data = value;
      temp->next = bottom;
      top = temp;
      length++;

    }

    else {
      Node* temp = new Node;
      temp->data = value;
      temp->next = top;
      top = temp;
      length++;

    }
    
  }

  void pop() {
    if(top->data == "") {
      top->data = "";
    }
    else if(top == bottom) {
      bottom->data = "";
      top->data = "";
      length--;

    } else {
    Node* temp = top->next;
    delete top;
    top = temp;
    length--;
    }

  }
};






int main() {
  Stack obj;
  obj.push("google");
  obj.push("udemy");
  obj.push("Tester");
  //obj.push("discord");

  obj.pop();
  obj.pop();
  obj.pop();
  obj.pop();

  obj.push("apple");
  obj.push("mountain");
  obj.pop();
  obj.pop();
  obj.pop();
  obj.peek();
}