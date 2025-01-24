#include <stdio.h>
FILE *file;
char output[10000];

int main(int argc, char **argv) {
	for(int i = 1; i < argc; i++) {
		file = fopen(argv[1], "r");
		printf("%s\n%s\n%s", "#################", argv[i], "#################\n\n");
		while(fgets(output, 10000, file)) {
			printf("%s", output);
		}
		printf("%s", "\n#################\n###END OF FILE###\n#################\n");	
		fclose(file);
	}
	return 0;
}
