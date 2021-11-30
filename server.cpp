#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <zmq.hpp>
#include "zhelpers.hpp"

bool compare_str(const std::string &line1, const std::string &line2) {
    int i = 0, j = 0;

    // Skipping first digits
    while (line1[i] >= 48 && line1[i] <= 57) i++;
    while (line2[j] >= 48 && line2[j] <= 57) j++;
    return (strcmp(&line1[i], &line2[j]) == 0);
}

const std::vector<std::string>    parse(std::string file1, std::string file2) {
    std::string line;
    std::ifstream   stud1, stud2;
    std::vector<std::string> st1, st2, result;

    stud1.open(file1);
    stud2.open(file2);
    if (stud1.is_open()) {
        while (std::getline(stud1, line))
            st1.push_back(line);
    }
    if (stud2.is_open()) {
        while (std::getline(stud2, line))
            st2.push_back(line);
    }
    stud1.close();
    stud2.close();
    for (int i = 0; i < st1.size(); i++) {
        for (int j = 0; j < st2.size(); j++) {
            if (compare_str(st1[i], st2[j]) != 0)
                result.push_back(st1[i]);
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}

int main(int argc, char **argv) 
{
    if (argc != 3) {
        std::cout << "[Usage]: ./progname student_file1.txt student_file2.txt" << std::endl;
        return 1;
    }
    // Create vector of data
    std::vector<std::string>    res = parse(argv[1], argv[2]);

    zmq::context_t context{1};
    // Create publisher
    zmq::socket_t   publisher(context, ZMQ_PUB);
    publisher.bind("tcp://*:5556");
    while (1) {
        for (int i = 0; i < res.size(); i++) {
            s_send(publisher, res[i]);
        }
    }
    return 0;
}
