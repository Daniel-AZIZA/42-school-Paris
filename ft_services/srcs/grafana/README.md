# construction img docker
  sudo docker build -t test .

# lancement docker avec port specifier
  sudo docker run -p 3000:3000 test

# clear all docker img
  sudo docker system prune

# liste docker
  sudo docker ps

# stop docker
  sudo docker stop "id conteneur"

# test url
http://127.0.0.1:3000

# database
  grafana
  
# user par default
  admin

# mot de passe par default
  admin