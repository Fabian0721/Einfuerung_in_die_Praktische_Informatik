#include <iostream>


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
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list( IntList* list, IntListElem* where, IntListElem* ins 
)
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

void deletelists(IntList& list)
{
  IntListElem* p;
  while (list.count!=0){
    p=remove_from_list(&list, 0);
    delete p;
  }
}

void hase_und_igel(IntList liste)
{
  IntListElem* hase,* igel;
  hase=liste.first;
  igel=liste.first;
  bool cycle_found=false;

  //hase und igel gehen so lange weiter bis der igel vor dem hasen ist, 
oder der hase am ziel angekommen ist.
  while (true)
  {
    //optionale abfrage für den fall, dass es kein zykklus enthält
    if(hase->next==nullptr||hase==nullptr||hase->next->next==nullptr)
    {
      std::cout<<"Kein Zyklus vorhanden!\n";
      break;
    }
    //hase geht 2 felder, igel nur 1
    hase=hase->next->next;
    igel=igel->next;
    if (hase->next==igel || hase==igel )
    {
      std::cout<<"Zyklus gefunden!\n";
      cycle_found=true;//zyklus länge wird nur berechnet wenn ein zyklus 
existiert
      break;
    }
  }
//zum berechnen der zykel länge
  int count=0;
  IntListElem* zykelstart;
  //zykelstart dient als vergleichspunkt im Zyklus
  zykelstart=igel;
  zykelstart->next=igel->next;
  igel=igel->next;
  count++;
  //igel läuft den zyklus so lange ab, bis er den vergleichspunkt 
erreicht hat.
  //der zyklus kann jedoch nicht länger als die länge der gesamten list 
sein
  //nur zur sicherheit
  if (cycle_found==true)
  {
    for (int i=0; i<liste.count; ++i)
    {
      if(igel==zykelstart)
      {
        break;
      }
      igel=igel->next;
      count++;
    }
  }
  //berechnung der zykellänge
  std::cout<<"Zyklischer Teil: "<<count;
  std::cout<<"\nLinearer Teil: "<<liste.count-count;
  std::cout<<"\nGesamte Länge: "<<liste.count;
}

int main(int argc, char** argv) {
 int k;
 int n;
 std::cout<<"Linearteil k: "<<std::flush;
 std::cin>>k;
 std::cout<<"Zykelteil n: "<<std::flush;
 std::cin>>n;

 if (k==0 || n==0)
 {
   std::cout<<"Netter Versuch, die Aufgabe war es eine zyklsche Liste zu 
erstellen mit einem linearn Teil. Demnach ist 0 eine verbotene länge für 
die Liste."<<std::endl;
    return 0;
 }

 IntListElem* element;
//initialisiere meinen linearen teil
  IntList linear;
  empty_list(&linear);

//erstelle meinen linearen teil
  for (int i=0; i<k; ++i){
    element = new IntListElem;
    insert_in_list(&linear, 0, element);
  //  std::cout<<"linear: "<<i<<" | "<<linear.first<<"\n";
  }


  //initialisiere meinen zyklischen teil
  IntList cycle;
  empty_list(&cycle);
//erstelle meinen zyklus
  for (int i=0; i<n; ++i){
    element = new IntListElem;
    insert_in_list(&cycle, 0, element);
  }
//laufe meinen zyklus bis zum ende ab
  while(element->next!=0)
  {
    element=element->next;
  }
 //verbinde mein ende mitdem anfang des zyklus
  element->next=cycle.first;
//laufe meinen linearen teil bis zum ende ab
  element=linear.first;
  while(element->next!=0)
  {
    element=element->next;
  }
//verbinde das ende meines linearen teils mit dem anfang des zyklus
  element->next=cycle.first;
  element=linear.first;

//keine ahnung was das hier gemacht hat, schient auch ohne zu 
funktionieren
//falls das programm warum auch immer nicht mehr funktionieren sollte 
einfach auskommentieren
//¯\_(ツ)_/¯
//war glaube nur für tests
//  for(int i=0; i<10;i++)
//  {
//    element=element->next;
//  }

//meine verknuepfte list ehat die laenge beider listen addiert
  linear.count+=cycle.count;
//uebergebe die lineare liste, da an der der zyklus angebunden ist
  hase_und_igel(linear);

//loesche alle meine pointer, damit keine leaks entstehen
  deletelists(cycle);
  deletelists(linear);
}
