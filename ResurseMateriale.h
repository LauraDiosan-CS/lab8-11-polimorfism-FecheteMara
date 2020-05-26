#pragma once
#include "Resurse.h"
#include<string>
class ResurseMateriale : public Resurse {
private:
	string durata;
	int nr_exemplare;
public:
	ResurseMateriale();
	ResurseMateriale(string nume, string data_in, int valoare, string durata, int nr_exemplare);
	ResurseMateriale(const ResurseMateriale& r);
	~ResurseMateriale();

	Resurse* clone();

	string  getDurata();
	void setDurata(string durata);
	int getNr_exemplare();
	void setNr_exemplare(int nr_exemplare);
	ResurseMateriale& operator=(const ResurseMateriale& r);
	bool operator==(const ResurseMateriale& r);
	string toString(string delim);
};

