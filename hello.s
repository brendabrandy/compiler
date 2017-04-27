	.section	.rodata
.string_ro_0:
	.string	"Hello world!\n"
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
	movl	.string_0, %ecx
	pushl	%ecx
	call	printf
	addl	$4, %esp
	movl	%eax, (%ebp)
	movl	$0, %eax
	leave
	ret
