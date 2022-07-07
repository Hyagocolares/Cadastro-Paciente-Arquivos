#pragma once
//bibliotecas...
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

//usando std...
using namespace std;

int cont5 = 0;//variaveis contador.
int cont6 = 0;
int cont7 = 0;

bool LISTAR()
{
	setlocale(LC_ALL, "portuguese");

	int op;//indicador de opções.

	cout << "----------------------------------------------\n---                                        ---\n";
	cout << "---            Listar pacientes            ---\n---                                        ---\n";
	cout << "----------------------------------------------\n";
	cout << "  - Opcao 1 = Local atual do diretorio\n\n";
	cout << "  - Opcao 2 = Listar conteudo do arquivo\n\n";
	cout << "  - Opcao 3 = Listar arquivos no diretorio\n\n";
	cout << "  - Opcao 0 = Para sair\n";
	cout << "----------------------------------------------\n";
	cout << "\n Opcao Selecionada: ";
	cin >> op;
	cout << "\n";

	system("pause");
	system("cls");

	if(op == 1 || op == 2 || op == 3 || op == 0)//verificador de inputs corretos.
	{
		switch(op)
		{
		case 1:
		{
			cont5++;//contador de listar 
			
			//cout << "Listar: " << cont5 << endl;
			
			cout << "----------------------------------------------\n---                                        ---\n";
			cout << "---        Local atual do diretorio        ---\n---                                        ---\n";
			cout << "----------------------------------------------\n";

			errno = 0;
			
			char *buf = getcwd(NULL, 0);
			if (buf == NULL)
			{
				perror("getcwd");
				exit(EXIT_FAILURE);
			}
			printf("Diretorio atual do programa: %s\n", buf);
			
			free(buf);

			cout << "\n";

			system("pause");
			system("cls");

			return LISTAR();
		}
		break;
	
		case 2:
		{
			cont6++;//contador de listar.
			
			//cout << "Listar: " << cont6 << endl;
			
			cout << "----------------------------------------------\n---                                        ---\n";
			cout << "---       Listar conteudo do arquivo       ---\n---                                        ---\n";
			cout << "----------------------------------------------\n";

			int x = 1000;
			char impressao[x];

			ifstream fin("./banco_pacientes/bd_p.txt");

			cout << " Visualizando o arquivo: \n\n";

			while(fin)
			{
				fin.getline(impressao, x);
				cout << impressao << "\n";
			}

			cout << "\n";

			system("pause");
			system("cls");

			return LISTAR();
		}
		case 3:
		{
			cont7++;//contador de listar
			
			//cout << "Listar: " << cont7 << endl;
			
			cout << "----------------------------------------------\n---                                        ---\n";
			cout << "---     Listar arquivos no diretorio       ---\n---                                        ---\n";
			cout << "----------------------------------------------\n";
			
			DIR *d;

			struct dirent *dir;

			d = opendir("banco_pacientes");

			if (d)
			{
				while ((dir = readdir(d)) != NULL)
				{
					printf(" %s\n", dir->d_name);
				}
				closedir(d);
			}
			
			cout << "\n";

			system("pause");
			system("cls");

			return LISTAR();
		}
		default:
		{

		}
		break;
		}
	}
	else
	{
		return LISTAR();
	}
	
	FILE * r;//salvando os contadores de listar em um arquivo txt para usar no relatorio.

	r = fopen("relatorio/relatorio2.txt", "w+");

	fprintf(r, " - Visita(s) ao Atual Diretorio: %d\n\n - Conteudo(s) Listado(s): %d\n\n - Listado(s) os Arquivo(s) no Diretorio: %d\n", cont5, cont6, cont7);

	fclose(r);
	
	return false;
}
