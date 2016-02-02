# Cleanup
# Run as root

cd /var/log
cat /dev/null > messages
cat /dev/null > wtmpo 
echo "Log files cleaned up"
