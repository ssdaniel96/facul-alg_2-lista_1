#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	cout << "Quantidade: "<< endl;
	int qtd;
	cin >> qtd;
	double numeros[qtd];
	for (int i=0; i < qtd; i++){
		cout << "Digite o " << i+1 << "ro valor: ";
		cin >> numeros[i];
		cout << endl;
	}

	for (int i=0; i < qtd; i++){
		cout << numeros[i] << ' ';
	}
	cout << endl;

}