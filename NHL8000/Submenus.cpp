#include "Database.h"
#include "Submenus.h"
#include "Parser.h"
#include "Loader.h"

Submenus::Submenus()
{

}
Submenus::~Submenus()
{

}
void Submenus::printSplash()
{
	system("cls");
	SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);

	cout << endl << "			!!  NHL STAT TRACKER 8000 !!" << endl << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);

cout << "	                                .-.-." << endl <<
"                                       /_____\\" << endl <<
"                                      :._|_|_.:" << endl <<
"                                      |/a> a>\\|" << endl <<
"                                   _.-:  (    ;._" << endl <<
"                                 ,'::::\\  _  /:::`-._" << endl <<
"                                /:::::::`._,'|:::::::`._" << endl <<
"                               /:::::_.--`._,'-.::::::::`." << endl <<
"                              :`:::;' \\  )SSt(   `':_:;-' \\" << endl <<
"                              |: `'   : \\         \\ .   ,-.\\" << endl <<
"                              |'  --._;.           `:\\,' .._\\" << endl <<
"                              |:.   -.\\:          `;:;'.'    :" << endl <<
"                              :,----..(:._ ._,---.';'.  `.__.'" << endl <<
"                              /\\,---.|:':..-(\\,-,   `.`..-'" << endl <<
"                             /  :.--.'|:'   ;',:.__.-''" << endl <<
"                            :   |     |'  ,',' /:/ /" << endl <<
"                            :   |,'|.-| ,','  /:/ /" << endl <<
"                           /:\\  : ,'_,:','   /:/ /" << endl <<
"                          /  `:._\\,'.`.`, -.';','" << endl <<
"                         :`-._`:/ >._>.'   .;\\'" << endl <<
"                         |`-._`:,',/_     ,'" << endl <<
"                         |::::;',' ; `-'':" << endl <<
"                         /\\:,',|  :`-..-.;" << endl <<
"                       _,`,',' ;  ;:::::/" << endl <<
"                     ,'`,','.;':_;`-::'/" << endl <<
"                    <`,',;::;:-'      /" << endl <<
"                    ,','   (  ````  ,'.::::." << endl <<
"                  ,'.'     /`_.__.-'::::'" << endl <<
"               _,','         `:::::::'" << endl <<
"    _______..-`.,'" << endl <<
"  ,' ,----.   ,'" << endl <<
" '---`----'-''";

