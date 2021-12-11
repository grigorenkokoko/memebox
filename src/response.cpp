#include <nlohmann/json.hpp>
#include <iostream>

#include "connection.h"


void Response::do_response() {
    response_.version(request_.version());
    response_.keep_alive(false);
    switch (request_.method()) {
        case http::verb::get: {
            response_.result(http::status::ok);
            response_.set(http::field::server, "memebox");

            pqxx::result response = worker_.exec("UPDATE public.image_mem SET mem_likes = 1 WHERE mem = '/home/dmitry/prep_project/src/1614550079_23-p-memi-na-belom-fone-24.png';");

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
            response_.body() = "Invalid request method '" + std::string{request_.method_string()} + "'";
            break;
        }
    }
    request_.clear();
}

void Response::create_response_get() {
    if (request_.target() == "/meme_post") {
        response_.set(http::field::content_type, "text/plane");
        response_.body() = "There will be a meme here\n";
    }
}

void Response::create_response_post() {
    response_.set(http::field::content_type, "application/json");

    if (request_.target() == "/sign_in") {
        auto json_body = json::parse(request_.body().data());
        std::cerr << json_body << std::endl;
        json json_response;
        if (check_user_registration(json_body)) {
            json_response = {{"status", "already exist"}};
        } else {
            if (!register_user(json_body)) {
                json_response = {{"status", "success"}};
            } else {
                json_response = {{"status", "fail"}};
            }
        }
        response_.body() = json_response.dump();
    } else if (request_.target() == "/registration") {
        auto json_body = json::parse(request_.body().data());
        json json_response;
        if (check_user_registration(json_body)) {
            json_response = {{"status", "already exist"}};
        } else {
            if (!register_user(json_body)) {
                json_response = {{"status", "success"}};
            } else {
                json_response = {{"status", "fail"}};
            }
        }
        response_.body() = json_response.dump();
    }
}

int Response::check_user_registration(json &user_data) {
    //we get j-son

    // в сигнатуре функции должен быть j-son от клиента, который мы распарсим прямо внутри фнукции
    /*User user{"edp6000@mail.ru", "password"};
    nlohmann::json j{};
    j["login"] = user.e_mail;
    j["password"] = user.password;*/

    //std::cout << j << std::endl;

    /*std::string serializedString = j.dump();
    //we need deserialize it*/
    User user_client{};
    //nlohmann::json j1 = nlohmann::json::parse(serializedString);//

    std::cerr << "in check : " << user_data << std::endl;

    user_client.e_mail = user_data["login"];
    user_client.password = user_data["password"];

    pqxx::result response_= worker_.exec("SELECT * FROM user_registration WHERE e_mail='"+ user_client.e_mail+" ' AND password = '"+user_client.password+"';");
    //worker_.commit();

    std::cerr << "check registr" << std::endl;

    if (response_.size() < 1) {
        return 0;
    }

    return 1;
}

int Response::register_user(json &user_data) {
    /*User user{"edp6000@mail.ru", "password"};
    nlohmann::json j{};
    j["login"] = user.e_mail;
    j["password"] = user.password;*/

    //std::cout << j << std::endl;

    //std::string serializedString = j.dump();
    //we need deserialize it
    User user_client{};
    //nlohmann::json j1 = nlohmann::json::parse(serializedString);

    user_client.e_mail = user_data["login"];
    user_client.password = user_data["password"];

    pqxx::result response_ = worker_.exec("INSERT INTO user_registration(e_mail, password) VALUES ('"+ user_client.e_mail+"', '"+user_client.password+ "');");
    worker_.commit();
    std::cerr << "add to db" << std::endl;

    if (response_.size() >= 1) {
        // бд записывает в таблицу данные, но ничего не возвращает
        return -1;
    }
    //надо дописать что конкретно будет выведено клиенту в случае успеха
    return 0;
}

