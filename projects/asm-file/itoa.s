	.file	"itoa.c"
	.section	.rodata
.LC0:
	.string	"\nEnter the data:"
.LC1:
	.string	"%d"
.LC2:
	.string	"Enter the base required:"
.LC3:
	.string	"base %d:%s\n"
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
	subl	$116, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	subl	$12, %esp
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	leal	-120(%ebp), %eax
	pushl	%eax
	pushl	$.LC1
	call	__isoc99_scanf
	addl	$16, %esp
	subl	$12, %esp
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	leal	-116(%ebp), %eax
	pushl	%eax
	pushl	$.LC1
	call	__isoc99_scanf
	addl	$16, %esp
	movl	-116(%ebp), %edx
	movl	-120(%ebp), %eax
	subl	$4, %esp
	pushl	%edx
	pushl	%eax
	leal	-112(%ebp), %eax
	pushl	%eax
	call	my_itoa
	addl	$16, %esp
	movl	%eax, %edx
	movl	-116(%ebp), %eax
	subl	$4, %esp
	pushl	%edx
	pushl	%eax
	pushl	$.LC3
	call	printf
	addl	$16, %esp
	nop
	movl	-12(%ebp), %eax
	xorl	%gs:20, %eax
	je	.L2
	call	__stack_chk_fail
.L2:
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
	.globl	my_itoa
	.type	my_itoa, @function
my_itoa:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	12(%ebp), %eax
	movl	%eax, -8(%ebp)
	movb	$0, -12(%ebp)
	cmpl	$0, 12(%ebp)
	jns	.L6
	negl	12(%ebp)
	jmp	.L6
.L9:
	movl	12(%ebp), %eax
	cltd
	idivl	16(%ebp)
	movl	%edx, -4(%ebp)
	cmpl	$9, -4(%ebp)
	jle	.L7
	movsbl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	addl	$87, %edx
	movb	%dl, (%eax)
	jmp	.L8
.L7:
	movsbl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	addl	$48, %edx
	movb	%dl, (%eax)
.L8:
	movl	12(%ebp), %eax
	cltd
	idivl	16(%ebp)
	movl	%eax, 12(%ebp)
	movzbl	-12(%ebp), %eax
	addl	$1, %eax
	movb	%al, -12(%ebp)
.L6:
	cmpl	$0, 12(%ebp)
	jne	.L9
	cmpl	$10, 16(%ebp)
	jne	.L10
	cmpl	$0, -8(%ebp)
	jns	.L10
	movsbl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$45, (%eax)
	movzbl	-12(%ebp), %eax
	addl	$1, %eax
	movb	%al, -12(%ebp)
.L10:
	movb	$0, -11(%ebp)
	movzbl	-12(%ebp), %eax
	subl	$1, %eax
	movb	%al, -10(%ebp)
	jmp	.L11
.L12:
	movsbl	-11(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -9(%ebp)
	movsbl	-11(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movsbl	-10(%ebp), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	movsbl	-10(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-9(%ebp), %eax
	movb	%al, (%edx)
	movzbl	-11(%ebp), %eax
	addl	$1, %eax
	movb	%al, -11(%ebp)
	movzbl	-10(%ebp), %eax
	subl	$1, %eax
	movb	%al, -10(%ebp)
.L11:
	movzbl	-11(%ebp), %eax
	cmpb	-10(%ebp), %al
	jl	.L12
	movsbl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	movzbl	-12(%ebp), %eax
	addl	$1, %eax
	movb	%al, -12(%ebp)
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	my_itoa, .-my_itoa
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
