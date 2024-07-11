Project Idea: File Organizer
----
**The goal of this project is to create a Bash script that organizes files in a specified directory based on their file types into separate subdirectories. This can be useful to keep your directories clean and tidy by automatically sorting files into appropriate categories.**
## Features:
- The script should take a directory path as an argument and organize the files within that directory.
- It should create subdirectories based on the file extensions (e.g., "txt" for text files, "jpg" for image files).
- Files with unknown or no file extensions should be placed in a "misc" subdirectory.
- If a subdirectory for a particular file type already exists, the script should move the files into that existing directory.
- The script should handle edge cases, such as files with no extensions or hidden files (those starting with a dot).
## Script:
```bash
#!/bin/bash
 

## Function to create a directory if it doesn't exist

create_directory()

{

    if [ ! -d "$1" ]; then

        mkdir -p "$1" # Create specific directories and their [p]arents if needed.

    fi

}  

# Check if the user provided a directory path

if [ -z "$1" ]; then

    echo "Usage: $0 <directory-path>"

    exit 1

fi

# Get the directory path from the argument

DIR_PATH="$1"
  

# Check if the provided path is a directory

if [ ! -d "$DIR_PATH" ]; then

    echo "Error: $DIR_PATH is not a directory"

    exit 1

fi

# Change to the specified directory

cd "$DIR_PATH"

# Loop through all the files in the directory

for file in *; do

    # Skip directories

    if [ -d "$file" ]; then

        continue

    fi

    # Get the file extension

    extension="${file##*.}"  

    # Check if the file has no extension or is hidden (starts with a dot)

    if [[ "$file" == .* || "$file" == *.* ]]; then

        if [ "$file" == "$extension" ]; then

            # File has no extension

            extension="misc"

        fi

    else

        # File has an extension

        extension=$(echo "$extension" | tr '[:upper:]' '[:lower:]')

    fi

    # create the subdirectory if it doesn't exist

    create_directory "$extension"

    # Move the file to the appropriate subdirectory

    mv "$file" "$extension/"

done

echo "Files have been organized."

# print files in the directory

tree "$DIR_PATH"
```
## Before run script:
![befor-run-script](Images/befor-run-script.png)
## After run script:
![after-run-script](Images/after-run-script.png)
