#include <vector>
#include <iostream>

int main(int argc, char const *argv[]) {
  std::vector<int> v;
  int i = 1;
  while (true) {
    i++;
    v.push_back(i);
    //std::cout << v[i] << '\n';
  }

  /*
  while (i < 2000) {
    v.push_back(i);
    i++;
    std::cout << v[i] <<std::endl;
  }
  */
  return 0;
}
