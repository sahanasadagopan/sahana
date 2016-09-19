	.file	"data.c"
	.text
	.globl	my_itoa
	.type	my_itoa, @function
my_itoa:
.LFB0:
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
	jns	.L4
	negl	12(%ebp)
	jmp	.L4
.L7:
	movl	12(%ebp), %eax
	cltd
	idivl	16(%ebp)
	movl	%edx, -4(%ebp)
	cmpl	$9, -4(%ebp)
	jle	.L5
	movsbl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	addl	$87, %edx
	movb	%dl, (%eax)
	jmp	.L6
.L5:
	movsbl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-4(%ebp), %edx
	addl	$48, %edx
	movb	%dl, (%eax)
.L6:
	movl	12(%ebp), %eax
	cltd
	idivl	16(%ebp)
	movl	%eax, 12(%ebp)
	movzbl	-12(%ebp), %eax
	addl	$1, %eax
	movb	%al, -12(%ebp)
.L4:
	cmpl	$0, 12(%ebp)
	jne	.L7
	cmpl	$10, 16(%ebp)
	jne	.L8
	cmpl	$0, -8(%ebp)
	jns	.L8
	movsbl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$45, (%eax)
	movzbl	-12(%ebp), %eax
	addl	$1, %eax
	movb	%al, -12(%ebp)
.L8:
	movb	$0, -11(%ebp)
	movzbl	-12(%ebp), %eax
	subl	$1, %eax
	movb	%al, -10(%ebp)
	jmp	.L9
.L10:
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
.L9:
	movzbl	-11(%ebp), %eax
	cmpb	-10(%ebp), %al
	jl	.L10
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
.LFE0:
	.size	my_itoa, .-my_itoa
	.section	.rodata
.LC0:
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
	je	.L13
	jmp	.L14
.L19:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$47, %al
	jle	.L15
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$57, %al
	jle	.L16
.L15:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$45, %al
	jne	.L17
.L16:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	addl	$1, 8(%ebp)
	jmp	.L14
.L17:
	movl	$0, %eax
	jmp	.L12
.L14:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L19
.L13:
	movl	8(%ebp), %eax
	movb	$0, (%eax)
.L12:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	my_atoi, .-my_atoi
	.section	.rodata
.LC1:
	.string	"%x"
	.text
	.globl	dump_memory
	.type	dump_memory, @function
dump_memory:
.LFB2:
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
	jmp	.L21
.L22:
	movzbl	-9(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	movzbl	-9(%ebp), %eax
	addl	$1, %eax
	movb	%al, -9(%ebp)
.L21:
	movzbl	-9(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	.L22
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
.LFE2:
	.size	dump_memory, .-dump_memory
	.globl	big_to_little
	.type	big_to_little, @function
big_to_little:
.LFB3:
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
	je	.L25
	call	__stack_chk_fail
.L25:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	big_to_little, .-big_to_little
	.globl	little_to_big
	.type	little_to_big, @function
little_to_big:
.LFB4:
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
	je	.L28
	call	__stack_chk_fail
.L28:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	little_to_big, .-little_to_big
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
