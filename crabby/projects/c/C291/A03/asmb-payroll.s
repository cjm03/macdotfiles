	.file	"payroll.c"
	.text
	.globl	month_strings
	.data
	.align 32
	.type	month_strings, @object
	.size	month_strings, 120
month_strings:
	.string	"JANUARY"
	.zero	2
	.string	"FEBRUARY"
	.zero	1
	.string	"MARCH"
	.zero	4
	.string	"APRIL"
	.zero	4
	.string	"MAY"
	.zero	6
	.string	"JUNE"
	.zero	5
	.string	"JULY"
	.zero	5
	.string	"AUGUST"
	.zero	3
	.string	"SEPTEMBER"
	.string	"OCTOBER"
	.zero	2
	.string	"NOVEMBER"
	.zero	1
	.string	"DECEMBER"
	.zero	1
	.globl	employee_sales_array
	.bss
	.align 16
	.type	employee_sales_array, @object
	.size	employee_sales_array, 20
employee_sales_array:
	.zero	20
	.globl	employee_tenure_array
	.align 16
	.type	employee_tenure_array, @object
	.size	employee_tenure_array, 20
employee_tenure_array:
	.zero	20
	.text
	.globl	sum_employee_sales
	.type	sum_employee_sales, @function
sum_employee_sales:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	addl	%eax, -8(%rbp)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$4, -4(%rbp)
	jle	.L3
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	sum_employee_sales, .-sum_employee_sales
	.globl	calculate_monthly_profit
	.type	calculate_monthly_profit, @function
