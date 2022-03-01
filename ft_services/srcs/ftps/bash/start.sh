#!/bin/sh

# start vsftpd, maintien connexion
rc-service vsftpd restart
tail -f /dev/null

