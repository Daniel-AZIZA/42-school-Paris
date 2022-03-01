# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daziza <daziza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 19:53:38 by daziza            #+#    #+#              #
#    Updated: 2021/03/13 19:53:39 by daziza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BITS 64

global	ft_strlen

ft_strlen :
	mov	rcx, 0			; on initialise rcx qui est notre compteur à 0

loop	:
	cmp	byte[rdi + rcx], 0	; on compare notre octet avec \0, si égal --> ZF = 1
	jz	return			; si ZF = 1 go return 
	inc	rcx			; incrémentation de rcx
	jmp	loop			; retourn au début du loop

return	:
	mov	rax, rcx		; on met rcx dans rax car c'est lui qui est return
	ret
