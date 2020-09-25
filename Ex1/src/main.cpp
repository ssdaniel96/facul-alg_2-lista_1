#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	float price = 0.0;
	bool cond = true;
	cout << "Digite um valor: ";
	cin >> price;

	while(price <= 100 && cond){
		cout << "Preco inflacionado: " << price * 1.1;
		cond = false;
	}

	while(price > 100 && cond){
		cout << "Preco inflacionado: " << price * 1.2;
		cond = false;
	}
}