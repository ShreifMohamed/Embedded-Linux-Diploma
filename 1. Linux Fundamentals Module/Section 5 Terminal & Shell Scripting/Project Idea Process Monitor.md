----
## Project Overview

**Create a Bash script that serves as a simple process monitor, allowing users to view, manage, and analyze running processes on a Unix-like system.**   
## Features

#### List Running Processes:

Implement functionality to list all running processes with essential information (PID, name, CPU/Memory usage).
#### 1. Process Information:

Provide detailed information about a specific process, including its PID, parent process ID, user, CPU and memory usage, etc.
#### 2. Kill a Process:

Allow users to terminate a specific process by entering its PID.
#### 3. Process Statistics:

Display overall system process statistics, such as the total number of processes, memory usage, and CPU load.
#### 4. Real-time Monitoring:

Implement real-time monitoring, updating the display at regular intervals to show the latest process information.
#### 5. Search and Filter:

Allow users to search for processes based on criteria such as name, user, or resource usage.
#### 6. Interactive Mode:

Implement an interactive mode where users can choose operations from a menu.
#### 7. Resource Usage Alerts:

Set up alerts for processes exceeding predefined resource usage thresholds.
#### 8. Logging:

Include logging features to record process-related activities, especially when a process is terminated.
#### 9. Configuration Options:

Allow users to configure the script through a configuration file. For example, users might specify the update interval, alert thresholds, etc.
### Configuration File

Users can create a configuration file (e.g., process_monitor.conf) with settings like:
```bash
# Sample configuration file for Process Monitor

# Update interval in seconds
UPDATE_INTERVAL=5

# CPU usage threshold for alerts (percentage)
CPU_ALERT_THRESHOLD=90

# Memory usage threshold for alerts (percentage)
MEMORY_ALERT_THRESHOLD=80
```

### Script:
```bash
#!/usr/bin/bash -i

# Source the configuration file

if [ -f process_monitor.conf ]; then

    source process_monitor.conf

else

    echo "Configuration file not found! Using default values."

    UPDATE_INTERVAL=5

    CPU_ALERT_THRESHOLD=90

    MEMORY_ALERT_THRESHOLD=80

fi  

# Function to list running processes

list_processes()

{

    ps -eo pid,user,%cpu,%mem,comm --sort=-%cpu | head -n 15

    # To see every process with a user-defined format:

    # ---------> ps -eo pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:14,comm

    # --sort=-%cpu --------> Specify sorting order.

    # head -n 15   --------> Output the first part of files.

}

# Fuction to get detailed information about a specific process

process_info()

{

    local pid=$1

    ps -p "$pid" -o pid,ppid,user,%cpu,%mem,etime,comm

    # -p ------>  Select by process ID.  Identical to -p and --pid.

    # -o ------>  User-defined format.

}

# Function to kill a process by PID

kill_process()

{

    local pid=$1

    kill "$pid" && echo "process $pid terminated." || echo "Failed to terminate process $pid"

}

# Function to display overall system process statistics, such as the total number of processes, memory usage, and CPU load.

process_statistics()

{

    echo "Total number of processes: $(ps -e | wc -l)"

    echo "Memory usage: $(free -h | grep Mem | awk '{print $3 "/" $2}')"

    echo "CPU load: $(uptime | awk -F'load average:' '{ print $2 }' | cut -d, -f1)"}

}    

# Function for real-time monitoring

real_time_monitor()

{

    while true; do

        clear

        list_processes

        echo

        process_statistics

        sleep "$UPDATE_INTERVAL"

    done

}

# Function to search and filter processes

search_processes()

{

    local filter=$1

    ps -eo pid,user,%cpu,%mem,comm --sort=-%cpu | grep "$filter" | head -n 15

}

# Function to log activities

log_activity()

{

    local message=$1

    echo "$(date): $message" >> process_monitor.log

}

# Function to check resource usage and set up alerts

check_alerts()

{

    ps -eo pid,%cpu,%mem,comm --sort=-%cpu | while read -r line; do

        pid=$(echo "$line" | awk '{print $1}')

        cpu=$(echo "$line" | awk '{print $2}' | cut -d. -f1)

        mem=$(echo "$line" | awk '{print $3}' | cut -d. -f1)

        comm=$(echo "$line" | awk '{print $4}')

  

        if [ "$cpu" -ge "$CPU_ALERT_THRESHOLD" ]; then

            log_activity "Alert: Process $comm ($pid) is using $cpu% CPU"

        fi

  

        if [ "$mem" -ge "$MEMORY_ALERT_THRESHOLD" ]; then

            log_activity "Alert: Process $comm ($pid) is using $mem% Memory"

        fi

    done

}
  

# Function to display the menu in interactive mode

interactive_mode()

{

    while true; do

        clear

        echo "Process Monitor"

        echo "1. List running processes"

        echo "2. Detailed process information"

        echo "3. Kill a process"

        echo "4. Display process statistics"

        echo "5. Real-time monitoring"

        echo "6. Search processes"

        echo "7. Check resource usage alerts"

        echo "8. Exit"

        echo -n "Choose an option: "

        read -r option

  

        case $option in

            1)

                list_processes

                ;;

            2)

                echo -n "Enter PID: "

                read -r pid

                process_info "$pid"

                ;;

            3)

                echo -n "Enter PID to kill: "

                read -r pid

                kill_process "$pid"

                log_activity "Process $pid killed."

                ;;

            4)

                process_statistics

                ;;

            5)

                real_time_monitor

                ;;

            6)

                echo -n "Enter search filter: "

                read -r filter

                search_processes "$filter"

                ;;

            7)

                check_alerts

                ;;

            8)

                exit 0

                ;;

            *)

                echo "Invalid option!"

                ;;

        esac

        echo -n "Press any key to continue..."

        read -r -n 1

    done

}

# Start interactive mode

interactive_mode
```