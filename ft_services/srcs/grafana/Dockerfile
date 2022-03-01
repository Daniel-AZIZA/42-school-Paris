FROM	alpine:3.13.2 
# derniere version alpine

# commande bin /share/grafana
ENV	PATH=/usr/share/grafana/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin 

# repertoire de travail
WORKDIR	/usr/share/grafana

# ajout fichier srcs tmp
ADD ./srcs/ /tmp

# ajout start.sh
ADD ./bash ./

# mise a jour, install grafana
RUN	apk update
RUN	apk add --no-cache libc6-compat
RUN	apk add --no-cache ca-certificates
RUN    	apk add --no-cache --virtual .build-deps wget gnupg tar 
RUN	apk add vim

RUN	mkdir ~/.gnupg;

# install grafana
RUN	wget -q https://dl.grafana.com/oss/release/grafana-7.3.2.linux-amd64.tar.gz; \
	tar -zxf grafana-7.3.2.linux-amd64.tar.gz; \
	cp -r grafana-7.3.2/* .; \
    	addgroup -S grafana; \
    	adduser -S -G grafana grafana; \
	cp /tmp/dashboard.yaml /usr/share/grafana/conf/provisioning/dashboards/; \
	cp /tmp/*.json /usr/share/grafana/conf/provisioning/dashboards/;

# port d'ecoute
EXPOSE 3000

# lancement start.sh
CMD ./start.sh
