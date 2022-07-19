#include<SFML/Network.hpp>
#include<iostream>
#include<string>
#include<Windows.h>
#include <chrono>
#include <thread>
#include<mutex>
void cin_message(sf::Packet &packet, sf::TcpSocket &socket, std::string message, std::string name)
{

	std::cin >> message;
	
	if (message != "")
	{
		std::mutex mtx;
		mtx.lock();
		packet.clear();
		packet << name << message;
		socket.send(packet);
		message = "";
		mtx.unlock();
	}
}
void cout_message(sf::Packet packet, sf::TcpSocket &socket, std::string message, std::string name)
{
	if (socket.receive(packet) == sf::Socket::Done)
	{
		std::mutex mtx;
		//socket.setBlocking(false);
		std::string nameRec;
		std::string messageRec;

		mtx.lock();
		packet >> nameRec >> messageRec;
		std::cout << nameRec << ":" << messageRec << "\n";
		mtx.unlock();
	}
}

void endPAcket(sf::Packet& packet)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << packet.endOfPacket() << std::endl;
}
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
		//std::cin >> ip; 
		ip = "192.168.3.6";
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
		
		std::thread h1(cin_message, std::ref(packet), std::ref(socket), message, name);
		//endPAcket(std::ref(packet));
		std::thread h2(cout_message, std::move(packet), std::ref(socket), message, name);
		h1.detach();
		h2.detach();
	}
	
}