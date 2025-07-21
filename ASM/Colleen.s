	.section .rodata
src:
	.string "%3$s.section .rodata%1$ssrc:%1$s%3$s.string %2$s%5$s%2$s%1$s%1$snewline:%1$s%3$s.byte 10, 0%1$s%1$sdoublequote:%1$s%3$s.byte 34, 0%1$s%1$stab:%1$s%3$s.byte 9, 0%1$s%1$spercent:%1$s%3$s.byte 37, 0%1$s%1$s%3$s.section .text%1$s%3$s.globl main%1$s%3$s.extern printf%1$s%1$sprinter:%1$s%3$spush %4$srbp%1$s%3$smov %4$srsp, %4$srbp%1$s%1$s%3$slea src(%4$srip), %4$srax%1$s%1$s%3$spop %4$srbp%1$s%3$sret%1$s%1$smain:%1$s#Main comment%1$s%3$spush %4$srbp%1$s%3$smov %4$srsp, %4$srbp%1$s%1$s%3$scall printer%1$s%3$smov %4$srax, %4$srdi%1$s%3$smov %4$srax, %4$sr9%1$s%3$slea newline(%4$srip), %4$srsi%1$s%3$slea doublequote(%4$srip), %4$srdx%1$s%3$slea tab(%4$srip), %4$srcx%1$s%3$slea percent(%4$srip), %4$sr8%1$s%3$smov $0, %4$srax%1$s%3$scall printf%1$s%1$s%3$smov $0, %4$seax%1$s%3$spop %4$srbp%1$s%3$sret%1$s%1$s.section .note.GNU-stack,%2$s%2$s,@progbits%1$s%1$s#Outside comment%1$s"

newline:
	.byte 10, 0

doublequote:
	.byte 34, 0

tab:
	.byte 9, 0

percent:
	.byte 37, 0

	.section .text
	.globl main
	.extern printf

printer:
	push %rbp
	mov %rsp, %rbp

	lea src(%rip), %rax

	pop %rbp
	ret

main:
#Main comment
	push %rbp
	mov %rsp, %rbp

	call printer
	mov %rax, %rdi
	mov %rax, %r9
	lea newline(%rip), %rsi
	lea doublequote(%rip), %rdx
	lea tab(%rip), %rcx
	lea percent(%rip), %r8
	mov $0, %rax
	call printf

	mov $0, %eax
	pop %rbp
	ret

.section .note.GNU-stack,"",@progbits

#Outside comment
