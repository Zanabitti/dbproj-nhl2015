#ifndef DATABASE_H
#define DATABASE_H

#include "Includelist.h"

class Database
{
public:
	Database();
	~Database();

	void OpenDatabase(void);
	void CloseDatabase(void);

	void InsertData(string _query); //Ei palauta tai sano mitään, update-lauseiden käyttöön
	void getTeamData(string _query); //Joukkueitten tietoihin sopivat formatoinnit ulkoasun takia.
	vector<int> getComparisonData(string _query); //palauttaa vectorina kaikki vertailuun halutut tiedot
	void getPlayerData(string _query); //pelaajien tietoihin sopivat formatoinnit
	void getGoalieData(string _query); //maalivahtien tietoja vastaavat formatoinnit
	void getSearchData(string _query, int mode); //erilliset modet pelaajien tai maalivahtien hakemista varten
	string getTeamName(string _query); // Palauttaa joukkueen tunnuksen (tai minkä tahansa yhden lokeron kyselyn)

private:
	MYSQL omaKanta;
	MYSQL_RES *tulos;
	MYSQL_ROW rivi;
};

#endif