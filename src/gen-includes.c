// gcc src/gen-includes.c -I includes/ -L. -lnanoc -nostdlib crt/amd64/*.s -o bin/gen-includes

#include <nanoc/metadata.h>
#include <string.h>
#include <stdio.h>

int main()
{
	if (metadata_version() == -1)
	{
		puts("No metadata available.\n");
		return -1;
	}

	void* target = (void*) 1;
	metadata_query(target);
	return 0;
}
