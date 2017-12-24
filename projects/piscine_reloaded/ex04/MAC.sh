ifconfig -a | cut -d ' ' -f 1,2 | grep "ether" | cut -d ' ' -f 2
