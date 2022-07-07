#pragma once
//bibliotecas...
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

//cabe�alho e etc...
#include "CADASTRAR.h"
#include "EDITAR.h"
#include "LISTAR.h"
#include "DELETAR.h"

//usando std...
using namespace std;

int cont1 = 0;
int cont2 = 0;
	
bool MENU()
{	
	setlocale(LC_ALL, "portuguese");

	int opcao; //variavel de escolha no menu de utilidades

	do   //menu op��es de utilidades do sistema
	{
		cout << "----------------------------------------------\n---                                        ---\n";
		cout << "---          Menu utilitarios              ---\n---                                        ---\n";
		cout << "----------------------------------------------";
		cout << "\n - Opcao 1 = Cadastrar" << endl;
		cout << "\n - Opcao 2 = Editar" << endl;
		cout << "\n - Opcao 3 = Listar" << endl;
		cout << "\n - Opcao 4 = Deletar" << endl;
		cout << "\n Para sair do sistema" << endl;
		cout << "\n - Opcao 0 = Sair" << endl;
		cout << "----------------------------------------------";
		cout << "\n Opcao Selecionada: ";
		cin >> opcao;
		cout << "\n";

		system("pause");
		system("cls");

		if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 0)
		{
			switch(opcao)//switch de op��es menu.
			{
			case 1://fun��o cadastrar paciente no sistema.
			{
				cont1++;
				
				//cout << "cadastrar: " << cont1 << endl;

				if(CADASTRAR() == true)
				{
					system("pause");
					system("cls");
				}

				return MENU();

			}
			break;//fim da op��o de cadastro.

			case 2://op��o caso editar arquivo.
			{
				cont2++;
				
				//cout << "usuarios cadastrados: " << cont2 << endl;

				if(EDITAR() == true)
				{
					system("pause");
					system("cls");
				}

				return MENU();
			}
			break;//fim da op��o de editar.

			case 3://op��o caso listar arquivo.
			{
				if(LISTAR() == true)
				{
					system("pause");
					system("cls");
				}

				return MENU();
			}
			break;//fim da op��o de listar.

			case 4://op��o caso deletar arquivo.
			{
				DELETAR();

				return MENU();
			}
			break;//fim da op��o de deletar.

			default://finaliza��o do menu com o caso default.
			{
				cout << "----------------------------------------------\n---                                        ---\n";
				cout << "---          Usuario Deslogado!            ---\n---                                        ---\n";
				cout << "----------------------------------------------\n" << endl;

				system("pause");
				system("cls");
			}
			break;//fim finaliza��o do menu.
			}//fim do switch do menu das op��es do painel inicial do programa.
			break;
		}//fim do if.
		else
		{
			return MENU();
		}

	}//fim do "DO".
	while(opcao != 0);//fim do while de pausa do loop.

	FILE * r;

	r = fopen("relatorio/relatorio1.txt", "w+");

	fprintf(r, " - Paciente(s) Cadastrado(s): %d\n\n - Paciente(s) Editado(s): %d\n", cont1, cont2);

	fclose(r);
	
	return false;//retorna 0.
}