#include <stdio.h>
#include <string.h>
#include <libc.h>
int main ()
{
	char src[6] = "Hello";
	char dst[4];
	memmove(dst, src, 4);
	printf("%s", dst);
}