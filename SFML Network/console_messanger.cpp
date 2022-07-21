#include "User.h"
#include"Server.h"
#include"Client.h"
#include<chrono>
//char read_type()
//{
//	std::cout << "Enter type connect: [c] - client, [s]-server\n";
//	char type;
//	std::cin >> type;
//	return type;
//}
//std::string read_name()
//{
//	std::cout << "Enter your name: \n";
//	std::string name;
//	std::cin >> name;
//	
//	return name;
//}
User* create_user(char type)
{
	User* user;
	if (type == 's')
	{
		user = new Server();
		
	}
	else if (type == 'c')
	{
		user = new Client();
		std::cout << "Enter ip friend " << std::endl;
		std::string connect_ip;
		std::cin >> connect_ip;
		user->set_connect_ip(connect_ip);

	}
	else
	{
		std::cout << "no connection \t error symbol\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::exit(true);
	}
	return user;
}
void handle_connection(User *user)
{
	if (user->connect())
	{
		std::cout << "connect is correct\n";
	}
	else
	{
		std::cout << "connect is not correct\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::exit(true);
	}
}

template<typename T>
T read(std::string str )
{
	std::cout << str;
	T type;
	std::cin >> type;
	return type;
}

int main()
{
	
	char type = read<char>("Enter type connect: [c] - client, [s]-server\n");
	User *user=create_user(type);

	handle_connection(user);
	
	std::string user_name = read<std::string>("Enter your name: \n");
	user->set_name(user_name);


	std::cout << "Enter message\n";

	user->run_message();

}