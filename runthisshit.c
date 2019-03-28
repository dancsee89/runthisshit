#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void matchFileType(char* filename);

int main(void) {
	DIR *dirPointer;
	struct dirent *elementPointer;
	
	dirPointer = opendir("./");
	if (dirPointer != NULL) {
		while ((elementPointer = readdir(dirPointer)) != NULL) {
			matchFileType(elementPointer->d_name);
		}
		closedir(dirPointer);
	}
	else {
		perror("Could not read directory.");
	}
	
	return 0;
}

void matchFileType(char* filename) {
	if (filename != NULL) {
		if (strcmp(filename, "package.json") == 0) {
			system("npm start");
		}
	}
	else {
		perror("Filename could not be null.");
	}
}