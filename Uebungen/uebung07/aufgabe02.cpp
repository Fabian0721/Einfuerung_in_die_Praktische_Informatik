#include <iostream>

//Circular Buffer Program
// g++ --std=c++14 aufgabe02.cpp -Wall -o aufgabe02

int main(int argc, char const *argv[]) {
  bool errorPossible = false;
  int zaehler = 0;
  //Create the circular buffer and write first value:
  int buffer[10];
  buffer[0] = 1;
  for (int i = 1; i < 10; i++) {
    buffer[i] = 0;
  }
  //Create and set Pointer:
  int* in;
  int* out;
  int* end;
  in = buffer + 1;
  out = buffer;
  end =& buffer[10];
  //Counter stuff:
  bool ueberholt = false;
  int counter = 0;
  //The Loop runns until the program ends:
  while (true) {
    int input;
    std::cin >> input;
    //If wanted end program:
    if (input < 0) {
      std::cout << "You end the program!" << '\n';
      break;
    }
    //If wanted output of oldest value:
    if (input == 0) {
      std::cout << "Oldest value: " << *out << '\n';
      out = out + 1;
    }
    //Write input into the buffer:
    if (input > 0) {
      *in = input;
      in = in + 1;
      counter = counter + 1;
      if (ueberholt) {
        out = out + 1;
      }
    }
    //Creats a circle:
    if (in == end) {
      in = in - 10;
      ueberholt = true;
    }
    if (out == end) {
      out = out - 10;
      ueberholt = true;
    }
    //Terminal output of the circular buffer:
    for (int i = 0; i < 10; i++) {
      int* adress;
      adress =& buffer[i];
      if (in == adress && out == adress) {
        std::cout << "< > :: " << buffer[i] << '\n';
      } else {
        if (in == adress) {
          std::cout << "  > :: " << buffer[i]<< '\n';
        } else {
          if (out == adress) {
            std::cout << "<   :: " << buffer[i]<< '\n';
          } else {
            std::cout << "    :: " << buffer[i]<< '\n';
          }
        }
      }
    }
    //Error finder, for a komplex but possible Error.
    if (in != out) {
      if (errorPossible == true && input != 0) {
        zaehler = 0;
        std::cout << "zaehlerstand: " << zaehler << '\n';
      }
      if (errorPossible == true && input == 0) {
        zaehler = zaehler + 1;
        std::cout << "zaehlerstand: " << zaehler << '\n';
      }
    }
    if (in == out) {
      if (errorPossible == true && input == 0) {
        if (zaehler == 9) {
          std::cout << "Error: Not possible in a circular buffer!" << '\n';
          break;
        }
      }
      if (errorPossible == false) {
        errorPossible = true;
      }
    }
    //Warning if circular buffer is the first time full:
    if(counter == 9) {
      std::cout << "Warning: circular buffer full" << '\n';
    }

}
}
