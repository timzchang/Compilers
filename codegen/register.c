#include "register.h"

const char * register_name(int r){
	switch(r){
	case RAX:
		return "%rax";
		break;
	case RBX:
		return "%rbx";
		break;
	case RCX:
		return "%rcx";
		break;
	case RDX:
		return "%rdx";
		break;
	case RSI:
		return "%rsi";
		break;
	case RDI:
		return "%rdi";
		break;
	case RBP:
		return "%rbp";
		break;
	case RSP:
		return "%rsp";
		break;
	case R8:
		return "%r8";
		break;
	case R9:
		return "%r9";
		break;
	case R10:
		return "%r10";
		break;
	case R11:
		return "%r11";
		break;
	case R12:
		return "%r12";
		break;
	case R13:
		return "%r13";
		break;
	case R14:
		return "%r14";
		break;
	case R15:
		return "%r15";
		break;
	default:
		return "error";
	}
}

int register_alloc(){
	int i;

	for(i=0; i<16; i++){
		if(reg[i] ==0){
			reg[i] = 1;
			return i;
		}
	}
	printf("out of registers\n");
	exit(1);
}

void register_free(int r){
	if(r >= 0 && r < 16){
		reg[r] = 0;
	}else{
		printf("out of bounds\n");
		// exit(1);
	}
}