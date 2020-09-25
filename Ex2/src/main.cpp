#include <iostream>

using namespace std;

int main()
{
	float value1=0, value2=0, result=0;
	char op = 'a';
	int cont = 0;

	cout << "\nDigite um valor: ";
	cin >> value1;
	while (op != '+' && op != '-' && op != '/' && op != '*'){
		if (cont > 0) cout << "\nAlternativa invalida!";
		cout << "\nDigite a operacao: ";
		cin >> op;
		cont++;		
	}


	cout << "\nDigite um segundo valor: ";
	cin >> value2;

	switch (op)
	{
	case '+':
		result = value1 + value2;		
		break;
	case '-':
		result = value1 - value2;
		break;
	case '/':
		result = value1 / value2;
		break;
	case '*':
		result = value1 * value2;
		break;
	default:
		cout << "\nERRO - ENTRE EM CONTATO COM O SUPORTE";
		exit(1);
		break;
	}

	cout << value1 << ' ' << op  << ' ' << value2 << " = " << result;

	return 0;
}