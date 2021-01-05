#pragma comment(lib,"ws2_32.lib")
#include "Loader.h"
using namespace std;

Loader::Loader()
{

}

Loader::~Loader()
{

}

string Loader::getCurrentdate()
{
	fstream tiedosto;
	string currentdate;
	tiedosto.open("data/PATCHINFO.DAT");
	getline(tiedosto, currentdate);
	tiedosto.close();
	return currentdate;
}

string Loader::getUpdatedate()
{
	fstream tiedosto;
	tiedosto.open(("data/TEAMSTATS.txt"), ios::trunc | ios::out);

	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << "ERROR IN WSASTARTUP";
		cin.ignore();
		return "ERROR IN WSASTARTUP";
	}

	SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct hostent *hostaddress;
	string datalocation;


	hostaddress = gethostbyname("www.tsn.ca");
	datalocation = "GET /datafiles/XML/NHL/standings.xml   HTTP/1.0\r\nHost: www.tsn.ca\r\nConnection: close\r\n\r\n";


	SOCKADDR_IN SockAddr;
	SockAddr.sin_port = htons(80);
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = *((unsigned long*)hostaddress->h_addr);


	if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0){
		cout << "SOCKET CONNECTION FAILURE";
		cin.ignore();
		return "SOCKET CONNECTION FAILURE";
	}

	send(Socket, datalocation.c_str(), strlen(datalocation.c_str()), 0);
	char buffer[9000];
	int nDataLength = 1;
	while (nDataLength != 0) {
		nDataLength = recv(Socket, buffer, 9000, 0);
		//for (int i = 0; i < 25; i++)	{
		//	if (buffer[i] == '\xCC') {
		//		buffer[i] = '\0';
		//		break;
		//	}
		//}


		for (int i = 0; i < 9000; i++)	{
			if (buffer[i] == 'Ì') {
				buffer[i] = '\0';
			}
			tiedosto << buffer[i];
		}
		if (strstr(buffer, "</standings>") != NULL) {
			break;
		}
	}

	closesocket(Socket);
	WSACleanup();
	tiedosto.close();
	string updatedate;

	tiedosto.open("data/TEAMSTATS.txt");
	int linenumber = 1;
	do
	{
		getline(tiedosto, updatedate);
		linenumber++;
	} while (linenumber < 15);
	tiedosto.close();
	updatedate = updatedate.substr(38, 22);
	linenumber = 0;
	do {
		if (updatedate.at(linenumber) == '"') updatedate.at(linenumber) = '\0';
		linenumber++;
	} while (linenumber < updatedate.length());
	tiedosto.close();

	return updatedate;
}
void Loader::getAlldatafiles()
{
	ofstream tiedosto;
	array<string, 31> filename = { "TEAMSTATS", "MTL", "ANA", "PIT", "NYI", "TBL", "VAN", "NSH", "STL", "CGY", "DET", "LAK", "CHI", "BOS", "WPG", "TOR", "MIN", "OTT", "SJS", "FLA", "WSH", "NYR", "DAL", "NJD", "ARI", "COL", "PHI", "CAR", "CBJ", "EDM", "BUF" };
	double PATCHERLOOPER = 1;
	vector<string> filechecker;
	do {

		tiedosto.open(("data/" + filename[PATCHERLOOPER] + ".txt"), ofstream::trunc);

		WSADATA wsaData;

		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			cout << "ERROR IN WSASTARTUP";
			cin.ignore();
			return;
		}

		SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		struct hostent *hostaddress;
		string datalocation;

		if (PATCHERLOOPER == 0) {
			hostaddress = gethostbyname("www.tsn.ca");
			datalocation = "GET /datafiles/XML/NHL/standings.xml   HTTP/1.0\r\nHost: www.tsn.ca\r\nConnection: close\r\n\r\n";
		}
		else if (PATCHERLOOPER > 0) {
			hostaddress = gethostbyname("nhlwc.cdnak.neulion.com");
			datalocation = ("GET /fs1/nhl/league/playerstatsline/20142015/2/" + filename[PATCHERLOOPER] + "/iphone/playerstatsline.json  HTTP/1.1\r\nHOST: nhlwc.cdnak.neulion.com\r\nConnection: close\r\n\r\n");
		}
		SOCKADDR_IN SockAddr;
		SockAddr.sin_port = htons(80);
		SockAddr.sin_family = AF_INET;
		SockAddr.sin_addr.s_addr = *((unsigned long*)hostaddress->h_addr);


		if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0){
			cout << "SOCKET CONNECTION FAILURE";
			cin.ignore();
			return;
		}

		send(Socket, datalocation.c_str(), strlen(datalocation.c_str()), 0);
		char buffer[4000];
		int nDataLength = 1;
		while (nDataLength != 0) {
			nDataLength = recv(Socket, buffer, 4000, 0);
			//for (int i = 0; i < 50; i++)	{
			//	if (buffer[i] == '\xCC') {
			//		buffer[i] = '\0';
			//		break;
			//	}
			//}


			for (int i = 0; i < 4000; i++)	{
				if (buffer[i] == 'Ì' && buffer[i + 1] == 'Ì') {
					buffer[i] = '\0';
				}
				tiedosto << buffer[i];
			}
			if (strstr(buffer, "</standings>") != NULL) {
				break;
			}
			else if (strstr(buffer, "goalieCategories") != NULL) {
				break;
			}
		}

		closesocket(Socket);
		WSACleanup();

		tiedosto.close();

		PATCHERLOOPER++;
		_sleep(500);
		system("cls");
		cout << endl << endl << "			-  UPDATE  -" << endl << endl;
		cout << "	Update Progress: " << fixed << setprecision(2) << ((PATCHERLOOPER/31)*50) << "%" << endl;
	} while (PATCHERLOOPER < 31);

	return;
}
void Loader::getBrokenfiles(string _teamname)
{
	ofstream tiedosto;
	tiedosto.open(("data/" + _teamname + ".txt"), ofstream::trunc);

	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << "ERROR IN WSASTARTUP";
		cin.ignore();
		return;
	}

	SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct hostent *hostaddress;
	string datalocation;

	hostaddress = gethostbyname("nhlwc.cdnak.neulion.com");
	datalocation = ("GET /fs1/nhl/league/playerstatsline/20142015/2/" + _teamname + "/iphone/playerstatsline.json  HTTP/1.1\r\nHOST: nhlwc.cdnak.neulion.com\r\nConnection: close\r\n\r\n");

	SOCKADDR_IN SockAddr;
	SockAddr.sin_port = htons(80);
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = *((unsigned long*)hostaddress->h_addr);


	if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0){
		cout << "SOCKET CONNECTION FAILURE";
		cin.ignore();
		return;
	}

	send(Socket, datalocation.c_str(), strlen(datalocation.c_str()), 0);
	char buffer[50];
	int nDataLength = 1;
	while (nDataLength != 0) {
		nDataLength = recv(Socket, buffer, 50, 0);
		for (int i = 0; i < 50; i++)	{
			if (buffer[i] == '\xCC') {
				buffer[i] = '\0';
				break;
			}
		}


		for (int i = 0; i < 50; i++)	{
			if (buffer[i] == '\xCC') {
				buffer[i] = '\0';
			}
			tiedosto << buffer[i];
		}
		if (strstr(buffer, "</standings>") != NULL) {
			break;
		}
		else if (strstr(buffer, "goalieCategories") != NULL) {
			break;
		}
	}

	closesocket(Socket);
	WSACleanup();
	tiedosto.close();

	return;
}
