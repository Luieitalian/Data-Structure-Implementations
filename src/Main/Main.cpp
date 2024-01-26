#include "../LinkedList/LinkedList.cpp"
#include <iostream>

using namespace std;

int main() {
  LinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  cout << list.value_n_from_end(1);
}