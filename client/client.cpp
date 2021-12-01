#include <cstdlib>
#include <fstream>
#include <string>
#include <set>
#include <iostream>

#include <unistd.h>
#include <zmq.hpp>
#include "zhelpers.hpp"

int main()
{
    zmq::context_t context(1);

    // Subscribe to everything
    zmq::socket_t subscriber(context, ZMQ_SUB);
    subscriber.connect("tcp://127.0.0.1:5556");
    subscriber.setsockopt (ZMQ_SUBSCRIBE, "", 0);

    std::stringstream ss;
    std::set<std::string> data;
    while (1) {
        size_t tmp = data.size();
        ss.clear();
        ss.str(s_recv(subscriber));
        data.insert(ss.str());
        if (tmp - data.size() == 0)
            break;
    }
    std::ofstream   data_file("students_result.txt");
    for (auto it : data) {
        data_file << it << std::endl;
    }
    // int i = 0;
    // while (i < 5) {
    //     sleep(3);
    //     i++;
    // }
    return 0;
}
