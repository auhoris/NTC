server = server
serv_src = server.cpp

all: $(server)

cc = clang++
ccflags = -I /usr/local/include -L /usr/local/lib -lzmq
warnf = -Wall -Wextra -Werror
# CXXFLAGS += -I/usr/local/include
# LDFLAGS += -L/usr/local/lib

$(server): $(serv_src) zhelpers.hpp
	$(cc) $(ccflags) $< -o $@

clean:
	rm -f $(server)

re: clean all
