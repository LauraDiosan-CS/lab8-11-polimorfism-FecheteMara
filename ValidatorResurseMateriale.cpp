#include "ValidatorResurseMateriale.h"
#include"ResurseMateriale.h"
#include "ValidationException.h"
#include "ValidatorResurse.h"

ValidatorResurseMateriale::ValidatorResurseMateriale()
{
}

ValidatorResurseMateriale::~ValidatorResurseMateriale()
{
}

void ValidatorResurseMateriale::validate(Resurse * r)
{
	ValidatorResurse::validate(r);
	ResurseMateriale* ps = (ResurseMateriale*)r;
	if (ps->getDurata().empty())
	{
		throw ValidationException("Durata resursei nu poate fi gol!");
	}
	if (ps->getNr_exemplare() <= 0)
	{
		throw ValidationException("Numarul de exemplare a resursei materiale trebuie sa fie strict pozitiva!");
	}
}


