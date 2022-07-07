#pragma once
//bibliotecas...
#include <iostream>
#include <stdio.h>
#include <string>

//usando std...
using namespace std;

int cont4 = 0;//contador de deletar.
int cont8 = 0;
int cont9 = 0;

bool DELETAR()
{
	setlocale(LC_ALL, "portuguese");

	int LE;

	do
	{
		cout << "----------------------------------------------\n---                                        ---\n";
		cout << "---  Qual arquivo deseja apagar?!          ---\n";
		cout << "---     - Opcao 1 = Dados pacientes        ---\n";
		cout << "---     - Opcao 2 = Dados usuarios         ---\n";
		cout << "---     - Opcao 0 = Para sair              ---\n";
		cout << "----------------------------------------------\n";
		cin >> LE;

		system("pause");
		system("cls");

		if (LE == 1 || LE == 2 || LE == 0)//verificador de inputs.
		{
			switch(LE)
			{
			case 1:
			{
				cont4++;//contador de dleção do bd_p.txt.

				//cout << "usuarios cadastrados: " << cont4 << endl;

				remove("./banco_pacientes/bd_p.txt");

				cout << "----------------------------------------------\n---                                        ---\n";
				cout << "---           Paciente Deletado!           ---\n---                                        ---\n";
				cout << "----------------------------------------------\n";

				system("pause");
				system("cls");
			}
			break;

			case 2:
			{
				cont8++;//contador dos relatorios.

				//cout << "usuarios cadastrados: " << cont8 << endl;

				remove("./usuario/bd_u.txt");

				cout << "----------------------------------------------\n---                                        ---\n";
				cout << "---          Usuario Deletado!             ---\n---                                        ---\n";
				cout << "----------------------------------------------\n";

				system("pause");
				system("cls");
			}
			break;

			default:
			{

			} break;
			}
		}
		else
		{
			return DELETAR();
		}


	}
	while(LE != 0);

	FILE * r;//salvando os contadores de delete em um arquivo txt para por no relatorio.

	r = fopen("relatorio/relatorio3.txt", "w+");

	fprintf(r, " - Paciente(s) Deletado(s): %d\n\n - Usuario(s) Deletado(s): %d\n\n", cont4, cont8);

	fclose(r);

	return false;
}
