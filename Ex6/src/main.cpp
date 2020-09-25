#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
	srand(time(NULL));
	int numeros[10];
	int soma = 0;
	for (int i=0; i<10; i++){
		int num = rand() % 100+1;
		numeros[i] = num;
		soma+=num;
	}

	soma = soma /10;

	if ((soma / (int)soma != 1)) {
		cout << "Nenhum dos valores são iguais"<<endl;
	} 
	else {
		bool found = false;
		for (int i=0; i<10; i++){
			if (numeros[i] == (int)soma){
				found = true;
				break;
			}
		}
		string frase;
		found ? frase = "Encontrado" : frase = "Nao encontrado";
		cout << frase << endl;
	}


}