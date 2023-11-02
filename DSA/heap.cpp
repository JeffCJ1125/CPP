#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  // default heap is a max heap, one the top of max_heap is maximum number in
  // the heap the complete declaration of max_heap :
  // priority_queue<int,vector<int>,less<int>> max_heap;
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;

  vector<int> arr = {1, 4, 2, 3};
  cout << "arr ";
  for (int i = 0; i < arr.size(); i++) {
    min_heap.push(arr[i]);
    max_heap.push(arr[i]);
    cout << arr[i];
    if (i != arr.size() - 1) cout << ", ";
  }
  cout << endl;
  cout << "min_heap top -> bottom ";
  while (!min_heap.empty()) {
    cout << min_heap.top();
    if (min_heap.size() != 1) cout << ", ";
    min_heap.pop();
  }
  cout << endl;
  cout << "max_heap top -> bottom ";
  while (!max_heap.empty()) {
    cout << max_heap.top();
    if (max_heap.size() != 1) cout << ", ";
    max_heap.pop();
  }
  cout << endl;
}