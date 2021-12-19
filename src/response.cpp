#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

#include "connection.h"
#include "base64.h"

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
        if (user_.check_user_login(json_body) == 1) {
            meme_.get_filename_by_db();
            meme_.create_str_byte();
            json_response = {{"status", "success"}, {"meme", meme_.get_meme_byte()}};
        } else {
            json_response = {{"status", "fail"}};
        }
        response_.body() = json_response.dump();
    } else if (request_.target() == "/registration") {
        auto json_body = json::parse(request_.body().data());
        json json_response;
        if (!user_.check_user_login(json_body)) {
            if (!user_.register_user(json_body)) {
                json_response = {{"status", "success"}};
                meme_.get_filename_by_db();
            } else {
                json_response = {{"status", "fail"}};
            }
        } else {
            json_response = {{"status", "already exist"}};
        }
        response_.body() = json_response.dump();
    }
}


// парсим логин и пароль из джоса из тела запроса и посылаем запрос базе данных на проверку этого пользователя в ней
int User::check_user_login(json &user_data) {
    std::cerr << "in check : " << user_data << std::endl;

    e_mail = user_data["login"];
    password = user_data["password"];

    pqxx::result response_= worker_.exec("SELECT login, password FROM user_registration WHERE login='" + e_mail + "';");

    /*pqxx::result id_ = worker_.exec("SELECT id FROM user_registration WHERE e_mail='" + e_mail + "';");

    id = id_[0][0].c_str();*/

    std::cerr << "check registr" << std::endl;

    std::cerr << "response size: " << response_.size() << std::endl;

    if (response_.size() < 1) {
        return 0;
    }

    if (password != response_[0][1].c_str()) {
        return -1;
    }

    return 1;
}

// если пользователя нет в базе данных, добавляем
int User::register_user(json &user_data) {
    name = user_data["name"];
    surname = user_data["surname"];

    pqxx::result response_ = worker_.exec("INSERT INTO user_registration(login, password, name, surname) "
                                          "VALUES ('" + e_mail + "', '" + password + "', '" + name + "', '" + surname + "');");

    worker_.exec("commit;");

    std::cerr << "add to db" << std::endl;

    if (response_.size() >= 1) {
        // бд записывает в таблицу данные, но ничего не возвращает
        return -1;
    }
    //надо дописать что конкретно будет выведено клиенту в случае успеха
    return 0;
}


int Meme::create_str_byte() {
    std::ifstream input(path, std::ios::binary);

    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});

    meme_byte = base64_encode(buffer, buffer.size());

    std::cout << meme_byte;

    return 0;
}

int Meme::create_file_by_byte() {
    std::vector<BYTE> output = base64_decode(meme_byte);

    std::ofstream outfile(path, std::ios::out | std::ios::binary);
    outfile.write(reinterpret_cast<const char*>(output.data()), output.size());

    return 0;
}

std::string& Meme::get_filename_by_db() {

    std::cout << "in get_file";
    pqxx::result response_ = worker_.exec("SELECT * FROM mem ORDER BY random() LIMIT 1");

    path = response_[0][1].c_str();

    std::cerr << response_[0][1].c_str() << std::endl;
}

int Meme::upload_image_mem(json &mem_data) {
    create_str_byte();

    category_name1 = mem_data["category1"];

    pqxx::result response_ = worker_.exec("INSERT INTO category(category) VALUES ('" + category_name1 + "');");

    response_ = worker_.exec("SELECT id FROM category WHERE category =' " + category_name1 + "';");

    category_id1 = response_[0][0];
    //тут нужно передать поток байт
    response_ = worker_.exec("INSERT INTO mem(mem, mem_type, likes, dislikes) VALUES ('" + path + "', 'image', 0,0);");

    response_ = worker_.exec("SELECT id FROM mem WHERE mem =' " + path + "';");

    id = response_[0][0];

    response_ = worker_.exec("INSERT INTO mem_category(mem_id, category_id) VALUES (" + id + ", " + category_id1 + ");");
    
    return 0;
}
    
//int Meme::upload_text_mem() {

    
//}

//int Meme::get_text_mem() {
//    pqxx::result response_ = worker_.exec("SELECT * FROM mem ORDER BY random() LIMIT 1");

//}

int User::set_category(json &user_data) {
    category = user_data["category"];
    e_mail = user_data["e_mail"];

    pqxx::result response_ = worker_.exec("SELECT id FROM category WHERE category =' " + category + "';");

    category_id = response_[0][0];

    response_ = worker_.exec("SELECT id FROM user_registration WHERE email =' " + e_mail + "';");  

    id = response_[0][0];

    response_ = worker_.exec("INSERT INTO user_registration_category(user_registration_id, category_id) VALUES (" + id + ", " + category_id + ");");
    
    return 0;
}

int Meme::get_image_mem(json &mem_data) {

    category_num = mem_data["number_of_category"];
    switch (category_num) {
    case 2 :
        category_name1 = mem_data["category1"];
        category_name2 = mem_data["category2"];

        pqxx::result response_ = worker_.exec("SELECT id FROM category WHERE category =' " + category_name1 + "';");
        
        category_id1 = response_[0][0];

        response_ = worker_.exec("SELECT id FROM category WHERE category =' " + category_name2 + "';");

        category_id2 = response_[0][0];

        response_ = worker_.exec("SELECT mem FROM mem_category LEFT JOIN mem ON mem_category.mem_id = mem.id  LEFT JOIN category ON mem_category.category_id = mem.id WHERE mem_category.category_id = " + category_id1 + " AND mem_category.category_id = " + category_id2 + ";");

        path = response_[0][0];

        Meme::create_str_byte();
        
        break;
    case 3 :
        category_name1 = mem_data["category1"];
        category_name2 = mem_data["category2"];
        category_name3 = mem_data["category3"];

        pqxx::result response_ = worker_.exec("SELECT id FROM category WHERE category =' " + category_name1 + "';");
        
        category_id1 = response_[0][0];

        response_ = worker_.exec("SELECT id FROM category WHERE category =' " + category_name2 + "';");

        category_id2 = response_[0][0];

        response_ = worker_.exec("SELECT id FROM category WHERE category =' " + category_name3 + "';");

        category_id3 = response_[0][0];

        response_ = worker_.exec("SELECT mem FROM mem_category LEFT JOIN mem ON mem_category.mem_id = mem.id  LEFT JOIN category ON mem_category.category_id = mem.id WHERE mem_category.category_id = " + category_id1 + " AND mem_category.category_id = " + category_id2 + " AND mem_category.category_id = " category_id3 + ";");

        path = response_[0][0];

        Meme::create_str_byte();

        break;
    default:
        category_name1 = mem_data["category1"];

        pqxx::result response_ = worker_.exec("SELECT id FROM category WHERE category =' " + category_name1 + "';");
        
        category_id1 = response_[0][0];

        response_ = worker_.exec("SELECT mem FROM mem_category LEFT JOIN mem ON mem_category.mem_id = mem.id  LEFT JOIN category ON mem_category.category_id = mem.id WHERE mem_category.category_id = " + category_id1 + ";");
        // сейчас в респонсе лежит(ат) нужный(ые) мем(ы) в ячейка [0][0] [1][0] [2][0]  и т д.
        path = response_[0][0];

        Meme::create_str_byte();

        break;
    }

    return 0;

}


