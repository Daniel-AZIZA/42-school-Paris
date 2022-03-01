FROM alpine:3.13.2
# derniere version alpine linux

# maintien ngninx dashboard 
ADD ./srcs/ /tmp/

# mise a jour  
 RUN apk update \
 && apk add --no-cache nginx \
 && apk add openssl openrc openssh --no-cache 
 RUN rc-update add sshd default

# config nginx
RUN		adduser -D -g 'www' www; \
		adduser -D user42; \
		echo "user42:user42" | chpasswd; \
		mkdir /www; \
		mkdir -p /run/nginx; \
		mkdir -p /run/sshd; \
		mkdir -p /run/openrc/softlevel; \
		mv tmp/nginx.conf /etc/nginx/nginx.conf; \
		mv tmp/index.html /www/index.html; \
		mv tmp/proxy_params /etc/nginx/proxy_params; \
		rc-status --manual; \
		rc-status --crashed; \ 
		openssl req -x509 -nodes -days 365 -subj "/C=CA/ST=QC/O=user42, Inc./CN=user42" -addext "subjectAltName=DNS:mydomain.com" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

# port d'ecoute 
EXPOSE 80 443 22

#CMD ./start.sh
CMD		\
		rc-service nginx start; \
		rc-service sshd start; \
		tail -f /dev/null;

