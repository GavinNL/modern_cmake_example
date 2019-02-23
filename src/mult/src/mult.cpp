#include <mult.h>
#include <add.h>

int mult::mult( int a, int b )
{
    int r = 0;
    for(int i=0;i<a;i++)
    {
        r = add::add(r, b);
    }
    return r;
}
