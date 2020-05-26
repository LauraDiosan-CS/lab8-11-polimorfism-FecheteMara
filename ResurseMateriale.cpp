#include "ResurseMateriale.h"
#include<iostream>
ResurseMateriale::ResurseMateriale() : Resurse()
{
	this->durata = "";
	this->nr_exemplare = 0;
}

ResurseMateriale::ResurseMateriale(string nume, string data_in, int valoare, string durata,int nr_exemplare) : Resurse(nume, data_in, valoare)
{
	this->durata = durata;
	this->nr_exemplare = nr_exemplare;
}

ResurseMateriale::ResurseMateriale(const ResurseMateriale& r) : Resurse(r)
{
	this->durata = r.durata;
	this->nr_exemplare = r.nr_exemplare;
}

ResurseMateriale::~ResurseMateriale()
{
}

Resurse* ResurseMateriale::clone()
{
	return new ResurseMateriale(this->nume, this->data_in, this->valoare, this->durata,this->nr_exemplare);
}

string ResurseMateriale::getDurata()
{
	return this->durata;
}
int ResurseMateriale::getNr_exemplare()
{
	return this->nr_exemplare;
}
void ResurseMateriale::setDurata(string durata)
{
	this->durata = durata;
}
void ResurseMateriale::setNr_exemplare(int nr_exemplare)
{
	this->nr_exemplare = nr_exemplare;
}
ResurseMateriale& ResurseMateriale::operator=(const ResurseMateriale& r)
{
	Resurse::operator=(r);
	this->durata = r.durata;
	this->nr_exemplare = r.nr_exemplare;
	return *this;
}

bool ResurseMateriale::operator==(const ResurseMateriale& r)
{
	return ((Resurse::operator==(r) )&& (this->durata == r.durata) && (this->nr_exemplare==r.nr_exemplare));
}

string ResurseMateriale::toString(string delim)
{
	return ("RM" + delim + Resurse::toString(delim) + delim + this->durata + delim + to_string(this->nr_exemplare));
}
