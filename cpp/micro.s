	.file	"micro.cpp"
	.text
	.section	.rodata
.LC0:
	.string	"???"
.LC1:
	.string	"[%s:%d] %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %ecx
	movl	$9, %edx
	movl	$_ZZ4mainE8__func__, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.type	_ZZ4mainE8__func__, @object
	.size	_ZZ4mainE8__func__, 5
_ZZ4mainE8__func__:
	.string	"main"
	.ident	"GCC: (GNU) 8.3.1 20191121 (Red Hat 8.3.1-5)"
	.section	.note.GNU-stack,"",@progbits
