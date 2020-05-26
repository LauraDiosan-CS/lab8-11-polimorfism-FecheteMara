#pragma once
#include "RepoFile.h"

class Service {
private:
	RepoFile* repo;
public:
	Service();
	Service(RepoFile* repo);
	~Service();

	vector<Resurse*> getAll();
	Resurse* getResurseAtPosition(int pos);
	void addResurseFinanciare(string nume, string data_in, int valoare, int valuta);
	void addResurseMateriale(string nume, string data_in, int valoare, string durata, int nr_exemplare);
	void updateResurseFinanciare(string numeVechi, string numeNou, string data_in, int valoare, int valuta);
	void updateResurseMateriale(string numeVechi, string numeNou, string data_in, int valoare, string durata, int nr_exemplare);
	void deleteResurse(string nume);

	vector<Resurse*> cautaDupaNume(string nume, string data_in);

	void loadFromFile();
	void saveToFile();
	void setFileName(string fileName);
	void setRepo(RepoFile* repo);
};

