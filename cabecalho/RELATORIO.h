#pragma once
//bibliotecas...
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

bool RELA()
{
	setlocale(LC_ALL, "portuguese");

	int L;

	do
	{
		cout << "----------------------------------------------\n---                                        ---\n";
		cout << "---    - Opcao 1 = Ver relatorio           ---\n";
		cout << "---                                        ---\n";
		cout << "---    - Opcao 0 = Para sair               ---\n";
		cout << "----------------------------------------------\n";
		cin >> L;

		system("pause");
		system("cls");
					
		if (L == 1 || L == 0)
		{
			switch(L)
			{
				case 1:
				{
					cout << "----------------------------------------------\n---   	                              	   ---\n";
					cout << "---      Relatorio de usos do sistema      ---\n---   	                              	   ---\n";
					cout << "----------------------------------------------\n";
	
					//Arquivo 1
					int x = 1000;
					char impressao[x];
	
					ifstream fin("relatorio/relatorio.txt");
	
					while(fin)
					{
						fin.getline(impressao, x);
						cout << impressao << endl;
					}
	
					//Arquivo 2
					int z = 1000;
					char impressa[z];
	
					ifstream ain("relatorio/relatorio1.txt");
	
					while(ain)
					{
						ain.getline(impressa, z);
						cout << impressa << "\n";
					}
	
					//Arquivo 3
					int y = 1000;
					char impress[y];
	
					ifstream bin("relatorio/relatorio2.txt");
	
					while(bin)
					{
						bin.getline(impress, y);
						cout << impress << "\n";
					}
	
					//Arquivo 4
					int w = 1000;
					char impres[w];
	
					ifstream cin("relatorio/relatorio3.txt");
	
					while(cin)
					{
						cin.getline(impres, w);
						cout << impres << "\n";
					}
					system("pause");
					system("cls");
				}
				break;
			
				default:
				{
					cout << " \n  Excluindo relatorios..." << endl;
	
					remove("./relatorio/relatorio.txt");
					remove("./relatorio/relatorio1.txt");
					remove("./relatorio/relatorio2.txt");
					remove("./relatorio/relatorio3.txt");
	
					system("pause");
					system("cls");
				}break;
			}
		}
		else
		{
			return RELA();
		}
	}while(L != 0);
		return false;
	}
