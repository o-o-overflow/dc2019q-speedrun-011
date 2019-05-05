from ubuntu:18.04
run echo "travis_fold:start:Dapt\033[33;1mservice Dockerfile apt\033[0m" &&     apt-get -qq update && apt-get install -qq xinetd libseccomp-dev &&     echo "\ntravis_fold:end:Dapt\r"


copy speedrun-011 /
run chmod 755 /speedrun-011

run touch /flag && chmod 644 /flag && echo "OOO{Why___does_th0r__need_a_car?}" > /flag
copy service.conf /service.conf
copy wrapper /wrapper

expose 31337

cmd ["/usr/sbin/xinetd", "-filelog", "-", "-dontfork", "-f", "/service.conf"]

