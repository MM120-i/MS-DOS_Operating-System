#include "osapi.h"

private bool isOpen(fd file)
{
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
}

// read 1 char
int8 store(int16);
