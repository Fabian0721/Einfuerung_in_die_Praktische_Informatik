#include <iostream>
#include <string>
#include <fstream>
//Das ist die Aufgabe zwei die Bewertet werden soll:
void copytext()
{
    //Lese den Dateinamen ein
    std::string name;
    std::cout << "Geben Sie den Dateinamen an (ohne Endung) = " << std::endl;
    std::cin >> name;

    //erzeuge die Dateinamen
    std::string filename_original = name + ".txt";
    std::string filename_copy = name + "-a.txt";

    // erzeuge die Ein/Ausgabestreams
    std::ifstream Eingabestream;
    std::ofstream Ausgabestream;

    std::string Ausgabestring;

    //oeffne den Eingabestream
    Eingabestream.open(filename_original, std::ifstream::in);
    //öffne den Ausgabestream
    Ausgabestream.open(filename_copy, std::ofstream::out);

    // itteriere über die Ausgabe der einzelnen Zeilen des originalTextes
    //und schreibe die Zeile in die Ausgabedatei
    int Line = 1;
    while (getline(Eingabestream, Ausgabestring))
    {
      Ausgabestream << Line << ": " << Ausgabestring << std::endl;
      Line++;
    }

    // schliesse die Streams
    Eingabestream.close();
    Ausgabestream.close();
}



int main()
{
    copytext();
}
