#include <limits.h>

#include <iostream>
using namespace std;

class mst {
 public:
  int vertex, edge;
  int adj_matrix[10][10] = {};
  int sp[10][10] = {};
  void create_graph();
  void display();
  void sptree();
};

void mst::create_graph() {
  int v1, v2, v, e;
  cout << "Enter no of vertices: " << endl;
  cin >> v;
  cout << "Enter no of edges: " << endl;
  cin >> e;

  vertex = v;
  edge = e;

  cout << "Enter vertex 1, vertex 2 and weight for the the edges: " << endl;
  while (e--) {
    cin >> v1 >> v2;
    cin >> adj_matrix[v1][v2];
    adj_matrix[v2][v1] = adj_matrix[v1][v2];
  }
  cout << "Adjacency matrix created" << endl;
}

void mst::display() {
  for (int i = 0; i < vertex; i++) {
    for (int j = 0; j < vertex; j++) {
      cout << adj_matrix[i][j] << "\t";
    }
    cout << endl;
  }
}

void mst::sptree() {
  int cost[10][10] = {}, dist[10] = {}, visited[10] = {}, source[10] = {};

  //make cost matrix
  int min_dist, u, v;
  for (int i = 0; i < vertex; i++) {
    for (int j = 0; j < vertex; j++) {
      if (adj_matrix[i][j] == 0) {
        cost[i][j] = INT_MAX;
      } else {
        cost[i][j] = adj_matrix[i][j];
      }
    }
  }

  // start from vertex 0
  dist[0] = 0;
  visited[0] = 1;
  //source[0] = -1;

  // calculate distance of all vertices
  for (int i = 1; i < vertex; i++) {
    dist[i] = cost[0][i];
    source[i] = 0;
    visited[i] = 0;
  }

  int min_cost = 0;
  int E = vertex - 1;
  while (E--) {
    min_dist = INT_MAX;

    // find edge with minimum distance from source
    for (int i = 1; i < vertex; i++) {
      if (visited[i] == 0 && dist[i] < min_dist) {
        min_dist = dist[i];
        v = i;
      }
    }

    // add edge in spanning tree and mark vertex as visited
    u = source[v];
    sp[u][v] = sp[v][u] = dist[v];
    visited[v] = 1;

    for (int i = 1; i < vertex; i++) {
      if (visited[i] == 0 && cost[i][v] < dist[i]) {
        dist[i] = cost[i][v];
        source[i] = v;
      }
    }
    min_cost = min_cost + cost[u][v];
  }
}

int main() {
  mst m1;
  int choice = 0;
  while (choice < 7) {
    cout << "\nEnter choice: " << endl;
    cout << "1.Create a graph\n2.Display Adjacency Matrix\n3.Display "
            "MST\n4.Exit\n";
    cin >> choice;

    switch (choice) {
      case 1:
        m1.create_graph();
        break;
      case 2:
        m1.display();
        break;
      case 3:
        m1.sptree();
        for (int i = 0; i < m1.vertex; i++) {
          for (int j = 0; j < m1.vertex; j++) {
            cout << m1.sp[i][j] << " ";
          }
          cout << endl;
        }
        break;
      case 4:
        return 0;
    }
  }
}
