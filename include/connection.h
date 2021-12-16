#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <pqxx/pqxx>
#include <nlohmann/json.hpp>


namespace beast = boost::beast;
namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;
namespace net = boost::asio;
using json = nlohmann::json;


class User {
    std::string e_mail;
    std::string password;
    std::string name;
    std::string surname;
    std::string id;
    pqxx::work &worker_;
public:
    User(pqxx::work &worker) : worker_(worker) {};

    int check_user_login(json &user_data);

    int register_user(json &user_data);

    int check_user_password(json &user_data);
};

class Response {

    http::request<http::string_body> request_;

    http::response<http::string_body> response_;

    //pqxx::work &worker_;

    User user_;

    void create_response_get();

    void create_response_post();

public:
    Response(http::request<http::string_body> &request, pqxx::work &worker) : request_(request), user_(worker) {};

    void do_response();

    http::response<http::string_body> get_response() {
        response_.prepare_payload();
        return response_;
    }
};


class Connection : public std::enable_shared_from_this<Connection> {
    tcp::socket socket_;

    beast::flat_buffer buffer_{8192};

    http::request<http::string_body> request_;

    http::response<http::string_body> response_;

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
