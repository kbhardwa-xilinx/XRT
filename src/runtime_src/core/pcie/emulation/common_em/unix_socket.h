/**
 * Copyright (C) 2016-2018 Xilinx, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef _WINDOWS

#ifndef __XCLHOST_UNIXSOCKET__
#define __XCLHOST_UNIXSOCKET__
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <boost/algorithm/string.hpp>
#include <iostream>

#include "system_utils.h"
#include "em_defines.h"
#include "xclhal2.h"

class unix_socket {
  private:
    int fd;
    std::string name;
public:
    bool server_started;
    void set_name(const std::string &sock_name) { name = sock_name;}
    std::string get_name() { return name;}
    unix_socket(const std::string& env = "EMULATION_SOCKETID", const std::string& sock_id="xcl_sock",double timeout_insec=300,bool fatal_error=true);
    ~unix_socket()
    {
       server_started = false;
       close(fd);
    }
    void start_server(double timeout_insec,bool fatal_error);
    ssize_t sk_write(const void *wbuf, size_t count);
    ssize_t sk_read(void *rbuf, size_t count);
};


#endif

#endif
