#include <iostream>

#include "client_memebox.h"
#include "nlohmann/json.hpp"

std::string host = "127.0.0.1";
std::string port = "8080";


void Client::run() {
    std::cerr << "in run\n";
    resolver_.async_resolve(host, port, std::bind(&Client::on_resolve, shared_from_this(),
                                                  std::placeholders::_1, std::placeholders::_2));
}

void Client::on_resolve(boost::system::error_code ec, tcp::resolver::results_type result) {
    std::cerr << "in resolve\n";
    boost::asio::async_connect(socket_, result.begin(), result.end(), std::bind(&Client::on_connect,
                                                                                shared_from_this(),
                                                                                std::placeholders::_1));

}


void Client::on_connect(boost::system::error_code ec) {
    std::cerr << "in connect\n";
    http::async_write(socket_, request_, std::bind(&Client::on_write, shared_from_this(),
                                               std::placeholders::_1, std::placeholders::_2));

}

void Client::on_write(boost::system::error_code ec, std::size_t bytes_transferred) {
    std::cerr << "in write\n";
    boost::ignore_unused(bytes_transferred);


    http::async_read(socket_, buffer_, response_, std::bind(&Client::on_read, shared_from_this(),
                                                       std::placeholders::_1, std::placeholders::_2));
}

void Client::on_read(boost::system::error_code ec, std::size_t bytes_transferred) {
    std::cerr << "in read\n";
    boost::ignore_unused(bytes_transferred);

    std::cout << response_ << std::endl;

    socket_.shutdown(tcp::socket::shutdown_both, ec);
    socket_.close();
}


int Client::check_status() {
    auto json_body = nlohmann::json::parse(response_.body().data());
    std::string status = json_body["status"];
    if (status == "success") {
        return SUCCESS;
    } else if (status == "fail") {
        return FAIL;
    } else if (status == "alredy_exist") {
        return ALREDY_EXIST;
    }

    return ERROR;
}

/*int main() {
    std::cout << "Choose action:" << std::endl;
    std::cout << "1. Get meme" << std::endl;
    std::cout << "2. Sign in" << std::endl;
    std::cout << "3. Authorization" << std::endl;

    int choose = 0;
    std::cin >> choose;

    request_info request_struct = { };

    Request request;

    switch (choose) {
        case MEME_POST: {
            request_struct.type_request = GET;
            request_struct.target_request = MEME_POST;
            request.do_request(request_struct);
            break;
        }
        case SIGN_IN: {
            std::string login;
            std::cout << "Login: ";
            std::cin >> login;
            std::string password;
            std::cout << "Password: ";
            std::cin >> password;
            request_struct.type_request = POST;
            request_struct.target_request = SIGN_IN;
            std::map<std::string, std::string> body;
            body["login"] = login;
            body["password"] = password;
            request.do_request(request_struct, body);
            break;
        }
        case AUTHORIZATION: {
            std::string login;
            std::cout << "Login: ";
            std::cin >> login;
            std::string password;
            std::cout << "Password: ";
            std::cin >> password;
            request_struct.type_request = POST;
            request_struct.target_request = SIGN_IN;
            std::map<std::string, std::string> body;
            body["login"] = login;
            body["password"] = password;
            request.do_request(request_struct, body);
            break;
        }
    }

    http::request<http::string_body> to_client = request.get_request();

    std::cerr << "Запрос: \n" << to_client;

    net::io_context ioc;
    std::shared_ptr<Client> client(new Client(ioc, to_client));

    client->run();

    ioc.run();

    return 0;
}*/
