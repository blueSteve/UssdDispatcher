#pragma once
#include "client.h"
class MyClient :
	public Client
{
public:
	MyClient(void);
	~MyClient(void);
	bool recv();
	bool exec();
	bool makePkg();
	bool parseMsg();
};

