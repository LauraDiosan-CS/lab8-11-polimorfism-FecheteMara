#include "ValidatorResurseFinanciare.h"
#include "ValidationException.h"
#include "ResurseFinanciare.h"

ValidatorResurseFinanciare::ValidatorResurseFinanciare()
{
}

ValidatorResurseFinanciare::~ValidatorResurseFinanciare()
{
}

void ValidatorResurseFinanciare::validate(Resurse * r)
{
	ValidatorResurse::validate(r);
	ResurseFinanciare* ps = (ResurseFinanciare*)r;
	if (ps->getValuta() <= 0)
	{
		throw ValidationException("Valuta resursei financiare trebuie sa fie strict pozitiva!");
	}
}
