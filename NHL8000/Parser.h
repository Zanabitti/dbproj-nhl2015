#ifndef PARSER_H
#define PARSER_H

#include "Includelist.h"

class Parser
{
public:
	Parser();
	~Parser();

	void setCurrentdate(string _cdate); //Kopioi uuden päiväyksen nykyiseksi, käytetään tietokantojen päivityksen jälkeen. Huono ratkaisu -> ajansäästö
	void getQueries(void); //Muuntaa /datan raaka-teksteistä MYSQL-lauseita ja tallentaa ne /data kansiion yhteen tiedostoon.
private:
};

#endif