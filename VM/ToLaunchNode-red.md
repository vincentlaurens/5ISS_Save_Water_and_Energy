website: https://hub.docker.com/r/nodered/node-red-docker
To create docker container mynodered with docker run command
docker run it -p 1880:1880 --name mynodered nodered/node-red-docker --restart unless-stopped mynodered
start mynodered container
docker start mynodered
stop mynodered container
docker stop mynodered
