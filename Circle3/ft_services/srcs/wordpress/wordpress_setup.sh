# chown -R www-data /var/www/*
chmod -R 755 /var/www/*

mkdir -p /var/www/html
touch /var/www/html/index.php
echo "<?php phpinfo(); ?>" >> /var/www/html/index.php

mkdir -p /etc/nginx/sites-available/
mkdir -p /etc/nginx/sites-enabled/

mysql -hmysql -Dwordpress -utseo -ptseo < /run/nginx/wordpress.sql
