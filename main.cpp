#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

bool compare_str(const std::string &line1, const std::string &line2) {
    int i = 0, j = 0;

    while (line1[i] >= 48 && line1[i] <= 57) i++;
    while (line2[j] >= 48 && line2[j] <= 57) j++;
    return (strcmp(&line1[i], &line2[j]) == 0);
}

std::vector<std::string>    parse(std::string file1, std::string file2) {
    std::string line;
    std::ifstream   stud1;
    std::ifstream   stud2;
    std::vector<std::string> st1;
    std::vector<std::string> st2;
    std::vector<std::string> res;

    stud1.open(file1);
    stud2.open(file2);
    if (stud1.is_open()) {
        while (std::getline(stud1, line)) {
            st1.push_back(line);
        }
    }
    if (stud2.is_open()) {
        while (std::getline(stud2, line)) {
            st2.push_back(line);
        }
    }
    stud1.close();
    stud2.close();
    for (int i = 0; i < st1.size(); i++) {
        for (int j = 0; j < st2.size(); j++) {
            if (compare_str(st1[i], st2[j]) != 0) {
                res.push_back(st1[i]);
            }
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cout << "[Usage]: ./progname student_file1.txt student_file2.txt" << std::endl;
        return 1;
    }
    std::vector<std::string>    res;

    res = parse(argv[1], argv[2]);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}
