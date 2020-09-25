#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
int main(int argc, char *argv[])
{
	srand(time(NULL));
	float matriz[5][3];

	for (int i=0; i<3; i++){
		for(int j=0; j<5; j++){
			matriz[i][j] = rand() % 100+1;
		}
	}

	float mediaColunaPares;
	float mediaLinhaImpares;
	int qtdColuna=0;
	int qtdLinha=0;

	for (int i=0; i<3; i++){
		for(int j=0; j<5; j++){
			if (j % 2 != 0){
				qtdLinha++;
				mediaLinhaImpares += matriz[i][j];
			}
			if (i % 2 == 0){
				qtdColuna++;
				mediaColunaPares += matriz[i][j];
			}
		}
	}

	cout << (mediaColunaPares/qtdColuna)-(mediaLinhaImpares/mediaLinhaImpares);
	return 0;
}