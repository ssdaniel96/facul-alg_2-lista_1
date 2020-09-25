#include <iostream>

using namespace std;

int razao(float num1, float num2, float *referencia){
	if (num2 == 0){
		cout << "Impossivel realizar a operacao" << endl;
		return 0;
	}
	else{
		cout << "Foi possivel a operacao" <<endl;
		*referencia = num1 / num2;
		return 1;
	}
}

int main(int argc, char *argv[])
{
	float n1, n2, resultado;
	cout << "Insira o primeiro valor: " << endl;
	cin >> n1;
	cout << "Insira o segundo valor: " << endl; 
	cin >> n2;

	int r = razao(n1, n2, &resultado);
	if (r == 1){
		cout << "O resultado: " << resultado;
	}
}