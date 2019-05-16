#include <iostream>
#include <string>
#include <algorithm>
//g++ --std=c++14 -Wall aufgabe02.cpp -o aufgabe02
  std::string poly() {
  std::cout << "Geben sie ein Polynom folgender Form ein: " << '\n'
  << "2 + 2x - 3x^2 + 4x^3"<< '\n';
  std::string polynom;
  std::cin >> polynom;
  replace(polynom.begin(), polynom.end(), '-', '+');
  //std::vector<std::string> sppoly;
  //sppoly = split(polynom,'+');
  return polynom;
}

int main(int argc, char const *argv[]) {
  std::cout << poly() << '\n';
  return 0;
}
