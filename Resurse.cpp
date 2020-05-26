#include "Resurse.h"
#include <iostream>
Resurse::Resurse()
{
	this->nume = "";
	this->data_in = "";
	this->valoare = 0;
}

Resurse::Resurse(string nume, string data_in, int valoare)
{
	this->nume = nume;
	this->data_in = data_in;
	this->valoare = valoare;
}

Resurse::Resurse(const Resurse& r)
{
	this->nume = r.nume;
	this->data_in = r.data_in;
	this->valoare = r.valoare;
}

Resurse::~Resurse()
{
}

Resurse* Resurse::clone()
{
	return new Resurse(this->nume, this->data_in,this->valoare);
}

string Resurse::getNume()
{
	return this->nume;
}

string Resurse::getData_in()
{
	return this->data_in;
}
int Resurse :: getValoare() {
	return this->valoare;
}

void Resurse::setNume(string nume)
{
	this->nume = nume;
}

void Resurse::setData_in(string data_in)
{
	this->data_in = data_in;
}
void Resurse::setValoare(int valoare) {
	this->valoare = valoare;
}

Resurse& Resurse::operator=(const Resurse& r)
{
	this->nume = r.nume;
	this->data_in = r.data_in;
	this->valoare = r.valoare;
	return *this;
}

bool Resurse::operator==(const Resurse& r)
{
	return ((this->nume == r.nume) && (this->data_in == r.data_in) && (this->valoare ==r.valoare));
}

string Resurse::toString(string delim)
{
	return (this->nume + delim + this->data_in + delim + to_string(this->valoare));
}
