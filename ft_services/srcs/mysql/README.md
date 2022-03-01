# stop mysql avant lancement docker
sudo systemctl stop mysql

# construction img docker
docker build -t test .

# stop docker
docker stop "id conteneur"

# sup docker
docker system prune

# lancement img avec port
docker run -p 3306:3306 test

# kill docker qui tourne
docker kill $(docker ps -q)

# user
wp-admin

# identification
admin

# mdp
pass

# test url
http://127.0.0.1:3306
