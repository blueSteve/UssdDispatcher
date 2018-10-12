#pragma once
#include <winsock2.h>
#include <string>
using namespace std;
class Client
{
public:
	Client(void);
	~Client(void);
	string ip;
	unsigned short port;
	SOCKET m_socket;

	bool send(BYTE* buff);
	bool connect(string ip,unsigned short port);
	bool disconnect();

	virtual bool recv() = 0;
	virtual bool exec() = 0;
	virtual bool makePkg() = 0;
	virtual bool parseMsg() = 0;

private:
	BYTE* buffer;
};

