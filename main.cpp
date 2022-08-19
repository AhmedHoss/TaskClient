#pragma warning(suppress : 4996)
#include<iostream>
#include<WS2tcpip.h>
#include<string>
#include <chrono>
#pragma comment (lib, "ws2_32.lib")
using namespace std;

void main() {

	string ipAdress = "127.0.0.1";  //IP of server
	int port = 54000;				//Listening port #

	// Initialize WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "cant initialize winsock, Err #" << wsResult << endl;
		return;
	}

	// Create socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cerr << "cant create socket, Err#" << WSAGetLastError() << endl;
		WSACleanup();
		return;
	}

	// Fill in hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAdress.c_str(), &hint.sin_addr);

	// Connecct to server
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR) {
		cerr << "cant connect to server, Err #" << WSAGetLastError() << endl;
		closesocket(sock);
		WSACleanup();
		return;
	}

	// Do-while loop to send and recieve data
	char buf[4096];
	char timebuf[4096];
	int value;
	int counter = 0;
	int total=0;
	int average = 0;;

	do {
		// wait for response
		for (int i = 0;i < 5;i++) {
			ZeroMemory(buf, 4096);
			int receiveResult = recv(sock, buf, 4096, 0);
			if (receiveResult != SOCKET_ERROR) {
				if (receiveResult > 0) {
					counter++;
					string temp = string(buf, 0, receiveResult);
					cout << temp<<endl;
					value = stoi(temp);
					total += value;
					average = total / counter;
				}
			}
		}
		auto timenow =
			chrono::system_clock::to_time_t(chrono::system_clock::now());
		cout << ctime(&timenow) ;
		cout << "Total>" << total << endl;
		cout << "Average>" << average << endl<<"\n";
	} while (true);
	//  close down everything
	closesocket(sock);
	WSACleanup();
}