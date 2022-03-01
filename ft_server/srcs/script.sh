#! /bin/bash

if [ $AUTOINDEX != 1 ]
then
	sed -Ei "s/autoindex on;/autoindex off;/" /etc/nginx/sites-available/localhost_conf
fi

rm etc/nginx/sites-enabled/default

ln -s /etc/nginx/sites-available/localhost_conf /etc/nginx/sites-enabled/localhost_conf

mkdir /var/www/localhost

chown -R www-data:www-data /var/www/localhost

#mysql
service mysql start

echo "CREATE DATABASE wp_database;" | mysql -u root
#endmysql

#phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
tar xf phpMyAdmin-4.9.0.1-all-languages.tar.gz
mv phpMyAdmin-4.9.0.1-all-languages var/www/localhost/phpmyadmin
mv ./config.inc.php var/www/localhost/phpmyadmin
chmod 660 /var/www/localhost/phpmyadmin/config.inc.php
chown -R www-data:www-data /var/www/localhost/phpmyadmin
service php7.3-fpm start
echo "GRANT ALL ON *.* TO 'daniel'@'localhost' IDENTIFIED BY '123'" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root
#end_phpmyadmin

#WORDPRESS
tar xf latest.tar.gz
mkdir var/www/localhost/wordpress
cp -a wordpress/. /var/www/localhost/wordpress
chown -R  www-data:www-data /var/www/localhost/wordpress
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=Fr/ST=Paris/L=Paris/O=42/OU=42/CN=localhost"
#endWordpress

service mysql restart
service php7.3-fpm restart

nginx

#bash

sleep infinity
