// gcc -DNANOC_BOOTSTRAP src/gen-includes.c -I includes/ -L. -lnanoc -nostdlib crt/amd64/*.s -o bin/gen-includes

#ifdef NANOC_BOOTSTRAP
int metadata_version();
void metadata_query(void* ptr);
#else
#include <nanoc/metadata.h>
#endif

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
