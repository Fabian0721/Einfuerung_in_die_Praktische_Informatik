#include "fcpp.hh"
#include <string.h> // fuer strlen, Laenge eines C-Strings

//g++ --std=c++14 aufgabe03.cc -Wall -o aufgabe03

// Definieren Sie hier Ihren Stack und legen Sie eine Instanz als globale
// Variable an
struct stack {
  int rechnung[3];
  int elementAnzahl;
};
stack stapel;
int top = 0;

//Stapel Operationen
void push( int e ) {
  stapel.rechnung[top] = e;
  top = top + 1;
}

bool empty() {
  return top == 0;
}

int pop() {
  top = top - 1;
  return stapel.rechnung[top];
}

// Funktion, die auf dem Stack eine Rechenoperation durchfuehrt
// Rueckgabewert: ob die Berechnung durchgefuehrt werden konnte
bool rechne( char operation )
{
  int ersterWert, zweiterWert;
  zweiterWert = pop(); //erster Wert
  ersterWert = pop(); //zweiter Wert
  // Pruefen Sie zunaechst, ob genuegend Zahlen auf dem Stack liegen, und
  // achten Sie bei der Berechnung auf die Reihenfolge der Zahlen
  if (stapel.elementAnzahl < 2) {
    std::cout << "Error: Not a valid entery!" << '\n' <<  "Error: The result will be wrong!" << '\n';
    return false;
  } else {
    if (operation == '+') {
      push(ersterWert + zweiterWert);
      stapel.elementAnzahl = stapel.elementAnzahl - 1;
    }
    if (operation == '-') {
      push(ersterWert - zweiterWert);
      stapel.elementAnzahl = stapel.elementAnzahl - 1;
    }
    if (operation == '*') {
      push(ersterWert * zweiterWert);
      stapel.elementAnzahl = stapel.elementAnzahl - 1;
    }
    if (operation == '/') {
      push(ersterWert / zweiterWert);
      stapel.elementAnzahl = stapel.elementAnzahl - 1;
    }
    return true;
  }
}

int main( int argc, char *argv[] )
{
  // arg enthaelt die als Eingabe uebergebene Zeichenfolge
  char *arg = argv[1];
  std::cout << "Die übergebene Zeichenkette lautet: " << arg << '\n';

  int zeichenint = 0;
  int operationCounter = 0;
  stapel.elementAnzahl = 0;
  bool ziffer = false;

  // Schleife, die die Zeichen der Eingabe nacheinander ablaeuft
  for ( int i=0; i<=strlen(arg); i=i+1 )
  {
    char zeichen = arg[i]; // aktuelles Zeichen
    // Beachten Sie: der Inhalt der Variable zeichen ist der ASCII-Code
    // des entsprechenden Zeichens. Dieser stimmt im Falle der Zeichen '0'..'9'
    // nicht mit der entsprechenden Ziffer Ueberein.

    // Fuegen Sie hier Code ein, der das Zeichen verarbeitet, also Ziffern
    // zu Zahlen zusammenfuegt, Operatoren anwendet und andere Zeichen
    // ignoriert
    if (zeichen < 48 || zeichen > 57) {
      if (zeichenint != 0) {
        ziffer = false;  //Eintrag einer Zahl wenn das Zeichen davor keine Ziffer ist.
        push(zeichenint);
        stapel.elementAnzahl = stapel.elementAnzahl + 1;
        zeichenint = 0;
      }
    } else {
        ziffer = true;
        if (ziffer) {
          zeichenint = (zeichenint * 10) + (zeichen - 48);
        }
    }
    if (zeichen == '+') {
      rechne('+');
      operationCounter++;
    }
    if (zeichen == '-') {
      rechne('-');
      operationCounter++;
    }
    if (zeichen == '*') {
      rechne('*');
      operationCounter++;
    }
    if (zeichen == '/') {
      rechne('/');
      operationCounter++;
    }
  }
  // Hier muessen Sie evtl. den Sonderfall behandeln, dass die Formel keine
  // Operatoren enthaelt
  if (operationCounter == 0) {
    std::cout << "Error: Not enough Operators!" << '\n';
  } else {
    // Pruefen Sie, ob der Stack genau eine Zahl (das Ergebnis) enthaelt, und
    // geben Sie sie gegebenenfalls aus
    if (stapel.elementAnzahl == 1) {
      std::cout << "Ergebnis: " << pop() << '\n';
    }
  }


  return 0;
}
