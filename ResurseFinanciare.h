#pragma once
#include "Resurse.h"
#include<string>
class ResurseFinanciare : public Resurse {
private:
	int valuta;
public:
	ResurseFinanciare();
	ResurseFinanciare(string nume, string data_in, int valoare, int valuta);
	ResurseFinanciare(const ResurseFinanciare& r);
	~ResurseFinanciare();

	Resurse* clone();

	int  getValuta();
	void setValuta(int valuta);
	ResurseFinanciare& operator=(const ResurseFinanciare& r);
	bool operator==(const ResurseFinanciare& r);
	string toString(string delim);
};
