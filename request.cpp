#include "client_memebox.h"
#include <iostream>

void Request::do_request(request_info &request) {
    request_.version(11);
    request_.set(http::field::host, "127.0.0.1");
    request_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    request_.set(http::field::content_type, "text/plane");
    if (request.type_request == GET) {
        request_.method(http::verb::get);
        if (request.target_request == MEME_POST) {
            request_.target("/meme_post");
        }
    }
    request_.prepare_payload();
}

void Request::do_request(request_info &request, std::string &body) {
    request_.version(11);
    request_.set(http::field::host, "127.0.0.1");
    request_.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    request_.set(http::field::content_type, "application/json");
    if (request.type_request == POST) {
        request_.method(http::verb::post);
        if (request.target_request == SIGN_IN) {
            request_.target("/sign_in");
        } else if (request.target_request == REGISTRATION) {
            request_.target("/registration");
        }
        request_.body() = body;
        std::cerr << "body: " << request_.body().data() << std::endl;
        //TODO: сформировать тело запроса в json и в string
    }
    request_.prepare_payload();
}

