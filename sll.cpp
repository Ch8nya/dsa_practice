#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
};

class A {
 public:
  node *header = nullptr;
  void insert_beg();
  void display();
  void delete_beg();
  void search();
  A() {}

 private:
  node *nn = nullptr;
};

void A::insert_beg() {
  nn = nullptr;
  nn = new node;
  cout << "Enter data: " << endl;
  cin >> nn->data;
  nn->next = header;
  header = nn;
}

void A::delete_beg() {
  node *temp_node;
  temp_node = header;
  if (header != nullptr) {
    header = header->next;
    delete temp_node;
    temp_node = nullptr;
  } else {
    cout << "No nodes in the list" << endl;
  }
}

void A::search(){
  int a;
  cout << "Enter term to search: " << endl;
  cin >> a;

  int count = 1;
  node* cn = header;

  while(cn != nullptr && cn->data != a){
    cn = cn->next;
    count++;
  }
  if(cn != nullptr){
    cout << "Data " << a << " found at position " << count << '\n'; 
  } else{
    cout << "Data not found" << '\n';
  }
}

void A::display() {
  node *cn;
  cn = header;
  cout << '\n';
  while (cn != nullptr) {
    cout << cn->data << " ";
    cn = cn->next;
  }
  cout << '\n';
  delete cn;
  cn = nullptr;
}

int main() {
  A sll;
  int choice = 1;
  while (choice != 7) {
    cout << "\n" << "Enter 1 to add new node in beginning" << endl << "Enter 2 to delete node at beginning" << endl     << "Enter 3 to search" << endl << "Enter 4 to exit" << endl;
    cin >> choice;

    switch (choice) {
      case 1:
        sll.insert_beg();
        cout << '\n';
        sll.display();
        break;
      case 2:
        sll.delete_beg();
        cout << '\n';
        sll.display();
        break;
      case 3:
        sll.search();
        cout << '\n';
        sll.display();
        break;
      case 4:
        cout << '\n';
        sll.display();
        cout << "Exiting...." << endl;
      return 0;
    }
  }
  return 0;
}
