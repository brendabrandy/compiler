	.text
	.globl	z
	.type	z,@function
z:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	subl	$12, %esp
	subl	$12, %esp
.BB1.1:
	movl	$1, -$0(%ebp)
	jmp	.BB1.2
.BB1.2:
	leal	-$8(%ebp), %ecx
	movl	(%ecx), %ebx
	movl	%ebx, -$12(%ebp)
	jnge	.BB1.4
	jge	.BB1.5
.BB1.5:
	movl	-$8(%ebp), %eax
	testl	%eax, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -$16(%ebp)
	jnle	.BB1.4
	jle	.BB1.3
.BB1.3:
	movl	$1, %ecx
	addl	-$0(%ebp), %ecx
	movl	%ecx, -$0(%ebp)
	jmp	.BB1.2
.BB1.4:
	movl	-$4(%ebp), %eax
	leave
	ret
	.text
	.globl	f
	.type	f,@function
f:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	subl	$8, %esp
.BB2.1:
	movl	$10, -$0(%ebp)
	movl	$20, -$4(%ebp)
	jmp	.BB2.2
.BB2.2:
	movl	-$0(%ebp), %ecx
	addl	-$4(%ebp), %ecx
	movl	%ecx, -$4(%ebp)
	jmp	.BB2.3
.BB2.3:
	jnl	.BB2.4
	jl	.BB2.2
.BB2.4:
	movl	$0, %eax
	leave
	ret
	.text
	.globl	g
	.type	g,@function
g:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	subl	$8, %esp
.BB3.1:
	movl	$0, -$0(%ebp)
	jmp	.BB3.4
.BB3.4:
	jnl	.BB3.5
	jl	.BB3.2
.BB3.2:
	movl	$1, %ecx
	addl	-$4(%ebp), %ecx
	movl	%ecx, -$4(%ebp)
	jne	.BB3.7
	je	.BB3.6
.BB3.6:
	movl	$2, %ecx
	addl	-$4(%ebp), %ecx
	movl	%ecx, -$4(%ebp)
	jmp	.BB3.5
.BB3.5:
	movl	$1, %ecx
	addl	-$0(%ebp), %ecx
	movl	%ecx, -$0(%ebp)
	leave
	ret
.BB3.7:
	jnl	.BB3.10
	jl	.BB3.9
.BB3.9:
	jmp	.BB3.3
.BB3.3:
	movl	$1, %ecx
	addl	-$0(%ebp), %ecx
	movl	%ecx, -$0(%ebp)
	jmp	.BB3.4
.BB3.10:
	movl	$1, %ecx
	addl	-$4(%ebp), %ecx
	movl	%ecx, -$4(%ebp)
	jmp	.BB3.3
