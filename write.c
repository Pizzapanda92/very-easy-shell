#include <unistd.h>
#include <stdio.h>

int main(void)
{


char buffer[200];
buffer[0] = '$';
buffer[1] = ' ';

write(1, buffer, 2);
wait (


return (0);
}
