#include <iostream>
#include <vector>
#include <algorithm>

//Vektor Klasse
template <class T>
class Vector {
public:
  void print() {                                              //Ausgabe des Vektors
    for (int i = 0; i < vect.size(); i++) {
      std::cout << "Vector [ " << i << " ] = " << vect[i] << '\n';
    }
  }
  int size() {                                                //Rückgabe der Anzahl der Vektorelemente
    return vect.size();
  }
  void push_back(T a) {                                       //Einfügen eines Elemnts am Ende
    return vect.push_back(a);
  }
  T max() {                                                   //Rückgabe des größten Elements
    return *std::max_element(vect.begin(), vect.end());
  }
  T operator[] (int a) {                                      //Definition des zugriffes
    return vect[a];
  }
  friend Vector<T> operator+ (Vector<T> a, Vector<T> b) {     //friend Def der Addition
    Vector<T> sum;
    for (int i = 0; i < a.size(); i++) {
      sum.push_back(a[i] + b[i]);
    }
    return sum;
  }
  friend Vector operator* (int skalar, Vector<T> a) {       //friend Def der Skalaren Multipikation
    Vector<T> prod;
    for (int i = 0; i < a.size(); i++) {
      prod.push_back(skalar * a[i]);
    }
    return prod;
  }
private:
  std::vector<T> vect;
};

int main(int argc, char const *argv[]) {


  std::cout <<'\n'<< "Vector-Klasse Anwendungstest Double:" <<'\n'<<'\n';
  Vector<double> Vector1, Vector2, VectorSumme, SkalarProdukt;
  Vector1.push_back(3.3);
  Vector1.push_back(1.98);
  Vector1.push_back(7.45);
  std::cout << "Vektor1:" << '\n';
  Vector1.print();
  std::cout << '\n';
  Vector2.push_back(9.3);
  Vector2.push_back(4.1);
  Vector2.push_back(8.9);
  std::cout << "Vektor2:" << '\n';
  Vector2.print();
  std::cout << '\n';
  //Test der Vektoraddition
  VectorSumme = Vector1 + Vector2;
  std::cout << "VektorSumme:" << '\n';
  VectorSumme.print();
  std::cout << '\n';
  //Test der Skalaren Multipikation
  SkalarProdukt = 5 * VectorSumme;
  std::cout << "Skalarprodukt:" << '\n';
  SkalarProdukt.print();
  std::cout << '\n';
  //Maximalen Wert ausgeben
  std::cout << "Maximum: " << SkalarProdukt.max() << '\n';


  std::cout <<'\n'<< "Vector-Klasse Anwendungstest Integer:" <<'\n'<<'\n';
  Vector<int> Vector3, Vector4, VectorSumme2, SkalarProdukt2;
  Vector3.push_back(9);
  Vector3.push_back(5);
  Vector3.push_back(7);
  std::cout << "Vektor1:" << '\n';
  Vector3.print();
  std::cout << '\n';
  Vector4.push_back(12);
  Vector4.push_back(4);
  Vector4.push_back(8);
  std::cout << "Vektor2:" << '\n';
  Vector4.print();
  std::cout << '\n';
  //Test der Vektoraddition
  VectorSumme2 = Vector3 + Vector4;
  std::cout << "VektorSumme:" << '\n';
  VectorSumme2.print();
  std::cout << '\n';
  //Test der Skalaren Multipikation
  SkalarProdukt2 = 3 * VectorSumme2;
  std::cout << "Skalarprodukt:" << '\n';
  SkalarProdukt2.print();
  std::cout << '\n';
  //Maximalen Wert ausgeben
  std::cout << "Maximum: " << SkalarProdukt2.max() << '\n';


  return 0;
}
