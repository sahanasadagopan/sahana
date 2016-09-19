	.file	"bigtolittle.c"
	.section	.rodata
.LC0:
	.string	"Enter a 32 bit data:"
.LC1:
	.string	"%x"
.LC2:
	.string	"little:%x\n"
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
	subl	$20, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	subl	$12, %esp
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	leal	-20(%ebp), %eax
	pushl	%eax
	pushl	$.LC1
	call	__isoc99_scanf
	addl	$16, %esp
	movl	-20(%ebp), %eax
	subl	$12, %esp
	pushl	%eax
	call	big_to_little
	addl	$16, %esp
	movl	%eax, -16(%ebp)
	subl	$8, %esp
	pushl	-16(%ebp)
	pushl	$.LC2
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
	.globl	big_to_little
	.type	big_to_little, @function
big_to_little:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	leal	8(%ebp), %eax
	movl	%eax, -20(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-20(%ebp), %eax
	movzbl	3(%eax), %edx
	movl	-16(%ebp), %eax
	movb	%dl, (%eax)
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	-20(%ebp), %eax
	movzbl	2(%eax), %eax
	movb	%al, (%edx)
	movl	-16(%ebp), %eax
	leal	2(%eax), %edx
	movl	-20(%ebp), %eax
	movzbl	1(%eax), %eax
	movb	%al, (%edx)
	movl	-16(%ebp), %eax
	leal	3(%eax), %edx
	movl	-20(%ebp), %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
	movl	-24(%ebp), %eax
	movl	-12(%ebp), %ecx
	xorl	%gs:20, %ecx
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	big_to_little, .-big_to_little
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
