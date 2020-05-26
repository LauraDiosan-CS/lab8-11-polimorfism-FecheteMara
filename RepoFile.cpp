#include "RepoFile.h"
#include"ValidationException.h"
#include"RepoException.h"
#include"ResurseMateriale.h"
#include"ResurseFinanciare.h"
RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
	this->emptyRepo();
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}
RepoFile& RepoFile::operator=(const RepoFile& repo)
{
	this->fileName = repo.fileName;
	return *this;
}
vector<Resurse*> RepoFile::getAll()
{
	return this->resurse;
}

int RepoFile::getSize()
{
	return this->resurse.size();
}

Resurse* RepoFile::getResurse(int pos) throw(ValidationException, RepoException)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->resurse[pos]->clone();
	}
	throw RepoException("Indexul este invalid!");
}

int RepoFile::findResurse(Resurse* r)
{
	for (int i = 0; i < this->resurse.size(); i++)
	{
		if (this->resurse[i]->getNume() == r->getNume())
		{
			return i;
		}
	}
	return -1;
}

void RepoFile::addResurse(Resurse* r) throw(ValidationException, RepoException)
{  
	if (typeid(*r) == typeid(ResurseMateriale))
	{
		this->validatorRM.validate(r);
	}
	if (typeid(*r) == typeid(ResurseFinanciare))
	{
		this->validatorRF.validate(r);
	}

	this->resurse.push_back(r->clone());
	this->saveToFile();
}

void RepoFile::updateResurse(Resurse* rVechi, Resurse* rNou) throw(ValidationException, RepoException)
{
	
	if (typeid(*rNou) == typeid(ResurseFinanciare))
	{
		this->validatorRF.validate(rNou);
	}
	if (typeid(*rNou) == typeid(ResurseMateriale))
	{
		this->validatorRM.validate(rNou);
	}

	for (int i = 0; i < this->resurse.size(); i++)
	{
		if (this->getResurse(i)->getNume() == rVechi->getNume())
		{
			delete this->resurse[i];
			this->resurse[i] = rNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteResurse(Resurse* r) throw(RepoException)
{
	for (int i = 0; i < this->resurse.size(); i++)
	{
		if (this->resurse[i]->getNume() == r->getNume())
		{
			delete this->resurse[i];
			this->resurse.erase(this->resurse.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->resurse[i];
	}
	this->resurse.clear();
}


