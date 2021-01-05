#include "Parser.h"
#include "Loader.h"
using namespace std;

Parser::Parser()
{

}

Parser::~Parser()
{

}

void Parser::getQueries() 
{
	Loader *Lparser;
	Lparser = new Loader();
			fstream datafile;
			ofstream mysqllauseet, mysqllauseetplayers;
			datafile.open("data/TEAMSTATS.txt", ios::in);

	//		mysqllauseet.open("testdata/TEAMSTANDINGS.txt");
			mysqllauseet.open("data/queries.txt", ios::trunc);
			mysqllauseet.close();
			mysqllauseet.open("data/queries.txt", ios::app);

			int contentcounter = 0;
			int ibuffer = 0;
			int id = 0, wins, losses, overtime, points, goalsfor, goalsagainst,
				teams = 37, lastteam = 0;	 // rivi-numero mistä alkaa halutut tiedot
			string mysqlquery, mysqlqueryplayers, buffer;
			vector<string> filecontents;


			while (getline(datafile, buffer)) {
				filecontents.push_back(buffer);
				contentcounter++;
			}

			if (filecontents[teams].at(5) == 'w') teams = teams + 2;

			lastteam = teams + 30;
			// notepad line number - 1 = oikea kohta
			while (teams < lastteam) {

				buffer = "id=\"";
				ibuffer = filecontents[teams].find(buffer) + 4;
				id = stoi(filecontents[teams].substr(ibuffer, 2));

				buffer = "wins=\"";
				ibuffer = filecontents[teams].find(buffer) + 6;
				wins = stoi(filecontents[teams].substr(ibuffer, 2));

				buffer = "losses=\"";
				ibuffer = filecontents[teams].find(buffer) + 8;
				losses = stoi(filecontents[teams].substr(ibuffer, 2));

				buffer = "overtime=\"";
				ibuffer = filecontents[teams].find(buffer) + 10;
				overtime = stoi(filecontents[teams].substr(ibuffer, 2));

				buffer = "points=\"";
				ibuffer = filecontents[teams].find(buffer) + 8;
				points = stoi(filecontents[teams].substr(ibuffer, 2));

				buffer = "goalsFor=\"";
				ibuffer = filecontents[teams].find(buffer) + 10;
				goalsfor = stoi(filecontents[teams].substr(ibuffer, 3));

				buffer = "goalsAgainst=\"";
				ibuffer = filecontents[teams].find(buffer) + 14;
				goalsagainst = stoi(filecontents[teams].substr(ibuffer, 3));


				mysqlquery = ("UPDATE TEAMS SET wins = " + to_string(wins) + ", Losses = " + to_string(losses) + ", Overtime_losses = " + to_string(overtime) + ", League_points = " + to_string(points) + ", Goals_for = " + to_string(goalsfor) + ", Goals_against = " + to_string(goalsagainst) + ", games_played = wins+losses+overtime_losses where teamid = " + to_string(id) + ";");
				mysqllauseet << mysqlquery << endl;
				teams++;
			}
			datafile.close();
			filecontents.clear();
			contentcounter = 0;


			array<string, 30> teamfilename = { "MTL", "ANA", "PIT", "NYI", "TBL", "VAN", "NSH", "STL", "CGY", "DET", "LAK", "CHI", "BOS", "WPG", "TOR", "MIN", "OTT", "SJS", "FLA", "WSH", "NYR", "DAL", "NJD", "ARI", "COL", "PHI", "CAR", "CBJ", "EDM", "BUF" };

			vector<string> separatedstats;
			int breaker = 0, looper = 0, teamfilenamelooper = 0; //playercounter = 0, goaliecounter = 0;
			string rosterbuffer;
			bool filestart = false, fileending = false;
			//----------Loop for all teams----------
			do {
				datafile.open(("data/" + teamfilename[teamfilenamelooper] + ".txt"), ios::in);
			//	mysqllauseetplayers.open(("testdata/" + teamfilename[teamfilenamelooper] + ".txt")); //testing-purposes only



				while (getline(datafile, buffer)) {
					filecontents.push_back(buffer);
				}
				ibuffer = filecontents[9].length();

				while (looper < ibuffer && fileending == false) {
					while (looper < ibuffer && breaker == 0)
					{
						if ((filecontents[9].at(looper) == '{' && filecontents[9].at(looper + 1) == '"' && filecontents[9].at(looper + 2) == 'i') || filestart == true)
						{
							rosterbuffer = rosterbuffer + filecontents[9].at(looper);
							filestart = true;
						}
						if (filecontents[9].at(looper) == '}')
						{
							breaker = 1;
						}
						if ((filecontents[9].at(looper) == ']' && filecontents[9].at(looper + 1) == ',' && filecontents[9].at(looper + 2) == '"' && filecontents[9].at(looper + 3) == 'g')) fileending = true;
						looper++;
					}
					if (fileending == false) separatedstats.push_back(rosterbuffer);
					contentcounter++;
					breaker = 0;
					filestart = false;
					rosterbuffer.clear();
				}


				string playerid, GP, goals, assists, penalties, playerpoints, plusminus, shots, ppgoals, shgoals, gwgoals, overtimegoals, save_prct, shotsagainst, position, playernum, playername;
				bool goaliemode = false, errorinfile = false;
				ibuffer = 1000;
				looper = 0;
				int playerselect = 0, statcounter = 0;


				while (playerselect < contentcounter - 1) {
					playerid = separatedstats[playerselect].substr(6, 7);
					while (breaker == 0) {
						if (separatedstats[playerselect].at(looper) == ',') {
							statcounter++;
							if (statcounter == 1) looper += 7;
							looper++;
						}
						else if (separatedstats[playerselect].at(looper) == '"' && separatedstats[playerselect].at(looper + 1) == '}') breaker = 1;
						else {
							switch (statcounter)
							{
							case 1: //player number
								playernum = playernum + separatedstats[playerselect].at(looper);
								break;
							case 2: // player position
								if (separatedstats[playerselect].at(looper) == 'G') goaliemode = true;
								position = position + separatedstats[playerselect].at(looper);
								break;
							case 3: //player name
								playername = playername + separatedstats[playerselect].at(looper);
								break;
							case 4: //same in goalie
								GP = GP + separatedstats[playerselect].at(looper);
								break;
							case 5: //wins in goalie
								goals = goals + separatedstats[playerselect].at(looper);
								break;
							case 6: //losses in goalie
								assists = assists + separatedstats[playerselect].at(looper);
								break;
							case 7: //OT in goalie
								playerpoints = playerpoints + separatedstats[playerselect].at(looper);
								break;
							case 8: //goals against in goalie
								plusminus = plusminus + separatedstats[playerselect].at(looper);
								break;
							case 9: //shots against in goalie
								penalties = penalties + separatedstats[playerselect].at(looper);
								break;
							case 10: //saves in goalie
								shots = shots + separatedstats[playerselect].at(looper);
								break;
							case 11: //save% in goalie
								if (goaliemode == true) save_prct = save_prct + separatedstats[playerselect].at(looper);
								break;
							case 12: //goals-against-average in goalie
								ppgoals = ppgoals + separatedstats[playerselect].at(looper);
								break;
							case 13: //shutouts in goalie
								shgoals = shgoals + separatedstats[playerselect].at(looper);
								break;
							case 14: // penalties in goalie
								gwgoals = gwgoals + separatedstats[playerselect].at(looper);
								break;
							case 15: // played minutes in goalie
								overtimegoals = overtimegoals + separatedstats[playerselect].at(looper);
								break;
							default:
								break;
							}
						}
						looper++;
					}

					if (goaliemode == false) mysqlqueryplayers = ("UPDATE PLAYERS SET Played = " + GP + ", Goals = " + goals + ", Assists = " + assists + ", Points = " + playerpoints + ", PM = " + plusminus + ", Penalties = " + penalties + ", PP_goals = " + ppgoals + ", SH_goals = " + shgoals + ", GW_goals = " + gwgoals + ", Shots = " + shots + ", Shot_prct = ROUND((Goals/Shots)*100, 1) where PID = " + playerid + " and Symbol = '" + teamfilename[teamfilenamelooper] + "';");
					else 					 mysqlqueryplayers = ("UPDATE GOALIES SET Played = " + GP + ", Played_mins = " + overtimegoals + ", AVG_GA = " + ppgoals + ", Wins = " + goals + ", Losses = " + assists + ", OT_Losses = " + playerpoints + ", Shutouts = " + shgoals + ", SA = " + penalties + ", GA = " + plusminus + ", Penalties = " + gwgoals + ", Save_prct = " + save_prct + " where PID = " + playerid + " and Symbol = '" + teamfilename[teamfilenamelooper] + "';");

// for adding new		//					if (goaliemode == false) mysqlqueryplayers = ("INSERT INTO PLAYERS (PID,Symbol,NUM,Pos,Name) VALUES(" + playerid + ",'" + teamfilename[teamfilenamelooper] + "'," + playernum + ",'" + position + "',\"" + playername + "\");");
// players				//					else					 mysqlqueryplayers = ("INSERT INTO GOALIES (PID,Symbol,NUM,Name) VALUES(" + playerid + ",'" + teamfilename[teamfilenamelooper] + "'," + playernum + ",\"" + playername + "\");");
					if (shots == "" || plusminus == "" || shgoals == "" || shgoals.length() > 4 || plusminus.length() > 6 || playername.length() < 3 || ppgoals.length() > 4 || gwgoals.length() > 4) {
// dev error			//	cout << "ERROR IN DATAFILES, INCOMPLETE DOWNLOAD FOR " << teamfilename[teamfilenamelooper] << endl;
// checking				//	cout << "REDOWNLOADING..." << endl;
						Lparser->getBrokenfiles(teamfilename[teamfilenamelooper]);
						errorinfile = true;
					}
					else mysqllauseet << mysqlqueryplayers << endl;
					playerselect++;
					looper = 0;
					statcounter = 0;
					breaker = 0;
					playerid.clear();
					GP.clear();
					goals.clear();
					assists.clear();
					penalties.clear();
					plusminus.clear();
					shots.clear();
					ppgoals.clear();
					shgoals.clear();
					gwgoals.clear();
					overtimegoals.clear();
					shotsagainst.clear();
					save_prct.clear();
					playername.clear();
					playernum.clear();
					position.clear();
					playerpoints.clear();
					if (errorinfile == true) {
						teamfilenamelooper--;
						errorinfile = false;
						break;
					}
				}
				datafile.close();
				mysqllauseetplayers.close();
				separatedstats.clear();
				filecontents.clear();
				contentcounter = 0;
				fileending = false;
				teamfilenamelooper++;
			} while (teamfilenamelooper < 30);
			//--------------end of loop for all teams---------------------------
			mysqllauseet.close();
			delete Lparser;
	return;
}

void Parser::setCurrentdate(string _cdate)
{
	fstream patchinfo;
	patchinfo.open("data/PATCHINFO.dat", ios::out | ios::trunc);
	patchinfo << _cdate;
	return;
}