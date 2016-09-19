	.file	"dump_mem.c"
	.section	.rodata
.LC0:
	.string	"\nEnter the data:"
.LC1:
	.string	"%[^\n]"
	.align 4
.LC2:
	.string	"\nThe length of the entered data:%u"
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
	movl	$0, -120(%ebp)
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
	movl	%eax, -116(%ebp)
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
	call	dump_memory
	addl	$16, %esp
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
.LC3:
	.string	"%x"
	.text
	.globl	dump_memory
	.type	dump_memory, @function
dump_memory:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	subl	$12, %esp
	pushl	$10
	call	putchar
	addl	$16, %esp
	movb	$0, -9(%ebp)
	jmp	.L6
.L7:
	movzbl	-9(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC3
	call	printf
	addl	$16, %esp
	movzbl	-9(%ebp), %eax
	addl	$1, %eax
	movb	%al, -9(%ebp)
.L6:
	movzbl	-9(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	.L7
	subl	$12, %esp
	pushl	$10
	call	putchar
	addl	$16, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	dump_memory, .-dump_memory
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
