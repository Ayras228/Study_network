#include "User.h"
#include"Server.h"
#include"Client.h"
#include<chrono>

int main()
{
	
	std::cout << "Enter type connect: [c] - client, [s]-server\n";
	char type;
	std::cin >> type;

	User *msg;
	if (type == 's')
	{
		msg = new Server();
		msg->connect();
	}
	else if (type == 'c')
	{
		msg = new Client ();
		std::cout << "Enter ip friend " << std::endl;
		std::string connect_ip;
		std::cin >> connect_ip;
		msg->connect(connect_ip);
		
	}
	else
	{
		std::cout << "no connection \t error symbol\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::exit(true);
	}

	
	std::cout << "connect is correct\n";

	std::cout << "Enter your name: \n";
	std::string name;
	std::cin >> name;
	msg->set_name(name);


	std::cout << "Enter message\n";

	msg->run_message();

}