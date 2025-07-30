#pragma once

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "os.h"

#define getPosixfd(x) fds[(x)]
#define assert_initialized() \
    if (!initialized)        \
    reterr(ErrInit)

private
bool isOpen(fd);

private
void setupfds(void);

private
void zero(int8 *, int16);