	.file	"memory.c"
	.text
	.globl	my_memmove
	.type	my_memmove, @function
my_memmove:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	cmpl	$0, 8(%ebp)
	je	.L2
	cmpl	$0, 12(%ebp)
	je	.L2
	jmp	.L3
.L5:
	movl	12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jbe	.L4
	movl	8(%ebp), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	cmpl	12(%ebp), %eax
	jbe	.L4
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
	jmp	.L3
.L4:
	movl	8(%ebp), %eax
	movzbl	(%eax), %edx
	movl	12(%ebp), %eax
	movb	%dl, (%eax)
	addl	$1, 8(%ebp)
	addl	$1, 12(%ebp)
	subl	$1, 16(%ebp)
.L3:
	movl	8(%ebp), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	cmpl	8(%ebp), %eax
	ja	.L5
	movl	$1, %eax
	jmp	.L6
.L2:
	movl	$0, %eax
.L6:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	my_memmove, .-my_memmove
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
	je	.L8
	jmp	.L9
.L10:
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	addl	$1, 8(%ebp)
	subl	$1, 12(%ebp)
.L9:
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	cmpl	8(%ebp), %eax
	ja	.L10
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	$1, %eax
	jmp	.L11
.L8:
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	$0, %eax
.L11:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	my_memzero, .-my_memzero
	.globl	my_reverse
	.type	my_reverse, @function
my_reverse:
.LFB2:
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
	je	.L13
	jmp	.L14
.L15:
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
.L14:
	movl	8(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jb	.L15
	movl	$1, %eax
	jmp	.L16
.L13:
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	$0, %eax
.L16:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	my_reverse, .-my_reverse
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
