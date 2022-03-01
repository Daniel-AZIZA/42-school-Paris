# stop nginx pr pouvoir lancer le docker run
  sudo systemctl stop nginx    

# construction img docker
  sudo docker build -t test .

# lancement img bash
  sudo docker run -it test bash

# lancement docker avec port specifier
  sudo docker run -it -p 80:80 -p 443:443 test

# clear all docker img
  sudo docker system prune

# liste docker
  sudo docker ps -a

# stop docker
  sudo docker stop "id conteneur"
  
# redirection erreur 307 sujet a gerer

# lien install nginx alpine linux :
 https://wiki.alpinelinux.org/wiki/Nginx

# lien openssl alpine
 https://exampleconfig.com/openssl-alpine-etc-ssl-openssl.cnf/	