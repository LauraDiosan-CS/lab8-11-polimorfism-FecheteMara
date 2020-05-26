#include"Teste.h"
#include"TestRepoFile.h"
#include"RepoFile.h"
#include"RepoFileTXT.h"
#include"Resurse.h"
#include"ResurseFinanciare.h"
#include"ResurseMateriale.h"
#include"Service.h"
#include"TestService.h"
#include"TestValidatorResurse.h"
#include"UI.h"
#include<string>
#include<iostream>
using namespace std;
int main()
{

	testAllResurse();
	TestValidatorResurse tvp;
	tvp.testAll();
	TestRepoFile testRepoFile;
    testRepoFile.testAll();
	TestService testService;
	testService.testAll();
	UI ui;
	ui.runUI();
	cout << "Gata";

	
}

