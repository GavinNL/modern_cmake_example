#include <mult.h>
#include <add.h>
#include <subtract.h>

int main(int argc, char ** argv)
{
    // return 10*5 + 7 - 3 = 54
    return subtract::subtract( add::add( mult::mult(10,5), 7 ), 3);
}
