FROM ubuntu
RUN apt update && apt install -y gcc
COPY . .
RUN gcc udp_server.c -o udp_server
CMD ./udp_server
