FROM ubuntu
RUN apt update && apt install -y g++
COPY main.cpp .
RUN g++ main.cpp -std=c++17 -pthread
RUN mkdir /hello
CMD ./a.out /etc /hello && ls /hello
