.data
s: .quad 0
.data
a: .quad 10
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
	SUBQ $16, %rsp
	PUSHQ %rbx
	PUSHQ %r12
	PUSHQ %r13
	PUSHQ %r14
	PUSHQ %r15
	#################### body of function starts here
	CMP error, $0
	JE .L0
	MOV error, %rax
	jmp .RET
	JMP .L1
.L0:
	MOV error, %rax
	jmp .RET
.L1:
.L2:
	CMP error, $0
	JE .L3
	JMP .L2
.L3
	MOV error, %rax
	jmp .RET
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
