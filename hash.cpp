#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define SIZE 10

class Employee {
  struct database {
    int age, empId, salary;
    string name;
  }h[SIZE];

public:
  Employee();
  void insert();
  int hashfun(int emid);
  void collision(int emid, int eage, int esal, string ename, int key);
  void display();
   void search();
  int collision(int id);
   void deleteId();
};

Employee::Employee() {
  for (int i = 0; i < SIZE; i++) {
    h[i].empId = -1;
    h[i].age = 0;
    h[i].salary = 0;
    h[i].name = "________";
  }
}
void Employee::insert() {
  int emid, esal, eage, key;
  string ename;
  cout << "Enter Employee id:";
  cin >> emid;
  cout << endl;
  cout << "Enter name:";
  cin >> ename;
  cout << endl;
  cout << "Enter age:";
  cin >> eage;
  cout << endl;
  cout << "Enter Salary:";
  cin >> esal;
  cout << endl;

  key = hashfun(emid);
  if (h[key].empId == -1) {
    h[key].empId = emid;
    h[key].age = eage;
    h[key].name = ename;
    h[key].salary = esal;
  } else {
    collision(emid, eage, esal, ename, key);
  }
}

int Employee::hashfun(int emid) { return (emid % 10); }

void Employee::collision(int emid, int eage, int esal, string ename, int key) {
  cout << "Collision!!";
  for (int i = key; i != (SIZE - 1); i++) {
    if (i == SIZE - 1) {
      i = 0;
    }
    if (h[i].empId == -1) {
      h[i].empId = emid;
      h[i].age = eage;
      h[i].name = ename;
      h[i].salary = esal;
      break;
    }
  }
}

void Employee::display() {
  cout << endl
       << setw(10) << "SR.no" << setw(20) << "Employee ID" << setw(20) << "Name" << setw(20) << "Age" << setw(20) << "Salary" << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << setw(10) << i << setw(20);
    cout << setw(20) << h[i].empId << setw(20);
    cout << setw(20) << h[i].name << setw(20);
    cout << setw(20) << h[i].age << setw(20);
    cout << setw(20) << h[i].salary;
  }
}

void Employee::search(){
  int id;
  cout << "Enter the employee id: ";
  cin >> id;
  int key = hashfun(id);
  if(id==h[key].empId){
    cout << "Employee found\n";
  }
  else{
    int key = collision(id);
     if(id==h[key].empId){
    cout << "Employee found\n";
       }
    else{
    cout << "Employee not found\n";
  }
  }
}

void Employee::deleteId(){
  int id;
  cout << "Enter the employee id you want to delete: ";
  cin >> id;
  int key = hashfun(id);
  if(id==h[key].empId){
     h[key].empId = -1;
    h[key].age = 0;
    h[key].salary = 0;
    h[key].name = "________";
    cout << "Deleted successfully\n";
  }
  else{
    int key = collision(id);
     if(id==h[key].empId){
        h[key].empId = -1;
      h[key].age = 0;
       h[key].salary = 0;
      h[key].name = "________";
    cout << "Deleted successfully\n";
       }
    else{
    cout << "Employee not found\n";
  }
  }
}
int Employee::collision(int id){
   for (int i = id; i != (SIZE - 1); i++) {
    if (i == SIZE - 1) {
      i = 0;
    }
    if (h[i].empId == id) {
        return i;
      break;
    }
  }
  return 0;
}

int main() {
  Employee emp;
  int n;
  do {
    cout << "Enter 1 for Inserting content\n";
    cout << "Enter 2 for Displaying content\n";
    cout << "Enter 3 for Searching content\n";
    cout << "Enter 4 for Deleting content\n";
    cout << "Enter 5 TO EXIT!!!!\n";
    cin >> n;
    switch (n) {
    case 1:
      emp.insert();
      break;
    case 2:
      emp.display();
      break;
      case 3:
        emp.search();
        break;
        case 4:
        emp.deleteId();
        break;
    case 5:
      break;
    }
  } while (n != 5);
}
