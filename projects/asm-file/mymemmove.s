	.file	"mymemmove.c"
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
	subl	$228, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$0, -224(%ebp)
	leal	-212(%ebp), %eax
	movl	%eax, -220(%ebp)
	subl	$12, %esp
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	leal	-212(%ebp), %eax
	pushl	%eax
	pushl	$.LC1
	call	__isoc99_scanf
	addl	$16, %esp
	jmp	.L2
.L3:
	addl	$1, -224(%ebp)
	addl	$1, -220(%ebp)
.L2:
	movl	-220(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L3
	movl	-220(%ebp), %eax
	movb	$0, (%eax)
	leal	-112(%ebp), %eax
	movl	%eax, -216(%ebp)
	subl	$8, %esp
	pushl	-224(%ebp)
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	subl	$4, %esp
	pushl	-224(%ebp)
	leal	-112(%ebp), %eax
	pushl	%eax
	leal	-212(%ebp), %eax
	pushl	%eax
	call	my_memmove
	addl	$16, %esp
	movb	%al, -225(%ebp)
	cmpb	$1, -225(%ebp)
	jne	.L4
	subl	$12, %esp
	pushl	$.LC3
	call	printf
	addl	$16, %esp
	jmp	.L5
.L6:
	movl	-216(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	subl	$12, %esp
	pushl	%eax
	call	putchar
	addl	$16, %esp
	addl	$1, -216(%ebp)
.L5:
	movl	-216(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L6
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
	.globl	my_memmove
	.type	my_memmove, @function
my_memmove:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	cmpl	$0, 8(%ebp)
	je	.L10
	cmpl	$0, 12(%ebp)
	je	.L10
	jmp	.L11
.L13:
	movl	12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jbe	.L12
	movl	8(%ebp), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	cmpl	12(%ebp), %eax
	jbe	.L12
	movl	16(%ebp), %eax
	addl	%eax, 12(%ebp)
	movl	16(%ebp), %eax
	addl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movl	16(%ebp), %edx
	addl	%eax, %edx
	movl	12(%ebp), %eax
	movb	%dl, (%eax)
	subl	$1, 12(%ebp)
	subl	$1, 8(%ebp)
	jmp	.L11
.L12:
	movl	8(%ebp), %eax
	movzbl	(%eax), %edx
	movl	12(%ebp), %eax
	movb	%dl, (%eax)
	addl	$1, 8(%ebp)
	addl	$1, 12(%ebp)
	subl	$1, 16(%ebp)
.L11:
	movl	8(%ebp), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	cmpl	8(%ebp), %eax
	ja	.L13
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	12(%ebp), %eax
	movb	$0, (%eax)
	movl	$1, %eax
	jmp	.L14
.L10:
	movl	$0, %eax
.L14:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	my_memmove, .-my_memmove
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
