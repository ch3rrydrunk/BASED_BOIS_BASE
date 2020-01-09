# From an alpine image you’ll add to your container your favorite text editor, vim or
# emacs, that will launch along with your container.
FROM alpine:latest
RUN apk update && apk add vim
ENTRYPOINT vim

# To build: docker build .
# To run: docker build .