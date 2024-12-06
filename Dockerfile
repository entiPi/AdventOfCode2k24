FROM debian:trixie

RUN apt update \
    && apt install --yes --no-install-recommends \
      cmake \
      clangd \
      clang-tidy \
      ncat \
      ninja-build \
    && apt clean

EXPOSE 10101
WORKDIR /AoC
