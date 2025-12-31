# ft_server

## 프로젝트 개요

ft_server는 Docker를 사용하여 완전한 웹 서버 환경을 구축하는 프로젝트입니다. Nginx, MariaDB, phpMyAdmin, WordPress를 포함한 LEMP 스택을 단일 Docker 컨테이너에 설정합니다.

## 기술 스택

- **OS**: Debian Buster
- **Web Server**: Nginx
- **Database**: MariaDB
- **Language**: PHP 7.3
- **CMS**: WordPress
- **DB Admin**: phpMyAdmin
- **SSL**: OpenSSL (자체 서명 인증서)

## 기능

- HTTPS (SSL/TLS) 지원
- WordPress 블로그 호스팅
- phpMyAdmin을 통한 데이터베이스 관리
- autoindex 토글 기능

## 구조

```
ft_server/
├── Dockerfile           # Docker 이미지 정의
└── srcs/
    ├── run.sh          # 컨테이너 시작 스크립트
    ├── default         # Nginx 설정 파일
    ├── wp-config.php   # WordPress 설정
    └── config.inc.php  # phpMyAdmin 설정
```

## Dockerfile 설명

```dockerfile
FROM debian:buster              # 베이스 이미지

# 필요한 패키지 설치
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    mariadb-server \
    php-mysql \
    php-mbstring \
    php7.3-fpm \
    wget

# 설정 파일 복사
COPY ./srcs/run.sh ./
COPY ./srcs/default ./tmp
COPY ./srcs/wp-config.php ./tmp
COPY ./srcs/config.inc.php ./tmp

# 포트 노출
EXPOSE 80 443

# 시작 명령
CMD bash run.sh
```

## 빌드 및 실행

```bash
# Docker 이미지 빌드
docker build -t ft_server .

# 컨테이너 실행
docker run -d -p 80:80 -p 443:443 --name ft_server ft_server

# 컨테이너 접속
docker exec -it ft_server bash

# 컨테이너 중지
docker stop ft_server

# 컨테이너 삭제
docker rm ft_server
```

## 접속 URL

| 서비스 | URL |
|--------|-----|
| WordPress | https://localhost |
| phpMyAdmin | https://localhost/phpmyadmin |

## autoindex 토글

```bash
# 컨테이너 내에서
# autoindex 켜기
sed -i 's/autoindex off/autoindex on/g' /etc/nginx/sites-available/default
nginx -s reload

# autoindex 끄기
sed -i 's/autoindex on/autoindex off/g' /etc/nginx/sites-available/default
nginx -s reload
```

## SSL 인증서 생성

```bash
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt
```

## Nginx 설정 주요 항목

```nginx
server {
    listen 80;
    listen [::]:80;
    return 301 https://$host$request_uri;    # HTTP → HTTPS 리다이렉트
}

server {
    listen 443 ssl;
    listen [::]:443 ssl;

    ssl_certificate /etc/ssl/certs/nginx-selfsigned.crt;
    ssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;

    root /var/www/html;
    index index.php index.html;

    location ~ \.php$ {
        include snippets/fastcgi-php.conf;
        fastcgi_pass unix:/run/php/php7.3-fpm.sock;
    }
}
```

## 트러블슈팅

### 502 Bad Gateway
- PHP-FPM이 실행 중인지 확인: `service php7.3-fpm status`

### 데이터베이스 연결 실패
- MariaDB 실행 확인: `service mysql status`
- 권한 확인: `mysql -u root -p`

### SSL 경고
- 자체 서명 인증서이므로 브라우저에서 경고가 표시됨 (정상)
