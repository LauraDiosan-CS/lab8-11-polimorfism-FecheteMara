#include "RepoFileTXT.h"
#include <fstream>
#include "ResurseMateriale.h"
#include "ResurseFinanciare.h"
#include"ReadFromFileException.h"
RepoFileTXT::RepoFileTXT() : RepoFile()
{
}

RepoFileTXT::RepoFileTXT(string fileName) : RepoFile(fileName)
{
}

RepoFileTXT::~RepoFileTXT()
{
}
void RepoFileTXT::loadFromFile() throw(ReadFromFileException)
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = " ";
		try {
			while (getline(f, linie))
			{
				if (linie.substr(0, 2) == "RF")
				{
					linie = linie.erase(0, 3);

					int pos = linie.find(delim);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string data_in = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int valoare = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int valuta = stoi(linie.substr(0, pos));

					ResurseFinanciare* rf = new ResurseFinanciare(nume, data_in, valoare, valuta);
					this->resurse.push_back(rf);
				}
				else if (linie.substr(0, 2) == "RM")
				{
					linie = linie.erase(0, 3);

					int pos = linie.find(delim);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string data_in = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int valoare = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string durata = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int nr_exemplare = stoi(linie.substr(0, pos));

					ResurseMateriale* rm = new ResurseMateriale(nume, data_in, valoare, durata, nr_exemplare);
					this->resurse.push_back(rm);
				}
			}
		}
		catch (...) {
			throw ReadFromFileException("formatul datelor din fisier este invalid!");
		}
		f.close();
	}
	else {
		throw ReadFromFileException("fisierul nu exista!");
	}
}

void RepoFileTXT::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Resurse* elem : this->resurse)
		{
			f << elem->toString(" ") << endl;
		}
	}
}

