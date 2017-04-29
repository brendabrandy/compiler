	.section	.rodata
.string_ro_0:
	.string	"Hello world"
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
