#define Library

#include "osapi.h"

private fd fds[256];

private bool isOpen(fd file)
{
    signed int posixfd;
    struct stat _;

    if (file < 2)
    {
        return false;
    }

    posixfd = getPosixfd(file);

    if (posixfd == -1)
    {
        return false;
    }

    if (fstat(posixfd, &_) == -1)
    {
        return false;
    }

    return true;
}

// write 1 char
public bool load(fd file, int8 c)
{
    if (file > 1)
    {
        if (!isOpen(file))
        {
            reterr(ErrBadFD);
        }
    }

    return false;
}

// read 1 char
public int8 store(fd file)
{
    return 0;
}