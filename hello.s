	.section	.rodata
.string_ro_0:
	.string	"Hello world!"
	.data
	.align	4
	.size	.string_0, 13
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
	movl	.string_0, %ecx
	pushl	%ecx
	subl	$4, %esp
	call	printf
	addl	$4, %esp
	movl	%eax, (%ebp)
	movl	$zero, %eax
	leave
	ret
