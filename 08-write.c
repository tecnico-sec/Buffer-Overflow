// sudo sysctl -w kernel.randomize_va_space=0
// gcc -g -o 08-write 08-write.c -m32

#include <stdio.h>

int main(int argc, char* argv[]){
	char buffer[128];
	int integrity_number=42;
	static char integrity_message[12]="COVFEFE";

	printf("***** BEFORE ATTACK *****\n");
	printf("VAR integrity_number  : %p %d\n", &integrity_number, integrity_number);
	printf("VAR integrity_message : %p %s\n", &integrity_message, integrity_message);
	printf("VAR buffer            : %p %s\n", &buffer, buffer);

	fgets(buffer, 128, stdin);
	printf("\nbuffer : ");
	printf(buffer);
	printf("\n");

	printf("***** AFTER ATTACK *****\n");
	printf("VAR integrity_number  : %p %d\n", &integrity_number, integrity_number);
	printf("VAR integrity_message : %p %s\n", &integrity_message, integrity_message);
	printf("VAR buffer            : %p %s\n", &buffer, buffer);
}