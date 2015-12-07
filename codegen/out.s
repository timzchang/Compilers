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
	CMP $0, %rax
	JE .L0
	MOV %rax, %rax
	jmp .RET
	JMP .L1
.L0:
	MOV %r10, %rax
	jmp .RET
.L1:
.L2:
	CMP $0, %rax
	JE .L3
	JMP .L2
.L3:
	MOV %r11, %rax
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
