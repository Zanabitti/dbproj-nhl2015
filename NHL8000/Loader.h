#ifndef LOADER_H
#define LOADER_H

#include "Includelist.h"

class Loader
{
public:
	Loader();
	~Loader();


	string getCurrentdate(void); //Lukee PATCHINFO.DATin ja palauttaa tiedon stringin�
	string getUpdatedate(void); //Lataa ja lukee TEAMSTATS.txtist� tiedoston p�iv�yksen ja palauttaa samanlainesa stringin� kuin currendate. 
	void getAlldatafiles(void); //Lataa kaikki raaka-teksti versiot netist� data/ kansioon.
	void getBrokenfiles(string _teamname); //Uudelleen lataa hajonneen joukkueen raaka-teksti.
private:
};

#endif