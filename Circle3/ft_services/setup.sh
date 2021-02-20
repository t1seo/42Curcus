#!/bin/bash

# Start the cluster if it is not running
if [[ $(minikube status | grep -c "Running") == 0 ]]
then
	minikube start --driver virtualbox
	minikube addons enable metrics-server # show RAM and CPU usage in dashboard
	minikube addons enable dashboard
	minikube addons enable metallb
fi

# Set Docker cmd path from host to minikube
eval $(minikube docker-env)

# MetalLB
kubectl apply -f ./srcs/metallb/metallb.yaml

# Nginx
docker build -t ft_services-nginx srcs/nginx >> logs.txt
printf "🐳  Building Nginx Docker Image Done...\n"
kubectl apply -f ./srcs/nginx/nginx_secret.yaml >> logs.txt
kubectl apply -f ./srcs/nginx/nginx.yaml >> logs.txt
printf "⚓️  Deploying Nginx Done...\n"

# MySQL
# docker build -t ft_services-nginx srcs/nginx >> logs.txt
# printf "🐳  Building Nginx Docker Image Done...\n"
# kubectl apply -f ./srcs/nginx/nginx_secret.yaml >> logs.txt
# kubectl apply -f ./srcs/nginx/nginx.yaml >> logs.txt
# printf "⚓️  Deploying Nginx Done...\n"

# phpmyadmin

# Wordpress

# ftps

# influxdb

# telegraf

# grafana

# Deploy Services
printf "⚓️  Nginx Done...\n"

# Show IP address can be accssed
echo "⭐️ ft_services IP: 192.168.99.100"
