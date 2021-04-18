FROM ubuntu
RUN apt update && apt install -y g++
COPY main.cpp .
COPY main2.cpp .

RUN g++ main.cpp -o 1.elf
RUN g++ main2.cpp -o 2.elf -std=c++17

RUN mkdir /hello
CMD ./2.elf /etc /hello && ls /hello
