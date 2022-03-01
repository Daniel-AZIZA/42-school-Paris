FROM debian:buster

RUN apt-get update
RUN apt-get install -y wget nginx mariadb-server php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline php7.3-cgi php7.3-mbstring

ARG autoindex=1

ENV AUTOINDEX $autoindex

COPY srcs/localhost_conf etc/nginx/sites-available
COPY srcs/latest.tar.gz /
COPY srcs/config.inc.php /
COPY srcs/script.sh /

CMD ["bash", "script.sh"]
