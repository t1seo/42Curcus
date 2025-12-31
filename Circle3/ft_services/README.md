# ft_services

## 프로젝트 개요

ft_services는 Kubernetes를 사용하여 다양한 서비스를 클러스터로 배포하는 프로젝트입니다. 컨테이너 오케스트레이션, 서비스 디스커버리, 로드 밸런싱 등을 학습합니다.

## 기술 스택

- **Container Runtime**: Docker
- **Orchestration**: Kubernetes (Minikube)
- **Services**:
  - Nginx (리버스 프록시, SSH)
  - MySQL (데이터베이스)
  - WordPress (CMS)
  - phpMyAdmin (DB 관리)
  - Grafana (모니터링)
  - InfluxDB (메트릭 저장)
  - FTPS (파일 전송)

## 구조

```
ft_services/
├── setup.sh         # 클러스터 설정 스크립트
├── logs.txt         # 로그 파일
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

## Kubernetes 기본 개념

### Pod
가장 작은 배포 단위, 하나 이상의 컨테이너를 포함

### Service
Pod에 대한 네트워크 접근을 제공
- **ClusterIP**: 내부 통신용
- **NodePort**: 외부에서 접근 가능
- **LoadBalancer**: 외부 로드 밸런서 사용

### Deployment
Pod의 복제본(ReplicaSet) 관리

### ConfigMap / Secret
설정 정보 및 민감한 데이터 저장

## 주요 kubectl 명령어

```bash
# 클러스터 상태 확인
kubectl get nodes
kubectl get pods
kubectl get services
kubectl get deployments

# 리소스 생성/삭제
kubectl apply -f nginx.yaml
kubectl delete -f nginx.yaml

# 로그 확인
kubectl logs <pod-name>

# Pod 접속
kubectl exec -it <pod-name> -- /bin/sh

# 포트 포워딩
kubectl port-forward <pod-name> 8080:80
```

## 서비스 포트 구성

| 서비스 | 내부 포트 | 외부 포트 | 프로토콜 |
|--------|-----------|-----------|----------|
| Nginx HTTP | 80 | 80 | HTTP |
| Nginx HTTPS | 443 | 443 | HTTPS |
| Nginx SSH | 22 | 22 | SSH |
| MySQL | 3306 | - | MySQL |
| WordPress | 5050 | 5050 | HTTP |
| phpMyAdmin | 5000 | 5000 | HTTP |
| Grafana | 3000 | 3000 | HTTP |
| InfluxDB | 8086 | 8086 | HTTP |
| FTPS | 21 | 21 | FTP |

## 실행 방법

```bash
# Minikube 시작
minikube start --driver=docker

# 환경 설정
eval $(minikube docker-env)

# 서비스 배포
./setup.sh

# 대시보드 확인
minikube dashboard

# 서비스 URL 확인
minikube service list
```

## 모니터링 구성

### InfluxDB
- 메트릭 데이터 저장소
- Telegraf로 데이터 수집

### Grafana
- InfluxDB 데이터 시각화
- 대시보드 구성

## 헬스 체크

각 서비스는 livenessProbe와 readinessProbe를 설정해야 합니다:

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

## 자동 재시작

Pod가 충돌하면 Kubernetes가 자동으로 재시작합니다:

```yaml
spec:
  restartPolicy: Always
```

## MetalLB (LoadBalancer)

Minikube에서 LoadBalancer 서비스를 사용하기 위한 구성:

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
