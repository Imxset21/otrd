#ifndef OTRD_H_INCLUDED
#define OTRD_H_INCLUDED

#include <stddef.h>

/**
 * Copies the current version of OTR into the name buffer.
 *
 * @param name_buff Buffer which version gets copied into.
 * @param name_buff_len Length of the name buffer.
 *
 * @returns 0 if successful, -1 if an error occurred, with errno set.
 */
extern int otrd_get_libotr_version(char* name_buff, size_t name_buff_len);

extern int otrd_init();

#endif // OTRD_H_INCLUDED
