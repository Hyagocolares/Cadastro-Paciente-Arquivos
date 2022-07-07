//bibliotecas...
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <string>
#include <fstream>

//cabeçalho e etc...
#include "cabecalho/LOGINC.h"
#include "cabecalho/LOGIN.h"
#include "cabecalho/MENU.h"
#include "cabecalho/RELATORIO.h"


using namespace std;

//base do programa.
int main()
{
	setlocale(LC_ALL, "portuguese");

	int cont = 0;//variavel de contador de cadastro de login.
	int cont1 = 0;//variavel de contador de login.
	int contr = 0;
	int op;//variavel de escolha no menu login.

	do
	{
		//interface de login do sistema, cadastrar e logar.
		cout << "----------------------------------------------\n---                                        ---\n";
		cout << "---           Postinho de Saúde            ---\n---                                        ---\n";
		cout << "----------------------------------------------\n";
		cout << "         - 1 = Cadastrar login\n" << endl;
		cout << "         - 2 = Entrar com login\n" << endl;
		cout << "         - 0 = Para sair do sistema" << endl;
		cout << "----------------------------------------------";
		std::cout << "\nOpcao Selecionada: ";
		std::cin >> op;
		cout << "\n";

		system("pause");//pausa no menu.
		system("cls");//finalização do menu.

		if(op == 1 || op == 2 || op == 0)
		{
			switch(op)//menu das opções do painel inicial do programa, login cadastro login ou sair.
			{
			case 1://opção do cadastro de login.
			{
				cont++;//contador de cadastro de login.

				//cout << "CAD: " << cont << endl;

				if(LOGINC() == true)//arquivo de cadastro.
				{
					system("pause");
					system("cls");
				}
			}
			break;//fim do caso cadastro de login.

			case 2://opções dos utilitarios do login.
			{

				if (LOGIN() == true)//arquivo de login.
				{
					cont1 ++;//contador de login.

					//cout << "CAD: " << cont1 << endl;

					system("pause");
					system("cls");

					if (MENU() == true)//arquivo de interface do menu de opções.
					{
						system("pause");
						system("cls");
					}
				}
				else
				{
					contr++;
				}
			}
			break;//fim do caso login.

			default://finalização do programa com o caso default.
			{
				cout << "\n###############################################\n###                                         ###\n";
				cout << "###             Sistema fechou!             ###\n###                                         ###\n";
				cout << "###############################################\n\n";

				system("pause");
				system("cls");

				RELA();//exibição de relatorio.

				system("pause");
				system("cls");

				exit(0);//fechar arquivo.
			}
			break;
			}//fim do switch do menu das opções do painel inicial do programa.
		}//fim do if.
		else
		{
			return main();//voltar ao menu caso não fosse selecionado.
		}

		FILE * r;//declarando.

		r = fopen("./relatorio/relatorio.txt", "w+");//abrindo e criando.

		fprintf(r, " - Cadastro(s) de Usuario(s): %d\n\n - Usuario(s) Logado(s): %d\n\n - Erro(s) de Logar Usuario(s): %d", cont, cont1, contr); //escrever no arquivo.

		fclose(r);//fechar arquivo.

	}//fim do "DO".
	while(op != 0);//fim do while de pausa do loop.

	return 0; //retorna 0.
}
