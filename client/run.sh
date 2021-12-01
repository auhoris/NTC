#!/bin/sh
docker run -d --rm --name client --network=host -h 127.0.0.1 ntc_client
sleep 1
docker cp client:/NTC/students_result.txt .
