# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daziza <daziza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 19:53:13 by daziza            #+#    #+#              #
#    Updated: 2021/03/13 19:53:17 by daziza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BITS 64

section	.text

global	ft_strcmp

ft_strcmp:						; s1 = rdi, s2 = rsi
		xor		rcx, rcx		; i = 0
		xor		rdx, rdx		; cmp = 0
		cmp		rdi, 0			; !s1
		jz		check_null
		cmp		rsi, 0			; !s2
		jz		check_null
		jmp		check
check_null:
		cmp		rdi, rsi
		jz		equal			; s1 == s2 (NULL)
		jg		superior		; s1 == NULL
		jmp		inferior		; s2 == NULL
compare:
		mov		dl, BYTE [rsi + rcx]	; tmp = s2[i]
		cmp		BYTE [rdi + rcx], dl	; s1[i] == tmp
		jne		last_char
increment:
		inc		rcx
check:
		cmp		BYTE [rdi + rcx], 0	; !s1[i]
		je		last_char
		cmp		BYTE [rsi + rcx], 0	; !s2[i]
		je		last_char
		jmp		compare
last_char:
		mov		dl, BYTE [rdi + rcx]	; cmp = s1[i]
		sub		dl, BYTE [rsi + rcx]	; cmp -= s2[i]
		cmp		dl, 0			; cmp == 0
		jz		equal
		jl		inferior
superior:
		mov		rax, 1
		ret
inferior:
		mov		rax, -1			; ret < 0
		ret
equal:
		mov		rax, 0			; ret > 0
		ret
