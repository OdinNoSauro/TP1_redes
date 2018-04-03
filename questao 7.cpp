#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    int ordem = 1;
    int i = 0;
    int j = 0;
    int baralho[4][13];
    string naipes[4] = {"copas", "ouros", "paus", "espadas"};
    string cartas[13] = {"As", "Dois", "TrEs", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 13; j++)
        {
            baralho[i][j] = 0;
        }
    }

    srand(time(NULL));
    while (ordem <= 52)
    {
        int naipe_aleatorio = rand()%4;
        int carta_aleatoria = rand()%13;
        if(baralho[naipe_aleatorio][carta_aleatoria] == 0)
        {
            baralho[naipe_aleatorio][carta_aleatoria] = ordem;
            ordem++;
        }
    }

    ordem = 1;
    while(ordem <= 52)
    {
        for(i = 0; i < 4; i++)
        {
            for(j = 0; j < 13; j++)
            {
                if(baralho[i][j] == ordem)
                {
                    cout<<cartas[j]<<" de "<<naipes[i]<<endl;
                    ordem++;
                }
            }
        }
    }
    system("pause");

    return 0;
}
