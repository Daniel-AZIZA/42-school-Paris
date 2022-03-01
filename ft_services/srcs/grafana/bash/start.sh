#!/bin/sh

# lancement grafana
sed -i 's/influxdb-alpine/'$INFLUXDB_SERVICE_PORT_8086_TCP_ADDR'/g' /tmp/datasource.yaml
cp /tmp/datasource.yaml /usr/share/grafana/conf/provisioning/datasources/ 
grafana-server --homepath=/usr/share/grafana
grafana-server --config=/tmp/grafana.ini
grafana-server --packaging=docker 
"$@";
