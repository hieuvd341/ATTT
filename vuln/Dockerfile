# Use the official Ubuntu base image
FROM ubuntu:22.04

# Update packages and install necessary tools
RUN apt-get update && apt-get install -y \
    socat \
    supervisor \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Create a non-root user and setup the home directory
RUN useradd -m -d /home/grass -s /bin/bash user

# Set the working directory
WORKDIR /home/grass

# Copy the vulnerable application into the container
COPY vuln .

# Change ownership to the new user and set appropriate permissions
RUN chown -R user:user /home/grass && chmod 777 vuln

# Expose the port the application uses
EXPOSE 6011

# Command to run socat to listen on the exposed port and execute 'vuln'
CMD ["socat", "-T", "30", "-d", "-d", "TCP-LISTEN:6011,reuseaddr,fork", "EXEC:./vuln"]
