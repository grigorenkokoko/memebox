#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

#include "server_memebox.h"
#include "connection.h"

void Server::run_server() {
    std::cerr << "run server" << std::endl;
    start_accept();

    ioc_.run();
}

void Server::start_accept() {
    std::shared_ptr<Connection> connection(new Connection(ioc_));

    acceptor_.async_accept(connection->get_socket(),
                           boost::bind(&Server::handle_accept, this, connection, boost::asio::placeholders::error));
}


void Server::handle_accept(std::shared_ptr<Connection> connection, beast::error_code ec) {
    if (!ec) {
        connection->start_connection();
        start_accept();
    }
}

int main() {
    Server meme_server;

    meme_server.run_server();

    return 0;
}
