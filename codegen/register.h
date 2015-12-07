#include <stdio.h>
#include <stdlib.h>
#include "global.h"

typedef enum{  // might be useful for indexing
	RAX,
	RBX,
	RCX,
	RDX,
	RSI,
	RDI,
	RBP,
	RSP,
	R8,
	R9,
	R10,
	R11,
	R12,
	R13,
	R14,
	R15
} reg_name;



const char * register_name(int r);  // returns name of register in array indexed by e->reg
int register_alloc();  // find free register
void register_free(int r);  