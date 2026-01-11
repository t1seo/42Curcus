# ft_server

## Project Overview

ft_server is a project to build a complete web server environment using Docker. It sets up a LEMP stack including Nginx, MariaDB, phpMyAdmin, and WordPress in a single Docker container.

## Tech Stack

- **OS**: Debian Buster
- **Web Server**: Nginx
- **Database**: MariaDB
- **Language**: PHP 7.3
- **CMS**: WordPress
- **DB Admin**: phpMyAdmin
- **SSL**: OpenSSL (self-signed certificate)

## Features

- HTTPS (SSL/TLS) support
- WordPress blog hosting
- Database management via phpMyAdmin
- Autoindex toggle functionality

## Structure

```
ft_server/
├── Dockerfile           # Docker image definition
└── srcs/
    ├── run.sh          # Container startup script
    ├── default         # Nginx configuration file
    ├── wp-config.php   # WordPress configuration
    └── config.inc.php  # phpMyAdmin configuration
```

## Dockerfile Explanation

```dockerfile
FROM debian:buster              # Base image

# Install required packages
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    mariadb-server \
    php-mysql \
    php-mbstring \
    php7.3-fpm \
    wget

# Copy configuration files
COPY ./srcs/run.sh ./
COPY ./srcs/default ./tmp
COPY ./srcs/wp-config.php ./tmp
COPY ./srcs/config.inc.php ./tmp

# Expose ports
EXPOSE 80 443

# Startup command
CMD bash run.sh
```

## Build and Run

```bash
# Build Docker image
docker build -t ft_server .

# Run container
docker run -d -p 80:80 -p 443:443 --name ft_server ft_server

# Access container
docker exec -it ft_server bash

# Stop container
docker stop ft_server

# Remove container
docker rm ft_server
```

## Access URLs

| Service | URL |
|---------|-----|
| WordPress | https://localhost |
| phpMyAdmin | https://localhost/phpmyadmin |

## Autoindex Toggle

```bash
# Inside container
# Enable autoindex
sed -i 's/autoindex off/autoindex on/g' /etc/nginx/sites-available/default
nginx -s reload

# Disable autoindex
sed -i 's/autoindex on/autoindex off/g' /etc/nginx/sites-available/default
nginx -s reload
```

## SSL Certificate Generation

```bash
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt
```

## Main Nginx Configuration

```nginx
server {
    listen 80;
    listen [::]:80;
    return 301 https://$host$request_uri;    # HTTP → HTTPS redirect
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

## Troubleshooting

### 502 Bad Gateway
- Check if PHP-FPM is running: `service php7.3-fpm status`

### Database Connection Failed
- Check MariaDB status: `service mysql status`
- Verify permissions: `mysql -u root -p`

### SSL Warning
- Self-signed certificate causes browser warning (normal)
