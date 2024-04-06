FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y cmake git build-essential libomp-dev

RUN git clone https://github.com/google/googletest.git /googletest && \
    cd /googletest && \
    cmake . && \
    make && \
    make install

WORKDIR /app

COPY . /app/

CMD ["/app/compile_run.sh"]

