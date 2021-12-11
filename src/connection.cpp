#include <iostream>

#include "connection.h"

void Connection::start_connection() {
    read_request();
}

void Connection::read_request() {
    auto self = shared_from_this();
    http::async_read(socket_, buffer_, request_, [self](beast::error_code ec, std::size_t bytes_transferred) {
        boost::ignore_unused(bytes_transferred);
        self->handle_read();
    });
}

void Connection::handle_read() {
    std::cerr << "new accept: " << request_.method() << " " << request_.target() << std::endl;
    Response response(request_, worker_);
    response.do_response();

    response_ = response.get_response();

    write_response();
}


void Connection::write_response() {
    auto self = shared_from_this();

    //response_.body() = std::string("abobus");
    response_.content_length(response_.body().size());

    std::cerr << "close accept\n";

    http::async_write(socket_, response_, [self](beast::error_code ec, std::size_t) {
        std::cout << "end write" << std::endl;
        self->socket_.shutdown(tcp::socket::shutdown_send, ec);
    });
}
