#include <iostream>

class Filter {
public:
  virtual void Apply() = 0;
protected:
  int a = 10;
};

class Child : public Filter {
public:
  virtual void Apply() {
    std::cout << a << std::endl;
  }
};

int main() {
  Child ch;
  ch.Apply();

  Filter& filter_ref = ch;
  filter_ref.Apply();

  Filter* filter_ptr = &ch;
  filter_ptr->Apply();
  return 0;
}
