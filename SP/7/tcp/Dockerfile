FROM ubuntu
RUN apt update && apt install -y gcc
COPY . .
RUN gcc tcp_server.c -o tcp_server
CMD ./tcp_server
