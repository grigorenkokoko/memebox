#pragma ONCE

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;
namespace net = boost::asio;

typedef enum {
    GET = 1,
    POST = 2
} type_request_t;

typedef enum {
    MEME_POST = 1,
    SIGN_IN = 2,
    AUTHORIZATION = 3
} target_request_t;

typedef struct {
    type_request_t type_request;
    target_request_t target_request;
} request_info;


class Request {
    http::request<http::string_body> request_;
public:
    Request() = default;

    void do_request(request_info &request, std::map<std::string, std::string> &body);

    void do_request(request_info &request);

    http::request<http::string_body> get_request() { return request_; }
};


class Client : public std::enable_shared_from_this<Client> {
    tcp::resolver resolver_;
    tcp::socket socket_;
    http::request<http::string_body> request_;
    http::response<http::string_body> response_;

    boost::beast::flat_buffer buffer_;

    void on_resolve(boost::system::error_code ec, tcp::resolver::results_type result);

    void on_connect(boost::system::error_code ec);

    void on_write(boost::system::error_code ec, std::size_t bytes_transferred);

    void on_read(boost::system::error_code ec, std::size_t bytes_transferred);

public:
    Client(net::io_context &ioc, http::request<http::string_body> &request) :
            request_(std::move(request)), resolver_(ioc), socket_(ioc) {}

    void run();
};
