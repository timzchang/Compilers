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
	MOV $1, %rbx
	MOV $2, %r10
	CMP %rbx, %r10
	JL .L0
	MOV $1, %r10
	JMP .L1
.L0:
	MOV $0, %r10
.L1:
	CMP $0, %r10
	JE .L2
	MOV $0, %rbx
	MOV %rbx, %rax
	jmp .RET
	JMP .L3
.L2:
	MOV $1, %rbx
	MOV %rbx, %rax
	jmp .RET
.L3:
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
