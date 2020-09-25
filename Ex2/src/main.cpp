#include <iostream>
#include <string.h>

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

	cout << value1 << ' ' << op  << ' ' << value2 << " = " << result << endl;
	cout << "Digite o nome para salvar: ";
	char nome[30];
	cin >> nome;
	cin.ignore();
	strcat(nome, ".txt");
	FILE *arquivo = fopen(nome, "w");
	fprintf(arquivo, "A operacao foi: %.2f %c %.2f = %.2f", value1, op, value2, result);
	fclose(arquivo);

	return 0;
}