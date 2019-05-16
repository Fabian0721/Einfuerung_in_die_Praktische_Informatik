#include <iostream>
void perfectOutShuffle(int v[])
{
   int v_size = 52;
    // Zerlegung des Kartendecks in 2 Haelften
    // 1. Haelfte
    int v1[v_size/2-1];
    // "<=" wurde durch "<" ersetzt
    for(int i = 0; i < (v_size/2) ; i++)
    {
        v1[i] = v[i];
    }

    // 2. Haelfte
    int v2[v_size/2-1];
    int j = 0;
    for(int i = v_size/2; i <= v_size - 1 ; i++)
    {
        v2[j] = v[i];
        j++;
    }

    // perfekter Mischel-Vorgang: abwechselnd v1 und v2 (v1 beginnt)
    int t = 0;
    int k = 1;
    v[0] = v1[0];
    for(int i = 1 ; i <= v_size; i++)
    {
        if(i % 2 != 0)
        {
            v[i] = v2[t];
            t++;
        }
        else
        {
           v[i] = v1[k];
           k++;
        }
    }
}
void perfectInShuffle(int v[])
{
   int v_size = 52;
    // Zerlegung des Kartendecks in 2 Haelften
    // 1. Haelfte
    int v1[v_size/2-1];
    for(int i = 0; i <= (v_size/2) ; i++)
    {
        v1[i] = v[i];
    }

    // 2. Haelfte
    int v2[v_size/2-1];
    int j = 0;
    for(int i = v_size/2; i <= v_size - 1 ; i++)
    {
        v2[j] = v[i];
        j++;
    }

    // perfekter Mischel-Vorgang: abwechselnd v2 und v1 (v2 beginnt)
    int t = 0;
    int k = 1;
    v[0] = v2[0];
    for(int i = 1 ; i <= v_size; i++)
    {
        if(i % 2 != 0)
        {
            v[i] = v1[t];
            t++;
        }
        else
        {
           v[i] = v2[k];
           k++;
        }
    }
}



bool deck_check(int deck[], int n) // prüft ob der das Deck sortiert ist
{
    int counter = 0;

    for(int i = 0 ; i <= n ; i++)
    {
            if(deck[i] == i + 1 )
            {
                counter = counter + 1;
            }
            else
            {
               break;
            }
    }
    if(counter >= n-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char** argv)
{
    // Kartenvektor wird initialisiert und befuellt
    int v[52];
    int v_size = 52;
    for(int i = 0; i <= v_size - 1 ; i++)
        v[i] = i + 1;

    /*/zum Test wird Kartenvektor ausgegeben
    for(int i = 0; i < v_size ; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl; */

    // Mischelvorgang bis Test deck_check erfüllt ist
    for (int i = 1 ; i <= 100 ; i++)
    {
      perfectOutShuffle(v);
      std::cout << "i = " << i << ", deck_check = " << deck_check(v, v_size) << std::endl;
      if( deck_check(v, v_size) == 1)
          break;
    }
     std::cout << "Ergebnis von out shuffle" << std::endl;
     std::cout << std::endl;

    // Mischelvorgang bis Test deck_check erfüllt ist
    for (int i = 1 ; i <= 100 ; i++)
    {
      perfectInShuffle(v);
      std::cout << "i = " << i << ", deck_check = " << deck_check(v, v_size) << std::endl;
      if( deck_check(v, v_size) == 1)
          break;
    }
    std::cout << "Ergebnis von in shuffle" << std::endl;

    /*/Ausgabe des Vektors, ab dem das Deck wieder sortiert sein sollte
    for(int i = 0; i < v_size ; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl; */
}
