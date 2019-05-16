#include <iostream>
#include <string>
#include <utility>

void reverse(std::string& s) {
  for (int i = 0; i < (s.size()/2); i++) {
    std::swap(s[i], s[s.size()-1-i]);
  }
}

int main(int argc, char const *argv[]) {
  std::string kette = "HalloWelt";
  std::cout << kette << '\n';
  reverse(kette);
  std::cout << kette << '\n';
  return 0;
}

//Aufgabe 05
//128+64+16+8+4+1 = 221
//64+32+16+4 = 1110100
