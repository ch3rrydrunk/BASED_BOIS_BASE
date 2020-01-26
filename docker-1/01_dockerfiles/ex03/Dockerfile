# Docker can be useful to test an application that’s still being developed without polluting your libraries. You will have to design a Dockerfile that gets the development
# version of Gitlab - Community Edition installs it with all the dependencies and the necessary configurations, and launches the application, all as it builds. The container will be
# deemed valid if you can access the web client, create users and interact via GIT with this
# container (HTTPS and SSH). Obviously, you are not allowed to use the official container
# from Gitlab, it would be a shame...
FROM ubuntu:latest

# Install required packages
RUN apt-get update -q \
		&& DEBIAN_FRONTEND=noninteractive apt-get install -yq --no-install-recommends \
		ca-certificates postfix openssh-server wget apt-transport-https vim tzdata curl sudo gnupg\
		&& rm -rf /var/lib/apt/lists/* ;\
        rm -rf /etc/update-motd.d /etc/motd /etc/motd.dynamic ; ln -fs /dev/null /run/motd.dynamics

ENV PATH /opt/gitlab/embedded/bin:/opt/gitlab/bin:/assets:$PATH
EXPOSE 443 80 22
VOLUME ["/etc/gitlab", "/var/opt/gitlab", "/var/log/gitlab"]

# Gitlab CE package
RUN curl -sS https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
RUN EXTERNAL_URL="127.0.0.1:80" apt-get install -yq gitlab-ce

ENTRYPOINT 'sudo gitlab-ctl reconfigure'

# To build: docker build -t gitlab_box .
# To run: docker run gitlab_box
