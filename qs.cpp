#include <iostream>
using namespace std;
int a[25];

void swap(int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int partition(int m, int p) {
  int i = m, j = p;
  int pivot = a[m];

  while (i < j) {
    while (pivot >= a[i] && i < p) {
      i++;
    }
    while (pivot < a[j] && j > m) {
      j--;
    }
    if (i <= j) {
      swap(i, j);
    }
  }
  swap(m, j);
  return j;
}

void qs(int m, int p) {
  if (m >= p) {
    return;
  }
  int j;
  j = partition(m, p);
  qs(m, j - 1);
  qs(j + 1, p);
}

int main() {
  int count;
  cout << "Enter number of elements:" << endl;
  cin >> count;

  for (int i = 0; i < count; i++) {
    cin >> a[i];
  }
  qs(0, count - 1);

  for (int i = 0; i < count; i++) {
    cout << a[i] << " ";
  }
}
