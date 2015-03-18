#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


// heh.. heh.. heh
#define INFINITE 512

int time = 0;
char buf[INFINITE+1]; // null terminator so it becomes a valid string


void silly(){
	fprintf(stderr, "Whoops, it seems even infinity has its limits..\n");
	exit(1);
}

#define ISW(c) (c == ' ' || c == '-')
#define ISX(c) (c == 'x' || c == 'y')

// ' ' = space
// '-' = space that is becoming an x
// 'y' = x that is becoming a space
// 'x' = x
void perform_iteration() {
	// tmp codes
	//
	//
	int pos = 0;

	// Treat out-of-bounds as space, the first attempt to put an X there will
	// crash the program

	// rule 1
	for(pos = 0; pos < INFINITE; pos++) {
		// The out of bounds character is always whitespace, and we just attempted
		// to write to it
		if((pos == 0 || pos == INFINITE-1) && ISX(buf[pos]))
			silly();

		// If it's not whitespace, the rule does not apply
		if(!ISW(buf[pos])) continue;

		if((pos == 0 && ISX(buf[pos+1]))
		|| (pos == INFINITE-1 && ISX(buf[pos-1]))
		|| (ISX(buf[pos-1]) || ISX(buf[pos+1]))) {
			buf[pos] = '-';
		}
	}

	// rule 2 is a NOP, we don't need to do anything

	// rule 3, if x has 2 neighbor x, it dies
	// quickmatch is set to 1 if pos-1 and pos of the next iteration are both x
	for(pos = 1; pos < INFINITE-1; pos++) {
		// Remember at the outer edge there will never be two neighbor x
		if(ISX(buf[pos]) && ISX(buf[pos-1]) && ISX(buf[pos+1])) {
			buf[pos] = 'y';
		}
	}
	for(pos = 0; pos < INFINITE; pos++) {
		if(buf[pos] == 'y') buf[pos] = ' ';
		else if(buf[pos] == '-') buf[pos] = 'x';
	}
	time++;
}


void print_buf() {
	printf("%10i:%s\n", time, buf);
}
void count() {
	int pos, x=0;
	for(pos=0;pos<INFINITE;pos++) {
		if(buf[pos]=='x') x++;
	}
	printf("%i\n", x);
}

int main() {
	memset(buf, ' ', sizeof(buf));
	buf[INFINITE] = 0;
	buf[INFINITE/2] = 'x';

	while(time < 253) {
		perform_iteration();
	}
	count();

	return 0;
}
