#include "Server.h"

void Server::connect()
{
    sf::TcpListener listner;
    listner.listen(5000);
    
    if (listner.accept(*get_ptr_socket()) != sf::Socket::Done)
    {
        std::cout << "Error!\n";
    }
}
