#include <iostream>
using namespace std;

struct tnode {
  int data = 0;
  tnode *left = nullptr;
  tnode *right = nullptr;
};

class avl {
public:
  tnode *root = nullptr;

  void display(tnode *root);
  void display_preorder(tnode *root);
  void display_postorder(tnode *root);
  int balance_factor(tnode *node);
  int height(tnode *node);
  tnode *insert(tnode *root, int value);
  tnode *LL(tnode *node);
  tnode *RR(tnode *node);
  tnode *LR(tnode *node);
  tnode *RL(tnode *node);
};

int avl::height(tnode *node) {
  if (node == nullptr) {
    return 0;
  } else {
    int temp =
        1 + max(height(node->left), height(node->right)); // added 1 for root
    return temp;
  }
}

int avl::balance_factor(tnode *node) {
  if (node == nullptr) {
    return 0;
  } else {
    return height(node->left) - height(node->right);
  }
}

tnode *avl::LL(tnode *node) {
  tnode *temp = node->left;
  node->left = temp->right;
  temp->right = node;
  return temp;
}

tnode *avl::RR(tnode *node) {
  tnode *temp = node->right;
  node->right = temp->left;
  temp->left = node;
  return temp;
}

tnode *avl::LR(tnode *node) {
  node->left = RR(node->left);
  node = LL(node);
  return node;
}

tnode *avl::RL(tnode *node) {
  node->right = LL(node->right);
  node = RR(node);
  return node;
}

tnode *avl::insert(tnode *root, int value) {
  if (root == nullptr) {
    root = new tnode;
    root->data = value;
    root->left = root->right = nullptr;
  } else {
    if (value < root->data) {
      root->left = insert(root->left, value);
      if(balance_factor(root) == 2){
        if(value < root->left->data){
          root = LL(root);
        } else{
          root = LR(root);
        }
      }
    } else {
      root->right = insert(root->right, value);
      if(balance_factor(root) == -2){
        if(value > root->right->data){
          root = RR(root);
        } else{
          root = RL(root);
        }
      }
    }
  }
  return root;
}

void avl::display(tnode *root) {
  if (root != nullptr) {
    display(root->left);
    cout << root->data << " ";
    display(root->right);
  }
}

void avl::display_preorder(tnode *root) {
  if (root != nullptr) {
    cout << root->data << " ";
    display_preorder(root->left);
    display_preorder(root->right);
  }
}

void avl::display_postorder(tnode *root) {
  if (root != nullptr) {
    display_postorder(root->left);
    display_postorder(root->right);
    cout << root->data << " ";
  }
}

int main() {
  int choice = 0;

  avl a1;
  while (choice < 5) {
    cout << "\nEnter choice\n1.Insert\n2.Display\n3.Display preoder\n4.Display Postorder\n5.Exit\n";
    cin >> choice;
    switch (choice) {
    case 1:
      int value;
      cout << "Enter value: " << endl;
      cin >> value;
      a1.root = a1.insert(a1.root, value);
      break;
    case 2:
      cout << "\n------------------------\n";
      a1.display(a1.root);
      cout << "\n------------------------\n";
      break;
    case 3:
      cout << "\n------------------------\n";
      a1.display_preorder(a1.root);
      cout << "\n------------------------\n";
      break;
    case 4:
      cout << "\n------------------------\n";
      a1.display_postorder(a1.root);
      cout << "\n------------------------\n";
      break;
      
    case 5:
      return 0;
    }
  }
}
