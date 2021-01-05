#include <iostream>
#include "Loader.h"
#include "Parser.h"
#include "Database.h"
#include "Includelist.h"
#include "Submenus.h"
using namespace std;

//////////////////////////////
//	Made by:				//
//		Samu Härkönen		//
//	- For non-profit use -	//
//////////////////////////////

int main(){
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);

	Submenus *Menu;
	Loader *L1;

	L1 = new Loader();
	string tempbuffer = L1->getUpdatedate();
	char menuchoice;
	Menu = new Submenus();
	Menu->printSplash(); // Show start-screen
//------ Begin Main menu visual--------
	do {
		SetConsoleTextAttribute(console, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_RED);
		cout << "		+---------------------------------------+	" << endl;
		cout << "		|    \xDB\xDB     \xDB\xDB   \xDB\xDB   \xDB\xDB   \xDB\xDB           |	" << endl;
		cout << "		|    \xDB\xDB\xDB    \xDB\xDB   \xDB\xDB   \xDB\xDB   \xDB\xDB           |	" << endl;
		cout << "		|    \xDB\xDB\xDB\xDB   \xDB\xDB   \xDB\xDB   \xDB\xDB   \xDB\xDB           |	" << endl;
		cout << "		|    \xDB\xDB \xDB\xDB  \xDB\xDB   \xDB\xDB\xDB\xDB\xDB\xDB\xDB   \xDB\xDB           |	" << endl;
		cout << "		|    \xDB\xDB  \xDB\xDB \xDB\xDB   \xDB\xDB   \xDB\xDB   \xDB\xDB           |	" << endl;
		cout << "		|    \xDB\xDB   \xDB\xDB\xDB\xDB   \xDB\xDB   \xDB\xDB   \xDB\xDB           |	" << endl;
		cout << "		|    \xDB\xDB    \xDB\xDB\xDB   \xDB\xDB   \xDB\xDB   \xDB\xDB\xDB\xDB\xDB\xDB\xDB      |	" << endl;
		cout << "		|	  Stat Tracker 8000		| " << endl;
		cout << "		+---------------------------------------+	" << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout.width(20); cout << left << "	(B)rowse Teams";
		cout.width(20); cout << left << "(S)earch Players";
		cout.width(20); cout << left << "(L)eaderboards" << endl << endl;
		cout.width(20); cout << left << "	(C)ompare Teams";
		cout.width(20); cout << left << "(U)pdate database";
		cout.width(20); cout << left << "(E)xit" << endl << endl;
		cout << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout.width(56); cout << right << "Newest available: " << tempbuffer << endl;
		cout.width(56); cout << "Current database: " << L1->getCurrentdate() << endl;
//-------End Main menu visual-----------
		do
		{
			fflush(stdin);
			menuchoice = _getch();
		} while (!(menuchoice == 'E' || menuchoice == 'e' || menuchoice == 'B' || menuchoice == 'b' || menuchoice == 'L' || menuchoice == 'l' || menuchoice == 'S' || menuchoice == 's' || menuchoice == 'U' || menuchoice == 'u' || menuchoice == 'C' || menuchoice == 'c'));
		if (menuchoice > 65 && menuchoice < 90) menuchoice += 32;

		switch (menuchoice)
		{
		case 'b':
			Menu->printBrowse();
			break;
		case 's':
			Menu->printSearch();
			break;
		case 'l':
			Menu->printLeaderboards();
			break;
		case 'c':
			Menu->printComparison();
			break;
		case 'u':
			Menu->printUpdate();
			break;
		case 'e':
			Menu->printEndSplash();
			break;
		default:
			cerr << "ERROR IN MENUCHOICE";
			break;
		}

	} while (menuchoice != 'e');
	
	fflush(stdin);
	_getch();
	return 255;
}