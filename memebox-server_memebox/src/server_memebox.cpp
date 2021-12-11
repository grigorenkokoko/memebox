#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <pqxx/pqxx>

#include "server_memebox.h"
#include "connection.h"

void Server::run_server() {
    std::cerr << "run server" << std::endl;
    start_accept();

    ioc_.run();
}

void Server::start_accept() {
    std::shared_ptr<Connection> connection(new Connection(ioc_, worker_));

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
    std::string connection_string(" host=localhost port=5432 dbname=memebox_data_base user=dmitry password=password");

    pqxx::connection connection_object(connection_string.c_str());
    Server meme_server(connection_object);

    
    meme_server.run_server();

    return 0;
}
