#ifndef SERVER_H
#define SERVER_H

#include "Packet.h"
#include <winsock2.h>
#include <vector>

class Client; //Forward declaration

class Server {
private:
    SOCKET m_serverSocket;
    std::vector<Client*> m_clients;

    SOCKET waitForConnection();
    void listen();

public:
    Server();

    void removeClient(Client *client);
    void addClient(Client *client);

    void close();
    void start();
    void broadcast(Packet *packet);
};

#endif // SERVER_H
