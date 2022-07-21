#pragma once
#include<SFML/Network.hpp>
#include<iostream>
#include<string>
#include<Windows.h>
#include<thread>
#include<mutex>

class User
{
public:
	 User();
	~User();
	void cin_message();
	void cout_message();
	void run_message();
	virtual bool connect();
	void set_name(std::string name);
	sf::IpAddress const get_connect_ip();
	void set_connect_ip(sf::IpAddress connect_ip);
	std::string const get_name();
	std::unique_ptr<sf::TcpSocket> const& get_ptr_socket();

private:

	std::unique_ptr < sf::TcpSocket > ptr_socket =
		std::make_unique < sf::TcpSocket >();
	sf::IpAddress Localip;
	sf::IpAddress Publicip;
	sf::IpAddress connect_ip;
	std::mutex mtx;
	std::string name;
	std::string message = "";
	sf::Packet packet;

};



