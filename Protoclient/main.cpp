#include <cstdlib>
#include <cstring>
#include <iostream>
#include "asio.hpp"

using asio::ip::tcp;

enum { max_length = 1024 };

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 3)
        {
            std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
            return 1;
        }

        asio::io_context io_context;

        tcp::socket s(io_context);
        tcp::resolver resolver(io_context);
        asio::connect(s, resolver.resolve(argv[1], argv[2]));

        size_t request_length = 13;

        char reply[max_length];
        size_t reply_length = asio::async_read(s,
            asio::buffer(reply, request_length),
            [](std::error_code ec, std::size_t size)
            {}
        );
        std::cout << "Reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << "\n";
        
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}