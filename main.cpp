#include <iostream>
#include <fstream>
#include <string>
#include "generated/addressbook.pb.h"

#include "protostuff/tcpserver.h"
#include "asio.hpp"




// Main function:  Reads the entire address book from a file,
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char* argv[]) {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: async_tcp_echo_server <port>\n";
            return 1;
        }

        asio::io_context io_context;

        tcpserver s(io_context, std::atoi(argv[1]));

        std::cout << "Starte Server mit Port: " << argv[1] << std::endl;

        io_context.run();
    }
    catch (std::exception & e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }


    return 0;
}