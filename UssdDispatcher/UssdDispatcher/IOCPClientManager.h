#pragma once
#include "Client.h"
#include "list"
class IOCPClientManager
{
public:
	IOCPClientManager(void);
	~IOCPClientManager(void);
private:
	list<Client*> m_lst_client;
	bool AddClient(Client* client);
	bool RemoveClient(Client* client);
	Client* GetClient(SOCKET socket);
};

