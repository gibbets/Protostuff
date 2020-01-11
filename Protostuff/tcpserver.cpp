#include <iostream>

#include "tcpserver.h"
#include "session.h"

using asio::ip::tcp;


void tcpserver::do_accept() {
           acceptor_.async_accept(
            [this](std::error_code ec, tcp::socket socket)
            {
                if (!ec)
                {
                    auto ptr = std::make_shared<session>(std::move(socket));
                    ptr->start();

                    std::cout << "New connection. Number connections: " << ptr.use_count() << std::endl;

                }

                do_accept();
            });
}