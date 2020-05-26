#pragma once
#include "Resurse.h"
#include <vector>
#include"ValidatorResurseFinanciare.h"
#include"ValidatorResurseMateriale.h"
using namespace std;

class RepoFile {
protected:
	vector<Resurse*> resurse;
	string fileName;
	ValidatorResurseFinanciare validatorRF;
	ValidatorResurseMateriale validatorRM;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	vector<Resurse*> getAll();
	int getSize();
	Resurse* getResurse(int pos);
	void addResurse(Resurse* r);
	void updateResurse(Resurse* rVechi, Resurse* rNou);
	void deleteResurse(Resurse* r);

	void emptyRepo();
	RepoFile& operator=(const RepoFile& repo);
	int findResurse(Resurse* r);

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};


