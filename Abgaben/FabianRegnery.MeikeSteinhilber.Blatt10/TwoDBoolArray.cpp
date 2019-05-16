#include <iostream>

class TwoDBoolArray
{
public:
  // Initialisiere ein n x m Array
  TwoDBoolArray( int zeil, int spalt ) {
    n = zeil;
    m = spalt;
    daten = new bool[n * m];
    for (int i = 0; i < (n * m); i++) {
      daten[i] = false;
    }
  }
  // Copy-Konstruktor
  TwoDBoolArray( const TwoDBoolArray& other ) {
    n = other.n;
    m = other.m;
    daten = new bool[n * m];
    for (int i = 0; i < (n * m); i++) {
      daten[i]=other.daten[i];
    }
  }
  // Destruktor
  ~TwoDBoolArray() {
    delete[] daten;
  }
  // Zuweisungsoperator
  TwoDBoolArray& operator=( const TwoDBoolArray& other ) {
    delete[] daten;
    n = other.n;
    m = other.m;
    daten = new bool[n * m];
    for (int i = 0; i< (n * m); i++) {
      daten[i]=other.daten[i];
    }
  }
  // Gebe Zeilenzahl zurueck
  int rows() {
    return n;
  }
  // Gebe Spaltenzahl zurueck
  int cols() {
    return m;
  }

  // ein Objekt das vom operator[] zurueckgegeben wird
  class RowProxy
  {
  public:
    // Konstruktor
    RowProxy( bool* daten, int zeile, int spalte ) {
      _daten = daten;
      for ( int i = 0; i < (zeile * spalte); i++ ) {
        _daten++;
      }
      zeilenindex = zeile;
      spaltenzahl = spalte;
    }
    // der "innere" Klammerzugriffsoperator
    bool& operator[]( int j ) {
      return _daten[j];
    }

  private:
    bool* _daten;
    int zeilenindex; //länge einer Zeile
    int spaltenzahl; //Anzahl an Spalten
  };

  // der "aeussere" Klammerzugriffsoperator
  RowProxy operator[]( int i ) {
    RowProxy weiterleitung(daten, i, m);
    return weiterleitung;
  }

private:
  bool* daten;
  int n, m;
};


int main(int argc, char const *argv[]) {
  //Initialisieren von Matrix
  TwoDBoolArray matr(2,3);
  //Ausgabe von Zeilen- und Spaltenanzahl
  std::cout << "Zeilenzahl: " << matr.rows() << '\n';
  std::cout << "Spaltenzahl: " << matr.cols() << '\n';
  //Ausgabe von Wert
  matr[1] [1] = true;
  std::cout << "Wert: " << matr[1] [1] << '\n';

  //Testcode der gegeben war:
  // zu Teilaufgabe a)
  TwoDBoolArray matrix1 = TwoDBoolArray(2, 3);

  std::cout << "Initialisierte Matrix: " << std::endl;
  for (int i = 0; i < matrix1.rows(); i++)
  {
    for (int j = 0; j < matrix1.cols(); j++)
    {
      std::cout << matrix1[i][j] << " ";
    }
    std::cout << std::endl;
  }

  matrix1[0][0] = 1;
  matrix1[0][2] = 1;
  matrix1[1][1] = 1;
  std::cout << "Matrix nach dem Schreiben: " << std::endl;
  for (int i = 0; i < matrix1.rows(); i++)
  {
    for (int j = 0; j < matrix1.cols(); j++)
    {
      std::cout << matrix1[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
