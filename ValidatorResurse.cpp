#include "ValidatorResurse.h"
#include "ValidationException.h"
#include"Resurse.h"

ValidatorResurse::ValidatorResurse()
{
}

ValidatorResurse::~ValidatorResurse()
{
}

void ValidatorResurse::validate(Resurse* r)
{
	if (r->getNume().empty())
	{
		throw ValidationException("Numele resursei nu poate fi gol!");
	}

	if (r->getData_in().empty())
	{
		throw ValidationException("Data resursei nu poate fi gola!");
	}
	if (r->getValoare() < 0)
	{
		throw ValidationException("Valoarea resursei treuie sa fie pozitiva!");
	}
}

