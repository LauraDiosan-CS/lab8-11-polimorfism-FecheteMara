#pragma once
#include "ValidatorResurse.h"

class ValidatorResurseMateriale:public ValidatorResurse
{
public:
	ValidatorResurseMateriale();
	~ValidatorResurseMateriale();
	void validate(Resurse * r);
};

