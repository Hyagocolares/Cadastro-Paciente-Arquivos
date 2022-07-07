#pragma once
//bibliotecas...
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

//usando std...
using namespace std;

bool LOGINC()
{
	setlocale(LC_ALL, "portuguese");
	
	fstream arquivo;//declarando.

	arquivo.open("usuario/bd_u.txt", ios::out);//abrindo e criando o arquivo.

	cout << "----------------------------------------------\n---                                        ---\n";
	cout << "---       Cadastrar = Usuario e Senha      ---\n---                                        ---\n";
	cout << "----------------------------------------------";
	cout << "\n-Digite o nome e senha separados por ',':\n";
	cout << "  - Exemplo: 'nome,1234,' . \n";
	cout << "  - Digite '0' para finalizar o preenchimento.\n";
	cout << "----------------------------------------------\nR: ";

	string S = "";
	string T = "";

	while(S != "0")
	{
		getline(cin, S);//escrevendo e lendo os caracteres.
		T.append(S + "\n");
	}

	cout << "\n";

	arquivo << T ;

	arquivo.close();//fechando o arquivo

	system("pause");
	system("cls");

	cout << "----------------------------------------------\n---                                        ---\n";
	cout << "---           Usuário cadastrado!          ---\n---                                        ---\n";
	cout << "----------------------------------------------\n";
	cout << "\n";
	
	system("pause");
	system("cls");

	return false;
}