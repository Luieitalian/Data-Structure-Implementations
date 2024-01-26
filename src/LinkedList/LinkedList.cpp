#include <iostream>
/**
 * This is a Singly Linked List. It is capable of doing things a regular ARRAY
 * could do.
 */
template <typename T> class LinkedList {
private:
  struct Node {
    T value;
    Node *next;
    Node(const T &_value = 0, Node *_next = nullptr) {
      value = _value;
      next = _next;
    }
  };

  int _size = 0;
  Node *root = nullptr;

  /**
   * Basic node structure that contains value and pointer pairs.
   */

  Node *begin() const { return root; }
  Node *end() const { return nullptr; }

public:
  LinkedList() {}
  ~LinkedList() {}

  const int size() const { return _size; }
  const bool is_empty() const { return begin() == end(); }

  void push_back(const T &item) {
    if (!is_empty()) {
      Node *tmp = begin();

      while (tmp->next != nullptr) {
        tmp = tmp->next;
      }
      tmp->next = new Node(item);
      _size++;
    } else {
      root = new Node(item);
      _size++;
    }
  }

  const T value_at(int index) const {
    if (index < 0 || index >= _size) {
      system("color a");
      std::cerr << "Out of Range!\n";
      std::cin.get();
      std::exit(0);
    }
    Node *tmp = begin();
    int count = 0;
    while (tmp->next != nullptr) {
      if (count == index) {
        return tmp->value;
      }
      tmp = tmp->next;
      count++;
    }
    return tmp->value;
  }

  void push_front(const T &item) {
    if (!is_empty()) {
      Node *tmp = new Node(item);

      tmp->next = root;
      root = tmp;
    } else {
      root = new Node(item);
    }
    _size++;
  }

  void pop_front() {
    if (is_empty()) {
      std::cerr << "List is Empty!\n";
      return;
    } else {
      delete root;
      root = root->next;
      _size--;
    }
  }

  const void print() const {
    if (is_empty()) {
      std::cerr << "List is Empty!\n";
      return;
    } else {
      for (int i = 0; i < size(); i++) {
        std::cout << value_at(i) << " ";
      }
      std::cout << "\n";
    }
  }

  void pop_back() {
    if (is_empty()) {
      std::cerr << "List is Empty!\n";
      return;
    } else if (size() == 1) {
      delete root;
      root = nullptr;
    } else {
      Node *tmp = begin();

      while (tmp->next->next != nullptr) {
        tmp = tmp->next;
      }
      delete tmp->next;
      tmp->next = nullptr;
    }
    _size--;
  }

  const T &front() const { return root->value; }

  const T &back() const {
    Node *tmp = begin();

    while (tmp->next != nullptr) {
      tmp = tmp->next;
    }
    return tmp->value;
  }

  void insert(int index, const T &item) {
    if (index < 0 || index > _size) {
      std::cerr << "Out of Range!\n";
      std::cin.get();
      std::exit(0);
    } else if (index == 0)
      push_front(item);
    else if (index == size())
      push_back(item);
    else {
      int count = 0;
      Node *tmp = begin();
      while (tmp->next != nullptr) {
        if (count == index - 1) {
          Node *newnode = new Node(item, tmp->next);

          tmp->next = newnode;
          _size++;
          break;
        } else {
          tmp = tmp->next;
          count++;
        }
      }
    }
  }

  void erase(int index) {
    if (index < 0 || index >= _size) {
      system("color a");
      std::cerr << "Out of Range!\n";
      std::cin.get();
      std::exit(0);
    } else if (index == 0)
      pop_front();
    else if (index == size() - 1)
      pop_back();
    else {
      Node *tmp = begin();
      int count = 0;
      while (tmp != nullptr) {
        if (count == index - 1) {
          Node *point = tmp->next->next;

          delete tmp->next;
          tmp->next = point;
          _size--;
          break;
        } else {
          tmp = tmp->next;
          count++;
        }
      }
    }
  }

  const T value_n_from_end(int n) {
    if (n <= 0 || n > size()) {
      std::cerr << "Out of Range!\n";
      std::cin.get();
      std::exit(0);
    } else if (is_empty()) {
      std::cerr << "List is Empty!\n";
      std::cin.get();
      std::exit(0);
    } else if (n == 1)
      return back();
    else if (n == size())
      return front();
    else {
      int item_index = size() - n;
      int count = 0;
      Node *tmp = begin();
      while (tmp->next != nullptr) {
        if (count == item_index) {
          tmp = tmp->next;
          return tmp->value;
        } else {
          tmp = tmp->next;
          count++;
        }
      }
    }
  }

  void reverse() {
    if (is_empty()) {
      system("color a");
      std::cerr << "List is Empty!\n";
      std::cin.get();
      std::exit(0);
    } else if (size() == 1) {
      return void();
    } else {
      Node *pointer_front = begin();
      Node *pointer_back = begin();

      T tmp_value_front;
      T tmp_value_back;

      for (int i = 0; i < size() / 2; i++) {

        for (int j = 0; j < i; j++) {
          pointer_front = pointer_front->next;
        }
        tmp_value_front = pointer_front->value;

        for (int j = 0; j < size() - i - 1; j++) {
          pointer_back = pointer_back->next;
        }
        tmp_value_back = pointer_back->value;

        pointer_front->value = tmp_value_back;
        pointer_back->value = tmp_value_front;

        pointer_front = begin();
        pointer_back = begin();
      }
    }
  }

  void remove_value(const T &value) {
    Node *tmp = begin();

    if (is_empty()) {
      std::cerr << "List is Empty!\n";
    } else if (tmp->value == value) {
      erase(0);
    } else {
      int count = 1;
      while (tmp->next != nullptr) {
        tmp = tmp->next;
        if (tmp->value == value) {
          erase(count);
        } else {
          count++;
        }
      }
    }
  }
};