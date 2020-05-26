#pragma once
#ifndef USER_H
#define USER_H
#include<string>
#include <sstream>
#include<iostream>
using namespace std;
class User
{
private:
	string nume, parola;
public:
	User();
	User(string nume, string parola);
	User(const User &u);
	User&operator=(const User &u);
	void set_nume(string nume);
	void set_parola(string parola);
	string get_parola();
	string get_nume();
	~User();
	string toString();
	void sendPWORD();
	void sendNAME();
	friend ostream& operator<<(ostream &os, User &s)
	{
		os << "Nume= " << s.nume << "Parola= " << s.parola << endl;
		return os;
	}
	friend istream& operator>>(istream &is, User &f) {
		string nume, parola;

		cout << "nume= ";
		is >> nume;
		f.set_nume(nume);
		cout << "parola= ";
		is >> parola;
		f.set_parola(parola);
		return is;
	}
};
#endif