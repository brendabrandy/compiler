	.comm	i,4,4
	.section	.rodata
.string_ro_0:
	.string	"%d Hello world\n"
	.data
	.align	4
	.size	.string_0, 4
.string_0:
	.long	.string_ro_0
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
	movl	i, %ecx
	pushl	%ecx
	movl	.string_0, %ecx
	pushl	%ecx
	call	printf
	addl	$8, %esp
	movl	%eax, (%ebp)
	jmp	.BB1.3
.BB1.3:
	movl	i, %ecx
	movl	%ecx, -4(%ebp)
	movl	$1, %ecx
	addl	i, %ecx
	movl	%ecx, i
	jmp	.BB1.4
.BB1.5:
	movl	$0, %eax
	leave
	ret
