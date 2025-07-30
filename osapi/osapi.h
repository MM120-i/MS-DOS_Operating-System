#pragma once

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "os.h"

#define getPosixfd(x) fds[(x)]

private
bool isOpen(fd);