# ft_services

## Project Overview

ft_services is a project to deploy various services as a cluster using Kubernetes. It covers container orchestration, service discovery, and load balancing.

## Tech Stack

- **Container Runtime**: Docker
- **Orchestration**: Kubernetes (Minikube)
- **Services**:
  - Nginx (reverse proxy, SSH)
  - MySQL (database)
  - WordPress (CMS)
  - phpMyAdmin (DB management)
  - Grafana (monitoring)
  - InfluxDB (metrics storage)
  - FTPS (file transfer)

## Structure

```
ft_services/
├── setup.sh         # Cluster setup script
├── logs.txt         # Log file
└── srcs/
    ├── nginx/
    │   ├── Dockerfile
    │   └── nginx.yaml
    ├── mysql/
    │   ├── Dockerfile
    │   └── mysql.yaml
    ├── wordpress/
    │   ├── Dockerfile
    │   └── wordpress.yaml
    ├── phpmyadmin/
    │   ├── Dockerfile
    │   └── phpmyadmin.yaml
    ├── grafana/
    │   ├── Dockerfile
    │   └── grafana.yaml
    ├── influxdb/
    │   ├── Dockerfile
    │   └── influxdb.yaml
    └── ftps/
        ├── Dockerfile
        └── ftps.yaml
```

## Kubernetes Basic Concepts

### Pod
Smallest deployment unit, contains one or more containers

### Service
Provides network access to Pods
- **ClusterIP**: Internal communication
- **NodePort**: Externally accessible
- **LoadBalancer**: Uses external load balancer

### Deployment
Manages Pod replicas (ReplicaSet)

### ConfigMap / Secret
Stores configuration and sensitive data

## Essential kubectl Commands

```bash
# Check cluster status
kubectl get nodes
kubectl get pods
kubectl get services
kubectl get deployments

# Create/Delete resources
kubectl apply -f nginx.yaml
kubectl delete -f nginx.yaml

# Check logs
kubectl logs <pod-name>

# Access Pod
kubectl exec -it <pod-name> -- /bin/sh

# Port forwarding
kubectl port-forward <pod-name> 8080:80
```

## Service Port Configuration

| Service | Internal Port | External Port | Protocol |
|---------|---------------|---------------|----------|
| Nginx HTTP | 80 | 80 | HTTP |
| Nginx HTTPS | 443 | 443 | HTTPS |
| Nginx SSH | 22 | 22 | SSH |
| MySQL | 3306 | - | MySQL |
| WordPress | 5050 | 5050 | HTTP |
| phpMyAdmin | 5000 | 5000 | HTTP |
| Grafana | 3000 | 3000 | HTTP |
| InfluxDB | 8086 | 8086 | HTTP |
| FTPS | 21 | 21 | FTP |

## Execution

```bash
# Start Minikube
minikube start --driver=docker

# Environment setup
eval $(minikube docker-env)

# Deploy services
./setup.sh

# Check dashboard
minikube dashboard

# Check service URLs
minikube service list
```

## Monitoring Setup

### InfluxDB
- Metrics data storage
- Data collection via Telegraf

### Grafana
- InfluxDB data visualization
- Dashboard configuration

## Health Check

Each service should have livenessProbe and readinessProbe configured:

```yaml
livenessProbe:
  httpGet:
    path: /healthz
    port: 80
  initialDelaySeconds: 30
  periodSeconds: 10

readinessProbe:
  httpGet:
    path: /ready
    port: 80
  initialDelaySeconds: 5
  periodSeconds: 5
```

## Auto Restart

Kubernetes automatically restarts Pods when they crash:

```yaml
spec:
  restartPolicy: Always
```

## MetalLB (LoadBalancer)

Configuration for using LoadBalancer services in Minikube:

```yaml
apiVersion: v1
kind: ConfigMap
metadata:
  namespace: metallb-system
  name: config
data:
  config: |
    address-pools:
    - name: default
      protocol: layer2
      addresses:
      - 192.168.49.240-192.168.49.250
```
