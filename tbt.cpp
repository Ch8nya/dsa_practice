#include <iostream>
using namespace std;

void printline() { cout << "\n--------------------------\n"; }
struct tnode {
  int data = 0;
  tnode *left = nullptr;
  tnode *right = nullptr;
  bool right_is_child = 0;
  bool left_is_child = 0;
};

class tbt {
public:
  tnode *root = nullptr;
  tnode *dummy = nullptr;
  tnode *nn = nullptr;

  tbt() {
    dummy = new tnode;
    dummy->data = -99;
    dummy->left = dummy->right = nullptr;
    dummy->right_is_child = dummy->left_is_child = 0;
  }

  void insert();
  void rec_inorder(tnode *root);
  void inorder();
};

void tbt::insert() {
  nn = new tnode;
  cout << "Enter value: " << endl;
  cin >> nn->data;

  if (root == nullptr) {
    root = nn;
    nn->left = nn->right = dummy;
    dummy->left = nn;
    dummy->left_is_child = 1;
  } else {
    tnode *cn;
    cn = root;
    while (cn != nullptr) {
      if (nn->data < cn->data) {
        if (cn->left_is_child == 1) {
          cn = cn->left;
        } else {
          nn->left = cn->left; // here temp->left will be pointing to dummy
          cn->left = nn;
          cn->left_is_child = 1;
          nn->right = cn;
          nn->right_is_child = 0;
          cn = nullptr;
        }
      } else {
        if (cn->right_is_child == 1) {
          cn = cn->right;
        } else {
          nn->right = cn->right;
          cn->right = nn;
          cn->right_is_child = 1;
          nn->left = cn;
          nn->left_is_child = 0;
          cn = nullptr;
        }
      }
    }
  }
}

void tbt::inorder() {
  tnode *cn = root;
  while (cn != nullptr) {
    while (cn->left != nullptr && cn->left_is_child) {
      cn = cn->left;
    }

    std::cout << cn->data << " ";

    while (cn->right != nullptr && !cn->right_is_child) {
      cn = cn->right;
      if (cn != dummy) {
        std::cout << cn->data << " ";
      }
    }
    cn = cn->right;
  }
}
int main() {
  int choice = 0;

  tbt t1;
  while (choice < 5) {
    cout << "\nEnter choice\n1.Insert\n2.display\n3.Exit\n";
    cin >> choice;
    switch (choice) {
    case 1:
      t1.insert();
      break;
    case 2:
      // t1.rec_inorder(t1.root);
      t1.inorder();
      break;
    case 3:
      return 0;
    }
  }
}
