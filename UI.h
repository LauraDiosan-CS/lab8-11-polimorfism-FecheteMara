#pragma once
#include "Service.h"

class UI {
private:
	Service serv;
	void login();
	void displayMenu();
	void chooseFileType();
	void UILoadFromFile();
	void UIAddResurseMateriale();
	void UIAddResurseFinanciare();
	void UIModifyResurse();
	void UIDeleteResurse();
	void UIShowAll();
	void printResurse(vector<Resurse*> resurse);
	void UICautaDupaNume();

public:
	UI();
	~UI();
	void runUI();
};
