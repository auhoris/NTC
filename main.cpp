#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    std::string line;
    std::ifstream   stud1;
    std::ifstream   stud2;
    std::vector<std::string> st1;
    std::vector<std::string> st2;
    std::vector<std::string> res;

    stud1.open("student_file1.txt");
    stud2.open("student_file2.txt");
    if (stud1.is_open()) {
        while (std::getline(stud1, line)) {
            int j = 0;
            while (line[j] >= 48 && line[j] <= 57)
                j++;
            st1.push_back(&line[j]);
        }
    }
    if (stud2.is_open()) {
        while (std::getline(stud2, line)) {
            int j = 0;
            while (line[j] >= 48 && line[j] <= 57)
                j++;
            st2.push_back(&line[j]);
        }
    }
    stud1.close();
    stud2.close();
    for (int i = 0; i < st1.size(); i++) {
        for (int j = 0; j < st2.size(); j++) {
            if (st1[i].compare(st2[j]) == 0) {
                res.push_back(st1[i]);
            }
        }
    }
    std::sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}
