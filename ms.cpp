#include <iostream>
using namespace std;
int a[25];

void merge(int beg, int mid, int end) {
  int i, j, k;
  int n1 = mid - beg + 1;
  int n2 = end - mid;

  int larray[n1], rarray[n2];

  for (int i = 0; i < n1; i++) {
    larray[i] = a[beg + i];
  }
  for (int j = 0; j < n2; j++) {
    rarray[j] = a[mid + j + 1];
  }
  i = 0, j = 0, k = beg;

  while (i < n1 && j < n2) {
    if (larray[i] <= rarray[j]) {
      a[k] = larray[i];
      i++;
    } else {
      a[k] = rarray[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    a[k] = larray[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = rarray[j];
    j++;
    k++;
  }
}

void merge_sort(int beg, int end) {
  if (beg >= end)
    return;

  int mid = beg + (end - beg) / 2;

  merge_sort(beg, mid);
  merge_sort(mid + 1, end);

  merge(beg, mid, end);
}

int main() {
  int count;
  cout << "Enter number of elements:" << endl;
  cin >> count;

  for (int i = 0; i < count; i++) {
    cin >> a[i];
  }
  merge_sort(0, count - 1);

  for (int i = 0; i < count; i++) {
    cout << a[i] << " ";
  }
}
