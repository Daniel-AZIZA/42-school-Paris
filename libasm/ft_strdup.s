# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daziza <daziza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 19:53:31 by daziza            #+#    #+#              #
#    Updated: 2021/03/13 19:53:33 by daziza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BITS 64

global	ft_strdup
extern	ft_strlen
extern	ft_strcpy
extern	malloc
extern	__errno_location

ft_strdup :
		call	ft_strlen		; appel de ft_strlen(*s1)
		inc	rax			; rax contient la length de s1 donc on fait +1 pour le \0
		push	rdi			; rdi contient s1 on le push en haut de la pile pour pas le perdre
		mov	rdi, rax		; malloc va prendre rdi il doit donc avoir la bonne length
		call	malloc			; appel de malloc qui renverra un pointeur sur rax
		cmp	rax, 0			; check si malloc a fail --> ZF = 1
		jz	error			; si ZF = 1 --> error
		mov	rdi, rax		; on remet rax dans rdi pour qu'il ai la bonne length pour ft_strcpy
		pop	rsi			; on met s1 dans rsi(s2) pour le copier dans rdi(s1)
		call 	ft_strcpy		; copie de rsi(s2) dans rdi(s1)
		ret				; return rax qui contient le retour de ft_strcpy

error	:
		neg	rax			; car l'appel de malloc va mettre dans rax errno mais en neg
		mov	rdi, rax		; stockage de rax dans rdi
		call	__errno_location	; appel de errno qui va mettre dans rax un pointeur sur errno
		mov	[rax], rdi		; on met la valeur de rdi dans rax
		mov	rax, -1			; rax = -1 pour renvoyer la bonne valeur d'un appel à strdup
		ret				; return rax
				
