#include <assert.h>
#include "TestRepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"


void TestRepoFile::testGetSize()
{
	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);
	repoFile->addResurse(new Resurse());
	assert(repoFile->getSize() == 1);
}

void TestRepoFile::testGetAll()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p1 = new ResurseFinanciare("resursa1", " 11.11.2001", 3, 400);
	ResurseMateriale* p2 = new ResurseMateriale("resursa2", " 11.11.2001",3, "aaaa", 5);
	repoFile->addResurse(p1);
	repoFile->addResurse(p2);
	vector<Resurse*> resurse = repoFile->getAll();
	assert(*resurse[0] == *p1->clone());
	assert(*resurse[1] == *p2->clone());
}

void TestRepoFile::testGetResurse()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p1 = new ResurseFinanciare("resursa1", " 11.11.2001", 3, 400);
	repoFile->addResurse(p1);
	assert(*repoFile->getResurse(0) == *p1->clone());

}

void TestRepoFile::testAddResurse()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p1 = new ResurseFinanciare("resursa1", " 11.11.2001", 3, 400);
	repoFile->addResurse(p1);
	assert(*repoFile->getResurse(0) == *p1->clone());
}

void TestRepoFile::testUpdateResurse()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p1 = new ResurseFinanciare("resursa1", " 11.11.2001", 3, 400);
	repoFile->addResurse(p1);
	ResurseFinanciare* p2 = new ResurseFinanciare("resursa2", " 11.11.2001", 3, 400);
	ResurseFinanciare* p3 = new ResurseFinanciare("resursa3", " 11.11.2001", 1, 300);
	repoFile->updateResurse(p3, p2);
	assert(*repoFile->getResurse(0) == *p1);
	repoFile->updateResurse(p1, p2);
	assert(*repoFile->getResurse(0) == *p2);
}

void TestRepoFile::testDeleteResurse()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p1 = new ResurseFinanciare("resursa2", " 11.11.2001", 3, 400);
	ResurseFinanciare* p2 = new ResurseFinanciare("resursa2", " 11.11.2001", 3, 400);
	repoFile->addResurse(p1);
	repoFile->addResurse(p2);
	repoFile->deleteResurse(p2);
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getResurse(0) == *p1);
	repoFile->deleteResurse(p1);
	assert(repoFile->getSize() == 0);
}

void TestRepoFile::testLoadFromFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->resurseIn.size());

}
void TestRepoFile::testLoadFromFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->resurseIn.size());

}

void TestRepoFile::testSavetoFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutTXT);
	ResurseFinanciare* newRes = new ResurseFinanciare("new","1.12.2020",1,1);
	repoFile->addResurse(newRes);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->resurseIn.size() + 1);
	vector<Resurse*> resurse = repoFile->getAll();

}
void TestRepoFile::testSaveToFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutCSV);
	ResurseFinanciare* newRes = new ResurseFinanciare("MEW", "1.12.2020", 1, 1);
	repoFile->addResurse(newRes);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->resurseIn.size() + 1);
	vector<Resurse*> resurse = repoFile->getAll();
}

TestRepoFile::TestRepoFile()
{
	ResurseFinanciare* p1 = new ResurseFinanciare("resursefinanciare", " 11.11.2001", 3, 400);
	ResurseMateriale* p2 = new ResurseMateriale("resursemateriale", " 11.11.2001",3, "3ani",3);
	this->resurseIn.push_back(p1);
	this->resurseIn.push_back(p2);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testGetAll();
	this->testGetResurse();
	this->testAddResurse();
	this->testUpdateResurse();
	this->testDeleteResurse();
	this->testLoadFromFileTXT();
	this->testSavetoFileTXT();
	this->testLoadFromFileCSV();
	this->testSaveToFileCSV();
}
