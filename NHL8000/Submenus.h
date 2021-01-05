#ifndef SUBMENUS_H
#define SUBMENUS_H

#include "Includelist.h"

class Submenus
{
public:
	Submenus();
	~Submenus();

	void printSplash(void); 
	void printLeaderboards(void); 
	void printBrowse(void);
	void printUpdate(void);
	void printComparison(void);
	void printSearch(void);
	void printEndSplash(void);

private:
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // värien helpompaan muokkaukseen
};

#endif