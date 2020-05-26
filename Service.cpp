#include "Service.h"
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"
#include "RepoException.h"
#include"ValidationException.h"
#include "ReadFromFileException.h"
#include <algorithm>
using namespace std;

Service::Service()
{
	this->repo = NULL;
}

Service::Service(RepoFile* repo)
{
	this->repo = repo;
}

Service::~Service()
{
	if (this->repo != NULL)
	{
		delete this->repo;
	}
}

vector<Resurse*> Service::getAll()
{
	return this->repo->getAll();
}

Resurse* Service::getResurseAtPosition(int pos) throw(RepoException)
{
	return this->repo->getResurse(pos);
}

void Service::addResurseFinanciare(string nume, string data_in, int valoare, int valuta)
throw(ValidationException, RepoException)
{
	ResurseFinanciare* rf = new ResurseFinanciare(nume, data_in, valoare, valuta);
	this->repo->addResurse(rf);
}

void Service::addResurseMateriale(string nume, string data_in, int valoare, string durata, int nr_exemplare)
throw(ValidationException, RepoException)
{
	ResurseMateriale* rm = new ResurseMateriale(nume, data_in, valoare, durata,nr_exemplare);
	this->repo->addResurse(rm);
}

void Service::updateResurseFinanciare(string numeVechi, string numeNou, string data_in, int valoare, int valuta)
throw(ValidationException, RepoException)
{
	Resurse* rVechi = new Resurse(numeVechi,"", 0);
	ResurseFinanciare* rNou = new ResurseFinanciare(numeNou, data_in, valoare, valuta);
	this->repo->updateResurse(rVechi, rNou);
}

void Service::updateResurseMateriale(string numeVechi, string numeNou, string data_in, int valoare, string durata, int nr_exemplare)
throw(ValidationException, RepoException)
{
	Resurse* rVechi = new Resurse(numeVechi,"", 0);
	ResurseMateriale* rNou = new ResurseMateriale(numeNou, data_in, valoare, durata,nr_exemplare);
	this->repo->updateResurse(rVechi, rNou);
}

void Service::deleteResurse(string nume) 
throw(RepoException)
{
	Resurse* r = new Resurse(nume,"", 0);
	this->repo->deleteResurse(r);
}
vector<Resurse*> Service::cautaDupaNume(string nume, string data_in)
{
	vector<Resurse*> resurse = this->repo->getAll();
	vector<Resurse*> result;
	for (Resurse* r : resurse)
	{
		if (r->getNume() == nume || r->getData_in() == data_in )
		{
			result.push_back(r->clone());
		}
	}
	return result;
}
void Service::loadFromFile() throw(ReadFromFileException)
{
	this->repo->loadFromFile();
}

void Service::saveToFile()
{
	this->repo->saveToFile();
}

void Service::setFileName(string fileName)
{
	this->repo->setFileName(fileName);
}

void Service::setRepo(RepoFile* repo)
{
	this->repo = repo;
}
