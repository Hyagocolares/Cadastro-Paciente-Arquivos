#pragma once
//bibliotecas...
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

//usando std...
using namespace std;

bool EDITAR()
{
	setlocale(LC_ALL, "portuguese");
	
	cout << "----------------------------------------------\n---   	                              	   ---\n";
	cout << "---       Editar cadastro do paciente      ---\n---   	                              	   ---\n";
	cout << "----------------------------------------------\n";

	int x = 1000;//variaveis de inputs.
	char impressao[x];

	ifstream fin("./banco_pacientes/bd_p.txt");//criando e abrindo o arquivo.

	cout << " Visualizando o arquivo: \n\n";

	while(fin)
	{
		fin.getline(impressao, x);
		cout << impressao << "\n";
	}

	cout << "----------------------------------------------\n";

	system("pause");
	system("cls");

	FILE * ak;//adastrando novamente nome, cpf e situação como edição do doc.

	char nome[40];
	char cpf[14];
	char situacao[80];

	cout << "----------------------------------------------\n---   	                              	   ---\n";
	cout << "--- 	  Editar cadastro do paciente 	   ---\n---                                        ---\n";
	cout << "----------------------------------------------";
	cout << "\n  [ Use '-' como espaço entre as palavras ]\n";
	cout << "----------------------------------------------\n";

	printf("\n- Digite o Nome: \nEX: Hyago-Colares.\n\nR:  ");
	scanf("%s", nome);
	printf("\n- Digite o CPF: \nEX: 000-000-000-00.\n\nR:  ");
	scanf("\n%s", cpf);
	printf("\n- Digite a Situação: \nEX: Não-muito-bem.\n\nR:  ");
	scanf("\n%s", situacao);

	ak = fopen("./banco_pacientes/bd_p.txt", "w+");//abrindo e criando o arquivo.

	fprintf(ak, " Nome: %s\n CPF: %s\n Situação: %s\n", nome, cpf, situacao);//escrevendo no arquivo.

	fclose(ak);//fechando o arquivo.

	cout << "\n";

	system("pause");
	system("cls");

	cout << "----------------------------------------------\n---   	                              	   ---\n";
	cout << "---          Paciente recadastrado!        ---\n---                                        ---\n";
	cout << "----------------------------------------------\n";

	system("pause");
	system("cls");
	
	return false;
}