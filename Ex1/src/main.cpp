#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
	float price = 0.0, inflacionado = 0.0;
	bool cond = true;
	cout << "Digite um valor: ";
	cin >> price;

	while (price <= 100 && cond)
	{
		inflacionado = price * 1.1;
		cout << "Preco inflacionado: " << inflacionado << endl;
		cond = false;
	}

	while (price > 100 && cond)
	{
		inflacionado = price * 1.2;
		cout << "Preco inflacionado: " << inflacionado << endl;
		cond = false;
	}

	char nome[30];
	cout << "Digite o nome para salvar: ";
	cin >> nome;
	cin.ignore();
	strcat(nome, ".txt");
	FILE *arquivo = fopen(nome, "w");
	fprintf(arquivo, "O preco informado foi: %.2f e o preco inflacionado eh: %.2f", price, inflacionado);
	return 0;
}