#include "session.h"

using asio::ip::tcp;

    void session::do_write(std::size_t length)
    {
        auto self(shared_from_this());
        asio::async_write(socket_, asio::buffer(data_, length),
            [](std::error_code ec, std::size_t /*length*/)
            {           });
    }
