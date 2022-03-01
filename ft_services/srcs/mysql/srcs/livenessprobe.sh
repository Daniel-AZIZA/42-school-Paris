#!/bin/sh

# etat connextion mysql, maintien connexion
service mariadb status
return_mysql=$?
if [ "$return_mysql" = "0" ]; then
	exit 0
else
	exit 1
fi
