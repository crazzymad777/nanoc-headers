// gcc -DNANOC_BOOTSTRAP src/gen-includes.c -I includes/ -L. -lnanoc -nostdlib crt/amd64/*.s -o bin/gen-includes

#ifdef NANOC_BOOTSTRAP
int metadata_version();
void metadata_query(void* ptr);
#else
#include <nanoc/metadata.h>
#endif

#include <string.h>
#include <stdio.h>

int main(int argc, char** argv, char** envp)
{
	if (metadata_version() == -1)
	{
		puts("No metadata available.\n");
		return -1;
	}

	void* target = (void*) 1;
	if (argc > 1)
	{
		if (strcmp(argv[1], "1") == 0)
		{
			target = (void*) 1; // create includes directories and write headers file
		}
		else if (strcmp(argv[1], "2") == 0)
		{
			target = (void*) 2; // output all header files
		}
		else
		{
			target = (void*) argv[1]; // show specified module, e.g. nanoc.std.stdio
		}
	}
	metadata_query(target);
	return 0;
}
