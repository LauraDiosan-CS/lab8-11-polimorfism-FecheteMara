#include "UI.h"
#include <iostream>
#include <fstream>
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "ValidationException.h"
#include "ResurseMateriale.h"
#include "ResurseFinanciare.h"
#include "Resurse.h"
#include "ReadFromFileException.h"
#include "RepoException.h"
#include "User.h"

using namespace std;

void UI::displayMenu()
{
	cout << "1. Citeste din fisier\n";
	cout << "2. Afiseaza toate resursele\n";
	cout << "3. Adauga resurse materiale\n";
	cout << "4. Adauga resurse financiare\n";
	cout << "5. Modifica resurse\n";
	cout << "6. Sterge resurse\n";
	cout << "7. Filtreaza resurse dupa nume si data de intrare\n";
	cout << "----------------\n";
	cout << "0. Logout\n";
}
void UI::login()
{
	string userName;
	string userPassword;
	int loginAttempt = 0;

	while (loginAttempt < 5)
	{
		string nume;
		string pass;
		cout << "LOGIN" << endl;
		cout << "Numele: ";
		cin >> userName;
		cout << "Parola: ";
		cin >> userPassword;
		ifstream f("User.txt");
		ifstream c("User.csv");
		if (f.is_open())
		{
			string linie;
			string delim = " ";
			while (getline(f, linie))
			{

				int pos = linie.find(delim);
				nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				pass = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);
			}
			if (userName == nume && userPassword == pass)
			{
				cout << "Bun venit!\n";
				break;
			}

			else
			{
				cout << "Te rog incearca din nou.\n" << '\n';
				loginAttempt++;
			}
		}
		else if (c.is_open()) {
			string linie;
			string delim = ",";
			while (getline(c, linie))
			{

				int pos = linie.find(delim);
				nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				pass = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);
			}
			if (userName == nume && userPassword == pass)
			{
				cout << "Bun venit!\n";
				break;
			}

			else
			{
				cout << "Te rog incearca din nou.\n" << '\n';
				loginAttempt++;
			}
		}
		if (loginAttempt == 5)
		{
			cout << "Prea multe incercari de logare.\n";

		}

		cout << "Bun venit!.\n";
	}
}
void UI::chooseFileType()
{
	int option = 0;
	cout << "Alegeti ce tip de fisier doriti. Scrieti 1 pt. TXT si 2 pt. CSV: ";
	cin >> option;
	while (option < 1 || option > 2)
	{
		cout << "Ati trecut un identificator gresit! Scrieti 1 pt. TXT si 2 pt. CSV: ";
		cin >> option;
	}
	if (option == 1)
	{
		this->serv.setRepo(new RepoFileTXT("fisier.txt"));
	}
	else
	{
		this->serv.setRepo(new RepoFileCSV("fisier.csv"));
	}
}

void UI::UILoadFromFile()
{
	try {
		this->serv.loadFromFile();
	}
	catch (ReadFromFileException & e) {
		cout << e.what() << endl;
		cout << "Dati un alt nume de fisier: ";
		string fileName;
		getline(cin, fileName);
		this->serv.setFileName(fileName);
	}
	catch (ValidationException & e) {
		cout << e.what() << endl;
	}
}

void UI::UIAddResurseMateriale()
{
	cout << "Dati numele: ";
	string nume;
	getline(cin, nume);
	string data_in;
	cout << "Dati data de intrare: ";
	cin >> data_in;
	int valoare;
	cout << "Dati valoarea: ";
	cin >> valoare;
	cin.ignore();
	string durata;
	cout << "Dati durata: ";
	getline(cin, durata);
	int nr_exemplare;
	cout << "Dati nr de exemplare: ";
	cin >> nr_exemplare;
	cin.ignore();
	try {
		this->serv.addResurseMateriale(nume, data_in, valoare, durata,nr_exemplare);
	}
	catch (ValidationException & e) {
		cout << e.what() << endl;
	}
	catch (RepoException & e) {
		cout << e.what() << endl;
	}
}