calculate_monthly_profit:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movss	%xmm0, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	sum_employee_sales
	movl	%eax, -8(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-8(%rbp), %xmm0
	movss	-28(%rbp), %xmm1
	mulss	%xmm1, %xmm0
	movss	%xmm0, -4(%rbp)
	movss	-4(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	calculate_monthly_profit, .-calculate_monthly_profit
	.globl	calculate_employee_commission
	.type	calculate_employee_commission, @function
calculate_employee_commission:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movss	%xmm0, -8(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-4(%rbp), %xmm0
	mulss	-8(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	calculate_employee_commission, .-calculate_employee_commission
	.globl	calculate_total_commission
	.type	calculate_total_commission, @function
calculate_total_commission:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movss	%xmm0, -28(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L10
.L11:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%eax, %xmm0
	mulss	-28(%rbp), %xmm0
	movss	-8(%rbp), %xmm1
	addss	%xmm1, %xmm0
	movss	%xmm0, -8(%rbp)
	addl	$1, -4(%rbp)
.L10:
	cmpl	$4, -4(%rbp)
	jle	.L11
	movss	-8(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	calculate_total_commission, .-calculate_total_commission
	.globl	calculate_employee_bonus
	.type	calculate_employee_bonus, @function
calculate_employee_bonus:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movss	%xmm0, -32(%rbp)
	movss	%xmm1, -36(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$0, -24(%rbp)
	jne	.L14
	cmpl	$0, -28(%rbp)
	jne	.L14
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-4(%rbp), %xmm0
	jmp	.L15
.L14:
	cmpl	$9, -28(%rbp)
	jg	.L16
	movl	$0, -8(%rbp)
	jmp	.L17
.L16:
	movl	-28(%rbp), %ecx
	movslq	%ecx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testl	%edx, %edx
	je	.L18
	movl	-28(%rbp), %ecx
	movslq	%ecx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	-28(%rbp), %eax
	subl	%edx, %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	$2, %ecx
	cltd
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, -8(%rbp)
	jmp	.L17
.L18:
	movl	-28(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	$2, %ecx
	cltd
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, -8(%rbp)
.L17:
	cmpl	$0, -8(%rbp)
	je	.L19
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-8(%rbp), %xmm0
	mulss	-36(%rbp), %xmm0
	movss	-32(%rbp), %xmm1
	addss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	jmp	.L20
.L19:
	movss	-32(%rbp), %xmm0
	movss	%xmm0, -12(%rbp)
.L20:
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-20(%rbp), %xmm0
	mulss	-12(%rbp), %xmm0
.L15:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	calculate_employee_bonus, .-calculate_employee_bonus
	.globl	total_employee_bonus
	.type	total_employee_bonus, @function
total_employee_bonus:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -24(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L22
.L23:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %r12d
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ebx
	movq	-40(%rbp), %rax
	movl	.LC1(%rip), %edx
	movd	%edx, %xmm0
	movq	%rax, %rdi
	call	calculate_monthly_profit
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %edx
	movd	%edx, %xmm0
	movl	%r12d, %edx
	movl	%ebx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	movss	-24(%rbp), %xmm1
	addss	%xmm1, %xmm0
	movss	%xmm0, -24(%rbp)
	addl	$1, -20(%rbp)
.L22:
	cmpl	$4, -20(%rbp)
	jle	.L23
	movss	-24(%rbp), %xmm0
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	total_employee_bonus, .-total_employee_bonus
	.globl	calculate_net_profit
	.type	calculate_net_profit, @function
calculate_net_profit:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	.LC1(%rip), %edx
	movd	%edx, %xmm0
	movq	%rax, %rdi
	call	calculate_monthly_profit
	movd	%xmm0, %eax
	movl	%eax, -8(%rbp)
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	total_employee_bonus
	movaps	%xmm0, %xmm1
	movss	-8(%rbp), %xmm0
	subss	%xmm1, %xmm0
	movss	%xmm0, -4(%rbp)
	movss	-4(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	calculate_net_profit, .-calculate_net_profit
	.globl	calculate_employee_gross
	.type	calculate_employee_gross, @function
calculate_employee_gross:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	movss	-4(%rbp), %xmm0
	addss	-8(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	calculate_employee_gross, .-calculate_employee_gross
	.globl	calculate_federal
	.type	calculate_federal, @function
calculate_federal:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	movss	-4(%rbp), %xmm0
	mulss	-8(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	calculate_federal, .-calculate_federal
	.globl	calculate_state
	.type	calculate_state, @function
calculate_state:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	movss	-4(%rbp), %xmm0
	mulss	-8(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	calculate_state, .-calculate_state
	.globl	calculate_soc_sec
	.type	calculate_soc_sec, @function
calculate_soc_sec:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	movss	-4(%rbp), %xmm0
	mulss	-8(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	calculate_soc_sec, .-calculate_soc_sec
	.globl	calculate_employee_net
	.type	calculate_employee_net, @function
calculate_employee_net:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)
	movss	%xmm2, -12(%rbp)
	movss	%xmm3, -16(%rbp)
	movss	-4(%rbp), %xmm0
	subss	-8(%rbp), %xmm0
	subss	-12(%rbp), %xmm0
	subss	-16(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	calculate_employee_net, .-calculate_employee_net
	.globl	s_r
	.type	s_r, @function
s_r:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movss	%xmm0, -4(%rbp)
	movss	-4(%rbp), %xmm1
	movss	.LC4(%rip), %xmm0
	mulss	%xmm1, %xmm0
	pxor	%xmm2, %xmm2
	cvtss2sd	%xmm0, %xmm2
	movq	%xmm2, %rax
	movq	%rax, %xmm0
	call	round@PLT
	movq	%xmm0, %rax
	movsd	.LC5(%rip), %xmm0
	movq	%rax, %xmm1
	divsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsd2ss	%xmm1, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	s_r, .-s_r
	.globl	report_month_int
	.bss
	.align 4
	.type	report_month_int, @object
	.size	report_month_int, 4
report_month_int:
	.zero	4
	.globl	report_year_int
	.align 4
	.type	report_year_int, @object
	.size	report_year_int, 4
report_year_int:
	.zero	4
	.section	.rodata
	.align 8
.LC6:
	.string	"Enter the month for the report as an integer, a space, then the year as an integer: "
.LC7:
	.string	" %d %d"
	.align 8
.LC8:
	.string	"\nNow, enter employee's sales followed by their tenure, repeat for up to 5 total employees."
.LC9:
	.string	"\nEmployee %d: "
.LC13:
	.string	"\nMONTHLY STATEMENT (%s %d)\n"
.LC14:
	.string	"Bloomington Skating Company"
.LC15:
	.string	"%79s\n"
.LC16:
	.string	"Bloomington, IN"
.LC17:
	.string	"Phone: (812)-855-0000"
.LC18:
	.string	"\nMONTHLY SALES: $%.2f\n"
.LC19:
	.string	"MONTHLY PROFIT: $%.2f\n"
	.align 8
.LC20:
	.string	"==============================================================================="
.LC21:
	.string	"ST W."
.LC22:
	.string	"Fed W."
.LC23:
	.string	"Bonus"
.LC24:
	.string	"Commission"
.LC25:
	.string	"Name"
	.align 8
.LC26:
	.string	"%-10s %-12s %-11s %-12s %-11s %-9s %-8s\n"
.LC27:
	.string	"Net Pay"
.LC28:
	.string	"FICA"
	.align 8
.LC29:
	.string	"-------------------------------------------------------------------------------"
.LC30:
	.string	"Empl A:"
	.align 8
.LC31:
	.string	"%-10s %-12.2f %-11.2f %-12.2f %-11.2f %-9.2f %-8.2f\n"
.LC32:
	.string	"Empl B:"
.LC33:
	.string	"Empl C:"
.LC34:
	.string	"Empl D:"
.LC35:
	.string	"Empl E:"
.LC36:
	.string	"Total"
	.align 8
.LC37:
	.string	"Net Profit (Profit - Bonus): %.2f\n"
.LC38:
	.string	"John Doe, Branch Manager"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$184, %rsp
	.cfi_offset 3, -24
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	report_year_int(%rip), %rax
	movq	%rax, %rdx
	leaq	report_month_int(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -132(%rbp)
	jmp	.L40
.L45:
	movl	-132(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-132(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	employee_tenure_array(%rip), %rax
	addq	%rax, %rdx
	movl	-132(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	employee_sales_array(%rip), %rax
	addq	%rcx, %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-132(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	employee_sales_array(%rip), %rax
	movl	(%rdx,%rax), %eax
	testl	%eax, %eax
	jne	.L48
	movl	-132(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	employee_tenure_array(%rip), %rax
	movl	(%rdx,%rax), %eax
	testl	%eax, %eax
	jne	.L48
	movl	-132(%rbp), %eax
	movl	%eax, -128(%rbp)
	jmp	.L42
.L43:
	movl	-128(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	employee_sales_array(%rip), %rax
	movl	$0, (%rdx,%rax)
	movl	-128(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	employee_tenure_array(%rip), %rax
	movl	$0, (%rdx,%rax)
	addl	$1, -128(%rbp)
.L42:
	cmpl	$4, -128(%rbp)
	jle	.L43
	jmp	.L44
.L48:
	nop
	addl	$1, -132(%rbp)
.L40:
	cmpl	$4, -132(%rbp)
	jle	.L45
.L44:
	leaq	employee_sales_array(%rip), %rax
	movq	%rax, %rdi
	call	sum_employee_sales
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%eax, %xmm0
	movss	%xmm0, -124(%rbp)
	movl	.LC1(%rip), %eax
	movd	%eax, %xmm0
	leaq	employee_sales_array(%rip), %rax
	movq	%rax, %rdi
	call	calculate_monthly_profit
	movd	%xmm0, %eax
	movl	%eax, -120(%rbp)
	leaq	employee_tenure_array(%rip), %rax
	movq	%rax, %rsi
	leaq	employee_sales_array(%rip), %rax
	movq	%rax, %rdi
	call	total_employee_bonus
	movd	%xmm0, %eax
	movl	%eax, -116(%rbp)
	movl	employee_tenure_array(%rip), %edx
	movl	employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	movd	%xmm0, %ebx
	movl	employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	movd	%xmm0, %eax
	movd	%ebx, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_gross
	movd	%xmm0, %eax
	movl	%eax, -112(%rbp)
	movl	4+employee_tenure_array(%rip), %edx
	movl	4+employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	movd	%xmm0, %ebx
	movl	4+employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	movd	%xmm0, %eax
	movd	%ebx, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_gross
	movd	%xmm0, %eax
	movl	%eax, -108(%rbp)
	movl	8+employee_tenure_array(%rip), %edx
	movl	8+employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	movd	%xmm0, %ebx
	movl	8+employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	movd	%xmm0, %eax
	movd	%ebx, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_gross
	movd	%xmm0, %eax
	movl	%eax, -104(%rbp)
	movl	12+employee_tenure_array(%rip), %edx
	movl	12+employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	movd	%xmm0, %ebx
	movl	12+employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	movd	%xmm0, %eax
	movd	%ebx, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_gross
	movd	%xmm0, %eax
	movl	%eax, -100(%rbp)
	movl	16+employee_tenure_array(%rip), %edx
	movl	16+employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	movd	%xmm0, %ebx
	movl	16+employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	movd	%xmm0, %eax
	movd	%ebx, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_gross
	movd	%xmm0, %eax
	movl	%eax, -96(%rbp)
	movl	-112(%rbp), %eax
	movss	.LC11(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_federal
	movd	%xmm0, %eax
	movl	%eax, -92(%rbp)
	movl	-112(%rbp), %eax
	movss	.LC2(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_state
	movd	%xmm0, %eax
	movl	%eax, -88(%rbp)
	movl	-112(%rbp), %eax
	movss	.LC12(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_soc_sec
	movd	%xmm0, %eax
	movl	%eax, -84(%rbp)
	movl	-108(%rbp), %eax
	movss	.LC11(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_federal
	movd	%xmm0, %eax
	movl	%eax, -80(%rbp)
	movl	-108(%rbp), %eax
	movss	.LC2(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_state
	movd	%xmm0, %eax
	movl	%eax, -76(%rbp)
	movl	-108(%rbp), %eax
	movss	.LC12(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_soc_sec
	movd	%xmm0, %eax
	movl	%eax, -72(%rbp)
	movl	-104(%rbp), %eax
	movss	.LC11(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_federal
	movd	%xmm0, %eax
	movl	%eax, -68(%rbp)
	movl	-104(%rbp), %eax
	movss	.LC2(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_state
	movd	%xmm0, %eax
	movl	%eax, -64(%rbp)
	movl	-104(%rbp), %eax
	movss	.LC12(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_soc_sec
	movd	%xmm0, %eax
	movl	%eax, -60(%rbp)
	movl	-100(%rbp), %eax
	movss	.LC11(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_federal
	movd	%xmm0, %eax
	movl	%eax, -56(%rbp)
	movl	-100(%rbp), %eax
	movss	.LC2(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_state
	movd	%xmm0, %eax
	movl	%eax, -52(%rbp)
	movl	-100(%rbp), %eax
	movss	.LC12(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_soc_sec
	movd	%xmm0, %eax
	movl	%eax, -48(%rbp)
	movl	-96(%rbp), %eax
	movss	.LC11(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_federal
	movd	%xmm0, %eax
	movl	%eax, -44(%rbp)
	movl	-96(%rbp), %eax
	movss	.LC2(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_state
	movd	%xmm0, %eax
	movl	%eax, -40(%rbp)
	movl	-96(%rbp), %eax
	movss	.LC12(%rip), %xmm1
	movd	%eax, %xmm0
	call	calculate_soc_sec
	movd	%xmm0, %eax
	movl	%eax, -36(%rbp)
	movl	-92(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	movss	%xmm0, -152(%rbp)
	movl	-80(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	movaps	%xmm0, %xmm6
	addss	-152(%rbp), %xmm6
	movss	%xmm6, -152(%rbp)
	movl	-68(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	addss	-152(%rbp), %xmm0
	movss	%xmm0, -152(%rbp)
	movl	-56(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	movaps	%xmm0, %xmm6
	addss	-152(%rbp), %xmm6
	movss	%xmm6, -152(%rbp)
	movl	-44(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	addss	-152(%rbp), %xmm0
	movss	%xmm0, -32(%rbp)
	movl	-88(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	movss	%xmm0, -152(%rbp)
	movl	-76(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	movaps	%xmm0, %xmm7
	addss	-152(%rbp), %xmm7
	movss	%xmm7, -152(%rbp)
	movl	-64(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	addss	-152(%rbp), %xmm0
	movss	%xmm0, -152(%rbp)
	movl	-52(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	movaps	%xmm0, %xmm5
	addss	-152(%rbp), %xmm5
	movss	%xmm5, -152(%rbp)
	movl	-40(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	addss	-152(%rbp), %xmm0
	movss	%xmm0, -28(%rbp)
	movl	-84(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	movss	%xmm0, -152(%rbp)
	movl	-72(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	movaps	%xmm0, %xmm7
	addss	-152(%rbp), %xmm7
	movss	%xmm7, -152(%rbp)
	movl	-60(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	addss	-152(%rbp), %xmm0
	movss	%xmm0, -152(%rbp)
	movl	-48(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	movaps	%xmm0, %xmm6
	addss	-152(%rbp), %xmm6
	movss	%xmm6, -152(%rbp)
	movl	-36(%rbp), %eax
	movd	%eax, %xmm0
	call	s_r
	addss	-152(%rbp), %xmm0
	movss	%xmm0, -24(%rbp)
	movss	-84(%rbp), %xmm2
	movss	-88(%rbp), %xmm1
	movss	-92(%rbp), %xmm0
	movl	-112(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	movd	%xmm0, %eax
	movd	%eax, %xmm0
	call	s_r
	movss	%xmm0, -152(%rbp)
	movss	-72(%rbp), %xmm2
	movss	-76(%rbp), %xmm1
	movss	-80(%rbp), %xmm0
	movl	-108(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	movd	%xmm0, %eax
	movd	%eax, %xmm0
	call	s_r
	movaps	%xmm0, %xmm4
	addss	-152(%rbp), %xmm4
	movss	%xmm4, -152(%rbp)
	movss	-60(%rbp), %xmm2
	movss	-64(%rbp), %xmm1
	movss	-68(%rbp), %xmm0
	movl	-104(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	movd	%xmm0, %eax
	movd	%eax, %xmm0
	call	s_r
	addss	-152(%rbp), %xmm0
	movss	%xmm0, -152(%rbp)
	movss	-48(%rbp), %xmm2
	movss	-52(%rbp), %xmm1
	movss	-56(%rbp), %xmm0
	movl	-100(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	movd	%xmm0, %eax
	movd	%eax, %xmm0
	call	s_r
	movaps	%xmm0, %xmm7
	addss	-152(%rbp), %xmm7
	movss	%xmm7, -152(%rbp)
	movss	-36(%rbp), %xmm2
	movss	-40(%rbp), %xmm1
	movss	-44(%rbp), %xmm0
	movl	-96(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	movd	%xmm0, %eax
	movd	%eax, %xmm0
	call	s_r
	addss	-152(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
	movl	report_year_int(%rip), %ecx
	movl	report_month_int(%rip), %eax
	subl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rax, %rax
	leaq	month_strings(%rip), %rdx
	addq	%rdx, %rax
	movl	%ecx, %edx
	movq	%rax, %rsi
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC14(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC16(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC17(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	pxor	%xmm3, %xmm3
	cvtss2sd	-124(%rbp), %xmm3
	movq	%xmm3, %rax
	movq	%rax, %xmm0
	leaq	.LC18(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	pxor	%xmm4, %xmm4
	cvtss2sd	-120(%rbp), %xmm4
	movq	%xmm4, %rax
	movq	%rax, %xmm0
	leaq	.LC19(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	leaq	.LC20(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC27(%rip), %rax
	pushq	%rax
	leaq	.LC28(%rip), %rax
	pushq	%rax
	leaq	.LC21(%rip), %r9
	leaq	.LC22(%rip), %r8
	leaq	.LC23(%rip), %rax
	movq	%rax, %rcx
	leaq	.LC24(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC25(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC26(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$16, %rsp
	leaq	.LC29(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movss	-84(%rbp), %xmm2
	movss	-88(%rbp), %xmm1
	movss	-92(%rbp), %xmm0
	movl	-112(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	pxor	%xmm5, %xmm5
	cvtss2sd	%xmm0, %xmm5
	movsd	%xmm5, -152(%rbp)
	pxor	%xmm6, %xmm6
	cvtss2sd	-84(%rbp), %xmm6
	movsd	%xmm6, -160(%rbp)
	pxor	%xmm7, %xmm7
	cvtss2sd	-88(%rbp), %xmm7
	movsd	%xmm7, -168(%rbp)
	pxor	%xmm2, %xmm2
	cvtss2sd	-92(%rbp), %xmm2
	movsd	%xmm2, -176(%rbp)
	movl	employee_tenure_array(%rip), %edx
	movl	employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	pxor	%xmm1, %xmm1
	cvtss2sd	%xmm0, %xmm1
	movsd	%xmm1, -184(%rbp)
	movl	employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rax
	movsd	-152(%rbp), %xmm5
	movsd	-160(%rbp), %xmm4
	movsd	-168(%rbp), %xmm3
	movsd	-176(%rbp), %xmm2
	movsd	-184(%rbp), %xmm1
	movq	%rax, %xmm0
	leaq	.LC30(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC31(%rip), %rax
	movq	%rax, %rdi
	movl	$6, %eax
	call	printf@PLT
	movss	-72(%rbp), %xmm2
	movss	-76(%rbp), %xmm1
	movss	-80(%rbp), %xmm0
	movl	-108(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	pxor	%xmm3, %xmm3
	cvtss2sd	%xmm0, %xmm3
	movsd	%xmm3, -152(%rbp)
	pxor	%xmm4, %xmm4
	cvtss2sd	-72(%rbp), %xmm4
	movsd	%xmm4, -160(%rbp)
	pxor	%xmm6, %xmm6
	cvtss2sd	-76(%rbp), %xmm6
	movsd	%xmm6, -168(%rbp)
	pxor	%xmm7, %xmm7
	cvtss2sd	-80(%rbp), %xmm7
	movsd	%xmm7, -176(%rbp)
	movl	4+employee_tenure_array(%rip), %edx
	movl	4+employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	pxor	%xmm1, %xmm1
	cvtss2sd	%xmm0, %xmm1
	movsd	%xmm1, -184(%rbp)
	movl	4+employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rax
	movsd	-152(%rbp), %xmm5
	movsd	-160(%rbp), %xmm4
	movsd	-168(%rbp), %xmm3
	movsd	-176(%rbp), %xmm2
	movsd	-184(%rbp), %xmm1
	movq	%rax, %xmm0
	leaq	.LC32(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC31(%rip), %rax
	movq	%rax, %rdi
	movl	$6, %eax
	call	printf@PLT
	movss	-60(%rbp), %xmm2
	movss	-64(%rbp), %xmm1
	movss	-68(%rbp), %xmm0
	movl	-104(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	pxor	%xmm5, %xmm5
	cvtss2sd	%xmm0, %xmm5
	movsd	%xmm5, -152(%rbp)
	pxor	%xmm3, %xmm3
	cvtss2sd	-60(%rbp), %xmm3
	movsd	%xmm3, -160(%rbp)
	pxor	%xmm6, %xmm6
	cvtss2sd	-64(%rbp), %xmm6
	movsd	%xmm6, -168(%rbp)
	pxor	%xmm7, %xmm7
	cvtss2sd	-68(%rbp), %xmm7
	movsd	%xmm7, -176(%rbp)
	movl	8+employee_tenure_array(%rip), %edx
	movl	8+employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	pxor	%xmm1, %xmm1
	cvtss2sd	%xmm0, %xmm1
	movsd	%xmm1, -184(%rbp)
	movl	8+employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rax
	movsd	-152(%rbp), %xmm5
	movsd	-160(%rbp), %xmm4
	movsd	-168(%rbp), %xmm3
	movsd	-176(%rbp), %xmm2
	movsd	-184(%rbp), %xmm1
	movq	%rax, %xmm0
	leaq	.LC33(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC31(%rip), %rax
	movq	%rax, %rdi
	movl	$6, %eax
	call	printf@PLT
	movss	-48(%rbp), %xmm2
	movss	-52(%rbp), %xmm1
	movss	-56(%rbp), %xmm0
	movl	-100(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	pxor	%xmm4, %xmm4
	cvtss2sd	%xmm0, %xmm4
	movsd	%xmm4, -152(%rbp)
	pxor	%xmm3, %xmm3
	cvtss2sd	-48(%rbp), %xmm3
	movsd	%xmm3, -160(%rbp)
	pxor	%xmm6, %xmm6
	cvtss2sd	-52(%rbp), %xmm6
	movsd	%xmm6, -168(%rbp)
	pxor	%xmm7, %xmm7
	cvtss2sd	-56(%rbp), %xmm7
	movsd	%xmm7, -176(%rbp)
	movl	12+employee_tenure_array(%rip), %edx
	movl	12+employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	pxor	%xmm1, %xmm1
	cvtss2sd	%xmm0, %xmm1
	movsd	%xmm1, -184(%rbp)
	movl	12+employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rax
	movsd	-152(%rbp), %xmm5
	movsd	-160(%rbp), %xmm4
	movsd	-168(%rbp), %xmm3
	movsd	-176(%rbp), %xmm2
	movsd	-184(%rbp), %xmm1
	movq	%rax, %xmm0
	leaq	.LC34(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC31(%rip), %rax
	movq	%rax, %rdi
	movl	$6, %eax
	call	printf@PLT
	movss	-36(%rbp), %xmm2
	movss	-40(%rbp), %xmm1
	movss	-44(%rbp), %xmm0
	movl	-96(%rbp), %eax
	movaps	%xmm2, %xmm3
	movaps	%xmm1, %xmm2
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	calculate_employee_net
	pxor	%xmm5, %xmm5
	cvtss2sd	%xmm0, %xmm5
	movsd	%xmm5, -152(%rbp)
	pxor	%xmm4, %xmm4
	cvtss2sd	-36(%rbp), %xmm4
	movsd	%xmm4, -160(%rbp)
	pxor	%xmm3, %xmm3
	cvtss2sd	-40(%rbp), %xmm3
	movsd	%xmm3, -168(%rbp)
	pxor	%xmm6, %xmm6
	cvtss2sd	-44(%rbp), %xmm6
	movsd	%xmm6, -176(%rbp)
	movl	16+employee_tenure_array(%rip), %edx
	movl	16+employee_sales_array(%rip), %ecx
	movss	-120(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %esi
	movd	%esi, %xmm0
	movl	%ecx, %esi
	movl	%eax, %edi
	call	calculate_employee_bonus
	pxor	%xmm7, %xmm7
	cvtss2sd	%xmm0, %xmm7
	movsd	%xmm7, -184(%rbp)
	movl	16+employee_sales_array(%rip), %eax
	movl	.LC10(%rip), %edx
	movd	%edx, %xmm0
	movl	%eax, %edi
	call	calculate_employee_commission
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rax
	movsd	-152(%rbp), %xmm5
	movsd	-160(%rbp), %xmm4
	movsd	-168(%rbp), %xmm3
	movsd	-176(%rbp), %xmm2
	movsd	-184(%rbp), %xmm1
	movq	%rax, %xmm0
	leaq	.LC35(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC31(%rip), %rax
	movq	%rax, %rdi
	movl	$6, %eax
	call	printf@PLT
	leaq	.LC29(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	pxor	%xmm5, %xmm5
	cvtss2sd	-20(%rbp), %xmm5
	movsd	%xmm5, -152(%rbp)
	pxor	%xmm4, %xmm4
	cvtss2sd	-24(%rbp), %xmm4
	movsd	%xmm4, -160(%rbp)
	pxor	%xmm3, %xmm3
	cvtss2sd	-28(%rbp), %xmm3
	movsd	%xmm3, -168(%rbp)
	pxor	%xmm6, %xmm6
	cvtss2sd	-32(%rbp), %xmm6
	movsd	%xmm6, -176(%rbp)
	pxor	%xmm7, %xmm7
	cvtss2sd	-116(%rbp), %xmm7
	movsd	%xmm7, -184(%rbp)
	movl	.LC10(%rip), %eax
	movd	%eax, %xmm0
	leaq	employee_sales_array(%rip), %rax
	movq	%rax, %rdi
	call	calculate_total_commission
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rax
	movsd	-152(%rbp), %xmm5
	movsd	-160(%rbp), %xmm4
	movsd	-168(%rbp), %xmm3
	movsd	-176(%rbp), %xmm2
	movsd	-184(%rbp), %xmm1
	movq	%rax, %xmm0
	leaq	.LC36(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC31(%rip), %rax
	movq	%rax, %rdi
	movl	$6, %eax
	call	printf@PLT
	leaq	.LC29(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	employee_tenure_array(%rip), %rax
	movq	%rax, %rsi
	leaq	employee_sales_array(%rip), %rax
	movq	%rax, %rdi
	call	calculate_net_profit
	pxor	%xmm5, %xmm5
	cvtss2sd	%xmm0, %xmm5
	movq	%xmm5, %rax
	movq	%rax, %xmm0
	leaq	.LC37(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	leaq	.LC38(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC1:
	.long	1055286886
	.align 4
.LC2:
	.long	1028443341
	.align 4
.LC3:
	.long	1036831949
	.align 4
.LC4:
	.long	1120403456
	.align 8
.LC5:
	.long	0
	.long	1079574528
	.align 4
.LC10:
	.long	1040187392
	.align 4
.LC11:
	.long	1041865114
	.align 4
.LC12:
	.long	1033476506
	.ident	"GCC: (GNU) 14.2.1 20250207"
	.section	.note.GNU-stack,"",@progbits
