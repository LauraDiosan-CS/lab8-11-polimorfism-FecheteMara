#pragma once
#pragma once
#include "RepoFile.h"

class TestRepoFile {
private:
	const string fileNameInTXT = "TestResurseIn.txt";
	const string fileNameOutTXT = "TestResurseOut.txt";
	const string fileNameInCSV = "TestResurseIn.csv";
	const string fileNameOutCSV = "TestResurseOut.csv";


	//folosit pt. a testa lucrul cu fisiere
	vector<Resurse*> resurseIn;

	void testGetSize();
	void testGetAll();
	void testGetResurse();
	void testAddResurse();
	void testUpdateResurse();
	void testDeleteResurse();

	void testLoadFromFileTXT();
	void testSavetoFileTXT();
	void testLoadFromFileCSV();
	void testSaveToFileCSV();

public:
	TestRepoFile();
	~TestRepoFile();
	void testAll();
};
