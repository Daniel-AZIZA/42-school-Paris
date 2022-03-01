# construction img docker
docker build -t test .

# lancement img av&ec port
docker run -p 21:21 test

# kill docker qui tourne
docker kill $(docker ps -q)

# test url
ftp://127.0.0.1:21

# ip vsfttpd.conf
172.17.0.4

-username : user42
-pass : user42

ip conf : 172.15.0.4