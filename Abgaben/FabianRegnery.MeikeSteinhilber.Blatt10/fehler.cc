#include <iostream>
#include <cmath>

class FehlerWert {
public:
  //Konstruktor erzeugt und initialisiert FehlerWert
  FehlerWert(double value, double absolutError);
  //Getter Methoden geben wert und absolut aus
  double wert();
  double absolut();
  double relativ();
  //Setter Methoden setzen wert und absoluten
  void Set_wert(double wert);
  void Set_absolut(double absolut);
  void Set_relativ(double relativ);

private:
  double value;
  double absoluteValue;
  double relative;
};

//Konstruktor
FehlerWert::FehlerWert (double val, double abs) {
  value = val;
  absoluteValue = abs;
  relative = 0;
}
//Getter Methoden
double FehlerWert::wert() {
  return value;
}
double FehlerWert::absolut() {
  return absoluteValue;
}
double FehlerWert::relativ() {
  return relative;
}
//Setter Methoden
void FehlerWert::Set_wert(double wert) {
  value = wert;
}
void FehlerWert::Set_absolut(double absolut) {
  absoluteValue = absolut;
}
void FehlerWert::Set_relativ(double relativ) {
  relative = relativ;
}
//Operator Methoden
FehlerWert operator+ (FehlerWert a, FehlerWert b) {
  FehlerWert s( 0.0, 0.0 );
  s.Set_wert( a.wert() + b.wert() );
  s.Set_absolut( sqrt( (a.absolut() * a.absolut()) + (b.absolut() * b.absolut()) ) );
  s.Set_relativ(s.absolut() / s.wert());
  return s;
}
FehlerWert operator* (FehlerWert a, FehlerWert b) {
  FehlerWert s( 0.0, 0.0 );
  s.Set_wert( a.wert() * b.wert() );
  s.Set_relativ( sqrt( ((a.absolut() / a.wert()) * (a.absolut() / a.wert())) + ((b.absolut() / b.wert()) * (b.absolut() / b.wert())) ) );
  s.Set_absolut(s.relativ() * s.wert());
  return s;
}

int main () {

  // Konstruktor nimmt zwei double-Werte: den Wert und den absoluten Fehler
  FehlerWert a(12.0, 3.0), b(6.0, 2.0);

  FehlerWert s = a + b;

  std::cout << s.wert() << " +- " << s.absolut() <<
    " (" << s.relativ() * 100 << " %)" << std::endl;

  FehlerWert p = a * b;

  std::cout << p.wert() << " +- " << p.absolut() <<
    " (" << p.relativ() * 100 << " %)" << std::endl;
    
}
