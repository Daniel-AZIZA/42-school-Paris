#!/bin/sh

# lancement sshd nginx
rc-service start nginx 
rc-service start sshd

# maintien connexion
tail -f /dev/null
