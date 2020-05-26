#include "Teste.h"
#include <assert.h>
#include "Resurse.h"
#include"RepoFile.h"
#include"RepoFileTXT.h"
#include"ResurseFinanciare.h"
#include"ResurseMateriale.h"
#include<iostream>
using namespace std;
const string fileNameInTXT = "TestResurseIn.txt";
const string fileNameOutTXT = "TestResurseOut.txt";
void testImplicitConstructorResurse()
{
	Resurse r;
	assert(r.getNume()=="");
	assert(r.getData_in() == "");
	assert(r.getValoare() == 0);
}

void testConstructorWithParametersResurse()
{
	Resurse r("resursa1", "01.02.2020",3);
	assert(r.getNume() == "resursa1");
	assert(r.getData_in()=="01.02.2020");
	assert(r.getValoare() == 3);
}

void testCopyConstructorResurse()
{
	Resurse r1("resursa1", "01.02.2020", 3);
	Resurse r2(r1);
	assert(r2.getNume() == r1.getNume());
	assert(r2.getData_in() == r1.getData_in());
	assert(r2.getValoare() == r1.getValoare());

}

void testCloneResurse()
{
	Resurse r("resursa1", "01.02.2020", 3);
	Resurse* rClone = r.clone();
	assert(r == *rClone);
	assert(&r != rClone);
}


void testAssignmentOperatorResurse()
{
	Resurse r1("resursa1", "01.02.2020", 3);
	Resurse r2(r1);
	assert(r2.getNume() == r1.getNume());
	assert(r2.getData_in() == r1.getData_in());
	assert(r2.getValoare() == r1.getValoare());
}

void testEqualityOperatorResurse()
{
	Resurse r1("resursa1", "01.02.2020", 3);
	Resurse r2 = r1;
	assert(r1 == r2);
	
}

void testToStringResurse()
{
	Resurse r1("resursa1", "01.02.2020", 3);
	assert(r1.toString(" ") == "resursa1 01.02.2020 3");
	assert(r1.toString(",") == "resursa1,01.02.2020,3");
}
void testConstructorWithParametersResurseFinanciare()
{
	ResurseFinanciare r("resursa1", "01.02.2020", 3, 1);
	assert(r.getNume() == "resursa1");
	assert(r.getData_in() == "01.02.2020");
	assert(r.getValoare() == 3);
	assert(r.getValuta() == 1);
}

void testCopyConstructorResurseFinanciare()
{
	ResurseFinanciare r1("resursa1", "01.02.2020", 3, 1);
	ResurseFinanciare r2(r1);
	assert(r2.getNume() == r1.getNume());
	assert(r2.getData_in() == r1.getData_in());
	assert(r2.getValoare() == r1.getValoare());
	assert(r2.getValuta() == r1.getValuta());
}



void testConstructorWithParametersResurseMateriale()
{
	ResurseMateriale r("resursa1", "01.02.2020", 3, "3ani", 1);
	assert(r.getNume() == "resursa1");
	assert(r.getData_in() == "01.02.2020");
	assert(r.getValoare() == 3);
	assert(r.getDurata() == "3ani");
	assert(r.getNr_exemplare() == 1);
}

void testCopyConstructorResurseMateriale()
{
	ResurseMateriale r1("resursa1", "01.02.2020", 3, "3ani", 1);
	ResurseMateriale r2(r1);
	assert(r2.getNume() == r1.getNume());
	assert(r2.getData_in() == r1.getData_in());
	assert(r2.getValoare() == r1.getValoare());
	assert(r2.getDurata() == r1.getDurata());
	assert(r2.getNr_exemplare() == r1.getNr_exemplare());
}

void testToStringResurseFinanciare()
{
	ResurseFinanciare r1("resursa1", "01.02.2020", 3,1);

}

void testToStringResurseMateriale()
{
	ResurseMateriale r1("resursa1", "01.02.2020", 3,"ani",1);

}

void testAllResurse() {
	testImplicitConstructorResurse();
	testConstructorWithParametersResurse();
	testCopyConstructorResurse();
	testCloneResurse();
	testAssignmentOperatorResurse();
	testEqualityOperatorResurse();
	testToStringResurse();
	testConstructorWithParametersResurseFinanciare();
	testCopyConstructorResurseFinanciare();
	testConstructorWithParametersResurseMateriale();
	testCopyConstructorResurseMateriale();
	testToStringResurseMateriale();
	testToStringResurseFinanciare();
}





