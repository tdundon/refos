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

#ifndef _RPC_INTERFACE_SERV_SERVER_H_
#define _RPC_INTERFACE_SERV_SERVER_H_

#include <refos-rpc/rpc.h>
#include <refos/refos.h>

#include <refos/vmlayout.h>


/*! @file
    @brief Generated file for the serv interface. Please do NOT edit this file. */

#ifndef _RPC_SERV_LABEL_ENUMS_
#define _RPC_SERV_LABEL_ENUMS_
/*! @brief RPC syscall label enums for serv interface. */
enum rpc_serv_label_enum {
    RPC_SERV_LABEL_MIN = SERV_METHODS_BASE,
    RPC_SERV_CONNECT_DIRECT,
    RPC_SERV_PING,
    RPC_SERV_SET_PARAM_BUFFER,
    RPC_SERV_DISCONNECT_DIRECT,
    RPC_SERV_LABEL_MAX
};
#endif

void server_serv_connect_direct(void *rpc_userptr);
void reply_serv_connect_direct(void *rpc_userptr, int* rpc_errval, seL4_CPtr rpc___ret__);
extern seL4_CPtr serv_connect_direct_handler(void *rpc_userptr , seL4_CPtr rpc_liveness , int* rpc_errval) __attribute__((weak));

void server_serv_ping(void *rpc_userptr);
void reply_serv_ping(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t serv_ping_handler(void *rpc_userptr) __attribute__((weak));

void server_serv_set_param_buffer(void *rpc_userptr);
void reply_serv_set_param_buffer(void *rpc_userptr, refos_err_t rpc___ret__);
extern refos_err_t serv_set_param_buffer_handler(void *rpc_userptr , seL4_CPtr rpc_parambuffer_dataspace , uint32_t rpc_parambuffer_size) __attribute__((weak));

void server_serv_disconnect_direct(void *rpc_userptr);
void reply_serv_disconnect_direct(void *rpc_userptr);
extern void serv_disconnect_direct_handler(void *rpc_userptr) __attribute__((weak));

#endif /* _RPC_INTERFACE_SERV_SERVER_H_ */
