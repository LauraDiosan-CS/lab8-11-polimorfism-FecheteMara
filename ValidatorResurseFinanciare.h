#pragma once
#include "ValidatorResurse.h"

class ValidatorResurseFinanciare:public ValidatorResurse
{
public:
	ValidatorResurseFinanciare();
	~ValidatorResurseFinanciare();
	void validate(Resurse* r);
};
