.data
s: .quad 0
.data
a: .quad 90
.data
str: .string ""
.data
str1: .string "hello"
.text
.globl main
main:
	PUSHQ %rbp
	MOVQ %rsp, %rbp
	PUSHQ %rdi
	PUSHQ %rsi
	PUSHQ %rdx
	PUSHQ %rdi
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
STR0:
.string "hi"
.text
LEA STR0, %rbx
	#################### epilogue of function restores the stack
	.RET:
	POPQ %r15
	POPQ %r14
	POPQ %r13
	POPQ %r12
	POPQ %rbx
	MOVQ %rbp, %rsp
	POPQ %rbp
	ret
