#include <iostream>

struct node {
  node *prev;
  int data;
  node *next;
};
class DLL {
 public:
  node *header = nullptr;
  void insert_beg();
  void insert_pos();
  void insert_end();
  void display();
  void delete_beg();
  void delete_end();
  void delete_pos();

  DLL() {}

 private:
  node *nn = nullptr;
};

void DLL::insert_end() {
  nn = nullptr;
  nn = new node;
  std::cout << "Enter data: ";
  std::cin >> nn->data;
  nn->next = nullptr;
  nn->prev = nullptr;

  if (header == nullptr) {
    header = nn;
  } else {
    node *cn;
    cn = header;
    while (cn->next != nullptr) {
      cn = cn->next;
    }
    cn->next = nn;
    nn->prev = cn;
  }
}

void DLL::insert_beg() {
  nn = nullptr;
  nn = new node;
  std::cout << "Enter data: " << std::endl;
  std::cin >> nn->data;
  nn->next = header;
  header->prev = nn;
  header = nn;
}

void DLL::insert_pos() {
  nn = nullptr;
  nn = new node;
  int position;

  node *cn = header;
  int count = 0;

  while (cn != nullptr) {
    count++;
    cn = cn->next;
  }

pos:
  std::cout << "Enter position to insert node: " << std::endl;
  std::cin >> position;

  if (position == 1) {
    insert_beg();
  } else if (position == (count + 1)) {
    insert_end();
  } else if (position > (count + 1)) {
    std::cout << "Position invalid. Input a valid position" << std::endl;
    goto pos;
  } else {
    std::cout << "Enter data: " << std::endl;
    std::cin >> nn->data;
    cn = header;
    for (int i = 1; i < position - 1; i++) {
      cn = cn->next;
    }
    nn->next = cn->next;
    cn->next->prev = nn->next;
    cn->next = nn;
    nn->prev = cn->next;
  }
}
void DLL::delete_beg() {
  node *temp_node;
  temp_node = header;
  if (header != nullptr) {
    header = header->next;
    delete temp_node;
    temp_node = nullptr;
  } else {
    std::cout << "No nodes in the list" << std::endl;
  }
}

void DLL::delete_end() {
  node *cn = header;
  node *temp_node = nullptr;

  if (header != nullptr) {
    while (cn->next != nullptr) {
      temp_node = cn;
      cn = cn->next;
    }
    if (temp_node != nullptr) {
      temp_node->next = nullptr;
      delete cn;
    } else {
      delete cn;
      header = nullptr;
    }
  } else {
    std::cout << "No nodes in the list" << std::endl;
  }
}

void DLL::delete_pos() {
  int position;

  node *cn = header;
  int count = 0;

  while (cn != nullptr) {
    count++;
    cn = cn->next;
  }

pos:
  if (header != nullptr) {
    std::cout << "Enter position of node to delete: " << std::endl;
    std::cin >> position;

    if (position == 1) {
      delete_beg();
    } else if (position == count) {
      delete_end();
    } else if (position > count) {
      std::cout << "Invalid position. Try again" << std::endl;
      goto pos;
    } else {
      cn = header;
      node *temp_node = cn;
      for (int i = 1; i < (position - 1); i++) {
        cn = cn->next;
        temp_node = cn->next;
      }
      if (cn == temp_node) {
        temp_node = cn->next;
      }
      cn->next = temp_node->next;
      temp_node->next->prev = temp_node->prev;
      delete temp_node;
    }
  } else {
    std::cout << "No nodes in the list" << std::endl;
  }
}

void DLL::display() {
  node *cn;
  cn = header;
  std::cout << "-----------------------------------------------" << std::endl;
  while (cn != nullptr) {
    std::cout << cn->data << " ";
    cn = cn->next;
  }
  std::cout << "\n-----------------------------------------------" << std::endl;
  delete cn;
  cn = nullptr;
}

int main() {
  DLL student;
  char choice = 1;
  while (choice != '7') {
    std::cout << "*Doubly linked list*" << std::endl;
    std::cout << "\n";
    std::cout << "Enter 1 to add new node in end" << std::endl
              << "Enter 2 to add new node in beginning" << std::endl
              << "Enter 3 to add new node at a position" << std::endl
              << "Enter 4 to delete node at beginning" << std::endl
              << "Enter 5 to delete node at end" << std::endl
              << "Enter 6 to delete node at pos" << std::endl
              << "Enter 7 to exit" << std::endl;
    std::cin >> choice;

    switch (choice) {
      case '1':
        student.insert_end();
        std::cout << '\n';
        student.display();
        break;
      case '2':
        student.insert_beg();
        std::cout << '\n';
        student.display();
        break;
      case '3':
        student.insert_pos();
        std::cout << '\n';
        student.display();
        break;
      case '4':
        student.delete_beg();
        std::cout << '\n';
        student.display();
        break;
      case '5':
        student.delete_end();
        std::cout << '\n';
        student.display();
        break;
      case '6':
        student.delete_pos();
        std::cout << '\n';
        student.display();
        break;
      case '7':
        std::cout << '\n';
        student.display();
        std::cout << "Exiting...." << std::endl;
        break;
      default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }
  }
}
