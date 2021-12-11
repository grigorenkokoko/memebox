#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <pqxx/pqxx>

using namespace std;

int main(int argc, char* argv[]) {
    //ifstream input("/home/dmitry/prep_project/src/login.txt");

    //if (!input) {
     ///   cout << "problems" << endl;
      //  return -1;
    //}

   // vector<string> credentials;

    //while (!input.eof()) {
    //    string line;
    //    getline(input, line);
    //    credentials.push_back(line);
    //}

    string connection_string(" host=localhost port=5432 dbname=memebox_data_base user=dmitry password=password");

        pqxx::connection connection_object(connection_string.c_str());

        pqxx::work worker(connection_object);

        pqxx::result response = worker.exec("UPDATE public.image_mem SET mem_likes = 1 WHERE mem = '/home/dmitry/prep_project/src/1614550079_23-p-memi-na-belom-fone-24.png';");

        response = worker.exec("SELECT user_password FROM public.user_registration where user_email = 'eddfgdfg'");

        if (response.size() < 1) {
            cout << "error, mb empty" << endl;
            return -1;
        }

        for (size_t i = 0; i < response.size(); i++) {
            std::cout 
            << response[i][1]
            << " Количество лайков: " << response[i][2]
            << std::endl;
        }
    
    return 0;
}
