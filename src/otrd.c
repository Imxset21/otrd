#if HAVE_CONFIG_H
#include <config.h>
#endif 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

//! TODO Remove for production
#ifndef __clang__
#include <otrd.h>
#else
#include "../include/otrd.h"
#endif

#define VERSION_STR_SIZE 9

int main(int argc, char** argv)
{
    // No arguments: print out version information
    if (argc == 1)
    {
        char* name_buff = (char*) calloc(VERSION_STR_SIZE, sizeof(char));
        assert(name_buff != NULL);
        
        if (otrd_get_libotr_version(name_buff, VERSION_STR_SIZE * sizeof(char)))
        {
            perror("Error while getting libotr version: ");
            return EXIT_FAILURE;
        }
        printf("libotr version: %s\n", name_buff);
        
        free((void*) name_buff);
        
        return EXIT_SUCCESS;
    }
    
    return EXIT_SUCCESS;
}
