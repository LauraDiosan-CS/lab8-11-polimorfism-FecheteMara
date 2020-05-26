#include "TestService.h"
#include <assert.h>
#include "Service.h"
#include "RepoFileTXT.h"
#include "ResurseMateriale.h"
#include "ResurseFinanciare.h"
#include "RepoException.h"
#include <vector>

void TestService::testGetAll()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ResurseFinanciare* p1 = new ResurseFinanciare("banane","11.11.11", 5, 5);
	ResurseMateriale* p2 = new ResurseMateriale("banane", "11.11.11", 5, "3ani",3);
	serv.addResurseFinanciare(p1->getNume(), p1->getData_in(), p1->getValoare(), p1->getValuta());
	serv.addResurseMateriale(p2->getNume(), p2->getData_in(), p2->getValoare(), p2->getDurata(),p2->getNr_exemplare());
	vector<Resurse*> resurse = serv.getAll();
	assert(*resurse[0] == *p1);
	assert(*resurse[1] == *p2);
}

void TestService::testGetResurseAtPosition()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ResurseFinanciare* p = new ResurseFinanciare("banane", "11.11.11", 5, 5);
	serv.addResurseFinanciare(p->getNume(), p->getData_in(), p->getValoare(), p->getValuta());
	assert(*serv.getResurseAtPosition(0) == *p);
}

void TestService::testAddResurseFinanciare()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ResurseFinanciare* pd1 = new ResurseFinanciare("banane", "11.11.11", 5, 5);
	try {
		serv.addResurseFinanciare(pd1->getNume(), pd1->getData_in(), pd1->getValoare(), pd1->getValuta());
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getResurseAtPosition(0) == *pd1);
	

}

void TestService::testAddResurseMateriale()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ResurseMateriale* ps1 = new ResurseMateriale("banane", "11.11.11", 5, "3ani", 3);
	try {
		serv.addResurseMateriale(ps1->getNume(), ps1->getData_in(), ps1->getValoare(), ps1->getDurata(),ps1->getNr_exemplare());
	}
	catch (...) {
		assert(false);
	}
	assert(*serv.getResurseAtPosition(0) == *ps1);
}

void TestService::testUpdateResurseFinanciare()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ResurseFinanciare* p1 = new ResurseFinanciare("banane", "11.11.11", 5, 5);
	serv.addResurseFinanciare(p1->getNume(), p1->getData_in(), p1->getValoare(), p1->getValuta());
	ResurseFinanciare* p2 = new ResurseFinanciare("aaaa", "11.11.11", 5, 5);
	ResurseFinanciare* p3 = new ResurseFinanciare("bbbb", "11.11.11", 5, 5);
	serv.updateResurseFinanciare(p3->getNume(), p2->getNume(), p2->getData_in(), p2->getValoare(), p2->getValuta());	
	assert(*serv.getResurseAtPosition(0) == *p1);
}

void TestService::testUpdateResurseMateriale()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ResurseMateriale* p1 = new ResurseMateriale("banane", "11.11.11", 5, "4ani", 4);
	serv.addResurseMateriale(p1->getNume(), p1->getData_in(), p1->getValoare(), p1->getDurata(),p1->getNr_exemplare());
	ResurseMateriale* p2 = new ResurseMateriale("aaa", "11.11.11", 5, "4ani", 5);
	ResurseMateriale* p3 = new ResurseMateriale("bbb", "11.11.11", 5, "4ani", 4);
    serv.updateResurseMateriale(p3->getNume(), p2->getNume(), p2->getData_in(), p2->getValoare(), p2->getDurata(),p2->getNr_exemplare());
	assert(*serv.getResurseAtPosition(0) == *p1);
}

void TestService::testDeleteResurse()
{
	Service serv;
	RepoFile* repoFile = new RepoFileTXT();
	serv.setRepo(repoFile);
	ResurseFinanciare* p1 = new ResurseFinanciare("res1", "11.11.11", 5, 5);
	ResurseFinanciare* p2 = new ResurseFinanciare("res2", "11.11.11", 3, 5);
	serv.addResurseFinanciare(p1->getNume(), p1->getData_in(), p1->getValoare(), p1->getValuta());
	serv.addResurseFinanciare(p2->getNume(), p2->getData_in(), p2->getValoare(), p2->getValuta());
	serv.deleteResurse("res2");
	serv.deleteResurse(p2->getNume());
	assert(*serv.getResurseAtPosition(0) == *p1);


}

TestService::TestService()
{
}

TestService::~TestService()
{
}

void TestService::testAll()
{
	this->testGetAll();
	this->testGetResurseAtPosition();
	this->testAddResurseMateriale();
	this->testAddResurseFinanciare();
	this->testUpdateResurseMateriale();
	this->testUpdateResurseFinanciare();
	this->testDeleteResurse();


}
