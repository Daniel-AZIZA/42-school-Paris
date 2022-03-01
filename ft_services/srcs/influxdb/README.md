# construction img docker
docker build -t test .

# stop docker
docker stop "id conteneur"

# docker liste
docker ps -a

# sup docker
docker system prune

# lancement img avec port
docker run -p 8086:8086 test

# kill docker qui tourne
docker kill $(docker ps -q)

# test url
http://127.0.0.1:8086
