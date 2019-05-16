#include <iostream>
#include <vector>
//Compilen in aktueller Version: g++ --std=c++14 -Wall aufgabe01.cpp -o aufgabe01
double ergebnis;

//Horner Rekursiv
double horner(std::vector<double> coeffs, int deg, double x) {
    if (coeffs.size() == deg+1)
    {
      ergebnis = ((coeffs[0] * x) + coeffs[1]);
      horner(coeffs, deg-1, x);
    } else
    {
      //std::cout << "Das Ergebnis des Coeffs " << coeffs[coeffs.size()-(deg)] << '\n';
      ergebnis = (ergebnis * x) + coeffs[coeffs.size()-(deg)];
      //std::cout << "Das Ergebnis nach Deg: " << deg << " ist: " << ergebnis << '\n';
      if (deg == 1)
      {
        double ausgabe = ergebnis;
        std::cout << "Das Ergebnis vor der Ausgabe: " << ausgabe  << '\n';
        return ausgabe;
      }
      horner(coeffs, deg-1, x);
    }
}

/*double hornerrek(std::vector<double> coeffs, int deg, double x) {
  if (deg == 1) {
    std::cout << "Ergebnis vor der Ausgabe: " << ergebnis << '\n';
    return ergebnis;
  }
  ergebnis = (ergebnis * x) + coeffs[(coeffs.size()+2)-(deg)];
  hornerrek(coeffs, deg-1, x);
}*/

//Horner Iterativ
double hornerit(std::vector<double> coeffs, int deg, double x) {
    for (int i = 0; i < deg+1; i++) {
      ergebnis = (ergebnis * x) + coeffs[i];
    }
    return ergebnis;
}

//Die Kompleexität beträgt o(n)
//Die Vorteile des Hornerschemas sind deutlich weniger Operationen (multiplikationen)
//im Gegensatz zur direkten Berechneung darum weniger Komplex.

int main(int argc, char const *argv[]) {
  //Erstellung Eingabeparameter
  std::vector<double> poly = {-4.0, 0.0, 3.0, -2.0, 3.0};
  int grad = 4;
  double x = 2;

  //Auswertung und Arbeit mit der Funktion
  double ausgabe = hornerit(poly, grad, x);
  std::cout <<"Das Ergebnis nach der Ausgabe: " << ausgabe << '\n';
  return 0;
}
