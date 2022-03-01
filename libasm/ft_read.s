# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daziza <daziza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 19:48:50 by daziza            #+#    #+#              #
#    Updated: 2021/03/13 19:50:05 by daziza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BITS 64

global	ft_read
extern	__errno_location

ft_read : 		; cf ft_write pour l'explication du code car identique
	mov	rax, 0	; syscall write
	syscall
	cmp	rax, 0
	jl	error
	ret

error	:
	neg	rax
	mov	rdi, rax
	call	__errno_location
	mov	[rax], rdi
	mov	rax, -1
	ret
