FROM mhart/alpine-node:4

# Home directory for Node-RED application source code.
RUN mkdir -p /root/ilya/node-red

# User data directory, contains flows, config and nodes.
RUN mkdir -p /data/nodered

WORKDIR /root/ilya/service/node-red/service

# Add node-red user so we aren't running as root.
RUN adduser -h /usr/src/node-red -D -H node-red \
    && chown -R node-red:node-red /data/nodered \
    && chown -R node-red:node-red /root/ilya/service/node-red/service

USER node-red

# package.json contains Node-RED NPM module and node dependencies
COPY package.json /root/ilya/service/node-red/service
RUN npm install

# User configuration directory volume
VOLUME ["/data/nodered"]
EXPOSE 1880

# Environment variable holding file path for flows configuration
ENV FLOWS=flows.json

CMD ["npm", "start", "--", "--userDir", "/data/nodered"]
