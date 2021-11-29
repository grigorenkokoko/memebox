#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>


namespace beast = boost::beast;
namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;
namespace net = boost::asio;

class Response {
    http::request<http::dynamic_body> request_;

    http::response<http::dynamic_body> response_;

    void create_response_get();

    void create_response_post();

public:
    Response(http::request<http::dynamic_body> &request) : request_(request) {};

    void do_response();

    http::response<http::dynamic_body> get_response() { return response_; }
};


class Connection : public std::enable_shared_from_this<Connection> {
    tcp::socket socket_;

    beast::flat_buffer buffer_{8192};

    http::request<http::dynamic_body> request_;

    http::response<http::dynamic_body> response_;

    void read_request();

    void handle_read();

    void write_response();

    void handle_write(beast::error_code &ec);
public:
    Connection(net::io_context &ioc) : socket_{ioc} {}

    void start_connection();

    tcp::socket &get_socket() {return socket_;}
};

#endif  // CONNECTION_H