void UI::UIAddResurseFinanciare()
{
	cout << "Dati numele: ";
	string nume;
	getline(cin, nume);
	string data_in;
	cout << "Dati data de intrare: ";
	cin >> data_in;
	int valoare;
	cout << "Dati valoarea: ";
	cin >> valoare;
	int valuta;
	cout << "Dati valuta: ";
	cin >> valuta;
	try {
		this->serv.addResurseFinanciare(nume, data_in, valoare, valuta);
	}
	catch (ValidationException & e) {
		cout << e.what() << endl;
	}
	catch (RepoException & e) {
		cout << e.what() << endl;
	}
}

void UI::UIModifyResurse()
{
	cout << "Dati numele resursei vechi: ";
	string numeVechi;
	getline(cin, numeVechi);
	int option;
	do {
		cout << "Ce tip de resurse vreti sa adaugati? 1. materiala 2. financiara \n";
		cin >> option;
	} while (option < 1 || option > 2);
	cin.ignore();
	cout << "Dati numele nou: ";
	string numeNou;
	getline(cin, numeNou);
	string data_inNou;
	cout << "Dati data noua: ";
	cin >> data_inNou;
	int valoareNou;
	cout << "Dati valoarea noua: ";
	cin >> valoareNou;
	cin.ignore();
	
	if (option == 1) {
		string durata;
		cout << "Dati noua durata: ";
		getline(cin, durata);
		int nr_exemplare;
		cout << "Dati nr exemplare nou: ";
		cin >> nr_exemplare;
		try {

			this->serv.updateResurseMateriale(numeVechi, numeNou, data_inNou, valoareNou, durata, nr_exemplare);
			
		}
		catch (ValidationException & e) {
			cout << e.what() << endl;
		}
		catch (RepoException & e) {
			cout << e.what() << endl;
		}
	}
	else {
		int valuta;
		cout << "Dati noua valuta: ";
		cin >> valuta;
		try {
			this->serv.updateResurseFinanciare(numeVechi, numeNou, data_inNou, valoareNou, valuta);
		}
		catch (ValidationException & e) {
			cout << e.what() << endl;
		}
		catch (RepoException & e) {
			cout << e.what() << endl;
		}
	}
}

void UI::UIDeleteResurse()
{
	cout << "Dati numele produsului pe care doriti sa il stergeti: ";
	string nume;
	getline(cin, nume);
	try {
		this->serv.deleteResurse(nume);
	}
	catch (RepoException & e) {
		cout << e.what() << endl;
	}
}

void UI::UIShowAll()
{
	this->printResurse(this->serv.getAll());
}

void UI::printResurse(vector<Resurse*> resurse)
{
	for (Resurse* r : resurse)
	{
		if (r->getValoare() == 0 ) {
			char esc_char = 27; 
			cout << esc_char << "[1m" << r->toString(" ").erase(0, 3) << esc_char << "[0m" << endl;
		}
		else
		{
			cout << r->toString(" ").erase(0, 3) << endl;

		}
	}
}
void UI::UICautaDupaNume()
{
	string nume, data;
	cout << "Dati numele: ";
	cin >> nume;
	cout << "Dati data de intrare: ";
	cin >> data;
	cout << endl;
	cout << "Resursele dupa cautare sunt: "<<endl;
	this->printResurse(this->serv.cautaDupaNume(nume, data));
}

UI::UI()
{
}

UI::~UI()
{
}

void UI::runUI()
{
	this->login();
	this->chooseFileType();
	bool shouldRun = true;
	int option;
	while (shouldRun)
	{
		this->displayMenu();
		cin >> option;
		cin.ignore();
		switch (option)
		{
	
		case 1:
		{
			this->UILoadFromFile();
			break;
		}
		case 2: {
			this->UIShowAll();
			break;
		}
		case 3: {
			this->UIAddResurseMateriale();
			break;
		}
		case 4: {
			this->UIAddResurseFinanciare();
			break;
		}
		case 5: {
			this->UIModifyResurse();
			break;
		}
		case 6: {
			this->UIDeleteResurse();
			break;
		}
		case 7: {
			this->UICautaDupaNume();
			break;
		}
		
		case 0: {
			string rasp;
			cout << "Esti sigur ca vrei sa parasesti aplicatia?(Da/Nu)\n";
			cin >> rasp;
			if (rasp == "Da") {
				shouldRun = false;
				break;
			}
			else if (rasp == "Nu")
			{
				break;
			}
		
		}
		default: {
			break;
		}
		}
	}
}
