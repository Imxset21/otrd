#if HAVE_CONFIG_H
#include <config.h>
#endif

//! TODO: Change for production
#ifndef __clang__
#include <otrd.h>
#else
#include "../include/otrd.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <errno.h>

#include <libotr/version.h>

//! TODO: REMOVE for release
#define HAVE_INTTYPES_H 1

#if HAVE_INTTYPES_H
#include <inttypes.h>
#elif HAVE_STDINT_H
#include <stdint.h>
#else
#error libotrd requires a definition of int64_t
#endif

int otrd_get_libotr_version(char* name_buff, size_t name_buff_len)
{
    if (name_buff == NULL)
    {
        errno = EFAULT;
        return -1;
    } else if (name_buff_len == 0 || strlen(OTRL_VERSION) > name_buff_len) {
        errno = EOVERFLOW;
        return -1;
    }

    strncpy(name_buff, OTRL_VERSION, name_buff_len);

    return 0;
}
