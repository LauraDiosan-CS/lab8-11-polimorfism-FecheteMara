#include "ResurseFinanciare.h"

ResurseFinanciare::ResurseFinanciare() : Resurse()
{
	this->valuta = 0;
}

ResurseFinanciare::ResurseFinanciare(string nume, string data_in, int valoare, int valuta) : Resurse(nume, data_in, valoare)
{
	this->valuta = valuta;
}

ResurseFinanciare::ResurseFinanciare(const ResurseFinanciare& r) : Resurse(r)
{
	this->valuta = r.valuta;
}

ResurseFinanciare::~ResurseFinanciare()
{
}

Resurse* ResurseFinanciare::clone()
{
	return new ResurseFinanciare(this->nume, this->data_in, this->valoare,this->valuta);
}

int ResurseFinanciare::getValuta()
{
	return this->valuta;
}

void ResurseFinanciare::setValuta(int valuta)
{
	this->valuta = valuta;
}

ResurseFinanciare& ResurseFinanciare::operator=(const ResurseFinanciare& r)
{
	Resurse::operator=(r);
	this->valuta = r.valuta;
	return *this;
}

bool ResurseFinanciare::operator==(const ResurseFinanciare& r)
{
	return Resurse::operator==(r) && this->valuta == r.valuta;
}

string ResurseFinanciare::toString(string delim)
{
	return ("RF" + delim + Resurse::toString(delim) + delim + to_string(this->valuta));
}
