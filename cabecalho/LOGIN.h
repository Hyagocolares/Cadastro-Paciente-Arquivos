#pragma once
//bibliotecas...
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

//usando std...
using namespace std;

bool LOGIN()
{
	setlocale(LC_ALL, "portuguese");
	
	string login, senha;
	string login_usuario, senha_usuario;
	string linha;

	ifstream entrada;

	cout << "----------------------------------------------\n---                                        ---\n";
	cout << "---            Interface Login             ---\n---                                        ---\n";
	cout << "----------------------------------------------\n";

	cout << "\t LOGIN: ";
	cin >> login_usuario;//input nome de usuario.
	cout << "\n\t SENHA: ";
	cin >> senha_usuario;//input senha de usuario.

	cout << "----------------------------------------------\n";

	entrada.open("usuario/bd_u.txt");//abrindo e criando arquivo.

	while(getline(entrada, linha))
	{
		//cout << linha << "\n";

		stringstream X(linha);
		
		getline(X, login, ',');

		//cout << login << endl;

		getline(X, senha, ',');

		//cout << senha << endl;

		if (((login_usuario.compare(login) == 0) && (login_usuario.compare(login) == 0)) && ((senha_usuario.compare(senha) == 0) && (senha_usuario.compare(senha) == 0)))
		{
			//cout << "Passoou!" << endl;

			entrada.close();

			cout << "----------------------------------------------\n---                                        ---\n";
			cout << "---            Usuario Logado!             ---\n---                                        ---\n";
			cout << "----------------------------------------------\n" << endl;

			return true;
		}
	}

	entrada.close();//fechando arquivo.

	cout << "----------------------------------------------\n---                                        ---\n";
	cout << "---            Usuário invalido!           ---\n---                                        ---\n";
	cout << "----------------------------------------------\n" << endl;

	system("pause");
	system("cls");
	
	return false;
}