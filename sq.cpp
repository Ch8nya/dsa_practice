#include <iostream>
using namespace std;

class stack{
  int top;
  int arr[20];
  public:
  stack(){
    top = -1;
  }
  void push(int data);
  int pop();
  bool isempty();
  bool isFull();
  void display();
};

void stack::push(int data){
  if(isFull()){
    cout << "Stack OverFlow\n";
  }
  else{
    top++;
    arr[top] = data;
  }
}

int stack::pop(){
  int x = 0;
  if(isempty()){
    cout << "Stack UnderFlow\n";
    
  }else{
    x = arr[top];
    top--;
  }
  return x;
}

bool stack::isFull(){
  if(top==19){
    return 1;
  }
  return 0;
}

bool stack::isempty(){
  if(top==-1){
    return 1;
  }
  return 0;
}

void stack::display(){
  for(int i=0;i<=top;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

class queue{
  int front, rear;
  int arr[20];
  public:
  queue(){
    front = rear = -1;
  }
  void enqueue();
  int dequeue();
  bool isEmpty();
  bool isFull();
};

void queue::enqueue(){
  if
}

int queue::dequeue(){
  
}

bool queue::isFull(){
  if(rear == 19){
    return 1;
  }
  return 0;
}

bool queue::isEmpty(){
  if(front > rear){
    return 1;
  }
  return 0;
}

int main() {
  stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  s.push(7);
  s.push(8);
  s.push(9);
  s.push(120);
  s.push(99);
  s.push(12);
  s.display();
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  
  cout << "Hello World!\n";
}
