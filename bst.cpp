#include <iostream>
using namespace std;

void printline() { cout << "\n--------------------------\n"; }
struct tnode {
  int data = 0;
  tnode *left = nullptr;
  tnode *right = nullptr;
};

class stack {
public:
  int top = -1;
  tnode *arr[20];
  tnode *pop();
  void push(tnode *temp);
  int is_empty();
};

class tree {
public:
  tnode *root = nullptr;
  tnode *nn = nullptr;

  void insert();
  void rec_inorder(tnode *root);
  void rec_preorder(tnode *root);
  void rec_postorder(tnode *root);
  void rec_descending(tnode *root);
  void inorder(tnode *root);
  void preorder(tnode *root);
  void postorder(tnode *root);
  void descending();
  tnode *search(tnode *root, int value);
  tnode *parent_node(tnode *root, int value);
  tnode *delete_val(tnode *root, int value);
};

int stack::is_empty() {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}
tnode *stack::pop() {
  if (!this->is_empty()) {
    tnode *temp = arr[top];
    top--;
    return temp;
  }
}
void stack::push(tnode *temp) {
  top++;
  arr[top] = temp;
}

void tree::insert() {
  nn = new tnode;
  cout << "Enter data: " << endl;
  cin >> nn->data;

  if (root == nullptr) {
    root = nn;
  } else {
    tnode *temp, *parent;
    temp = root;

    while (temp != nullptr) {
      parent = temp;
      if (temp->data > nn->data) {
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }

    if (parent->data > nn->data) {
      parent->left = nn;
    } else {
      parent->right = nn;
    }
  }
  cout << "\nData entered successfully" << endl;
  cout << "---------------------" << endl;
  rec_inorder(root);
  cout << "\n---------------------" << endl;
}

void tree::rec_inorder(tnode *root) {
  tnode *temp = root;
  if (temp != nullptr) {
    rec_inorder(temp->left);
    cout << temp->data << " ";
    rec_inorder(temp->right);
  }
}

void tree::rec_descending(tnode *root) {
  tnode *temp = root;
  if (temp != nullptr) {
    rec_descending(temp->right);
    cout << temp->data << " ";
    rec_descending(temp->left);
  }
}

void tree::rec_preorder(tnode *root) {
  tnode *temp = root;
  if (temp != nullptr) {
    cout << temp->data << " ";
    rec_preorder(temp->left);
    rec_preorder(temp->right);
  }
}

void tree::rec_postorder(tnode *root) {
  tnode *temp = root;
  if (temp != nullptr) {
    rec_postorder(temp->left);
    rec_postorder(temp->right);
    cout << temp->data << " ";
  }
}

void tree::inorder(tnode *root) {
  stack s;
  tnode *temp = root;
  while (temp != nullptr || !s.is_empty()) {
    if (temp != nullptr) {
      s.push(temp);
      temp = temp->left;
    } else {
      temp = s.pop();
      cout << temp->data << " ";
      temp = temp->right;
    }
  }
}

void tree::preorder(tnode *root) {
  stack s;
  tnode *temp = root;
  while (temp != nullptr || !s.is_empty()) {
    if (temp != nullptr) {
      cout << temp->data << " ";
      s.push(temp);
      temp = temp->left;
    } else {
      temp = s.pop();
      temp = temp->right;
    }
  }
}
// TODO: postorder using one stack

void tree::postorder(tnode *root) {
  stack s1, s2;
  if (root == nullptr) {
    cout << "Empty tree\n";
    return;
  }
  tnode *temp = root;
  s1.push(temp);
  while (!s1.is_empty()) {
    temp = s1.pop();
    s2.push(temp);
    if (temp->left != nullptr) {
    //if(temp->left_is_child)
      s1.push(temp->left);
    }
    if (temp->right != nullptr) {
      s1.push(temp->right);
    }
  }
  while (!s2.is_empty()) {
    tnode *temp = s2.pop();
    cout << temp->data << " ";
  }
}

tnode *tree::search(tnode *root, int value) {
  tnode *temp = root;
  while (temp != nullptr) {
    if (temp->data == value) {
      break;
    } else {
      if (value < temp->data) {
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }
  }
  return temp;
}

tnode *tree::parent_node(tnode *root, int value) {
  tnode *temp = root;
  tnode *parent = nullptr;
  while (temp != nullptr) {
    if (temp->data == value) {
      break;
    } else {
      parent = temp;
      if (value < temp->data) {
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }
  }
  if(parent->left->data == value || parent->right->data == value){
    return parent;
  }else{
    return nullptr;
  }
}

tnode *tree::delete_val(tnode *root, int value) {
  tnode *temp = root;
  tnode *cn = search(temp, value);
  tnode *parent = parent_node(temp, cn->data);

  // Leaf node
  if (cn->right == nullptr && cn->left == nullptr) {
    if (cn == root) {
      root = nullptr;
      cout << "Value deleted, tree is empty now";
      return root;
    } else {
      if (cn->data > parent->data) {
        parent->right = nullptr;
      } else {
        parent->left = nullptr;
        }
    }
    return root;
  }
  //node with left child
  else if (cn->left != nullptr && cn->right == nullptr) {
    if (cn == root) {
      root = root->left;
      return root;
    }
    if (parent->left == cn) {
      parent->left = cn->left;
    } else {
      parent->right = cn->left;
    }
    delete cn;
  }
  // node with right child
  else if (cn->left == nullptr && cn->right != nullptr) {
    if (cn == root) {
      root = root->right;
      return root;
    }
    if (parent->right == cn) {
      parent->right = cn->right;
    } else {
      parent->left = cn->right;
    }
    delete cn;
  }
  // two child
  else if (cn->left != nullptr && cn->right != nullptr) {
    tnode *replacement = cn->right;
    while (replacement->left) {
      replacement = replacement->left;
    }
    int temp_var = replacement->data;
    delete_val(root, replacement->data);
    cn->data = temp_var;
    return root;
  }
  return root;
}

int main() {
  tree t1;
  int choice = 0;
  while (choice < 15) {
    cout << "\n1.Insert data\n2.Display Inorder\n3.Display Preorder\n4.Display "
            "Postorder\n5.Display Descending\n6.Display Inorder(non-recursive) "
            "\n7.Display Preorder(non-recursive)\n8.Display Postorder "
            "(non-recursive)\n9.Search\n10.Delete node\n11.Exit\n";
    cout << "Enter choice: " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      t1.insert();
      break;
    case 2:
      printline();
      t1.rec_inorder(t1.root);
      printline();
      break;
    case 3:
      printline();
      t1.rec_preorder(t1.root);
      printline();
      break;
    case 4:
      printline();
      t1.rec_postorder(t1.root);
      printline();
      break;
    case 5:
      printline();
      t1.rec_descending(t1.root);
      printline();
      break;
    case 6:
      printline();
      t1.inorder(t1.root);
      printline();
      break;
    case 7:
      printline();
      t1.preorder(t1.root);
      printline();
      break;
    case 8:
      printline();
      t1.postorder(t1.root);
      printline();
      break;
    case 9: {
      int value_to_search;
      cout << "Enter value: " << endl;
      cin >> value_to_search;
      tnode *temp = t1.search(t1.root, value_to_search);
      printline();
      if (temp == nullptr) {
        cout << "Element not found";
      } else {
        cout << "Element found " << temp->data;
      }
      printline();
      break;
    }
    case 10:
      int value_to_delete;
      cout << "Enter value: " << endl;
      cin >> value_to_delete;
      t1.root = t1.delete_val(t1.root, value_to_delete);
      cout << '\n' << value_to_delete << " successfully deleted";
      printline();
      t1.inorder(t1.root);
      printline();
      
      break;
    case 11:
      return 0;
      default:
        return 0;
    }
  }
  return 0;
}
