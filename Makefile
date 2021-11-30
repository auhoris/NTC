server = server
client = client

serv_src = server.cpp
cli_src = client.cpp

all: $(server) $(client)

cc = clang++
ccflags = -I /usr/local/include -L /usr/local/lib -lzmq
warnf = -Wall -Wextra -Werror
# CXXFLAGS += -I/usr/local/include
# LDFLAGS += -L/usr/local/lib

$(server): $(serv_src) zhelpers.hpp
	$(cc) $(ccflags) $< -o $@

$(client): $(cli_src) zhelpers.hpp
	$(cc) $(ccflags) $< -o $@

clean:
	rm -f $(server) $(client)

re: clean all
