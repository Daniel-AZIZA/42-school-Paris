#!/bin/sh

# influx base de donnee, maintien connexion
influx -database 'docker_metrics' -execute 'select * from cpu' -format 'json' -pretty;
return_influx="$?"
if [ "$return_influx" = "0" ]; then
	exit 0
else
	exit 1
fi
