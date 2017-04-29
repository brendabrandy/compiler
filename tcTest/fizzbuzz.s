	.comm	i,4,4
	.section	.rodata
.string_ro_0:
	.string	"%d is divisble by 15\n"
	.data
	.align	4
	.size	.string_0, 4
.string_0:
	.long	.string_ro_0
	.section	.rodata
.string_ro_1:
	.string	"%d is divisible by 3 and not 5\n"
	.data
	.align	4
	.size	.string_1, 4
.string_1:
	.long	.string_ro_1
	.section	.rodata
.string_ro_2:
	.string	"%d is divisible by 5 but not 3\n"
	.data
	.align	4
	.size	.string_2, 4
.string_2:
	.long	.string_ro_2
	.text
	.globl	main
	.type	main,@function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	subl	$0, %esp
	subl	$8, %esp
.BB1.1:
	movl	$0, %ecx
	movl	%ecx, i
	jmp	.BB1.4
.BB1.4:
	movl	i, %ebx
	movl	$100, %ecx
	cmp	%ecx, %ebx
	jnl	.BB1.5
	jl	.BB1.2
.BB1.2:
	movl	i, %eax
	xor	%edx, %edx
	movl	$15, %ebx
	idiv	%ebx

	movl	%edx, (%ebp)
	movl	(%ebp), %ebx
	movl	$0, %ecx
	cmp	%ecx, %ebx
	jne	.BB1.7
	je	.BB1.6
.BB1.6:
	movl	i, %ecx
	pushl	%ecx
	movl	.string_0, %ecx
	pushl	%ecx
	call	printf
	addl	$8, %esp
	movl	%eax, -4(%ebp)
	jmp	.BB1.8
.BB1.8:
	jmp	.BB1.3
.BB1.3:
	movl	i, %ecx
	movl	%ecx, -24(%ebp)
	movl	$1, %ecx
	addl	i, %ecx
	movl	%ecx, i
	jmp	.BB1.4
.BB1.7:
	movl	i, %eax
	xor	%edx, %edx
	movl	$3, %ebx
	idiv	%ebx

	movl	%edx, -8(%ebp)
	movl	-8(%ebp), %ebx
	movl	$0, %ecx
	cmp	%ecx, %ebx
	jne	.BB1.10
	je	.BB1.9
.BB1.9:
	movl	i, %ecx
	pushl	%ecx
	movl	.string_1, %ecx
	pushl	%ecx
	call	printf
	addl	$8, %esp
	movl	%eax, -12(%ebp)
	jmp	.BB1.11
.BB1.11:
	jmp	.BB1.8
.BB1.10:
	movl	i, %eax
	xor	%edx, %edx
	movl	$5, %ebx
	idiv	%ebx

	movl	%edx, -16(%ebp)
	movl	-16(%ebp), %ebx
	movl	$0, %ecx
	cmp	%ecx, %ebx
	jne	.BB1.13
	je	.BB1.12
.BB1.12:
	movl	i, %ecx
	pushl	%ecx
	movl	.string_2, %ecx
	pushl	%ecx
	call	printf
	addl	$8, %esp
	movl	%eax, -20(%ebp)
	jmp	.BB1.13
.BB1.13:
	jmp	.BB1.11
.BB1.5:
	movl	$0, %eax
	leave
	ret
