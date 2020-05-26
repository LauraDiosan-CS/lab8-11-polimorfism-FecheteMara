#include "User.h"
#include<iostream>
#include "User.h"
using namespace std;

User::User()
{
	this->nume = "";
	this->parola = "";
}

User::User(string nume, string parola)
{
	this->nume = nume;
	this->parola = parola;
}
User::User(const User &u)
{
	this->nume = u.nume;
	this->parola = u.parola;
}
User&User::operator=(const User &u)
{
	if (this != &u) {

		this->set_nume(u.nume);
		this->set_parola(u.parola);
	}
	else
		cout << "self assignment ... " << endl;
	return *this;
}
void User::set_nume(string nume)
{
	this->nume = nume;
}
void User::set_parola(string parola)
{
	this->parola = parola;
}
string User::get_parola()
{
	return this->parola;
}
string User::get_nume()
{
	return this->nume;
}
User::~User()
{
}
//to string
string User::toString()
{
	string result;
	result = "";
	result += nume + "#";
	result += parola + "#";

	return result;
}

void User::sendNAME()
{
	cout << "Enter your desired username(max 16 characters): ";
	cin >> nume;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

};



void User::sendPWORD()

{

	cout << "Enter your password(max 10 characters): ";

	cin >> parola;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

};
