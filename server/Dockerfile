FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y make
RUN apt-get install -y libzmq3-dev
RUN apt-get install -y clang
RUN mkdir -p ./NTC

EXPOSE 5556

COPY ./Makefile ./server.cpp ./student_file1.txt ./student_file2.txt ./zhelpers.hpp ./NTC
COPY ./start.sh .

RUN chmod 777 start.sh
CMD bash start.sh
