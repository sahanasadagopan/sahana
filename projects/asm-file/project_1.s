	.file	"project_1.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
.LC1:
	.string	"\nThe array formed: "
.LC2:
	.string	"%d\t"
	.align 4
.LC3:
	.string	"\nThe final array after shuffling: "
	.text
	.globl	project_1_report
	.type	project_1_report, @function
project_1_report:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movb	$0, -60(%ebp)
	leal	-44(%ebp), %eax
	movl	%eax, -56(%ebp)
	leal	-44(%ebp), %eax
	addl	$8, %eax
	movl	%eax, -52(%ebp)
	leal	-44(%ebp), %eax
	addl	$16, %eax
	movl	%eax, -48(%ebp)
	movb	$31, -59(%ebp)
	jmp	.L2
.L3:
	movzbl	-60(%ebp), %edx
	movl	-56(%ebp), %eax
	addl	%eax, %edx
	movzbl	-59(%ebp), %eax
	movb	%al, (%edx)
	movzbl	-60(%ebp), %edx
	movl	-56(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movzbl	-59(%ebp), %eax
	addl	$1, %eax
	movb	%al, -59(%ebp)
	movzbl	-60(%ebp), %eax
	addl	$1, %eax
	movb	%al, -60(%ebp)
.L2:
	cmpb	$15, -60(%ebp)
	jbe	.L3
	subl	$8, %esp
	pushl	$16
	pushl	-48(%ebp)
	call	my_memzero
	addl	$16, %esp
	subl	$12, %esp
	pushl	$.LC1
	call	puts
	addl	$16, %esp
	movb	$0, -60(%ebp)
	jmp	.L4
.L5:
	movzbl	-60(%ebp), %edx
	movl	-56(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	movzbl	-60(%ebp), %eax
	addl	$1, %eax
	movb	%al, -60(%ebp)
.L4:
	cmpb	$31, -60(%ebp)
	jbe	.L5
	subl	$4, %esp
	pushl	$8
	pushl	-48(%ebp)
	pushl	-56(%ebp)
	call	my_memmove
	addl	$16, %esp
	subl	$4, %esp
	pushl	$16
	pushl	-56(%ebp)
	pushl	-52(%ebp)
	call	my_memmove
	addl	$16, %esp
	movb	%al, -58(%ebp)
	subl	$12, %esp
	pushl	$.LC3
	call	puts
	addl	$16, %esp
	subl	$8, %esp
	pushl	$32
	pushl	-56(%ebp)
	call	my_reverse
	addl	$16, %esp
	movb	%al, -57(%ebp)
	movb	$0, -60(%ebp)
	jmp	.L6
.L7:
	movzbl	-60(%ebp), %edx
	movl	-56(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	movzbl	-60(%ebp), %eax
	addl	$1, %eax
	movb	%al, -60(%ebp)
.L6:
	cmpb	$31, -60(%ebp)
	jbe	.L7
	nop
	movl	-12(%ebp), %eax
	xorl	%gs:20, %eax
	je	.L8
	call	__stack_chk_fail
.L8:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	project_1_report, .-project_1_report
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
