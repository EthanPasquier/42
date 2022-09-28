cat /etc/passwd | grep -v '^#' | awk 'NR % 2 == 0' | tail -r | sort -r | awk -F : '{ print $1 }'| sed 's/.\{2\}$/./'
