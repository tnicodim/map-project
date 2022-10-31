FROM gcc:latest
WORKDIR /usr/src/8rooks
RUN apt-get update
RUN apt-get install -y locales locales-all
ENV LC_ALL en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8
COPY chess_main.cpp .
RUN g++ -o 8rooks chess_main.cpp
CMD ["./8rooks"]