#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

struct agenda
{
	char nome[30];
	char endereco[100];
	char fone[10];
	long int cep;
};

void imprimir(vector<agenda> obj)
{
	for (int i = 0; i < obj.size(); i++)
	{
		cout << i + 1 << " - " << obj[i].nome << endl;
	}
}

void imprimirLetrasIniciadas(vector<agenda> obj){
	char letra;
	cout << "Digite uma letra: " << endl;
	cin >> letra;
	cin.ignore();

	cout << endl;

	for(int i=0; i<obj.size(); i++){
		if (obj[i].nome[0] == letra){
			cout << obj[i].nome << endl;
		}
	}
}

void imprimirPorPosicao(vector<agenda> obj)
{
	imprimir(obj);

	int posicao;
	cout << endl;
	cout << "Digite a posicao: " << endl;
	cin >> posicao;
	cin.ignore();

	cout << endl;

	cout << "Registro n. " << posicao << ": " << endl;
	cout << "Nome: " << obj[posicao - 1].nome << endl;
	cout << "Endereco: " << obj[posicao - 1].endereco << endl;
	cout << "Telefone: " << obj[posicao - 1].fone << endl;
	cout << "CEP: " << obj[posicao-1].cep << endl;
}

vector<agenda> adicionarNome(vector<agenda> objAgenda)
{
	char nome[30];
	string nomeS;
	char endereco[100];
	string enderecoS;
	char fone[10];
	long int cep;

	cout << "Nao tem validacao entao nao erre!" << endl;
	cout << "Digite o nome: " << endl;
	getline(cin, nomeS);
	strcpy(nome, nomeS.c_str());
	// gambiarra...
	cout << "Digite o endereco: " << endl;
	getline(cin, enderecoS);
	strcpy(endereco, enderecoS.c_str());

	cout << "Digite o telefone: " << endl;
	cin >> fone;
	cin.ignore();
	cout << "Digite o CEP sem pontuacao (apenas numeros)" << endl;
	cin >> cep;
	cin.ignore();

	agenda newAgenda;
	strcpy(newAgenda.nome, nome);
	strcpy(newAgenda.endereco, endereco);
	strcpy(newAgenda.fone, fone);
	newAgenda.cep = cep;

	objAgenda.push_back(newAgenda);
	return objAgenda;
}

int imprimirMenu(){
	cout << "Digite uma opcao: " << endl;
	cout << "1 - Entrar um novo nome na agenda" << endl;
	cout << "2 - Imprimir na tela os dados de uma pessoa cadastrada" << endl;
	cout << "3 - Encontrar lista que começa por letra" << endl;
	cout << "0 - Sair" << endl;
	int menu;
	cin >> menu;
	cin.ignore();

	cout << endl;
	return menu;
}

void salvarArquivo(string nome, vector<agenda> dados){
	char n[nome.length()+1];
	strcpy(n, nome.c_str());
	FILE *arquivo = fopen(n, "w");
	for (int i=0; i<dados.size();i++){
		char linha2[100] = "Nome: ";
		char linha3[120] = "Endereco: ";
		char linha4[100] = "Telefone: ";
		char linha5[100] = "Cep: ";
		strcat(linha2, dados[i].nome);
		strcat(linha2, "\n");
		strcat(linha3, dados[i].endereco);
		strcat(linha3, "\n");
		strcat(linha4, dados[i].fone);
		strcat(linha4, "\n");


		fprintf(arquivo, "\nLinha %d\n", i+1);
		fprintf(arquivo, linha2);
		fprintf(arquivo, linha3);
		fprintf(arquivo, linha4);
		fprintf(arquivo, "CEP: %i", dados[i].cep);
		fprintf(arquivo, "\n");
	}
	fclose(arquivo);
}

void salvar(vector<agenda> dados){
	string nome;
	cout << "Digite o nome para salvar: ";
	cin >> nome;
	nome = nome + ".txt";
	salvarArquivo(nome, dados);
}

void menu(){
	int opc = 0;
	vector<agenda> ag;

	do{
		opc = imprimirMenu();
		switch(opc){
			case 1:
				ag = adicionarNome(ag);
				break;
			case 2:
				imprimirPorPosicao(ag);
				break;
			case 3: 
				imprimirLetrasIniciadas(ag);
				break;
		}
	} 
	while(opc != 0);

	salvar(ag);
}

int main(int argc, char *argv[])
{
	menu();
}