	.file	"fizzbuzz.c"
	.comm	i,4,4
	.section	.rodata
.LC0:
	.string	"%d is divisble by 15"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$4, %esp
	movl	$0, i
	jmp	.L2
.L4:
	movl	i, %ecx
	movl	$-2004318071, %edx
	movl	%ecx, %eax
	imull	%edx
	leal	(%edx,%ecx), %eax
	sarl	$3, %eax
	movl	%eax, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	sall	$4, %edx
	subl	%eax, %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	testl	%eax, %eax
	jne	.L3
	movl	i, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
.L3:
	movl	i, %eax
	addl	$1, %eax
	movl	%eax, i
.L2:
	movl	i, %eax
	cmpl	$99, %eax
	jle	.L4
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
