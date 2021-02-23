#!/bin/bash

minikube start --driver=virtualbox

# Set Docker cmd path from host to minikube
eval $(minikube docker-env)

# MetalLB
minikube addons enable metallb
kubectl apply -f ./srcs/metallb/metallb.yaml
printf "⚓️  MetalLB Done...\n"

# Nginx
docker build -t ft_services-nginx srcs/nginx >> logs.txt
printf "🐳  Building Nginx Docker Image Done...\n"
kubectl apply -f ./srcs/nginx/nginx.yaml >> logs.txt
printf "⚓️  Deploying Nginx Done...\n"

# MySQL
docker build -t ft_services-mysql srcs/mysql >> logs.txt
printf "🐳  Building MySQL Docker Image Done...\n"
kubectl apply -f ./srcs/mysql/mysql.yaml >> logs.txt
printf "⚓️  Deploying MySQL Done...\n"

# phpmyadmin
docker build -t ft_services-phpmyadmin srcs/phpmyadmin >> logs.txt
printf "🐳  Building phpMyAdmin Docker Image Done...\n"
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml >> logs.txt
printf "⚓️  Deploying phpMyAdmin Done...\n"

# Wordpress
docker build -t ft_services-wordpress srcs/wordpress >> logs.txt
printf "🐳  Building WordPress Docker Image Done...\n"
kubectl apply -f ./srcs/wordpress/wordpress.yaml >> logs.txt
printf "⚓️  Deploying WordPress Done...\n"

# ftps
docker build -t ft_services-ftps srcs/ftps >> logs.txt
printf "🐳  Building FTPS Docker Image Done...\n"
kubectl apply -f ./srcs/ftps/ftps.yaml >> logs.txt
printf "⚓️  Deploying FTPS Done...\n"

# influxdb
docker build -t ft_services-influxdb srcs/influxdb >> logs.txt
printf "🐳  Building InfluxDB Docker Image Done...\n"
kubectl apply -f ./srcs/influxdb/influxdb.yaml >> logs.txt
printf "⚓️  Deploying InfluxDB Done...\n"

# telegraf
docker build -t ft_services-telegraf srcs/telegraf >> logs.txt
printf "🐳  Building Telegraf Docker Image Done...\n"
kubectl apply -f ./srcs/telegraf/telegraf.yaml >> logs.txt
printf "⚓️  Deploying Telegraf Done...\n"

# grafana
docker build -t ft_services-grafana srcs/telegraf >> logs.txt
printf "🐳  Building Grafana Docker Image Done...\n"
kubectl apply -f ./srcs/grafana/grafana.yaml >> logs.txt
printf "⚓️  Deploying Grafana Done...\n"

# Show IP address can be accssed
echo "⭐️ ft_services IP: 192.168.99.100"
