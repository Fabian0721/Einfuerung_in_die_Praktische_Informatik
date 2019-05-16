#include <iostream>

// Ein Listenelement
struct IntListElem
{
  IntListElem* next;  // Zeiger auf nächstes Element
  int value;          // Daten zu diesem Element
} ;

// Eine Liste
struct IntList
{
  int count;          // Anzahl Elemente in der Liste
  IntListElem* first; // Zeiger auf erstes Element der Liste
} ;

// Initialisiere eine Listenstruktur
void empty_list( IntList* l )
{
  l->first = 0;   // 0 ist keine gueltige Adresse: Liste ist leer
  l->count = 0;
  std::cout << " Leere Liste wurde erstellt! " << '\n';
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list( IntList* list, IntListElem* where, IntListElem* ins )
{
  if ( where == 0 ) // fuege am Anfang ein
  {
    std::cout << "Anfang" << '\n';
    ins->next = list->first;
    list->first = ins;
    list->count = list->count + 1;
  }
  else              // fuege nach where ein
  {
    std::cout << "Rest" << '\n';
    ins->next = where->next;
    where->next = ins;
    list->count = list->count + 1;
  }
  std::cout << " Eintrag in die Liste wurde erstellt! " << '\n';
}

// Entferne ein Element nach einem gegebenem
// Liefere das entfernte Element zurueck
IntListElem* remove_from_list( IntList* list, IntListElem* where )
{
  IntListElem* p;  // das entfernte Element

  // where == 0 dann entferne erstes Element
  if ( where == 0 )
  {
    p = list->first;
    if ( p != 0 )
    {
      list->first = p->next;
      list->count = list->count - 1;
    }
    return p;
  }

  // entferne Element nach where
  p = where->next;
  if ( p != 0 )
  {
    where->next = p->next;
    list->count = list->count - 1;
  }
  return p;
}

IntList l;

void create_list ( int n, int zyk ) {

  //IntList l;
  IntListElem* erstes_Elm;

  //Leere Liste erstellen;
  empty_list(&l);

IntListElem* where = NULL;
IntListElem ins;

  //n Elemente in die Liste einfügen
  for ( int i = 0; i < n; i++ ) {

    if ( i == zyk) {    //Prüft ob bei i ein zyklus starten soll
      std::cout << "Start des Zyklus: " << erstes_Elm << '\n';
        erstes_Elm = &ins;
        *erstes_Elm = ins;

      std::cout << "Start des Zyklus: " << erstes_Elm << '\n';
    }

    insert_in_list( &l, where, &ins );

    if ( i == n - 1 ) { //Lässt den letzten Pointer auf den zyklusstart zeigen
      ins.next = erstes_Elm;
      std::cout << "Dies ist die Adresse des letzten Zeigers: " << ins.next << '\n';
    }

  }

}

void hase_igel () {
  //An sich einfach aber funktioniert nicht... syntax probleme
  bool anfang = true;
  IntListElem* hase;
  IntListElem* igel;
  //hase = &l;
  //*hase = l;
  //igel =& l.first;
  //while (true) {
  std::cout << "Adresse l.first: " << l.first << '\n';
  std::cout << "Adresse hase" << hase << '\n';
  std::cout << "Adresse igel" << igel << '\n';
    std::cout << "Inschliefe1" << '\n';

      //hase=hase->next;
      std::cout << "Inschliefe2" << '\n';
//igel=igel->next;
      std::cout << "Inschliefe3" << '\n';
      anfang = false;
      std::cout << "In Schleife4::" << '\n';
  //}
  /*
  while(anfang==true || hase->next==igel || hase==igel){
    if(hase->next==nullptr||hase==nullptr||hase->next == nullptr) {
      std::cout << "Kein Zyklus" << '\n';
      break;
    }
  std::cout << "Inschliefe1" << '\n';
    hase=hase->next->next;
    std::cout << "Inschliefe2" << '\n';
    igel=igel->next;
    std::cout << "Inschliefe3" << '\n';
    anfang = false;
    std::cout << "In Schleife4::" << '\n';
    //
  }*/
  std::cout << "Ergebnis" << '\n';
}

int main(int argc, char const *argv[]) {
  //Erster Wert ist die Anzahl der Elemente
  //Zweiter Wert ist stelle des Elements zu dem das letzte Elemnt zeigen soll
  create_list(10, 3);
  hase_igel ();
  return 0;
}
