#include <iostream>
// g++ --std=c++14 aufgabe03.cpp -Wall -o aufgabe03
int main(int argc, char const *argv[]) {

  int testArray[10];
  int i, j, uebergabe, eingabe;
  int meldung = 1;
  int lange = 10;

  //Pruefen das der Array leer ist:
  for (int l = 0; l < 10; l++)
  {
    testArray[l] = 0;
  }

  //Arbeiten mit dem Array
  for (int h = 0; h < 10; h++)
  {
    //Beschreiben des Arrays
    std::cin >> eingabe;
      //Pruefen auf Terminierung:
      if (eingabe == -1)
      {
        break;
      }
      //Pruefen auf Ausgabe forderung:
      if (eingabe == 0)
      {
        meldung = 0;
        break;
      }
      //Pruefen auf illegale Eingabe
      if (eingabe < -1)
      {
        std::cout << "Fehler!: Illegale Eingabe" << '\n';
        break;
      }
    testArray[0] = eingabe;

    //Sortieren mit BubbleSort (siehe Wikipedia)
    for (i = 1; i < lange; i++)
    {
      for (j = 0; j < lange; j++)
			{
        if (testArray[j] > testArray[j+1])
				{
          uebergabe = testArray[j];
          testArray[j] = testArray[j+1];
          testArray[j+1] = uebergabe;
        }
      }
    }
    //Fehlermeldung Array voll:
    if (h == 9)
    {
      std::cout << "Fehler!: Array voll" << '\n';
    }
  }

  //Array ausgeben
  if (meldung == 0)
  {
    std::cout << "Endausgabe:" << '\n';
    for (int i = 0; i < 10; i++)
    {
      std::cout << testArray[i] << '\n';
    }
  }
  return 0;
}
