#pragma ONCE

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "nlohmann/json.hpp"

namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;
namespace net = boost::asio;
namespace beast = boost::beast;

typedef enum {
    GET = 1,
    POST = 2
} type_request_t;

typedef enum {
    MEME_POST = 1,
    SIGN_IN = 2,
    REGISTRATION = 3,
    INCREASE_LIKE = 4,
    INCREASE_DISLIKE = 5,
    REDUCE_LIKE = 6,
    REDUCE_DISLIKE = 7,
    SET_MEME = 8,
    DOWNLOAD_MEME = 9
} target_request_t;

typedef struct {
    type_request_t type_request;
    target_request_t target_request;
} request_info;

typedef enum {
    SUCCESS = 1,
    FAIL = 2,
    ALREDY_EXIST = 3,
    ERROR = 4
} response_status_t;




class Request {
    http::request<http::string_body> request_;
public:
    Request() = default;

    void do_request(request_info &request, std::string &body);

    void do_request(request_info &request);

    http::request<http::string_body> get_request() { return request_; }
};


class Client : public std::enable_shared_from_this<Client> {
    tcp::resolver resolver_;
    tcp::socket socket_;
    http::request<http::string_body> request_;
    http::response<http::string_body> response_;

    boost::beast::flat_buffer buffer_;

    std::vector<unsigned char> meme_byte;

    std::string id_meme;

    nlohmann::json json_body;

    void on_resolve(boost::system::error_code ec, tcp::resolver::results_type result);

    void on_connect(boost::system::error_code ec);

    void on_write(boost::system::error_code ec, std::size_t bytes_transferred);

    void on_read(boost::system::error_code ec, std::size_t bytes_transferred);

    void get_filename();

public:
    Client(net::io_context &ioc, http::request<http::string_body> &request) :
            request_(std::move(request)), resolver_(ioc), socket_(ioc) {}

    void run();

    void set_request(http::request<http::string_body> &request) {request_ = request;}

    int check_status();

    std::vector<unsigned char> &get_meme();

    void clean_response() { response_.clear();}

    void parse_body() { json_body = nlohmann::json::parse(response_.body().data());}

    void set_id_meme() {id_meme = json_body["id"];}

    std::string &get_id_meme() { return id_meme;}

    int get_count_likes();

    int get_count_dislikes();

    http::request<http::string_body> &get_request() {return request_;}

    http::response<http::string_body>  &get_response() {return response_;}
};
