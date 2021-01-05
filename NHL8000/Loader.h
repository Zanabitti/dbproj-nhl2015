#ifndef LOADER_H
#define LOADER_H

#include "Includelist.h"

class Loader
{
public:
	Loader();
	~Loader();


	string getCurrentdate(void); //Lukee PATCHINFO.DATin ja palauttaa tiedon stringinä
	string getUpdatedate(void); //Lataa ja lukee TEAMSTATS.txtistä tiedoston päiväyksen ja palauttaa samanlainesa stringinä kuin currendate. 
	void getAlldatafiles(void); //Lataa kaikki raaka-teksti versiot netistä data/ kansioon.
	void getBrokenfiles(string _teamname); //Uudelleen lataa hajonneen joukkueen raaka-teksti.
private:
};

#endif