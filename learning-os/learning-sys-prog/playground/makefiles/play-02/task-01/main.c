#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	uid_t me = getuid();
	uid_t pretending = geteuid();
	printf("%d %d\n", me, pretending);
	exit(0);
}
