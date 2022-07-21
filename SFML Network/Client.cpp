#include "Client.h"

void Client::connect(sf::IpAddress connect_ip)
{

    if (get_ptr_socket().get()->connect(connect_ip, 5000) != sf::Socket::Done)
    {
        std::cout << "Error!\n";
    }

}
