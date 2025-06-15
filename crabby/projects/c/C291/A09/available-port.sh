#!/bin/bash

# Define the ephemeral port range
# Default Linux ephemeral port range is typically 32768-60999
# but this can be checked/adjusted based on your system
start_port=32768
end_port=60999

# Get the current ephemeral port range from the system
if [ -f /proc/sys/net/ipv4/ip_local_port_range ]; then
    port_range=$(cat /proc/sys/net/ipv4/ip_local_port_range)
    start_port=$(echo $port_range | awk '{print $1}')
    end_port=$(echo $port_range | awk '{print $2}')
fi

# Function to check if a port is in use
is_port_in_use() {
    port=$1
    # Use ss command (preferred over netstat in modern linux)
    ss -tuln | grep -q ":$port "
    return $?
}

# Loop through the port range to find an available port
current_port=$start_port
while [ $current_port -le $end_port ]; do
    if ! is_port_in_use $current_port; then
        echo $current_port
        exit 0
    fi
    current_port=$((current_port + 1))
done

echo "No available ports found in the ephemeral range ($start_port-$end_port)" >&2
exit 1
