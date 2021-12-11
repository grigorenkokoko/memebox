#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <pqxx/pqxx>

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>


namespace beast = boost::beast;
namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;
namespace net = boost::asio;

class Response {
    struct User {
        std::string e_mail;
        std::string password;
    };
    
    int check_user_registration();

    int register_user();

    http::request<http::string_body> request_;

    http::response<http::dynamic_body> response_;

    pqxx::work &worker_;

    void create_response_get();

    void create_response_post();

public:
    Response(http::request<http::dynamic_body> &request, pqxx::work &worker) : request_(request), worker_(worker) {};

    void do_response();

    http::response<http::dynamic_body> get_response() { return response_; }
};


class Connection : public std::enable_shared_from_this<Connection> {
    tcp::socket socket_;

    beast::flat_buffer buffer_{8192};

    http::request<http::dynamic_body> request_;

    http::response<http::dynamic_body> response_;

    pqxx::work &worker_;

    void read_request();

    void handle_read();

    void write_response();

    void handle_write(beast::error_code &ec);
public:
    Connection(net::io_context &ioc, pqxx::work &worker) : socket_{ioc}, worker_(worker) {}

    void start_connection();

    tcp::socket &get_socket() {return socket_;}
};

#endif  // CONNECTION_H
