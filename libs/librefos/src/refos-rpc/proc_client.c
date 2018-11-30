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

#include <refos-rpc/rpc.h>
#include <refos-rpc/proc_client.h>
#include <refos/refos.h>

#include <stdint.h>
#include <stdlib.h>

/*! @file
    @brief Generated file for the proc interface. Please do NOT edit this file. */

refos_err_t proc_ping() {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_ping", RPC_PROC_PING);
    rpc_set_dest(REFOS_PROCSERV_EP);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

seL4_CPtr proc_new_endpoint_internal(refos_err_t* errval) {
    int rpc__error_;
    seL4_CPtr __ret__;
    memset(&__ret__, 0, sizeof(seL4_CPtr));

    rpc_init("proc_new_endpoint_internal", RPC_PROC_NEW_ENDPOINT_INTERNAL);
    rpc_set_dest(REFOS_PROCSERV_EP);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(errval, sizeof(refos_err_t));
    __ret__ = (seL4_CPtr) rpc_pop_cptr();
    __ret__ = rpc_copyout_cptr(__ret__);
    rpc_release();
    return __ret__;
}

seL4_CPtr proc_new_async_endpoint_internal(refos_err_t* errval) {
    int rpc__error_;
    seL4_CPtr __ret__;
    memset(&__ret__, 0, sizeof(seL4_CPtr));

    rpc_init("proc_new_async_endpoint_internal", RPC_PROC_NEW_ASYNC_ENDPOINT_INTERNAL);
    rpc_set_dest(REFOS_PROCSERV_EP);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(errval, sizeof(refos_err_t));
    __ret__ = (seL4_CPtr) rpc_pop_cptr();
    __ret__ = rpc_copyout_cptr(__ret__);
    rpc_release();
    return __ret__;
}

refos_err_t proc_watch_client(seL4_CPtr liveness, seL4_CPtr deathEP, int32_t* deathID) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_watch_client", RPC_PROC_WATCH_CLIENT);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(liveness);
    rpc_push_cptr(deathEP);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(deathID, sizeof(int32_t));
    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t proc_unwatch_client(seL4_CPtr liveness) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_unwatch_client", RPC_PROC_UNWATCH_CLIENT);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(liveness);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

seL4_CPtr proc_create_mem_window_internal(uint32_t vaddr, uint32_t size, uint32_t permissions, uint32_t flags, refos_err_t* errval) {
    int rpc__error_;
    seL4_CPtr __ret__;
    memset(&__ret__, 0, sizeof(seL4_CPtr));

    rpc_init("proc_create_mem_window_internal", RPC_PROC_CREATE_MEM_WINDOW_INTERNAL);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_uint(vaddr);
    rpc_push_uint(size);
    rpc_push_uint(permissions);
    rpc_push_uint(flags);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(errval, sizeof(refos_err_t));
    __ret__ = (seL4_CPtr) rpc_pop_cptr();
    __ret__ = rpc_copyout_cptr(__ret__);
    rpc_release();
    return __ret__;
}

refos_err_t proc_resize_mem_window(seL4_CPtr window, uint32_t size) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_resize_mem_window", RPC_PROC_RESIZE_MEM_WINDOW);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(window);
    rpc_push_uint(size);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t proc_delete_mem_window(seL4_CPtr window) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_delete_mem_window", RPC_PROC_DELETE_MEM_WINDOW);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(window);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

seL4_CPtr proc_get_mem_window(uint32_t vaddr) {
    int rpc__error_;
    seL4_CPtr __ret__;
    memset(&__ret__, 0, sizeof(seL4_CPtr));

    rpc_init("proc_get_mem_window", RPC_PROC_GET_MEM_WINDOW);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_uint(vaddr);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    __ret__ = (seL4_CPtr) rpc_pop_cptr();
    __ret__ = rpc_copyout_cptr(__ret__);
    rpc_release();
    return __ret__;
}

seL4_CPtr proc_get_mem_window_dspace(seL4_CPtr window, refos_err_t* errval) {
    int rpc__error_;
    seL4_CPtr __ret__;
    memset(&__ret__, 0, sizeof(seL4_CPtr));

    rpc_init("proc_get_mem_window_dspace", RPC_PROC_GET_MEM_WINDOW_DSPACE);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(window);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(errval, sizeof(refos_err_t));
    __ret__ = (seL4_CPtr) rpc_pop_cptr();
    __ret__ = rpc_copyout_cptr(__ret__);
    rpc_release();
    return __ret__;
}

refos_err_t proc_register_as_pager(seL4_CPtr window, seL4_CPtr faultNotifyEP, seL4_Word* winID) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_register_as_pager", RPC_PROC_REGISTER_AS_PAGER);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(window);
    rpc_push_cptr(faultNotifyEP);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(winID, sizeof(seL4_Word));
    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t proc_unregister_as_pager(seL4_CPtr window) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_unregister_as_pager", RPC_PROC_UNREGISTER_AS_PAGER);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(window);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t proc_notification_buffer(seL4_CPtr dataspace) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_notification_buffer", RPC_PROC_NOTIFICATION_BUFFER);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(dataspace);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t proc_window_map(seL4_CPtr window, uint32_t windowOffset, uint32_t srcAddr) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_window_map", RPC_PROC_WINDOW_MAP);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(window);
    rpc_push_uint(windowOffset);
    rpc_push_uint(srcAddr);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t proc_window_unmap() {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_window_unmap", RPC_PROC_WINDOW_UNMAP);
    rpc_set_dest(REFOS_PROCSERV_EP);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

int proc_window_getID(seL4_CPtr window) {
    int rpc__error_;
    int __ret__;
    memset(&__ret__, 0, sizeof(int));

    rpc_init("proc_window_getID", RPC_PROC_WINDOW_GETID);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(window);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    __ret__ = (int) rpc_pop_uint();
    rpc_release();
    return __ret__;
}

refos_err_t proc_set_parambuffer(seL4_CPtr dataspace, uint32_t size) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_set_parambuffer", RPC_PROC_SET_PARAMBUFFER);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_cptr(dataspace);
    rpc_push_uint(size);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t proc_new_proc(char* name, char* params, bool block, int32_t priority, int32_t* status) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_new_proc", RPC_PROC_NEW_PROC);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_str(name);
    rpc_push_str(params);
    rpc_push_buf(&block, sizeof(bool));
    rpc_push_uint(priority);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(status, sizeof(int32_t));
    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

refos_err_t proc_exit(int32_t status) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_exit", RPC_PROC_EXIT);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_uint(status);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

int proc_clone_internal(seL4_Word entryPoint, seL4_Word childStack, int flags, seL4_Word arg, refos_err_t* errval) {
    int rpc__error_;
    int __ret__;
    memset(&__ret__, 0, sizeof(int));

    rpc_init("proc_clone_internal", RPC_PROC_CLONE_INTERNAL);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_buf(&entryPoint, sizeof(seL4_Word));
    rpc_push_buf(&childStack, sizeof(seL4_Word));
    rpc_push_uint(flags);
    rpc_push_buf(&arg, sizeof(seL4_Word));

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(errval, sizeof(refos_err_t));
    __ret__ = (int) rpc_pop_uint();
    rpc_release();
    return __ret__;
}

refos_err_t proc_nice(int threadID, int priority) {
    int rpc__error_;
    refos_err_t __ret__;
    memset(&__ret__, 0, sizeof(refos_err_t));

    rpc_init("proc_nice", RPC_PROC_NICE);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_uint(threadID);
    rpc_push_uint(priority);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    rpc_pop_buf(&__ret__, sizeof(refos_err_t));
    rpc_release();
    return __ret__;
}

seL4_CPtr proc_get_irq_handler(int irq) {
    int rpc__error_;
    seL4_CPtr __ret__;
    memset(&__ret__, 0, sizeof(seL4_CPtr));

    rpc_init("proc_get_irq_handler", RPC_PROC_GET_IRQ_HANDLER);
    rpc_set_dest(REFOS_PROCSERV_EP);
    rpc_push_uint(irq);

    rpc__error_ = rpc_call_server();
    if (rpc__error_) {
        rpc_release();
        return __ret__;
    }

    __ret__ = (seL4_CPtr) rpc_pop_cptr();
    __ret__ = rpc_copyout_cptr(__ret__);
    rpc_release();
    return __ret__;
}

