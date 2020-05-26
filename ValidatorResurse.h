#pragma once
#include <string>
#include "Resurse.h"

using namespace std;

class ValidatorResurse {
public:
	ValidatorResurse();
	~ValidatorResurse();
	virtual void validate(Resurse* r);
};
