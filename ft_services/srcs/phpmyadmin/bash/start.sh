#!/bin/sh

# configuration config.inc.php
sed -i 's/mysql-alpine/'$MYSQL_SERVICE_PORT_3306_TCP_ADDR':3306/g' /www/phpmyadmin/config.inc.php; 
export SECRET=`php -r 'echo base64_encode(random_bytes(24));'`;\
echo "\$cfg['blowfish_secret'] = '$SECRET';" \ >> /www/phpmyadmin/config.inc.php;

# lancement  php 
rc-service php-fpm7 start; 
rc-service nginx start; 
tail -f /dev/null;
