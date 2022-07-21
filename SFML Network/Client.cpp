#include "Client.h"

bool Client::connect()
{

    if (get_ptr_socket().get()->connect(get_connect_ip(), 5000) != sf::Socket::Done)
    {
        std::cout << "Error!\n";
        return false;
    }
    return true;
}
