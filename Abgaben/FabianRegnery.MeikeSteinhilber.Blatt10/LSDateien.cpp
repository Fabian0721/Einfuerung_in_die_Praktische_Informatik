#include <iostream>
#include <string>
#include <fstream>
//Das ist die Aufgabe 2 die nicht bewertet werden soll! Ich habe sie mit eingeschickt damit
//ich trotzdem eine korrektur bekomme, also wo sind die Fehler?
void kopierer(std::string name) {
  //Datei zum Auslesen
  std::ifstream datei;
  datei.open(name + ".txt");
  //Datei zum Schreiben
  std::ofstream neuDatei;
  neuDatei.open(name + "-a.txt");
  //Speicher der Zeile
  std::string zeile;
  //Zaehler
  int i = 0;
  //Uebertragen Zeile fuer Zeile bis zum Ende der Datei
  while (datei.good()) {
    //Liest Zeile von Datei bis zum Zeilenende
    getline(datei, zeile);
    //Kopiert Zeile in neue Datei und stellt ihr Zeilennummer vorran
    neuDatei << i << ": " << zeile << '\n';
    i++;
  }
}

int main(int argc, char const *argv[]) {
  std::string name;
  std::cout << "Geben sie den Namen ihrer Ausgangsdatei an: ";
  std::cin >> name;
  //Kopieren von einer Datei in die nächste unter hinzufügen der Zeilennummern
  kopierer(name);
  std::cout << "Erfolgreich Kopiert" << '\n';
  return 0;
}
