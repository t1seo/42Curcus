FROM alpine:3.12.0

RUN apk update && \
	apk --update --no-cache add \
	bash \
	vsftpd \
	openssl

ENV FTP_USER=tseo \
    FTP_PASS=tseo

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY ftps_setup.sh /usr/sbin/
RUN chmod +x /usr/sbin/ftps_setup.sh

EXPOSE 20 21 20000-20004
ENTRYPOINT [ "/usr/sbin/ftps_setup.sh" ]
