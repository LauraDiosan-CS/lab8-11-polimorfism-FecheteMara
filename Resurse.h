#pragma once
#pragma once
#include <string>
using namespace std;
class Resurse {
protected:
	string nume;
	string data_in;
	int valoare;

public:
	Resurse();
	Resurse(string nume, string data_int,int valoare);
	Resurse(const Resurse& r);
	~Resurse();

	virtual Resurse* clone();

	string getNume();
	string getData_in();
	int getValoare();

	void setNume(string nume);
	void setData_in(string data_in);
	void setValoare(int valoare);

	Resurse& operator=(const Resurse& r);
	bool operator==(const Resurse& r);
	virtual string toString(string delim);

};
