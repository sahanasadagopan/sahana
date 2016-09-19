	.file	"memzero.c"
	.section	.rodata
.LC0:
	.string	"\nEnter the data:"
.LC1:
	.string	"%[^\n]"
	.align 4
.LC2:
	.string	"The length of the string is:%u\n"
	.align 4
.LC3:
	.string	"The data at the destination is:"
.LC4:
	.string	"%d"
.LC5:
	.string	"Move failed"
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
	subl	$132, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$0, -120(%ebp)
	leal	-112(%ebp), %eax
	movl	%eax, -116(%ebp)
	subl	$12, %esp
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	leal	-112(%ebp), %eax
	pushl	%eax
	pushl	$.LC1
	call	__isoc99_scanf
	addl	$16, %esp
	jmp	.L2
.L3:
	addl	$1, -120(%ebp)
	addl	$1, -116(%ebp)
.L2:
	movl	-116(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L3
	movl	-116(%ebp), %eax
	movb	$0, (%eax)
	subl	$8, %esp
	pushl	-120(%ebp)
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	pushl	-120(%ebp)
	leal	-112(%ebp), %eax
	pushl	%eax
	call	my_memzero
	addl	$16, %esp
	movb	%al, -121(%ebp)
	cmpb	$1, -121(%ebp)
	jne	.L4
	subl	$12, %esp
	pushl	$.LC3
	call	printf
	addl	$16, %esp
	movb	$0, -122(%ebp)
	jmp	.L5
.L6:
	movzbl	-122(%ebp), %eax
	movzbl	-112(%ebp,%eax), %eax
	movsbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC4
	call	printf
	addl	$16, %esp
	movzbl	-122(%ebp), %eax
	addl	$1, %eax
	movb	%al, -122(%ebp)
.L5:
	movzbl	-122(%ebp), %eax
	cmpl	-120(%ebp), %eax
	jb	.L6
	jmp	.L7
.L4:
	subl	$12, %esp
	pushl	$.LC5
	call	printf
	addl	$16, %esp
.L7:
	subl	$12, %esp
	pushl	$10
	call	putchar
	addl	$16, %esp
	nop
	movl	-12(%ebp), %eax
	xorl	%gs:20, %eax
	je	.L8
	call	__stack_chk_fail
.L8:
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
	.globl	my_memzero
	.type	my_memzero, @function
my_memzero:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	cmpl	$0, 8(%ebp)
	je	.L10
	jmp	.L11
.L12:
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	addl	$1, 8(%ebp)
	subl	$1, 12(%ebp)
.L11:
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	cmpl	8(%ebp), %eax
	ja	.L12
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	$1, %eax
	jmp	.L13
.L10:
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	$0, %eax
.L13:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	my_memzero, .-my_memzero
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
