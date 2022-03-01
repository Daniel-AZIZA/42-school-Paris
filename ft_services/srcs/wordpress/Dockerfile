FROM alpine:3.13.2

# ajout fichier config
ADD ./srcs/ /tmp/

# ajout start.sh
ADD /bash/ ./

# mise a jour alpine, install paquet php
RUN apk update && apk add wget && mkdir /www \
&& apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session
RUN apk add --no-cache nginx 
RUN apk add openssl openrc openssh --no-cache 

# config fichier wordpress
RUN		\
		mkdir -p /run/nginx; \
		mkdir -p /run/php-fpm7; \
		adduser -D -g 'www' www; \
		mkdir /run/openrc; \
		touch /run/openrc/softlevel; \
		mkdir -p /www; \
		chown -R www:www /var/lib/nginx;\
		chown -R www:www /www; \
		mv /tmp/nginx.conf /etc/nginx/nginx.conf; \
		mv /tmp/index.html /www/index.html; \
		cd www; \
		wget -q http://wordpress.org/latest.tar.gz; \
		tar -xzf latest.tar.gz; \
		rm latest.tar.gz; \
		rc-status --manual;\
		rc-status --crashed; \
		mv /tmp/wp-config.php /www/wordpress/;

# port d'ecoute 5050
EXPOSE 5050

# lancement start.sh
CMD ./start.sh
