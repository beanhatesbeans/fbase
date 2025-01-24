#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

int
main(int argc, char **argv)
{
	FILE *fp;
	char buf[BUFSIZE];
	int i;
	if(argc < 2) {
		fprintf(stderr, "usage: %s [file] ...\n", argv[0]);
		exit(1);
	}
	for(i = 1; i < argc; i++) {
		if(!(fp = fopen(argv[i], "r"))) {
			fprintf(stderr, "failed to open %s: %s\n",
				argv[i], strerror(errno));
			continue;
		}
		printf("#################\n%s\n#################\n\n", argv[i]);
		while(fgets(buf, sizeof(buf), fp))
			fputs(buf, stdout);
		printf("\n#################\n###END OF FILE###\n#################\n");
		fclose(fp);
	}
	return 0;
}
