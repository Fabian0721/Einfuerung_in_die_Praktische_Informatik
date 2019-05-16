#include <iostream>

class IntListe {
public:
  // Konstruktor, erzeugt eine leere Liste
  IntListe();
  // Destruktor, löscht gesamten Listeninhalt
  ~IntListe();
  // Gibt Anzahl der Elemente zurück
  int getCount();
  // Gibt zurück ob die Liste leer ist
  bool isEmpty();
  // Gibt die Liste aus
  void print();
  // Fügt die Zahl "Element" an der beliebigen Position "Position" ein.
  void insert( int element, int position );
  // Löscht das Element an der Position "Position"
  void remove( int position );
  // Gibt den Wert des Elemnts an der Position "Postition" zurück
  int getElement( int position );
  // Copy Konstruktor, erstellt deep copy
  IntListe(const IntListe&);
  // Zuweisungsoperator
  IntListe& operator= (const IntListe&);


private:
  struct IntListElem {
    IntListElem* next;  // Zeiger auf naechstes Element
    int value;          // Daten zu diesem Element
  };
  struct IntList {
    int count;          // Anzahl Elemente in der Liste
    IntListElem* first; // Zeiger auf erstes Element der Liste
  };
  IntList* liste = new IntList; //Liste wird als Dynamische Variable erstellt
  IntListElem* elemente;  //Element
  IntListElem* p;  // das entfernte Element
};

//Erzeugt eine leere Liste
IntListe::IntListe() {
  liste->first = nullptr;   // nullptr: Liste ist leer
  liste->count = 0;
  std::cout << "Leere Liste wurde erstellt!" << '\n';
}
//Gibt die Anzahl der Elemente zurück
int IntListe::getCount() {
  return liste->count;
}
//Gibt zurück ob die Liste leer ist
bool IntListe::isEmpty() {
  if (liste->count == 0) {
    return true;
  } else {
    return false;
  }
}
//Gibt die Liste im Terminal aus:
void IntListe::print() {
  IntListElem* printer = liste->first;
  if (isEmpty()) {
    std::cout << "Die Liste ist leer!" << '\n';
  }
  for (int i = 0; i < liste->count; i++) {
    std::cout << "Element Wert: " << printer->value << '\n';
    printer = printer->next;
  }
}
//Fügt Elemente an einer gegebenen Position in die Liste ein
void IntListe::insert( int element, int position ) {
    //Prüfen ob Position erlaubt:
    if (position > ((liste->count)+1)) {
      std::cout << "Error: Die Position ist nicht in der Liste vorhanden" << '\n';
    } else {
      //Verfahren zum ermitteln der Position
      IntListElem* positionPtr = liste->first;
      if (position == 1) {  //Für den Fall das die 1. Position verändert werden soll
        positionPtr = nullptr;
      }
      //PositionsPtr an die Richtige Position schieben
      for (int i = 2; i < position; i++) {
        positionPtr = positionPtr->next;
      }
      //Erzeugen des neuen Elements
      elemente = new IntListElem;
      elemente->value = element;
      //Eintragen des Elements in der Liste
      if (positionPtr==0) {
        elemente->next = liste->first;
        liste->first = elemente;
        liste->count = liste->count + 1;
      } else {
        elemente->next = positionPtr->next;
        positionPtr->next = elemente;
        liste->count = liste->count + 1;
      }
    }
}
//Gibt den  Wert des Elements an der Position "Position" zurück
int IntListe::getElement( int position ) {
  IntListElem* sucher = liste->first;
  for (int i = 1; i < position; i++) {
    sucher = sucher->next;
  }
  return sucher->value;
}
//Loescht das Element an der Position "Position"
void IntListe::remove( int position ) {
  IntListElem* sucher = liste->first;
  for (int i = 2; i < position; i++) {
    sucher = sucher->next;
  }
  //IntListElem* p;  // das entfernte Element
  // entferne Element an der ersten Position
  if (position==1) {
    p = liste->first;
    if (p!=0) {
	     liste->first = p->next;
	     liste->count = liste->count - 1;
	  }
  }
  // entferne Element an der Position die niocht die erste ist.
  p = sucher->next;
  if (position!=1) {
    sucher->next = p->next;
    liste->count = liste->count - 1;
  }
}
//Destrucktor, löscht den gesamten Listeninhalt
IntListe::~IntListe() {
  while(liste->count != 0) {
    remove(1);
    delete p;
  }
}
// Copy Konstruktor, erstellt deep copy
IntListe::IntListe(const IntListe& other) {
    //this->liste->first = other.liste->first;
    //this->liste->count = other.liste->count;

  //deep copy
  if (other.liste->count == 0) {
    this->liste->count = 0;
    this->liste->first = 0;
  } else {
    IntListElem* neuElement;
    neuElement = new IntListElem;
    this->liste->first = neuElement;
    this->liste->count = other.liste->count;
    IntListElem* sucher = other.liste->first;
    neuElement->value = sucher->value; //Sehr wichtiger Code
    neuElement-> next = sucher->next;
  }
}
//Zuweisungsoperator
IntListe& IntListe::operator= (const IntListe& other) {
    while(this->liste->count != 0) {
      remove(1);
      delete p;
    }
    IntListElem* neuElement;
    neuElement = new IntListElem;
    this->liste->first = neuElement;
    this->liste->count = other.liste->count;
    IntListElem* sucher = other.liste->first;
    neuElement->value = sucher->value; //Sehr wichtiger Code
    neuElement-> next = sucher->next;
    return *this;
}

