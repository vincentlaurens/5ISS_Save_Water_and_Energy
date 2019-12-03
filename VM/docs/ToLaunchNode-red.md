# Launch Docker container Node-Red on VM
(Normally it is launch on boot however this document explain how to install it on VM if we encounter an issue)

We have created on our VM a container "Docker" to launch the service Node-Red

You can get more information on the docker hub official website: https://hub.docker.com/r/nodered/node-red-docker

## Creation of docker container

1) To create docker container mynodered with docker run command (already done/ already installed)
`docker run it -p 1880:1880 --name mynodered nodered/node-red-docker --restart unless-stopped mynodered`
2) Start mynodered container
`docker start mynodered`
3) Stop mynodered container
`docker stop mynodered`
4) Delete mynodered container
`docker rm mynodered`

