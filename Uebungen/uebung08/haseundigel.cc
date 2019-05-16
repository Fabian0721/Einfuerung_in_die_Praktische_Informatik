#include "fcpp.hh"

// Ein Listenelement
struct IntListElem
{
  IntListElem* next;  // Zeiger auf naechstes Element
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
  //std::cout << " Leere Liste wurde erstellt! " << '\n';
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list( IntList* list, IntListElem* where, IntListElem* ins )
{
  if ( where == 0 ) // fuege am Anfang ein
  {
    ins->next = list->first;
    list->first = ins;
    list->count = list->count + 1;
  }
  else              // fuege nach where ein
  {
    ins->next = where->next;
    where->next = ins;
    list->count = list->count + 1;
  }
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

//Funktion zur Speicherfreigabe
void speicherfreigeben(IntList* liste) {
  IntListElem* loescher;
  while (true) {
    if (liste->count == 0) {
      break;
    }
    loescher = remove_from_list(liste, 0);
    delete loescher;
  }
}

void hase_und_igel(IntList liste) {
  IntListElem* hase = liste.first;
  IntListElem* igel = liste.first;
  bool zyklus_gefunden = false;
  while(true) {
    //Prüfen ob kein Zyklus enthalten
    if(hase->next==nullptr || hase==nullptr || hase->next->next==nullptr) {
      std::cout << "Kein Zyklus enthalten" << '\n';
      break;
    }
    //Bewegen von Hase und Igel
    hase=hase->next->next;
    igel=igel->next;
    //Prüfen ob Zyklus gefunden
    if (hase->next==igel || hase==igel ) {
      std::cout << "Es ist ein Zyklus enthalten" << '\n';
      zyklus_gefunden = true;
      break;
    }

  }
  //Berechnen von k und n
  IntListElem* start;
  int zaehler = 0;
  start=igel;
  if (zyklus_gefunden==true) {
    for (int i=0; i<liste.count; i++) {
      igel=igel->next;
      zaehler++;
      if(igel==start) {
        break;
      }
    }
  }
  //Ausgabe der Werte
  std::cout << "k Linear = " << liste.count-zaehler << '\n';
  std::cout << "n Zyklus = " << zaehler << '\n';
}

int main(int argc, char** argv) {
  int k = readarg_int(argc, argv, 1);
  int n = readarg_int(argc, argv, 2);
  IntListElem* element;

//Zyklische Liste:
  IntList zykliste;
  //Initialisiere Listenstruktur
  empty_list(&zykliste);
  //Setze where auf den Anfang
  IntListElem* where = zykliste.first;
  //Füge Listenelemente hinzu:
  for (int i=0; i<n; i++){
    element = new IntListElem;
    element->value = i;
    //Füge die Listenelemente ein
    insert_in_list(&zykliste, where, element);
    //Schliese die Liste zu einem Zyklus
    if (i == n-1) {
      element->next = zykliste.first;
    }
    //Sorgt dafür das immer nach einander eingefügt wird
    where = element;
  }
//Lineare Liste:
  IntList linliste;
  //Initialisiere Listenstruktur
  empty_list(&linliste);
  //Setze where auf den Anfang
  where = linliste.first;
  //Füge Listenelemente hinzu:
  for (int i=0; i<k; i++){
    element = new IntListElem;
    element->value = i;
    //Füge die Listenelemente ein
    insert_in_list(&linliste, where, element);
    //Lässt das letzte Element auf ein Element des Zyklus zeigen.
    if (i == k-1) {
      element->next = zykliste.first;
    }
    //Sorgt dafür das immer nach einander eingefügt wird
    where = element;
  }
  linliste.count = zykliste.count + linliste.count;
  if (n==0 && k==0) {
    std::cout << "k Linear = 0" << '\n';
    std::cout << "n Zyklus = 0" << '\n';
  } else {
    if (n!=0 && k==0) {
      hase_und_igel(zykliste);
    } else {
      hase_und_igel(linliste);
    }
  }

  speicherfreigeben(&linliste);
}
