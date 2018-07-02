//test_client.cpp
//Author: Sivert Andresen Cubedo

#include <iostream>
#include <string>

#include "../include/TransportInterface.hpp"

const char* help_string = "Args: ./test_client <transport_deamon sock> <target address> <port>";
/*
Args: ./test_client <transport_deamon sock> <target address> <port>
*/
int main(int argc, char** argv)
{
	if (argc != 4) {
		std::cout << "Wrong args\n";
		std::cout << help_string << "\n";
		return EXIT_FAILURE;
	}

	AnonymousSocket sock = TransportInterface::requestConnect(argv[1], std::atoi(argv[2]), std::atoi(argv[3]));

	std::cout << "test_client: connected\n";
	std::cout << "test_client: start transmission\n";

	std::string str("This is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_clientThis is a string from test_client");

	std::size_t msg_size = str.size();

	std::size_t ret = sock.writeGeneric(msg_size);
	ret += sock.write(str.data(), msg_size);

	msg_size += sizeof(ret);

	std::cout << "test_client: transmission done\n";
	std::cout << "test_client: msg_size: " << msg_size << "\n";
	std::cout << "test_client: ret: " << ret << "\n";

	sock.closeResources();
	
	std::cout << "test_client: terminating\n";

	return 0;
}


