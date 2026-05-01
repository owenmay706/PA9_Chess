#pragma once


#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <optional>
#include <vector>

class NetworkManager {
private:
    sf::TcpSocket socket;
    sf::TcpListener listener;
    bool isHost = false;
    bool connected = false;

public:

    bool hostGame(unsigned short port)
    {
        isHost = true;

        if (listener.listen(port) != sf::Socket::Status::Done)
        {
            std::cout << "NetworkManager: Failed to listen on port " << port << "\n";
            return false;
        }

        std::cout << "NetworkManager: Listening on port " << port << ", waiting for opponent...\n";

        if (listener.accept(socket) != sf::Socket::Status::Done)
        {
            std::cout << "NetworkManager: Failed to accept connection\n";
            return false;
        }

        socket.setBlocking(false);
        connected = true;
        std::cout << "NetworkManager: Opponent connected!\n";
        return true;
    }

    bool joinGame(const std::string& ip, unsigned short port)
    {
        isHost = false;

        std::cout << "NetworkManager: Connecting to " << ip << ":" << port << "...\n";

        // sf::Dns::resolve() returns optional<vector<sf::IpAddress>>
        // so we check the list is not empty and take the first address
        std::optional<std::vector<sf::IpAddress>> addresses = sf::Dns::resolve(ip);

        if (!addresses || addresses->empty())
        {
            std::cout << "NetworkManager: Could not resolve IP address: " << ip << "\n";
            return false;
        }

        sf::IpAddress address = addresses->front();

        if (socket.connect(address, port) != sf::Socket::Status::Done)
        {
            std::cout << "NetworkManager: Failed to connect to " << ip << ":" << port << "\n";
            return false;
        }

        socket.setBlocking(false);
        connected = true;
        std::cout << "NetworkManager: Connected to host!\n";
        return true;
    }

    bool sendMove(int fr, int fc, int tr, int tc)
    {
        if (!connected)
        {
            std::cout << "NetworkManager: Cannot send, not connected\n";
            return false;
        }

        sf::Packet packet;
        packet << fr << fc << tr << tc;

        sf::Socket::Status status = socket.send(packet);

        if (status != sf::Socket::Status::Done)
        {
            std::cout << "NetworkManager: Failed to send move ("
                << fr << "," << fc << ") -> ("
                << tr << "," << tc << ")\n";
            return false;
        }

        return true;
    }

    bool receiveMove(int& fr, int& fc, int& tr, int& tc)
    {
        if (!connected)
            return false;

        sf::Packet packet;
        sf::Socket::Status status = socket.receive(packet);

        // NotReady means no data yet — normal for a non-blocking
        // socket being polled every frame, so silently return false
        if (status == sf::Socket::Status::NotReady)
            return false;

        if (status == sf::Socket::Status::Disconnected)
        {
            std::cout << "NetworkManager: Opponent disconnected\n";
            connected = false;
            return false;
        }

        if (status != sf::Socket::Status::Done)
        {
            std::cout << "NetworkManager: Receive error\n";
            return false;
        }

        packet >> fr >> fc >> tr >> tc;
        return true;
    }

    bool isConnected() const { return connected; }
    bool getIsHost()    const { return isHost; }
};