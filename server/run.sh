#!/bin/sh
docker run -d --rm --name server -p 127.0.0.1:5556:5556 ntc_server
