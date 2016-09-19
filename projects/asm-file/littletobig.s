	.file	"littletobig.c"
	.section	.rodata
.LC0:
	.string	"Enter a 32 bit data:"
.LC1:
	.string	"%x"
.LC2:
	.string	"1.big:%x\n"
.LC3:
	.string	"2.big:%x\n"
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
	subl	$36, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	subl	$12, %esp
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	leal	-28(%ebp), %eax
	pushl	%eax
	pushl	$.LC1
	call	__isoc99_scanf
	addl	$16, %esp
	movl	$1, -24(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$1, %al
	jne	.L2
	movl	-28(%ebp), %eax
	subl	$12, %esp
	pushl	%eax
	call	little_to_big
	addl	$16, %esp
	movl	%eax, -16(%ebp)
	subl	$8, %esp
	pushl	-16(%ebp)
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	jmp	.L5
.L2:
	movl	-28(%ebp), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC3
	call	printf
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
	.globl	little_to_big
	.type	little_to_big, @function
little_to_big:
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
	je	.L8
	call	__stack_chk_fail
.L8:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	little_to_big, .-little_to_big
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
