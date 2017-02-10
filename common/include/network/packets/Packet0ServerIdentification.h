#include "network/packets/Packet.h"

#ifndef PACKET0_SERVERIDENTIFICATION_H
#define PACKET0_SERVERIDENTIFICATION_H

#include "network/DataInputStream.h"
#include <string>

#define MAX_SERVERNAME_LENGTH 32

class Packet0ServerIdentification : public Packet {
    private:
        std::string m_servername;
    public:
        Packet0ServerIdentification(DataInputStream *dis);
        Packet0ServerIdentification(std::string servername);

        std::string getServername();
        virtual unsigned int getLength() override;
};

#endif