cout << endl << "			PRESS ANY KEY TO START";
_getch();
system("cls");
}
void Submenus::printLeaderboards()
{
	Database *LBdatabase;
	LBdatabase = new Database();
	string LBkysely;
	system("cls");
	LBdatabase->OpenDatabase();
	SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << endl << "			  -  LEADERBOARDS  -  " << endl << endl
		<< " Western Conference:" << endl;
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << "   Pacific Division:" << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << "      Sym | Name         | GP  |  W  |  L  | OT  | PTS | GF  | GA  |" << endl;
	cout << "      --------------------------------------------------------------" << endl;
	LBkysely = "select symbol, name, games_played, wins, losses, overtime_losses, league_points, goals_for, goals_against from TEAMS where division = 'pacific' order by League_points desc;";
	LBdatabase->getTeamData(LBkysely);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << endl << "   Central Division:" << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << "      Sym | Name         | GP  |  W  |  L  | OT  | PTS | GF  | GA  |" << endl;
	cout << "      --------------------------------------------------------------" << endl;
	LBkysely = "select symbol, name, games_played, wins, losses, overtime_losses, league_points, goals_for, goals_against from TEAMS where division = 'central' order by League_points desc;";
	LBdatabase->getTeamData(LBkysely);
	SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << endl << " Eastern Conference:" << endl;
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << "   Metropolitan Division:" << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << "      Sym | Name         | GP  |  W  |  L  | OT  | PTS | GF  | GA  |" << endl;
	cout << "      --------------------------------------------------------------" << endl;
	LBkysely = "select symbol, name, games_played, wins, losses, overtime_losses, league_points, goals_for, goals_against from TEAMS where division = 'metropolitan' order by League_points desc;";
	LBdatabase->getTeamData(LBkysely);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << endl << "   Atlantic Division:" << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout << "      Sym | Name         | GP  |  W  |  L  | OT  | PTS | GF  | GA  |" << endl;
	cout << "      --------------------------------------------------------------" << endl;
	LBkysely = "select symbol, name, games_played, wins, losses, overtime_losses, league_points, goals_for, goals_against from TEAMS where division = 'atlantic' order by League_points desc;";
	LBdatabase->getTeamData(LBkysely);
	LBdatabase->CloseDatabase();
	LBdatabase->~Database();

	cout << endl << "		(S)how descriptions - (B)ack to main menu" << endl;
	char LBchoice;
	do {
		fflush(stdin);
		LBchoice = _getch();
	} while (!(LBchoice == 's' || LBchoice == 'S' || LBchoice == 'b' || LBchoice == 'B'));
	if (LBchoice == 'S' || LBchoice == 's') {
		SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout << endl << " Sym = Team symbol   GP = Games played   W = Wins   L = Losses   GF = Goals for\n      OT = Overtime Losses   PTS = League points   GA = Goals against";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout << endl << endl << "		Press any key to return to main menu.";
		fflush(stdin);
		_getch();
		system("cls");
		return;
	}
	else {
		system("cls");
		return;
	}
}
void Submenus::printBrowse()
{
	array<string, 31> teamfull = { "NULL", "NEW JERSEY DEVILS", "NEW YORK ISLANDERS", "NEW YORK RANGERS", "PHILADELPHIA FLYERS", "PITTSBURGH PENGUINS", "CAROLINA HURRICANES", "TAMPA BAY LIGHTNING", "WASHINGTON CAPITALS", "WINNIPEG JETS", "FLORIDA PANTHERS", "BOSTON BRUINS", "BUFFALO SABRES", "MONTREAL CANADIENS", "OTTAWA SENATORS", "TORONTO MAPLE LEAFS", "CHICAGO BLACKHAWKS", "DETROIT RED WINGS", "ST. LOUIS BLUES", "NASHVILLE PREDATORS", "COLUMBUS BLUE JACKETS", "DALLAS STARS", "ANAHEIM DUCKS", "LOS ANGELES KINGS", "SAN JOSE SHARKS", "ARIZONA COYOTES", "VANCOUVER CANUCKS", "COLORADO AVALANCHE", "CALGARY FLAMES", "EDMONTON OILERS", "MINNESOTA WILD" };

	string BrowseQuery, Symbol, SortQuery = "", GSortQuery = "";
	Database *Bdatabase;
	Bdatabase = new Database();
	Bdatabase->OpenDatabase();
	int Bchoice = 0;
	bool redo = false;
	char B2choice, Sortchoice, Sort2choice;
	do {
	system("cls");

	cout << endl << "			-  SELECT TEAM  -" << endl << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout.width(10); cout << left << "	(1) NJD"; cout.width(10); cout << left << "(2) NYI"; cout.width(10); cout << left << "(3) NYR"; cout.width(10); cout << left << "(4) PHI"; cout.width(10); cout << left << "(5) PIT" << endl << endl;
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout.width(10); cout << left << "	(6) CAR"; cout.width(10); cout << left << "(7) TBL"; cout.width(10); cout << left << "(8) WSH"; cout.width(10); cout << left << "(9) WPG"; cout.width(10); cout << left << "(10) FLA" << endl << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout.width(10); cout << left << "	(11) BOS"; cout.width(10); cout << left << "(12) BUF"; cout.width(10); cout << left << "(13) MTL"; cout.width(10); cout << left << "(14) OTT"; cout.width(10); cout << left << "(15) TOR" << endl << endl;
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout.width(10); cout << left << "	(16) CHI"; cout.width(10); cout << left << "(17) DET"; cout.width(10); cout << left << "(18) STL"; cout.width(10); cout << left << "(19) NSH"; cout.width(10); cout << left << "(20) CBJ" << endl << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout.width(10); cout << left << "	(21) DAL"; cout.width(10); cout << left << "(22) ANA"; cout.width(10); cout << left << "(23) LAK"; cout.width(10); cout << left << "(24) SJS"; cout.width(10); cout << left << "(25) ARI" << endl << endl;
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY  | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout.width(10); cout << left << "	(26) VAN"; cout.width(10); cout << left << "(27) COL"; cout.width(10); cout << left << "(28) CGY"; cout.width(10); cout << left << "(29) EDM"; cout.width(10); cout << left << "(30) MIN" << endl << endl;
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
	cout.width(20); cout << left << "			(0) Back to main menu";
	
		fflush(stdin);
		cout << endl << endl << "Enter team number: ";
		cin >> Bchoice;
	} while (Bchoice < 0 || Bchoice > 30);
	if (Bchoice != 0) {
		do {
			redo = false;
			system("cls");
			BrowseQuery = ("select symbol from TEAMS where teamid = " + to_string(Bchoice) + ";");
			Symbol = Bdatabase->getTeamName(BrowseQuery);
			cout << endl << "			-  " << teamfull[Bchoice] << "  -" << endl << endl;
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
			cout << " Team Standings:" << endl << endl;
			SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
			cout << "      Sym | Name         | GP  |  W  |  L  | OT  | PTS | GF  | GA  |" << endl;
			cout << "      --------------------------------------------------------------" << endl;
			BrowseQuery = ("select symbol, name, games_played, wins, losses, overtime_losses, league_points, goals_for, goals_against from TEAMS where teamid = " + to_string(Bchoice) + ";");
			Bdatabase->getTeamData(BrowseQuery);
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
			cout << endl << " Team Roster:" << endl << "   Players:" << endl << endl;
			SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
			cout << "       #  | POS | Name             | GP  | G   |  A  | PTS | Pen |  S  |" << endl;
			cout << "      ------------------------------------------------------------------" << endl;
			BrowseQuery = ("select num, pos, name, played, goals, assists, points, penalties, shots from PLAYERS where symbol = '" + Symbol + "'" + SortQuery + ";");
			Bdatabase->getPlayerData(BrowseQuery);
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
			cout << endl << "   Goalies:" << endl << endl;
			SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
			BrowseQuery = ("select num, name, played, wins, losses, ot_losses, save_prct from GOALIES where symbol = '" + Symbol + "'" + GSortQuery + ";");
			cout << "       #  | Name             | GP  |  W  |  L  | OT  | Save% |" << endl;
			cout << "      --------------------------------------------------------" << endl;
			Bdatabase->getGoalieData(BrowseQuery);
			cout.width(20); cout << endl << left << "		(S)ort roster";
			cout.width(20); cout << left << "(D)escriptions";
			cout.width(20); cout << endl << endl;
			cout.width(20); cout << left << "			(B)ack to main menu";
			do {
				fflush(stdin);
				B2choice = _getch();
			} while (!(B2choice == 'S' || B2choice == 's' || B2choice == 'D' || B2choice == 'd' || B2choice == 'B' || B2choice == 'b'));
			if (B2choice > 65 && B2choice < 90) B2choice += 32;


			if (B2choice == 's') {
				cout << endl << endl << "	Sorting: (1) Players	(2) Goalies" << endl << endl;
				do
				{
					fflush(stdin);
					Sortchoice = _getch();
				} while (!(Sortchoice == '1' || Sortchoice == '2'));
				if (Sortchoice == '1') {
					cout << endl << "	(1) #   (2) Games Played   (3) Goals   (4) Assists   (5) Points\n		(6) Penalties   (7) Shots" << endl;
					do
					{
						fflush(stdin);
						Sort2choice = _getch();
					} while (!(Sortchoice == '1' || Sortchoice == '2' || Sortchoice == '3' || Sortchoice == '4' || Sortchoice == '5' || Sortchoice == '6' || Sortchoice == '7'));
					
					switch (Sort2choice)
					{
					case '1':
						SortQuery = " order by num";
						break;
					case '2':
						SortQuery = " order by played";
						break;
					case '3':
						SortQuery = " order by goals";
						break;
					case '4':
						SortQuery = " order by assists";
						break;
					case '5':
						SortQuery = " order by points";
						break;
					case '6':
						SortQuery = " order by penalties";
						break;
					case '7':
						SortQuery = " order by shots";
						break;
					default:
						break;
					}
					cout << "		(1) Ascending   (2) Descending";
					do
					{
						fflush(stdin);
						Sort2choice = _getch();
					} while (!(Sort2choice == '1' || Sort2choice == '2'));
					if (Sort2choice == '2') SortQuery = SortQuery + " desc";

				}
				else if (Sortchoice == '2') {
					cout << endl << "	(1) #   (2) Games Played   (3) Wins   (4) Losses   (5) Overtime Losses\n		(6) Save %" << endl;
					do
					{
						fflush(stdin);
						Sort2choice = _getch();
					} while (!(Sortchoice == '1' || Sortchoice == '2' || Sortchoice == '3' || Sortchoice == '4' || Sortchoice == '5' || Sortchoice == '6'));

					switch (Sort2choice)
					{
					case '1':
						GSortQuery = " order by num";
						break;
					case '2':
						GSortQuery = " order by played";
						break;
					case '3':
						GSortQuery = " order by wins";
						break;
					case '4':
						GSortQuery = " order by losses";
						break;
					case '5':
						GSortQuery = " order by ot_losses";
						break;
					case '6':
						GSortQuery = " order by save_prct";
						break;
					default:
						break;
					}
					cout << "		(1) Ascending   (2) Descending";
					do
					{
						fflush(stdin);
						Sort2choice = _getch();
					} while (!(Sort2choice == '1' || Sort2choice == '2'));
					if (Sort2choice == '2') GSortQuery = GSortQuery + " desc";

				}

				redo = true;
			}

			else if (B2choice == 'd') {
				cout << endl << "   Team statistics:";
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
				cout << endl << " Sym = Team symbol   GP = Games played   W = Wins   L = Losses   GF = Goals for\n      OT = Overtime Losses   PTS = League points   GA = Goals against";
				SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
				cout << endl << "   Player statistics:";
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
				cout << endl << " # = Player Number   GP = Games played   G = Goals   A = Assists   PTS = Points\n     Pen = Penalties   S = Shots";
				SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
				cout << endl << "   Goalie statistics:";
				SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
				cout << endl << " # = Player Number   GP = Games played   W = Wins   L = Losses\n     Save% = Save percentage   OT = Overtime Losses";
				SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
				cout << endl << endl << "			Press any key to continue.";
				redo = true;
				fflush(stdin);
				_getch();
			}
		} while (redo == true);
	}
	fflush(stdin);
	Bdatabase->CloseDatabase();
	Bdatabase->~Database();
	system("cls");
	return;
}
void Submenus::printUpdate()
{
	system("cls");
	Parser *P1;
	Loader *L1;
	P1 = new Parser();
	L1 = new Loader();
	string tempbuffer = L1->getUpdatedate();

	cout << endl << endl << "			-  UPDATE  -";
//	cout << endl << "Downloading data-files..." << endl << endl;
	L1->getAlldatafiles();
//	cout << endl << endl << "Download finished." << endl;
//	cout << "\n\nStarting parser for queries..." << endl;
	P1->getQueries();
	P1->setCurrentdate(tempbuffer); //tallenna muutos patchinfoon

	//----------------------------------------------------------
	fstream querytext;
	Database *D1;
	string qbuffer;
	double qcounter = 0, qlooper = 0;
	D1 = new Database();
	vector<string> queries;
//	cout << "Opening database access..." << endl;
	D1->OpenDatabase();
//	cout << "Success." << endl << endl << "Beginning to send queries..";

	querytext.open("data/queries.txt");
	while (getline(querytext, qbuffer)) {
	queries.push_back(qbuffer);
	qcounter++;
	}

	while (qlooper < qcounter) {
	D1->InsertData(queries[qlooper]);
	qlooper++;
	system("cls");
	cout << endl << endl << "			-  UPDATE  -" << endl;
	cout << endl << "	Update Progress: " << fixed << setprecision(2) << ((qlooper / qcounter) * 50)+50 << "%" << endl << endl;
	}
	cout << "		Finished Updating!." << endl << endl << "		Press any key to return to main menu!";
	fflush(stdin);
	_getch();
	system("cls");
	D1->CloseDatabase();

}
void Submenus::printComparison()
{
	Database *Cdatabase;
	Cdatabase = new Database();
	Cdatabase->OpenDatabase();
	string CQuery;
	char CMchoice;
	int Cchoice = 1, Cchoice2 = 1;
	bool redo = false;
	vector<int> Team1, Team2;
	array<string, 31> teamfull = { "NULL", "NEW JERSEY DEVILS", "NEW YORK ISLANDERS", "NEW YORK RANGERS", "PHILADELPHIA FLYERS", "PITTSBURGH PENGUINS", "CAROLINA HURRICANES", "TAMPA BAY LIGHTNING", "WASHINGTON CAPITALS", "WINNIPEG JETS", "FLORIDA PANTHERS", "BOSTON BRUINS", "BUFFALO SABRES", "MONTREAL CANADIENS", "OTTAWA SENATORS", "TORONTO MAPLE LEAFS", "CHICAGO BLACKHAWKS", "DETROIT RED WINGS", "ST. LOUIS BLUES", "NASHVILLE PREDATORS", "COLUMBUS BLUE JACKETS", "DALLAS STARS", "ANAHEIM DUCKS", "LOS ANGELES KINGS", "SAN JOSE SHARKS", "ARIZONA COYOTES", "VANCOUVER CANUCKS", "COLORADO AVALANCHE", "CALGARY FLAMES", "EDMONTON OILERS", "MINNESOTA WILD" };

	system("cls");
	do {
		system("cls");
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		redo = false;
		cout << endl << endl << "			-  TEAM COMPARISON  -" << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout.width(10); cout << left << "	(1) NJD"; cout.width(10); cout << left << "(2) NYI"; cout.width(10); cout << left << "(3) NYR"; cout.width(10); cout << left << "(4) PHI"; cout.width(10); cout << left << "(5) PIT" << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout.width(10); cout << left << "	(6) CAR"; cout.width(10); cout << left << "(7) TBL"; cout.width(10); cout << left << "(8) WSH"; cout.width(10); cout << left << "(9) WPG"; cout.width(10); cout << left << "(10) FLA" << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout.width(10); cout << left << "	(11) BOS"; cout.width(10); cout << left << "(12) BUF"; cout.width(10); cout << left << "(13) MTL"; cout.width(10); cout << left << "(14) OTT"; cout.width(10); cout << left << "(15) TOR" << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout.width(10); cout << left << "	(16) CHI"; cout.width(10); cout << left << "(17) DET"; cout.width(10); cout << left << "(18) STL"; cout.width(10); cout << left << "(19) NSH"; cout.width(10); cout << left << "(20) CBJ" << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout.width(10); cout << left << "	(21) DAL"; cout.width(10); cout << left << "(22) ANA"; cout.width(10); cout << left << "(23) LAK"; cout.width(10); cout << left << "(24) SJS"; cout.width(10); cout << left << "(25) ARI" << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout.width(10); cout << left << "	(26) VAN"; cout.width(10); cout << left << "(27) COL"; cout.width(10); cout << left << "(28) CGY"; cout.width(10); cout << left << "(29) EDM"; cout.width(10); cout << left << "(30) MIN" << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout.width(20); cout << left << "			(0) Back to main menu";
		
		do {
			fflush(stdin);
			cout << endl << endl << " Enter team 1 number: ";
			cin >> Cchoice;
		} while (Cchoice < 0 || Cchoice > 30);
		if (Cchoice == 0) return;
		else {
			CQuery = "select Games_played,wins,losses,overtime_losses,league_points,goals_for,goals_against from TEAMS where teamid = " + to_string(Cchoice) + ";";
			Team1 = Cdatabase->getComparisonData(CQuery);
		}
		do {
			fflush(stdin);
			cout << " Enter team 2 number: ";
			cin >> Cchoice2;
		} while (Cchoice2 < 0 || Cchoice2 > 30);
		if (Cchoice2 == 0) return;
		else {
			CQuery = "select Games_played,wins,losses,overtime_losses,league_points,goals_for,goals_against from TEAMS where teamid = " + to_string(Cchoice2) + ";";
			Team2 = Cdatabase->getComparisonData(CQuery);
		}
		system("cls");
		cout << endl << endl << "			-  TEAM COMPARISON  -" << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout << "	" << teamfull[Cchoice]; cout.width(18); cout << left << " " << teamfull[Cchoice2] << endl << endl;
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout << "		" << Cdatabase->getTeamName(("select symbol from TEAMS where teamid = " + to_string(Cchoice) + ";")) << "	-"; cout.width(18); cout << left << " Symbol"; cout << "-	" << Cdatabase->getTeamName(("select symbol from TEAMS where teamid = " + to_string(Cchoice2) + ";")) << endl << endl;
		cout << "		" << Team1[0] << "	-"; cout.width(18); cout << left << " Games Played"; cout << "-	" << Team2[0] << endl << endl;
		cout << "		" << Team1[1] << "	-"; cout.width(18); cout << left << " Wins"; cout << "-	" << Team2[1] << endl << endl;
		cout << "		" << Team1[2] << "	-"; cout.width(18); cout << left << " Losses"; cout << "-	" << Team2[2] << endl << endl;
		cout << "		" << Team1[3] << "	-"; cout.width(18); cout << left << " Overtime Losses"; cout << "-	" << Team2[3] << endl << endl;
		cout << "		" << Team1[4] << "	-"; cout.width(18); cout << left << " Points"; cout << "-	" << Team2[4] << endl << endl;
		cout << "		" << Team1[5] << "	-"; cout.width(18); cout << left << " Goals For"; cout << "-	" << Team2[5] << endl << endl;
		cout << "		" << Team1[6] << "	-"; cout.width(18); cout << left << " Goals Against"; cout << "-	" << Team2[6] << endl << endl;

		cout << endl << "		(N)ew Comparison	(B)ack to Main menu";
		do {
			fflush(stdin);
			CMchoice = _getch();
		} while (!(CMchoice == 'N' || CMchoice == 'n' || CMchoice == 'B' || CMchoice == 'b'));
		if (CMchoice > 65 && CMchoice < 90) CMchoice += 32;

		if (CMchoice == 'n') {
			redo = true;
			Team1.clear();
			Team2.clear();
		}
	} while (redo == true);
	Cdatabase->CloseDatabase();
	Cdatabase->~Database();
	system("cls");
}
void Submenus::printSearch()
{
	string SearchQuery, SearchUser, SearchNum = "";
	int Playernum = 0, smode = 0;
	bool redo;
	char Schoice;
	Database *Sdatabase;
	Sdatabase = new Database();
	Sdatabase->OpenDatabase();
	do {
		system("cls");
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		redo = false;
		cout << endl << endl << "			-  SEARCH  -" << endl << endl;
		if (Playernum == 0) {
			cout << " Enter Search Term: ";
			fflush(stdin);
			cin >> SearchUser;
		}
		if (Playernum == 0) {
			SearchQuery = "select Symbol,num,name,pos from PLAYERS where name like '%" + SearchUser + "%'" + SearchNum + ";";
			smode = 1;
		}
		else {
			SearchQuery = "select Symbol,num,name,pos,played,goals,assists,points,pm,penalties,pp_goals,sh_goals,gw_goals,shots,shot_prct from PLAYERS where name like '%" + SearchUser + "%'" + SearchNum + ";";
			smode = 3;
		}
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout << endl << "   Players:" << endl;
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		if (smode != 3 && smode != 4) {
			cout << "		Sym | #   | Name             | Pos |" << endl;
			cout << "		------------------------------------" << endl;
		}
		Sdatabase->getSearchData(SearchQuery, smode);
		if (Playernum == 0) {
			SearchQuery = "select Symbol,num,name from GOALIES where name like '%" + SearchUser + "%'" + SearchNum + ";";
			smode = 2;
		}
		else {
			SearchQuery = "select Symbol,num,name,played,played_mins,avg_ga,wins,losses,ot_losses,shutouts,sa,ga,save_prct,penalties from GOALIES where name like '%" + SearchUser + "%'" + SearchNum + ";";
			smode = 4;
		}
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		cout << endl << "   Goalies:" << endl;
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
		if (smode != 3 && smode != 4) {
			cout << "		Sym | #   | Name             |" << endl;
			cout << "		------------------------------" << endl;
		}
		Sdatabase->getSearchData(SearchQuery, smode);
		cout << endl << "	(N)ew Search	(S)elect Player		(B)ack to Main menu";
		do
		{
			fflush(stdin);
			Schoice = _getch();
		} while (!(Schoice == 'N' || Schoice == 'S' || Schoice == 'B' || Schoice == 'b' || Schoice == 'n' || Schoice == 's'));
		if (Schoice > 65 && Schoice < 90) Schoice += 32;
		if (Schoice == 'n') {
			SearchNum = "";
			Playernum = 0;
			redo = true;
		}
		else if (Schoice == 's') {
			cout << endl << endl << " Enter player number: ";
			cin >> Playernum;
			SearchNum = " and num = " + to_string(Playernum);
			redo = true;
		}
		else if (Schoice == 'b') redo = false;
	} while (redo == true);
	Sdatabase->CloseDatabase();
	Sdatabase->~Database();
	system("cls");
}
void Submenus::printEndSplash()
{
	system("cls");
	cout << "\n\n		Exiting NHL 8000...\n\n\n";
	cout << "	                        .---." << endl <<
		"	                       /_____\\" << endl <<
		"	                      _HH.H.HH" << endl <<
		"	       _          _-\"\" WHHHHHW\"\"--__" << endl <<
		"	       \\\\      _-\"   __\\VW=WV/__   /\"\"." << endl <<
		"	       \\\\  _-\" \\__--\"  \"-_-\"   \"\"\"    \"_" << endl <<
		"	         \\\\/ SJS  _                      \"\"" << endl <<
		"	          \\\\----_/_|     ___      /\"\\  T\"\"\\====-" << endl <<
		"	           \\\\ /\"-._     |%|S|    (   \"\\|) | / .:)" << endl <<
		"	            \\/     /    |-+-|     \\    |_ J .:::)" << endl <<
		"	            /     /     |S|%|  _-' '-._  \" )/;\\)" << endl <<
		"	           /     / \\    __    (  \\ \\   \\   " << endl <<
		"	          /     /\\/ '. /  \\   \\ \\ \\ _- \\" << endl <<
		"	          \"'-._/  \\/  \\    \"-_ \\ -\"\" _- \\" << endl <<
		"	         _,'\\\\  \\  \\/  )      \"-, -\"\"    \\" << endl <<
		"	      _,'_- _ \\\\ \\  \\,'          \\ \\_\\_\\  \\" << endl <<
		"	    ,'    _-    \\_\\  \\            \\ \\_\\_\\  \\" << endl <<
		"	    \\_ _-   _- _,' \\  \\            \\ \"\"\"\"   )" << endl <<
		"	     C\\_ _- _,'     \\  \"--------.   L_\"\"\"\"_/" << endl <<
		"	      \" \\/-'         \"-_________|     '\"-Y" << endl;
	cout << "\n\n			Press any key to exit!";

}