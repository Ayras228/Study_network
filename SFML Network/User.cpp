#include "User.h"


User::User()
{
	sf::IpAddress Localip = sf::IpAddress::getLocalAddress();
	std::cout << "local: " << Localip << "\n";
	sf::IpAddress Publicip = sf::IpAddress::getPublicAddress();
	std::cout << "public: " << Publicip << "\n";
}
User::~User()
{
}
void User::cin_message()
{
	while (true)
	{
		std::getline(std::cin, message);

		if (message != "")
		{
			
			mtx.lock();
			packet.clear();
			packet << name << message;
			ptr_socket.get()->send(packet);
			packet.clear();

			message = "";
			mtx.unlock();
		}

	}

}
void User::cout_message()
{

	while (true)
	{

		if (get_ptr_socket().get()->receive(packet) == sf::Socket::Done)
		{
			
			std::string nameRec;
			std::string messageRec;
			mtx.lock();
			packet >> nameRec >> messageRec;
			std::cout << nameRec << ":" << messageRec << "\n";
			mtx.unlock();
		}
	}

}
void User::run_message()
{
	std::thread h1(&User::cin_message, this);
	std::thread h2(&User::cout_message, this);
	h1.join();
	h2.join();
}
bool User::connect()
{
	return false;
}





void User::set_name(std::string name)
{
	this->name = name;
}
sf::IpAddress const User::get_connect_ip()
{
	return connect_ip;
}
void User::set_connect_ip(sf::IpAddress connect_ip)
{
	this->connect_ip = connect_ip;
}
std::string const User::get_name()
{
	return name;
}


std::unique_ptr<sf::TcpSocket> const &User::get_ptr_socket()
{
	return ptr_socket;
}

