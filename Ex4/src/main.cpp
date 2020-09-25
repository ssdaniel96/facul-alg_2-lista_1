#include <iostream>

using namespace std;

float valorComposto(float totalGasto, int qtd) {
	for (int i = 1; i < qtd; i++){
		totalGasto *= 1.03;
	}
	return totalGasto;
}

float atribuirValor(float totalGasto, int qtd){
	if (qtd == 1){
		return totalGasto*0.9;
	}
	else if(qtd == 2){
		return totalGasto;
	}
	else{
		return valorComposto(totalGasto, qtd);
	}
}




int main()
{
	float totalGasto;
	cout << "Informe o total gasto:"<<endl;
	cin >> totalGasto;

	int opcao = 0;
	cout << "Seleciona a opcao abaixo:"<<endl;
	cout << "1 - A vista (10% desconto)"<<endl;
	cout << "2 - Duas vezes"<<endl;
	cout << "3 - 3 a 10x (3% juros mensais)"<< endl;
	cin >> opcao;

	int qtd = 1;
	if (opcao == 3){
		cout << "Digite a quantidade de vezes: " << endl;
		cin >> qtd;
	}
	else if (opcao == 2){
		qtd = opcao;
	}

	totalGasto = atribuirValor(totalGasto, qtd);

	cout << totalGasto <<endl;

	return 0;
}