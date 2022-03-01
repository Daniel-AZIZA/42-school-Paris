FROM alpine:3.13.2
#derniere version alpine

# ajout fichier tmp
ADD ./srcs /tmp/


# ajout start.sh 
COPY bash/start.sh ./

# mise a jour, install packet
RUN apk update
RUN apk --no-cache add vsftpd openssl openrc curl

RUN		\
		openssl \
			req \
			-new \
			-x509 \
			-days 365 \
			-nodes \
			-subj "/C=CA/ST=QC/O=Company, Inc./CN=user42" \
			-addext "subjectAltName=DNS:user42" \
			-newkey rsa:2048 \
			-out /etc/ssl/private/vsftpd.cert.pem \
			-keyout /etc/ssl/private/vsftpd.key.pem; \
		chown root:root /etc/ssl/private/vsftpd.cert.*; \
		chmod 600 /etc/ssl/private/vsftpd.cert.*; \
		mkdir -p /run/openrc; \
		touch /run/openrc/softlevel; \
		rc-status --manual; \
		rc-status --crashed; \
		cp /tmp/vsftpd.conf /etc/vsftpd/; \
		echo root:pass | chpasswd; \
		/etc/init.d/vsftpd restart;

# port d'ecoute
EXPOSE 21 20 

# lancement start.sh
CMD ./start.sh
