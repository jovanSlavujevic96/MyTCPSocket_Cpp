#include <iostream>

#define BUFFER_SIZE 4096u // 4 Mb

// https://www.geeksforgeeks.org/nat-hole-punching-in-computer-network/
// https://stackoverflow.com/questions/55885656/is-it-possible-to-address-a-server-client-socket-in-an-another-network-c

#include "ClientSocket.h"
#include "SocketException.h"
#include <memory.h>

int main()
{
	// ClientSocket socket("192.168.0.197");
	ClientSocket socket((size_t)BUFFER_SIZE);
	// While loop: accept and echo message back to client
	char buf[BUFFER_SIZE];
	const char* msgToSend = "Hello from client";

	while (true)
	{
		std::cin.get();

		// client to send data
		try
		{
			socket << msgToSend;
		}
		catch (const SocketException& exception)
		{
			//std::cout << exception.what() << std::endl;
			std::wcout << exception.wwhat() << L'\n';
		}
		memset(buf, 0, sizeof(buf));
		try
		{
			socket >> buf;
		}
		catch (const SocketException& exception)
		{
			std::wcout << (const wchar_t*)exception.what() << L'\n';
		}
		std::cout << buf << std::endl;
	}
	return 0;
}
