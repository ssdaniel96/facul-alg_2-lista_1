#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

enum dataType
{
	preNome = 1,
	nome = 2,
	sobreNome = 3
};

struct pessoa
{
	string preNome;
	string nome;
	string sobrenome;
};

void erro(string message)
{
	cout << message << endl;
	exit(1);
}

bool verificarNomeValido(string str)
{
	if (str.empty())
	{
		return false;
	}
	int count = 0;
	int oldPos = 0;
	int pos = 0;
	do
	{
		pos = str.find(' ', pos + 1);
		pos != 0 &&pos != -1 ? count++ : pos = -1;
	} while (pos != -1);
	if (count == 2)
	{
		return true;
	}
	else
	{
		cout << "Nome invalido" << endl;
		system("pause");
		return false;
	}
}

pessoa dividir(string str)
{
	int pos = str.find(' ', 0) + 1;
	int pos2 = str.find(' ', pos + 1);
	string preNome = str.substr(0, pos - 1);
	string nome = str.substr(pos, pos2 - pos);
	string sobrenome = str.substr(pos2 + 1);

	pessoa p;
	p.preNome = preNome;
	p.nome = nome;
	p.sobrenome = sobrenome;
	return p;
}

pessoa pegarNome(int counter)
{
	bool c;
	string nomeComposto;
	do
	{
		system("cls");
		cout << "Digite o nome " << counter + 1 << ": ";
		getline(cin, nomeComposto);
		cout << endl;
	} while (!verificarNomeValido(nomeComposto));

	return dividir(nomeComposto);
}

bool verificarContinuar(char c)
{
	toupper(c);
	bool r = !(c == 'S' || c == 'N');
	if (r)
	{
		cout << "Valor inválido!" << endl;
	}
	return r;
}

bool continuar()
{
	char resposta;
	do
	{
		cout << "Deseja adicionar mais um? (S/N)" << endl;
		cin >> resposta;
	} while (verificarContinuar(resposta));
	return resposta == 'S';
}

vector<pessoa> pegarNomes()
{
	vector<pessoa> pessoas;
	int counter = 0;
	do
	{
		pessoas.push_back(pegarNome(counter));
		counter++;
	} while (continuar());
	return pessoas;
}

void imprimir(vector<pessoa> obj)
{
	system("cls");
	for (int i = 0; i < obj.size(); i++)
	{
		cout << "Registro n. " << i + 1 << ": " << obj[i].preNome << " " << obj[i].nome << " " << obj[i].sobrenome << endl;
	}
}
vector<string> ordenar(vector<string> nomes)
{	
	bool cond = false;
	do
	{
		cond = false;
		for (int i = 0; i < nomes.size(); i++)
		{
			if (i < nomes.size() - 1)
			{
				int nextPos = i+1;
				if (nomes[i].compare(nomes[nextPos]) > 0)
				{
					string tmp = nomes[i];
					nomes[i] = nomes[nextPos];
					nomes[nextPos] = tmp;
					cond = true;
				}
			}
		}
	} while (cond);

	return nomes;
}
vector<string> ordenarPreNome(vector<pessoa> obj)
{
	vector<string> nomes;
	for (int i = 0; i < obj.size(); i++)
	{
		nomes.push_back(obj[i].preNome);
	}

	nomes = ordenar(nomes);
	return nomes;
}

vector<string> ordenarSobrenome(vector<pessoa> obj)
{
	vector<string> nomes;
	for (int i = 0; i < obj.size(); i++)
	{
		nomes.push_back(obj[i].sobrenome);
	}
	nomes = ordenar(nomes);

	return nomes;
}

void imprimirVector(vector<string> nomes)
{
	for (int i = 0; i < nomes.size(); i++)
	{
		cout << nomes[i] << endl;
	}
	cout << endl;
}

int mediaNome(vector<pessoa> obj)
{
	int sum = 0;
	for (int i = 0; i < obj.size(); i++)
	{
		sum += obj[i].nome.length();
	}
	return sum / obj.size();
}

int main(int argc, char *argv[])
{
	vector<pessoa> pessoas = pegarNomes();
	imprimir(pessoas);
	cout << "Media de letras por nome: " << mediaNome(pessoas) << endl;
	vector<string> preNomes = ordenarPreNome(pessoas);
	vector<string> sobreNome = ordenarSobrenome(pessoas);
	imprimirVector(preNomes);
	imprimirVector(sobreNome);

	return 0;
}