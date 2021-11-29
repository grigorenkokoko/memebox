#include "connection.h"

void Response::do_response() {
    response_.version(request_.version());
    response_.keep_alive(false);
    switch (request_.method()) {
        case http::verb::get: {
            response_.result(http::status::ok);
            response_.set(http::field::server, "memebox");
            create_response_get();
            break;
        }
        case http::verb::post: {
            response_.result(http::status::ok);
            response_.set(http::field::server, "memebox");
            create_response_post();
            break;
        }
        default: {
            response_.result(http::status::bad_request);
            response_.set(http::field::content_type, "text/plane");
            beast::ostream(response_.body())
                    << "Invalid request method '"
                    << std::string{request_.method_string()}
                    << "'";
            break;
        }
    }
}

void Response::create_response_get() {
    if (request_.target() == "/meme_post") {
        response_.set(http::field::content_type, "text/plane");
        beast::ostream(response_.body())
                << "There will be a meme here\n";
    }
}

void Response::create_response_post() {
    response_.set(http::field::content_type, "application/json");
    if (request_.target() == "/sign_in") {
        beast::ostream(response_.body())
                << "There will be a sign_in info here\n";
    } else if (request_.target() == "/authorization") {
        beast::ostream(response_.body())
                << "There will be a authorization info here\n";
    }
}
