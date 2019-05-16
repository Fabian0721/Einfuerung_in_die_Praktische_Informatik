#include <iostream>
// g++ --std=c++14 aufgabe01.cpp -Wall -o aufgabe01

//Funktion die die Funktion nachstellt
double wurzelfunktion(double wert, double wurzel )
{
  wurzel = (wert * wert) - wurzel;
  return wurzel;
}

//Funktion die den Mittelwert berechnet und in die Funktion: wurzelfunktion steckt:
double mittelwert (double a, double b, double wurzel)
{
  double mittelwert = wurzelfunktion(((a + b) / 2.0), wurzel);
  return mittelwert;
}

//Funktion die die Eingaben Prueft und eine Fehlermedung gibt:
void pruefen (double a, double b, double wurzel)
{
  if (((wurzelfunktion(a, wurzel) < 0) && (wurzelfunktion(b, wurzel) < 0))
    || ((wurzelfunktion(a, wurzel) > 0) && (wurzelfunktion(b, wurzel) > 0)))
  {
    std::cout << "Fehler!: Ungueltige Eingabe" << '\n';
  }
}

//Funktion die ein Intervall ausgibt:
void intervall(double a, double b, double wurzel)
{
  double werta = a;
  double wertb = b;
  double wertw = wurzel;

  for (int i = 0; i < 43; i++) {
    if (mittelwert(werta, wertb, wertw) > 0) {
      wertb = (werta + wertb) / 2.0;
      //std::cout << "Gesuchter Wert zwischen " << a << " und " << (a + b) / 2.0 << '\n';
    } else {
      if (mittelwert(werta, wertb, wertw) < 0) {
        werta = (werta + wertb) / 2.0;
        //std::cout << "Gesuchter Wert zwischen " << b << " und " << (a + b) / 2.0 << '\n';
      } else {
        if (mittelwert(werta, wertb, wertw) == 0) {
          std::cout << "Fehler!: Mittelwert 0" << '\n';
          break;
        }
      }
    }
  }

  if (mittelwert(werta, wertb, wertw) > 0) {
    std::cout << "Gesuchter Wert zwischen " << a << " und ";
    printf("%.12lf\n", wertb);
  }

  if (mittelwert(werta, wertb, wertw) < 0) {
    std::cout << "Gesuchter Wert zwischen " << b << " und ";
    printf("%.12lf\n", werta);
  }
}

int main(int argc, char const *argv[]) {

  //Eingaben tätigen:
  std::cout << "Geben sie Wert a ein:" << '\n';
  double a;
  std::cin >> a;

  std::cout << "Geben sie Wert b ein:" << '\n';
  double b;
  std::cin >> b;

  std::cout << "Geben sie die Zahl deren Wurzel sie wollen ein:" << '\n';
  double wurzel;
  std::cin >> wurzel;

  //Pruefen der Eingaben auf Gueltigkeit:
  pruefen(a, b, wurzel);

  //Intervall ausgeben:
  intervall(a, b, wurzel);

  return 0;
}

// Um die Wurzel von 2 auf 12 Nachkommastellen genau berechnen zu können
//benötigt unser Programm 43 Iterationen.
// Um die Wurzel von 3 auf 12 Nachkommastellen genau berechnen zu können
//benötigt unser Programm 42 Iterationen.
// Um die Wurzel von 4 auf 12 Nachkommastellen genau berechnen zu können
//benötigt unser Programm ein anderes Intervall, weil bei O nicht definiert ist
//was passieren soll. Unter dem Intervall 0 bis 5, erhalten wir eine auf 12 Nachkommastellen
//genaue ausgabe nach 43 iterationen.

//Beim Newton verfahren verdoppelt sich die anzahl der Korrekten Nachkommastellen bei jedem Iterations
//schritt, somit muss für eine Genauigkeit von 12 Nachkommastellen nur 5 mal Iteriert werden. 
