#!/bin/sh

sed -i 's/mysql-alpine/'$MYSQL_SERVICE_PORT_3306_TCP_ADDR':3306/g' /www/wordpress/wp-config.php
# lancement  php

rc-service php-fpm7 start; 
rc-service nginx start; 
tail -f /dev/null;

