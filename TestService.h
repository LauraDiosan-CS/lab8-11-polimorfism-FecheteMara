#pragma once

class TestService {
private:
	void testGetAll();
	void testGetResurseAtPosition();
	void testAddResurseMateriale();
	void testAddResurseFinanciare();
	void testUpdateResurseMateriale();
	void testUpdateResurseFinanciare();
	void testDeleteResurse();

public:
	TestService();
	~TestService();
	void testAll();
};
