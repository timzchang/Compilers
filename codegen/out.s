.text
.globl main
main:
	PUSHQ %rbp
	MOVQ %rsp, %rbp
	PUSHQ %rdi
	PUSHQ %rsi
	PUSHQ %rdx
	PUSHQ %rcx
	PUSHQ %r8
	PUSHQ %r9
	PUSHQ %rbx
	PUSHQ %r12
	PUSHQ %r13
	PUSHQ %r14
	PUSHQ %r15
	#################### body of function starts here
.data
.STR0:
.string"hello world"
.text
LEA .STR0, %rbx
	PUSHQ %r10
	PUSHQ %r11
	MOV %rbx, %rdi
	CALL print_string
	POPQ %r11
	POPQ %r10
	MOV $10, %rbx
	PUSHQ %r10
	PUSHQ %r11
	MOV %rbx, %rdi
	CALL print_character
	POPQ %r11
	POPQ %r10
	#################### epilogue of function restores the stack
	.RET0:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	ret