int main(int argc, char const *argv[]) {
  //Testen der Listen Klasse (funktioniert perfekt);
  IntListe ersteListe;
  std::cout << "Ist die Liste leer? " << ersteListe.isEmpty() << '\n';
  std::cout << "Die Anzahl der Listenelemente beträgt: " << ersteListe.getCount() << '\n';
  ersteListe.print();
  ersteListe.insert( 100, 1);
  std::cout << "Ist die Liste leer? " << ersteListe.isEmpty() << '\n';
  std::cout << "Die Anzahl der Listenelemente beträgt: " << ersteListe.getCount() << '\n';
  ersteListe.print();
  ersteListe.insert( 200, 2);
  std::cout << "Ist die Liste leer? " << ersteListe.isEmpty() << '\n';
  std::cout << "Die Anzahl der Listenelemente beträgt: " << ersteListe.getCount() << '\n';
  ersteListe.print();
  ersteListe.insert( 300, 3);
  std::cout << "Ist die Liste leer? " << ersteListe.isEmpty() << '\n';
  std::cout << "Die Anzahl der Listenelemente beträgt: " << ersteListe.getCount() << '\n';
  ersteListe.print();
  std::cout << "Wert an Pos 1 ist: " << ersteListe.getElement(1) << '\n';
  ersteListe.insert( 400, 4);
  std::cout << "Ist die Liste leer? " << ersteListe.isEmpty() << '\n';
  std::cout << "Die Anzahl der Listenelemente beträgt: " << ersteListe.getCount() << '\n';
  ersteListe.print();
  std::cout << "  " << '\n';
  ersteListe.remove(3);
  ersteListe.print();
  //Testen des Copy Konstruktors (funktioniert perfekt)
  IntListe zweiteListe = ersteListe;
  std::cout << "Das ist die zweite Liste: " << '\n';
  zweiteListe.print();
  zweiteListe.insert( 404040, 2);
  std::cout << "  " << '\n';
  zweiteListe.print();
  std::cout << "Nochmal die erste Liste " << '\n';
  ersteListe.print();
  ersteListe.insert( 12345,1);
  std::cout << "  " << '\n';
  ersteListe.print();
  std::cout << "Das ist die zweite Liste: " << '\n';
  zweiteListe.print();
  //Testen des Zuweisungsoperators (macht probleme)
  IntListe dritteListe = ersteListe;
  dritteListe = zweiteListe;
  std::cout << "Das ist die dritte Liste" << '\n';
  dritteListe.print();
  return 0;
}
