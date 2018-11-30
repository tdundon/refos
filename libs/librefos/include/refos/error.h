/*
 * Copyright 2016, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(D61_BSD)
 */

#ifndef _REFOS_ERROR_H_
#define _REFOS_ERROR_H_

/* Include Kconfig variables. */
#include <autoconf.h>

/*! @file
    @brief RefOS Error codes.

    Shared error codes for RefOS methods.
*/

enum refos_error {
    /*! @brief There was no error. */
    REFOS_ESUCCESS = 0,

    /*! @brief Ran out of heap, cslots or untyped memory. */
    REFOS_ENOMEM,

    /*! @brief An internal error occured with the service. */
    REFOS_EINVALID,

    /*! @brief The given client capability is invalid. */
    REFOS_EUNKNOWNCLIENT,

    /*! @brief A given parameter was invalid. */
    REFOS_EINVALIDPARAM,

    /*! @brief The server name was not found by the naming service. */
    REFOS_ESERVERNOTFOUND,

    /*! @brief The given window capability is invalid. */
    REFOS_EINVALIDWINDOW,

    /*! @brief The server is currently unavailable; try again later. */
    REFOS_ESERVICEUNAVAILABLE,

    /*! @brief Insufficient permission for the requested operation. */
    REFOS_EACCESSDENIED,

    /*! @brief Occurs when a pager service tries to map a frame where there already is one. */
    REFOS_EUNMAPFIRST,

    /*! @brief The file name was not found on the dataspace server. */
    REFOS_EFILENOTFOUND,

    /*! @brief End of file was reached. */
    REFOS_EENDOFFILE,

    /*! @brief The device was not found on the system. */
    REFOS_EDEVICENOTFOUND,

    /*! @brief The operation requires access to the param buffer but no param buffer exists */
    REFOS_ENOPARAMBUFFER,

    /*! @brief This feature has not been implemented. */
    REFOS_EUNIMPLEMENTED,

    /*! @brief Request has been delegated to another server. */
    REFOS_EDELEGATED
};

#ifndef __defined_err_t__
    typedef enum refos_error refos_err_t;
    #define __defined_err_t__
#endif

/*! @brief Helper function which returns the associated string with a RefOS error number. Useful for
           printing debugging information.
    @param err The RefOS error.
    @return Static string containing the error variable enum name. (No ownership transfer)
*/
static inline const char*
refos_error_str(refos_err_t err)
{
    switch (err) {
        case REFOS_ESUCCESS:
            return "ESUCCESS";
        case REFOS_ENOMEM:
            return "ENOMEM";
        case REFOS_EINVALID:
            return "EINVALID";
        case REFOS_EUNKNOWNCLIENT:
            return "EUNKNOWNCLIENT";
        case REFOS_EINVALIDPARAM:
            return "EINVALIDPARAM";
        case REFOS_ESERVERNOTFOUND:
            return "ESERVERNOTFOUND";
        case REFOS_EINVALIDWINDOW:
            return "EINVALIDWINDOW";
        case REFOS_ESERVICEUNAVAILABLE:
            return "ESERVICEUNAVAILABLE";
        case REFOS_EACCESSDENIED:
            return "EACCESSDENIED";
        case REFOS_EUNMAPFIRST:
            return "EUNMAPFIRST";
        case REFOS_EFILENOTFOUND:
            return "EFILENOTFOUND";
        case REFOS_EENDOFFILE:
            return "EENDOFFILE";
        case REFOS_EDEVICENOTFOUND:
            return "EDEVICENOTFOUND";
        case REFOS_ENOPARAMBUFFER:
            return "ENOPARAMBUFFER";
        case REFOS_EUNIMPLEMENTED:
            return "EUNIMPLEMENTED";
        case REFOS_EDELEGATED:
            return "EDELEGATED";
        default:
            return "EUNKNOWNERROR";
    }
    return (const char*) 0;
}

#include <sel4/errors.h>

/*! @brief Helper function to return the enum name string associated with a seL4 error.
    @param sel4err The seL4 error number.
    @return Static str containing the string name of the given error code. (No ownership transfer)
*/
static inline const char*
seL4_error_str(int sel4err)
{
    switch (sel4err) {
        case seL4_NoError:
            return "seL4_NoError";
        case seL4_InvalidArgument:
            return "seL4_InvalidArgument";
        case seL4_InvalidCapability:
            return "seL4_InvalidCapability";
        case seL4_IllegalOperation:
            return "seL4_IllegalOperation";
        case seL4_RangeError:
            return "seL4_RangeError";
        case seL4_AlignmentError:
            return "seL4_AlignmentError";
        case seL4_FailedLookup:
            return "seL4_FailedLookup";
        case seL4_TruncatedMessage:
            return "seL4_TruncatedMessage";
        case seL4_DeleteFirst:
            return "seL4_DeleteFirst";
        case seL4_RevokeFirst:
            return "seL4_RevokeFirst";
        case seL4_NotEnoughMemory:
            return "seL4_NotEnoughMemory";
        default:
            return "Unknown seL4 Error.";
    }
};

extern refos_err_t _refos_errno;

#if CONFIG_REFOS_HALT_ON_ERRNO
    #define REFOS_SET_ERRNO(x) _refos_errno = x; if (_refos_errno != REFOS_ESUCCESS) \
        {\
            printf("REFOS call generated error in file %s line %d", __FILE__, __LINE__);\
            assert(!"Halt because REFOS_HALT_ON_ERRNO is enabled.");\
            while(1);\
        }
    #define REFOS_GET_ERRNO() (_refos_errno)
#else
    #define REFOS_SET_ERRNO(x) (_refos_errno = x)
    #define REFOS_GET_ERRNO() (_refos_errno)
#endif
#define ROS_ERRNO REFOS_GET_ERRNO
#define ROS_SET_ERRNO REFOS_SET_ERRNO

#endif /* _REFOS_ERROR_H_ */
