#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc > 0)
    {
        double valor;
        double maior = atof(argv[1]);
        double menor = maior;
        double soma = maior;
        double media = 0;
        for (int i = 2; i < argc; i++)
        {
            valor = atof(argv[i]);
            if (valor > maior)
                maior = valor;
            if (valor < menor)
                menor = valor;
            soma = soma + valor;
        }
        media = soma / (argc - 1);
        cout << "Maior valor = " << maior << endl;
        cout << "Menor valor = " << menor << endl;
        cout << "Soma dos valores = " << soma << endl;
        cout << "Média aritmética = " << media << endl;
    }
    else cout<<"Entre com os valores na forma: maiorNumero.exe n1 n2 n3 ..."<<endl;
}
