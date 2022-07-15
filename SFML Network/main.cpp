#include<SFML/Network.hpp>
#include<iostream>
#include<string>
#include<Windows.h>
#include <chrono>
#include <thread>


int main()
{
	sf::TcpSocket socket;
	//sf::IpAddress ip = "192.168.3.6";//I
	//sf::IpAddress ip = "192.168.3.8";notebook
	//sf::IpAddress ip = "192.168.24.248";//aleksey
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	std::cout << "local: " << ip << "\n";
	std::cout <<"public: " << sf::IpAddress::getPublicAddress() << "\n";
	char type;
	std::cout << "Enter tyoe commcring: [c] - client, [s]-server\n";
	std::cin >> type;
	std::string name;
	if (type=='s')
	{
		sf::TcpListener listner;
		listner.listen(5000);
		name = "server";
		if (listner.accept(socket) != sf::Socket::Done)
		{
			std::cout << "Error!\n";
		}
	}
	else if (type == 'c')
	{
		name = "client ";
		std::cout << "connect to ip" << std::endl;
		std::cin >> ip; 
		if (socket.connect(ip, 5000) != sf::Socket::Done)
		{
			std::cout << "Error!\n";
		}
		
	}
	else
	{
		std::cout << "no connection \t error symbol\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::exit(1);
	}

	std::cout << "connect \n";
	//std::string name;
	//std::cout << "Enter your name \n";
	//std::cin >> name;
	socket.setBlocking(false);
	std::string message = "";
	sf::Packet packet;
	std::cout << "Enter message\n";
	while (true)
	{

		std::cin >> message;
		
		if (message!="")
		{
			packet.clear();
			packet << name << message;
			socket.send(packet);
			message = "";
			//socket.setBlocking(true);
		}
		if (socket.receive(packet)==sf::Socket::Done)
		{
			//socket.setBlocking(false);
			std::string nameRec;
			std::string messageRec;

			packet>>nameRec>> messageRec;
			std::cout<<nameRec<<":"<< messageRec <<"\n";

		}
	}
}