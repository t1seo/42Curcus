FROM alpine:3.12.0

RUN apk update \
		&& apk --update --no-cache add \
				bash \
				vsftpd \
				openssl

# ARG PASV=${pasv_address}

ENV FTP_USER=tseo \
    FTP_PASS=tseo
	#     PASV_ENABLE=YES \
    # PASV_MIN_PORT=20000 \
    # PASV_MAX_PORT=20003 \
	# NODE_ADDRESS=${PASV}

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY ftps_setup.sh /usr/sbin/
RUN chmod +x /usr/sbin/ftps_setup.sh

EXPOSE 20 21 20000-20004
ENTRYPOINT [ "/usr/sbin/ftps_setup.sh" ]
