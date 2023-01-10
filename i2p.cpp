#include <iostream>
using namespace std;

class postfix {
  char exp[20];
  char stack[20];
  char output[20];
  int top;
  int j, k;

public:
  postfix();
  void convert();
  void getExpression();
  void push(char c);
  char pop();
  int getPrecedence(char c);
  bool stackEmpty();
};

postfix::postfix() {
  exp[0] = '\0';
  stack[0] = '\0';
  output[0] = '\0';
  top = -1;
  k = 0;
  j = 0;
}

void postfix::getExpression() {
  cout << "Enter the expression: ";
  cin >> exp;
  //cout << exp << endl;
}

void postfix::push(char c) {
  stack[++top] = c;
  cout << "Stack is: " << stack << endl;
}

char postfix::pop() {
  char x;
  int smt = stackEmpty();
  if (smt == 1) {
    x = stack[top];
    top--;
    return x;
  } 
  // else {
  //   cout << "Stack is empty(pop). \n";
  // }
  return 0;
}

int postfix::getPrecedence(char c) {
  if (c == '*' || c == '/') {
    return 2;
  }
  if (c == '+' || c == '-') {
    return 1;
  }
  if (c == '(' || c == '[' || c == '{') {
    return 0;
  }
}

bool postfix::stackEmpty() {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

void postfix::convert() {
  int i = 0;
  while (exp[i++] != '\0') {
   cout <<"Input: " << exp[i] << endl;
    if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
      push(exp[i]);
    }
    else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
      if (exp[i] == ')') {
        while (stack[j--] != '(') {
          if (!stackEmpty()) {     
             char ch = pop();
              if(ch == '('){
                //cout << "Break;\n";
                break;
              }   
              else{
                output[k++] = ch;    
              }
          } 
        }
        if(!stackEmpty()){
            output[k++] = pop();
          }
      } else if (exp[i] == ']') {
        while (stack[j--] != '[') {
          if (!stackEmpty()) {
            output[k++] = pop();
          } 
        }
      } else if (exp[i] == ')') {
        while (stack[j--] != '{') {
          if (!stackEmpty()) {
            output[k++] = pop();
          }
        }
      }
    } else if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' ||
               exp[i] == '-') {

      int x = getPrecedence(exp[i]);
      int y = 0;
      if(stack[top] == '*' || stack[top] == '+' || stack[top] == '-' || stack[top] == '/' ){
        int y = getPrecedence(stack[top]);
            if (x >= y) {
              char ch = pop();
              if(ch=='('){
                push(exp[i]);
              }   
              else{
                output[k++] = ch; 
                push(exp[i]);
              }
            }
            }else{
              push(exp[i]);
            }
    } 
     else {
      output[k++] = exp[i];
      cout << "Output: " << output << endl;
    }
  }
  cout << "\nPostfix expression is: " << output << endl;
}

int main() {
  postfix p;
  p.getExpression();
  p.convert();
}
