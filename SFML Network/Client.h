#pragma once
#include "User.h"
class Client : virtual public User
{
	 void connect(sf::IpAddress connect_ip);
};

