#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <pqxx/pqxx>

#include "connection.h"

namespace beast = boost::beast;
namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;
namespace net = boost::asio;


const std::string address = "127.0.0.1";
const std::string port = "8080";

std::string connection_string("host=localhost port=5432 dbname=memebox_data_base user=dmitry password=password");



class Server : std::enable_shared_from_this<Server> {
    net::io_context ioc_;

    tcp::acceptor acceptor_;

    pqxx::work worker_;

    void start_accept();
    std::vector<std::shared_ptr<Connection>> connections_;

    void handle_accept(std::shared_ptr<Connection> connection, beast::error_code ec);
public:
    Server(pqxx::connection &connection_object) : acceptor_{ioc_/*, {address, port}*/}, worker_(connection_object) {
        tcp::resolver resolver(ioc_);
        tcp::endpoint endpoint = *resolver.resolve(address, port).begin();
        acceptor_.open(endpoint.protocol());
        acceptor_.set_option(net::socket_base::reuse_address(true));
        acceptor_.bind(endpoint);
        acceptor_.listen();
    }

    void run_server();
};
