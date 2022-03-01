FROM	alpine:3.13.2

# ajout start.sh
ADD ./bash ./

# ajout fichier config
ADD ./srcs /srcs

# mise a jour, install packet additionnel
RUN apk update
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli \
php7-zlib php7-curl php7-mbstring php7-json php7-session
RUN apk add --no-cache nginx
RUN apk add --no-cache phpmyadmin openrc

# config phpmyadmin 
RUN mkdir -p /run/nginx
RUN mkdir -p /run/php-fpm7
RUN mkdir /run/openrc
RUN touch /run/openrc/softlevel
RUN adduser -D -g 'www' www
RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www
RUN mv /srcs/nginx.conf /etc/nginx/nginx.conf
RUN mv /srcs/index.html /www/index.html
RUN chmod -R 777 /usr/share/webapps/
RUN chown -R www:www /etc/phpmyadmin
RUN ln -s /usr/share/webapps/phpmyadmin /www/phpmyadmin 
RUN rc-status --manual \
rc-status --crashed
RUN mv /srcs/config.inc.php /www/phpmyadmin

# port d'ecoute
EXPOSE	5000

# lancement start.sh
CMD ./start.sh
