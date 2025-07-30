#define Library

#include "osapi.h"

private int8 fds[256];

/**
 * fd = 0 -> error
 * fd = 1 -> stdin
 * fd = 2 -> stdio
 */

private bool isOpen(fd file)
{
    signed int posixfd;
    struct stat _;

    if (file < 3)
    {
        return false;
    }

    posixfd = getPosixfd(file);

    if (!posixfd)
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
    int8 buffer[2];
    signed int n;
    signed int posixfd;

    assert_initialized();

    // simplify this if
    if (file > 1)
    {
        if (!isOpen(file))
        {
            reterr(ErrBadFD);
        }
    }

    posixfd = getPosixfd(file);

    if (!posixfd)
    {
        reterr(ErrBadFD);
    }

    // posixfd = (posixfd == 1)   ? 0
    //           : (posixfd == 2) ? 1
    //                            : (posixfd);

    switch (posixfd)
    {
    case 1:
        posixfd = 0;
        break;

    case 2:
        posixfd = 1;
        break;

    default:
        break;
    }

    *buffer = *(buffer + 1) = (int8)0;
    *buffer = c;
    n = write(posixfd, $c buffer, 1);

    if (n != 1)
    {
        reterr(ErrIO);
    }

    return true;
}

// read 1 char
public int8 store(fd file)
{
    int8 buffer[2];
    signed int n;
    signed int posixfd;

    assert_initialized();

    // simplify this if
    if (file > 2)
    {
        if (!isOpen(file))
        {
            reterr(ErrBadFD);
        }
    }

    posixfd = getPosixfd(file);

    if (!posixfd)
    {
        reterr(ErrBadFD);
    }

    switch (posixfd)
    {
    case 1:
        posixfd = 0;
        break;

    case 2:
        posixfd = 1;
        break;

    default:
        break;
    }

    *buffer = *(buffer + 1) = (int8)0;
    n = read(posixfd, $c buffer, 1);

    if (n != 1)
    {
        reterr(ErrIO);
    }

    return (int8)*buffer;
}

private void setupfds(void)
{
    zero($1 fds, sizeof(fds));

    fds[0] = 1;
    fds[1] = 2;

    return;
}

private void zero(int8 *str, int16 size)
{
    int8 *p;
    int16 n;

    for (n = size, p = str; n; n--, p++)
    {
        *p = (int8)0;
    }

    return;
}

public void init(void)
{
    errnumber = (int8)0;
    setupfds();
    initialized = true;
    return;
}