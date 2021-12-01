client = client

cli_src = client.cpp

cc = clang++
ccflags = -I /usr/local/include -L /usr/local/lib -lzmq
warnf = -Wall -Wextra -Werror

all: $(client)

$(client): $(cli_src) zhelpers.hpp
	$(cc) $(ccflags) $< -o $@

clean:
	rm -f $(client)

re: clean all

