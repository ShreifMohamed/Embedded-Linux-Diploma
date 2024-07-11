#!/bin/bash

# Bash Script to Analyze Network Traffic

# Input: Path to the Wireshark pcap file
if [ -z "$1" ]; then
    echo "Usage: $0 <path_to_pcap_file>"
    exit 1
fi
pcap_file="$1" #task capture input from terminal.

# Check if the pcap file exists and is readable
if [ ! -r "$pcap_file" ]; then
    echo "Error: The file '$pcap_file' does not exist or is not readable."
    exit 1
fi

# Function to extract information from the pcap file
analyze_traffic() 
{
    # Check if tshark is installed
    if ! command -v tshark &> /dev/null; then
        echo "tshark could not be found. Please install it and try again"
        exit 1
    fi

    # Extract total packets
    total_packets=$(tshark -r "$pcap_file" | wc -l)
    
    # -r --> Analyze packets from a file.
    # -Y --> Only show packets matching a specific output filter.
    # -T --> Select specific fields to output
    # -e --> <field> Add a field to the list of fields to display if -T ek|fields|json|pdml is selected.
    
    # Extract HTTP packets
    http_packets=$(tshark -r "$pcap_file" -Y "http" | wc -l)

    # Extract HTTPS/TLS packets
    https_packets=$(tshark -r "$pcap_file" -Y "tls"| wc -l)
    
    # Extract top 5 source IP addresses 
    total_source_ips=$(tshark -r "$pcap_file" -T fields -e ip.src -Y "ip" | sort | uniq -c | sort -nr | head -5)
    
    # sort -nr --> --numeric-sort compare according to string numerical value --reverse reverse the result of comparisons
    # uniq --> Output the unique lines from a input or file.Since it does not detect repeated lines unless they are adjacent, we need to sort them first.
    
    # Extract top 5 destinion IP addresses 
    total_dest_ips=$(tshark -r "$pcap_file" -T fields -e ip.dst -Y "ip" | sort | uniq -c | sort -nr | head -5)

    # Output analysis summary
    echo "----- Network Traffic Analysis Report -----"

    # Provide summary information based on your analysis
    # Hints: Total packets, protocols, top source, and destination IP addresses.
    
    echo "1. Total Packets: $total_packets"
    echo "2. Protocols:"
    echo "   - HTTP: $http_packets packets"
    echo "   - HTTPS/TLS: $https_packets packets"
    echo ""
    
    echo "3. Top 5 Source IP Addresses:"
    # Provide the top source IP addresses
    echo "$total_source_ips"
    echo ""
    echo "4. Top 5 Destination IP Addresses:"
    # Provide the top destination IP addresses
    echo "$total_dest_ips"
    echo ""
    echo "----- End of Report -----"
}

# Run the analysis function
analyze_traffic