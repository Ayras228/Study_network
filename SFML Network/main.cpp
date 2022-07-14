#include<SFML/Network.hpp>
#include<iostream>
#include<string>
#include<Windows.h>





int main()
{
	sf::TcpSocket socket;
	//sf::IpAddress ip = "192.168.3.8";notebook
	sf::IpAddress ip = "192.168.24.248";//aleksey
	//sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	std::cout << "local: " << ip << "\n";
	std::cout <<"public: " << sf::IpAddress::getPublicAddress() << "\n";
	char type;
	std::cout << "Enter tyoe commcring: [c] - client, [s]-server\n";
	std::cin >> type;
	std::string name;
	if (type=='s')
	{
		sf::TcpListener listner;
		listner.listen(2000);
		name = "server\n";
		if (listner.accept(socket) != sf::Socket::Done)
		{
			std::cout << "Error!\n";
		}
	}
	else if (type == 'c')
	{
		name = "client ";
		if (socket.connect(ip, 2000) != sf::Socket::Done)
		{
			std::cout << "Error!\n";
		}
	}
	//std::string name;
	//std::cout << "Enter your name \n";
	//std::cin >> name;
	socket.setBlocking(false);
	std::string message = "";
	sf::Packet packet;
	bool stop = true;
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			std::cin >> message;
		}
		if (message!="")
		{
			packet.clear();
			packet << name << message;
			socket.send(packet);
			message = "";
		}
		if (socket.receive(packet)==sf::Socket::Done)
		{
			std::string nameRec;
			std::string messageRec;

			packet>>nameRec>> messageRec;
			std::cout<<nameRec<<":"<< messageRec <<"\n";

		}
	}
}