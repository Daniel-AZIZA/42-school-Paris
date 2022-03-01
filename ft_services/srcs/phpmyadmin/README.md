# construction img docker
docker build -t test .

# lancement img avec port
docker run -p 5000:5000 test

# kill docker qui tourne
docker kill $(docker ps -q)

# test url
http://127.0.0.1:5000

# lien phpmyadmin alpine
https://wiki.alpinelinux.org/wiki/PhpMyAdmin
