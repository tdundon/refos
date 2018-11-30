/* DO NOT EDIT MANUALLY!!!
   This file was generated by CIDL.

   Copyright 2016, Data61
   Commonwealth Scientific and Industrial Research Organisation (CSIRO)
   ABN 41 687 119 230.

   This software may be distributed and modified according to the terms of
   the BSD 2-Clause license. Note that NO WARRANTY is provided.
   See "LICENSE_BSD2.txt" for details.

   @TAG(D61_BSD)
*/

// DO NOT EDIT MANUALLY!!!
// This file was generated by CIDL - Simple C IDL Compiler.

#include <refos-rpc/rpc.h>
#include <refos-rpc/serv_server.h>
#include <refos/refos.h>

#include <refos/vmlayout.h>


int rpc_sv_serv_dispatcher(void *rpc_userptr, uint32_t label) {
    switch (label) {
        case RPC_SERV_CONNECT_DIRECT:
            assert(serv_connect_direct_handler);
            server_serv_connect_direct(rpc_userptr);
            break;
        case RPC_SERV_PING:
            assert(serv_ping_handler);
            server_serv_ping(rpc_userptr);
            break;
        case RPC_SERV_SET_PARAM_BUFFER:
            assert(serv_set_param_buffer_handler);
            server_serv_set_param_buffer(rpc_userptr);
            break;
        case RPC_SERV_DISCONNECT_DIRECT:
            assert(serv_disconnect_direct_handler);
            server_serv_disconnect_direct(rpc_userptr);
            break;
        default:
            return -1;
    }
    return 0;
}
