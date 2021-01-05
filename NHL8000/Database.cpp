#include "Database.h"
using namespace std;

Database::Database()
{

}

Database::~Database()
{

}
void Database::OpenDatabase()
{
	setlocale(LC_ALL, "fin");

	string passu;
	ifstream file;
	file.open("password.txt", ios::out);
	getline(file, passu);
	file.close();
	const char *workingpassu = passu.c_str();

	//	 mysql_library_init( 0, NULL, NULL ); 
	mysql_init(&omaKanta);
	mysql_real_connect(&omaKanta, "niisku.lamk.fi",
		"harksamu", workingpassu, "user_harksamu", 3306, NULL, 0);
	mysql_query(&omaKanta, "use user_harksamu;");
}
void Database::InsertData(string _query)
{
	string skysely = _query;
	int checker = 0;
	char kysely[300];
	int ls = 0;
	while (ls < skysely.length()) {
		kysely[ls] = skysely.at(ls);
		ls++;
	}
	kysely[ls] = '\0';
	if (mysql_query(&omaKanta, kysely))
	{
		checker = 1;
		cerr << "ERROR IN MYSQL-CONNECTION OR QUERIES!!\n";
		fflush(stdin);
		cin.get();
	}
	if (checker == 0)
	{
	
	}
	kysely[0] = '\0';
	return;
}
void Database::getTeamData(string _query)
{
	string skysely = _query;
	int checker = 0;
	char kysely[300];
	int ls = 0;
	while (ls < skysely.length()) {
		kysely[ls] = skysely.at(ls);
		ls++;
	}
	kysely[ls] = '\0';
	if (mysql_query(&omaKanta, kysely))
	{
		checker = 1;
		cerr << "ERROR IN MYSQL-CONNECTION OR QUERIES!!\n";
		fflush(stdin);
		cin.get();
	}
	if (checker == 0)
	{
		int riviloop = 0, rivinro = 0;
		tulos = mysql_store_result(&omaKanta);
		cout << "      ";
		int rownum = mysql_num_rows(tulos);
		int fieldnum = mysql_num_fields(tulos);
		do {
			rivi = mysql_fetch_row(tulos);
			riviloop++;
			do {
				if (rivi[rivinro] != NULL)
					{
						if (rivinro == 1) cout.width(12);
						else cout.width(3);
						cout << left << rivi[rivinro] << " | "; 
					}
				else cout << "NULL" << " | ";
				rivinro++;
			} while (rivinro < fieldnum);
			rivinro = 0;
			cout << endl << "      ";
		} while (riviloop < rownum);
	}
	kysely[0] = '\0';
	return;
}
vector<int> Database::getComparisonData(string _query)
{
	string skysely = _query;
	vector<int> Tdata;
	Tdata.clear();
	int checker = 0, Cmode;
	char kysely[300];
	int ls = 0;
	while (ls < skysely.length()) {
		kysely[ls] = skysely.at(ls);
		ls++;
	}
	kysely[ls] = '\0';
	if (mysql_query(&omaKanta, kysely))
	{
		checker = 1;
		cerr << "ERROR IN MYSQL-CONNECTION OR QUERIES!!\n";
		fflush(stdin);
		cin.get();
	}
	if (checker == 0)
	{
		int riviloop = 0, rivinro = 0;
		tulos = mysql_store_result(&omaKanta);
		int rownum = mysql_num_rows(tulos);
		int fieldnum = mysql_num_fields(tulos);
		do {
			rivi = mysql_fetch_row(tulos);
			riviloop++;
			do {
				if (rivi[rivinro] != NULL)
				{
					Tdata.push_back(stoi(rivi[rivinro]));

				}
				else cout << "NULL" << " | ";
				rivinro++;
			} while (rivinro < fieldnum);
			rivinro = 0;
		} while (riviloop < rownum);
	}
	kysely[0] = '\0';
	return Tdata;

}
void Database::getPlayerData(string _query)
{
	string skysely = _query;
	int checker = 0;
	char kysely[300];
	int ls = 0;
	while (ls < skysely.length()) {
		kysely[ls] = skysely.at(ls);
		ls++;
	}
	kysely[ls] = '\0';
	if (mysql_query(&omaKanta, kysely))
	{
		checker = 1;
		cerr << "ERROR IN MYSQL-CONNECTION OR QUERIES!!\n";
		fflush(stdin);
		cin.get();
	}
	if (checker == 0)
	{
		int riviloop = 0, rivinro = 0;
		tulos = mysql_store_result(&omaKanta);
		cout << "      ";
		int rownum = mysql_num_rows(tulos);
		int fieldnum = mysql_num_fields(tulos);
		if (rownum != 0 && fieldnum != 0) {
			do {
				rivi = mysql_fetch_row(tulos);
				riviloop++;
				do {
					if (rivi[rivinro] != NULL)
					{
						if (rivinro == 2) cout.width(16);
						else if (rivinro == 13) cout.width(5);
						else cout.width(3);
						cout << left << rivi[rivinro] << " | ";
					}
					else cout << "NULL" << " | ";
					rivinro++;
				} while (rivinro < fieldnum);
				rivinro = 0;
				cout << endl << "      ";
			} while (riviloop < rownum);
		}
	}
	kysely[0] = '\0';
	return;
}
void Database::getGoalieData(string _query)
{
	string skysely = _query;
	int checker = 0;
	char kysely[300];
	int ls = 0;
	while (ls < skysely.length()) {
		kysely[ls] = skysely.at(ls);
		ls++;
	}
	kysely[ls] = '\0';
	if (mysql_query(&omaKanta, kysely))
	{
		checker = 1;
		cerr << "ERROR IN MYSQL-CONNECTION OR QUERIES!!\n";
		fflush(stdin);
		cin.get();
	}
	if (checker == 0)
	{
		int riviloop = 0, rivinro = 0;
		tulos = mysql_store_result(&omaKanta);
		cout << "      ";
		int rownum = mysql_num_rows(tulos);
		int fieldnum = mysql_num_fields(tulos);
		if (rownum != 0 && fieldnum != 0) {
			do {
				rivi = mysql_fetch_row(tulos);
				riviloop++;
				do {
					if (rivi[rivinro] != NULL)
					{
						if (rivinro == 1) cout.width(16);
						else if (rivinro == 6) cout.width(5);
						else cout.width(3);
						cout << left << rivi[rivinro] << " | ";
					}
					else cout << "NULL" << " | ";
					rivinro++;
				} while (rivinro < fieldnum);
				rivinro = 0;
				cout << endl << "      ";
			} while (riviloop < rownum);
		}
	}
	kysely[0] = '\0';
	return;
}
void Database::getSearchData(string _query, int mode)
{
	int searchmode = mode;
	string skysely = _query;
	int checker = 0;
	char kysely[300];
	int ls = 0;
	while (ls < skysely.length()) {
		kysely[ls] = skysely.at(ls);
		ls++;
	}
	kysely[ls] = '\0';
	if (mysql_query(&omaKanta, kysely))
	{
		checker = 1;
		cerr << "ERROR IN MYSQL-CONNECTION OR QUERIES!!\n";
		fflush(stdin);
		cin.get();
	}
	if (checker == 0)
	{
		int riviloop = 0, rivinro = 0;
		tulos = mysql_store_result(&omaKanta);
		if (searchmode != 3 && searchmode != 4) cout << "		";
		int rownum = mysql_num_rows(tulos);
		int fieldnum = mysql_num_fields(tulos);
		if (rownum != 0 && fieldnum != 0) {
			do {
				rivi = mysql_fetch_row(tulos);
				riviloop++;
				do {
					if (rivi[rivinro] != NULL)
					{
						if (searchmode == 1) // player-formatting
						{
							if (rivinro == 2) cout.width(16);
					//		else if (rivinro == 13) cout.width(5);
							else cout.width(3);
							cout << left << rivi[rivinro] << " | ";
						}
						else if (searchmode == 2) // goalie-formatting
						{
							if (rivinro == 2) cout.width(16);
							else if (rivinro == 13) cout.width(5);
							else cout.width(3);
							cout << left << rivi[rivinro] << " | ";
						}
						else if (searchmode == 3) // players all data-formatting
						{
							switch (rivinro)
							{
							case 0:
								 cout << "		";
								 cout.width(20); cout << left << "Team:" << rivi[rivinro] << endl;
								break;
							case 1:
								cout << "		"; 
								cout.width(20); cout << left << "Number:" << rivi[rivinro] << endl;
								break;
							case 2:
								cout << "		";
								cout.width(20); cout << left << "Name:" << rivi[rivinro] << endl;
								break;
							case 3:
								cout << "		"; 
								cout.width(20); cout << left << "Position:" << rivi[rivinro] << endl;
								break;
							case 4:
								cout << "		"; 
								cout.width(20); cout << left << "Games Played:" << rivi[rivinro] << endl;
								break;
							case 5:
								cout << "		";
								cout.width(20); cout << left << "Goals:" << rivi[rivinro] << endl;
								break;
							case 6:
								cout << "		";
								cout.width(20); cout << left << "Assists:" << rivi[rivinro] << endl;
								break;
							case 7:
								cout << "		"; 
								cout.width(20); cout << left << "Points:" << rivi[rivinro] << endl;
								break;
							case 8:
								cout << "		"; 
								cout.width(20); cout << left << "+/-:" << rivi[rivinro] << endl;
								break;
							case 9:
								cout << "		";
								cout.width(20); cout << left << "Penalties:" << rivi[rivinro] << endl;
								break;
							case 10:
								cout << "		";
								cout.width(20); cout << left << "Powerplay Goals:" << rivi[rivinro] << endl;
								break;
							case 11:
								cout << "		";
								cout.width(20); cout << left << "Shorthanded Goals:" << rivi[rivinro] << endl;
								break;
							case 12:
								cout << "		";
								cout.width(20); cout << left << "Game Winning Goals:" << rivi[rivinro] << endl;
								break;
							case 13:
								cout << "		";
								cout.width(20); cout << left << "Shots:" << rivi[rivinro] << endl;
								break;
							case 14:
								cout << "		";
								cout.width(20); cout << left << "Shot %:" << rivi[rivinro] << "%" << endl;
								break;
							default:
								cout << "error";
								break;
							}
						}
						else if (searchmode == 4) // Goalies all data-formatting
						{
							switch (rivinro)
							{
							case 0:
								cout << "		";
								cout.width(20); cout << left << "Team:" << rivi[rivinro] << endl;
								break;
							case 1:
								cout << "		";
								cout.width(20); cout << left << "Number:" << rivi[rivinro] << endl;
								break;
							case 2:
								cout << "		";
								cout.width(20); cout << left << "Name:" << rivi[rivinro] << endl;
								break;
							case 3:
								cout << "		";
								cout.width(20); cout << left << "Games Played:" << rivi[rivinro] << endl;
								break;
							case 4:
								cout << "		";
								cout.width(20); cout << left << "Minutes Played:" << rivi[rivinro] << endl;
								break;
							case 5:
								cout << "		";
								cout.width(20); cout << left << "Goals Against Avg:" << rivi[rivinro] << endl;
								break;
							case 6:
								cout << "		";
								cout.width(20); cout << left << "Wins:" << rivi[rivinro] << endl;
								break;
							case 7:
								cout << "		";
								cout.width(20); cout << left << "Losses:" << rivi[rivinro] << endl;
								break;
							case 8:
								cout << "		";
								cout.width(20); cout << left << "Overtime Losses:" << rivi[rivinro] << endl;
								break;
							case 9:
								cout << "		";
								cout.width(20); cout << left << "Shutouts:" << rivi[rivinro] << endl;
								break;
							case 10:
								cout << "		";
								cout.width(20); cout << left << "Shots Against:" << rivi[rivinro] << endl;
								break;
							case 11:
								cout << "		";
								cout.width(20); cout << left << "Goals Against:" << rivi[rivinro] << endl;
								break;
							case 12:
								cout << "		";
								cout.width(20); cout << left << "Save %:" << rivi[rivinro] << "%" << endl;
								break;
							case 13:
								cout << "		";
								cout.width(20); cout << left << "Penalties:" << rivi[rivinro] << endl;
								break;
							default:
								cout << "error";
								break;
							}
						}
					}
					else cout << "NULL" << " | ";
					rivinro++;
				} while (rivinro < fieldnum);
				rivinro = 0;
				if (searchmode != 3 && searchmode != 4) cout << endl << "		";
				else cout << endl << endl;
			} while (riviloop < rownum);
		}
	}
	kysely[0] = '\0';
	return;
}
string Database::getTeamName(string _query)
{
	string skysely = _query, answer;
	int checker = 0;
	char kysely[300];
	int ls = 0;
	while (ls < skysely.length()) {
		kysely[ls] = skysely.at(ls);
		ls++;
	}
	kysely[ls] = '\0';
	if (mysql_query(&omaKanta, kysely))
	{
		checker = 1;
		cerr << "ERROR IN MYSQL-CONNECTION OR QUERIES!!\n";
		fflush(stdin);
		cin.get();
		return "ERROR!!";
	}
	if (checker == 0)
	{
		int riviloop = 0, rivinro = 0;
		tulos = mysql_store_result(&omaKanta);
		int rownum = mysql_num_rows(tulos);
		int fieldnum = mysql_num_fields(tulos);
		do {
			rivi = mysql_fetch_row(tulos);
			riviloop++;
			do {
				if (rivi[rivinro] != NULL)
				{
					answer = rivi[rivinro];
				}
				else cout << "NULL";
				rivinro++;
			} while (rivinro < fieldnum);
			rivinro = 0;
		} while (riviloop < rownum);
	}
	kysely[0] = '\0';
	return answer;
}
void Database::CloseDatabase()
{
	mysql_close(&omaKanta);
	mysql_library_end();
}