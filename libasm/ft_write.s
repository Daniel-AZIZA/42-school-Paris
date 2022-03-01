# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daziza <daziza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 19:53:42 by daziza            #+#    #+#              #
#    Updated: 2021/03/13 19:53:44 by daziza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BITS 64

global ft_write
extern __errno_location

ft_write :
	mov 	rax, 1			; on met write dans RAX
	syscall 			; on appel write
	cmp	rax, 0			; on compare le retour du syscall avec 0
	jl	error			; si rax < 0 on va error
	ret				; sinon on renvoie la valeur de write

 error 	 :
	neg 	rax			; errno renvoie valeur neg
	mov	rdi, rax		; on stock rax dans rdi car rax <- errno_location 
	call	__errno_location	; EL va renvoyer un pointeur sur errno
	mov 	[rax], rdi		; on met rdi dans errno car rax contient son adresse	
	mov 	rax, -1			; on met -1 dans rax pour le return
	ret

