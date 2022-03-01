# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daziza <daziza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 19:53:24 by daziza            #+#    #+#              #
#    Updated: 2021/03/13 19:53:25 by daziza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BITS 64 

global	ft_strcpy

ft_strcpy :
		mov	rax, 0
		mov	rcx, 0

loop :
		cmp	byte[rsi + rcx], 0	; on check si l'octet == \0 --> ZF = 1
		jz	return			; ZF = 1 donc go return
		mov	dl, byte[rsi + rcx]	; on copie dans dl car il fait 1 octet
		mov	byte[rdi + rcx], dl	; on copie dans l'octet dans la chaine dest
		inc	rcx			; rcx++
		jmp	loop

return :
		mov	byte[rdi + rcx], 0	; ajout du \0
		mov	rax, rdi		; copie de char *dest dans rax
		ret				; return rax
