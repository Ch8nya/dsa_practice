#include <iostream>
using namespace std;
const int SIZE = 20;

class stack {
 public:
  int stack[SIZE];
  void push(int temp);
  int pop();
  int is_empty();
  int is_full();
  int top = -1;
};

class queue {
 public:
  int queue[SIZE];
  int front = -1;
  int rear = -1;

  int enqueue(int temp);
  int dequeue();
  int is_empty();
  int is_full();
};

void stack::push(int temp) {
  top++;
  stack[top] = temp;
}

int stack::pop() {
  if (!is_empty()) {
    int temp = stack[top];
    top--;
    return temp;
  }
}

int stack::is_empty() {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int stack::is_full() {
  if (top > SIZE - 1) {
    return 1;
  } else {
    return 0;
  }
}

int queue::is_full() {
  if (rear > SIZE - 1) {
    return 1;
  } else {
    return 0;
  }
}

int queue::is_empty() {
  if (front == -1 && rear == -1) {
    return 1;
  } else {
    return 0;
  }
}

int queue::enqueue(int temp) {
  if (front == -1 && rear == -1) {
    front++;
    rear++;
    queue[front] = temp;
  } else {
    rear++;
    queue[rear] = temp;
  }
}

int queue::dequeue() {
  int temp = queue[front];
  if (front == rear) {
    front = rear = -1;
  } else {
    front++;
  }
  return temp;
}

class graph {
 public:
  int adj_matrix[10][10] = {};
  int visited[10] = {};
  int edges;
  int vertex;

  void create();
  void display();
  void dfs_recursive(int v1);
  void dfs_non_recursive(int v1);
  void bfs(int v1);
  void clear_visited();
};
void graph::create() {
  int v1, v2, vert, edges;
  cout << "Enter number of vertices:  " << endl;
  cin >> vert;
  cout << "Enter number of edges:  " << endl;
  cin >> edges;

  vertex = vert;
  this->edges = edges;

  cout << "Enter the edges: " << endl;
  while (edges--) {
    cin >> v1 >> v2;
    adj_matrix[v1][v2] = adj_matrix[v2][v1] = 1;
  }

  cout << "Adjacency Matrix created" << endl;
}

void graph::display() {
  for (int i = 0; i < vertex; i++) {
    for (int j = 0; j < vertex; j++) {
      cout << adj_matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void graph::dfs_recursive(int v1) {
  int v2;
  cout << v1 << " ";
  visited[v1] = 1;

  for (v2 = 0; v2 < vertex; v2++) {
    if (adj_matrix[v1][v2] == 1 && visited[v2] == 0) {
      dfs_recursive(v2);
    }
  }
}

void graph::dfs_non_recursive(int v1) {
  stack s;
  s.push(v1);
  visited[v1] = 1;

  while (!s.is_empty()) {
    v1 = s.pop();
    cout << v1 << " ";
    for (int v2 = 0; v2 < vertex; v2++) {
      if (adj_matrix[v1][v2] == 1 && visited[v2] == 0) {
        s.push(v2);
        visited[v2] = 1;
      }
    }
  }
}

void graph::clear_visited() {
  for (int i = 0; i < vertex; i++) {
    visited[i] = 0;
  }
}

void graph::bfs(int v1) {
  queue q;
  q.enqueue(v1);
  visited[v1] = 1;

  while (!q.is_empty()) {
    v1 = q.dequeue();
    cout << v1 << " ";

    for (int v2 = 0; v2 < vertex; v2++) {
      if (adj_matrix[v1][v2] == 1 && visited[v2] == 0) {
        q.enqueue(v2);
        visited[v2] = 1;
      }
    }
  }
}
int main() {
  graph g1;
  int choice = 0;
  while (choice < 7) {
    cout << "\nEnter choice: " << endl;
    cout << "1.Create a graph\n2.Display Adjacency Matrix\n3.DFS "
            "Recursive\n4.DFS Non-Recursive\n5.BFS\n6.Exit\n";
    cin >> choice;

    switch (choice) {
      case 1:
        g1.create();
        break;
      case 2:
        g1.display();
        break;
      case 3:
        g1.dfs_recursive(0);
        g1.clear_visited();
        break;
      case 4:
        g1.dfs_non_recursive(0);
       g1.clear_visited();
        break;
      case 5:
        g1.bfs(0);
       g1.clear_visited();
        break;
      case 6:
        return 0;
    }
  }
}
