#ifndef PARSER_H
#define PARSER_H

#include "Includelist.h"

class Parser
{
public:
	Parser();
	~Parser();

	void setCurrentdate(string _cdate); //Kopioi uuden p�iv�yksen nykyiseksi, k�ytet��n tietokantojen p�ivityksen j�lkeen. Huono ratkaisu -> ajans��st�
	void getQueries(void); //Muuntaa /datan raaka-teksteist� MYSQL-lauseita ja tallentaa ne /data kansiion yhteen tiedostoon.
private:
};

#endif