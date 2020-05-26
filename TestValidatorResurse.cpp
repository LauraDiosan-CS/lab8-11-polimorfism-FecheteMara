#include "TestValidatorResurse.h"
#include "ValidatorResurse.h"
#include "ValidationException.h"
#include <cassert>
#include "ValidatorResurseMateriale.h"
#include "ResurseMateriale.h"
#include "ValidatorResurseFinanciare.h"
#include "ResurseFinanciare.h"

void TestValidatorResurse::testValidatorResurse()
{
	ValidatorResurse val;
	Resurse* p1 = new Resurse("nume1", "11.11.2010", 20);
	try
	{
		val.validate(p1);
	}
	catch (...)
	{
	}
	Resurse* p2 = new Resurse("", "", 30);
	try
	{
		val.validate(p2);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	Resurse* p3 = new Resurse("abc_", "11.11.2020", 30);
	try
	{
		val.validate(p3);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	Resurse* p4 = new Resurse("abc", "", 30);
	try
	{
		val.validate(p4);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	
	delete p1;
	delete p2;
	delete p3;
	delete p4;

}

void TestValidatorResurse::testValidatorResurseMateriale()
{
	ValidatorResurseMateriale val;
	ResurseMateriale* p1 = new ResurseMateriale("ciocolata", "11.11.2020", 20, "3ani",20);
	try
	{
		val.validate(p1);
	}
	catch (...)
	{
		assert(false);
	}
	ResurseMateriale* p2 = new ResurseMateriale("ciocolata", "", 20, "", 20);
	try
	{
		val.validate(p2);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	ResurseMateriale* p3 = new ResurseMateriale("", "11.11.2020", 20, "3ani", 20);
	try
	{
		val.validate(p3);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	delete p1;
	delete p2;
	delete p3;
}

void TestValidatorResurse::testValidatorResurseFinanciare()
{
	ValidatorResurseFinanciare val;
	ResurseFinanciare* p1 = new ResurseFinanciare("nume", "11.11.2020", 20, 30);
	try
	{
		val.validate(p1);
	}
	catch (...)
	{
		assert(false);
	}
	ResurseFinanciare* p2 = new ResurseFinanciare("", "11.11.2020", 20, 30);
	try
	{
		val.validate(p2);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	ResurseFinanciare* p3 = new ResurseFinanciare("nume", "11.11.2020", 20, -30);
	try
	{
		val.validate(p3);
		assert(false);
	}
	catch (ValidationException & e) {}
	catch (...) {
		assert(false);
	}
	delete p1;
	delete p2;
	delete p3;
}

TestValidatorResurse::TestValidatorResurse()
{
}

TestValidatorResurse::~TestValidatorResurse()
{
}

void TestValidatorResurse::testAll()
{
	this->testValidatorResurse();
	this->testValidatorResurseMateriale();
	this->testValidatorResurseFinanciare();
}
