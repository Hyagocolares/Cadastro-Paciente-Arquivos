#pragma once
//bibliotecas...
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

//usando std...
using namespace std;

bool CADASTRAR()
{
	setlocale(LC_ALL, "portuguese");
	
	FILE * ak;

	char nome[50];//variavel declarada.
	char cpf[20];
	char situacao[250];

	cout << "----------------------------------------------\n---                                        ---\n";
	cout << "---           Cadastrar Paciente           ---\n---                                        ---\n";
	cout << "----------------------------------------------\n";
	cout << "   [ Use '-' como espaço entre as palavras ]\n";
	cout << "----------------------------------------------";

	printf("\n- Digite o Nome: \nEX: Hyago-Colares.\n\nR:  ");
	scanf("%s", nome);//input nome.
	printf("\n- Digite o CPF: \nEX: 000-000-000-00.\n\nR:  ");
	scanf("\n%s", cpf);//input cpf.
	printf("\n- Digite a Situação: \nEX: Não-muito-bem.\n\nR:  ");
	scanf("\n%s", situacao);//input situação.

	ak = fopen("./banco_pacientes/bd_p.txt", "w+");//abrindo o arquivo.

	fprintf(ak, " Nome: %s\n CPF: %s\n Situação: %s\n", nome, cpf, situacao);//escrevendo no arquivo.

	fclose(ak);//fechando arqivo.

	printf("\n");

	system("pause");
	system("cls");

	cout << "----------------------------------------------\n---                                        ---\n";
	cout << "---          Paciente Cadastrado!          ---\n---                                        ---\n";
	cout << "----------------------------------------------\n\n";

	system("pause");
	system("cls");
	
	return false;
}