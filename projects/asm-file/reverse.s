	.file	"reverse.c"
	.section	.rodata
.LC0:
	.string	"\nEnter the data:"
.LC1:
	.string	"%[^\n]"
	.align 4
.LC2:
	.string	"\nThe length of the entered data:%u"
.LC3:
	.string	"\nThe reversed data is:"
.LC4:
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
	movl	$0, -124(%ebp)
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
	leal	-112(%ebp), %eax
	movl	%eax, -120(%ebp)
	jmp	.L2
.L3:
	addl	$1, -124(%ebp)
	addl	$1, -120(%ebp)
.L2:
	movl	-120(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L3
	movl	-120(%ebp), %eax
	movb	$0, (%eax)
	subl	$8, %esp
	pushl	-124(%ebp)
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	pushl	-124(%ebp)
	leal	-112(%ebp), %eax
	pushl	%eax
	call	my_reverse
	addl	$16, %esp
	movb	%al, -125(%ebp)
	leal	-112(%ebp), %eax
	movl	%eax, -116(%ebp)
	cmpb	$1, -125(%ebp)
	jne	.L4
	subl	$12, %esp
	pushl	$.LC3
	call	printf
	addl	$16, %esp
	movb	$0, -126(%ebp)
	jmp	.L5
.L6:
	movzbl	-126(%ebp), %edx
	movl	-116(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	putchar
	addl	$16, %esp
	movzbl	-126(%ebp), %eax
	addl	$1, %eax
	movb	%al, -126(%ebp)
.L5:
	movzbl	-126(%ebp), %eax
	cmpl	-124(%ebp), %eax
	jbe	.L6
	jmp	.L7
.L4:
	subl	$12, %esp
	pushl	$.LC4
	call	printf
	addl	$16, %esp
.L7:
	subl	$12, %esp
	pushl	$10
	call	putchar
	addl	$16, %esp
	movl	$0, %eax
	movl	-12(%ebp), %ecx
	xorl	%gs:20, %ecx
	je	.L9
	call	__stack_chk_fail
.L9:
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
	.globl	my_reverse
	.type	my_reverse, @function
my_reverse:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	cmpl	$0, 8(%ebp)
	je	.L11
	jmp	.L12
.L13:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movb	%al, -5(%ebp)
	movl	-4(%ebp), %eax
	movzbl	(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, (%eax)
	movl	-4(%ebp), %eax
	movzbl	-5(%ebp), %edx
	movb	%dl, (%eax)
	addl	$1, 8(%ebp)
	subl	$1, -4(%ebp)
.L12:
	movl	8(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jb	.L13
	movl	$1, %eax
	jmp	.L14
.L11:
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	$0, %eax
.L14:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	my_reverse, .-my_reverse
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
