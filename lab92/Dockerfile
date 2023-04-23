# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY Practice1.c .
# Compile the C program
RUN gcc -o Practice1 Practice1.c
# Set the command to run when the container starts
CMD ["./Practice1"]