# construction img docker
  docker build -t test .

# lancement docker
  docker run -p 5050:5050 test

# clear all docker img
  docker system prune

# liste docker actif
  docker ps

# stop docker
  docker stop "id conteneur"

# test URL
  http://127.0.0.1:5050/