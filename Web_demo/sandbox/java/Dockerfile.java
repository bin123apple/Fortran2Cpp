FROM openjdk:11-jdk

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    git \
    maven \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

CMD ["/app/compile_run.sh"]
