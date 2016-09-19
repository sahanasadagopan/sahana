	.file	"atoi.c"
	.section	.rodata
.LC0:
	.string	"Enter a string:"
.LC1:
	.string	"%[^\n]"
	.align 4
.LC2:
	.string	"\nInvalid input!letters and special characters except '-' not allowed"
.LC3:
	.string	"\nSuccess"
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
	leal	-112(%ebp), %eax
	pushl	%eax
	pushl	$.LC1
	call	__isoc99_scanf
	addl	$16, %esp
	subl	$12, %esp
	leal	-112(%ebp), %eax
	pushl	%eax
	call	my_atoi
	addl	$16, %esp
	movl	%eax, -116(%ebp)
	cmpl	$0, -116(%ebp)
	jne	.L2
	subl	$12, %esp
	pushl	$.LC2
	call	puts
	addl	$16, %esp
	jmp	.L5
.L2:
	subl	$12, %esp
	pushl	$.LC3
	call	puts
	addl	$16, %esp
.L5:
	nop
	movl	-12(%ebp), %eax
	xorl	%gs:20, %eax
	je	.L4
	call	__stack_chk_fail
.L4:
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
	.section	.rodata
.LC4:
	.string	"%d"
	.text
	.globl	my_atoi
	.type	my_atoi, @function
my_atoi:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	cmpl	$0, 8(%ebp)
	je	.L7
	jmp	.L8
.L13:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$47, %al
	jle	.L9
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$57, %al
	jle	.L10
.L9:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$45, %al
	jne	.L11
.L10:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC4
	call	printf
	addl	$16, %esp
	addl	$1, 8(%ebp)
	jmp	.L8
.L11:
	movl	$0, %eax
	jmp	.L6
.L8:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L13
.L7:
	movl	8(%ebp), %eax
	movb	$0, (%eax)
.L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	my_atoi, .-my_atoi
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
