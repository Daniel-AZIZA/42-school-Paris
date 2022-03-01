FROM 	alpine:3.13.2
# derniere version alpine linux

# ajout livenessptobe tmp
ADD /srcs/livenessprobe.sh /tmp

# ajout fichier wordpress
COPY	srcs/my.cnf ./
COPY 	srcs/wordpress.sql ./

# ajout start.sh
COPY 	/bash/start.sh ./

# update, install mysql
RUN  	apk update
RUN 	apk add openrc --no-cache
RUN 	apk add --no-cache mysql mysql-client \
	&& apk add mariadb mariadb-client && apk add --no-cache --upgrade bash \
	&& rm -rf /var/cache/apk/*

# config mysql
RUN 	mkdir -p /run/mysqld && \
		mv my.cnf /etc/

# rajout openrx
RUN	mkdir -p /run/openrc \
	touch /run/openrc/softlevel

#port de defaut de mysql
EXPOSE	 3306

# lancement start.sh
CMD  	 ./start.sh
