#include <arpa/inet.h>
#include <error.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>

#define MESSAGE_SIZE 102400
#define SERVER_ADDR "127.0.0.1"

void send_data(int sockfd) {
  char *query;
  query = malloc(MESSAGE_SIZE + 1);
  for (int i = 0; i < MESSAGE_SIZE; i++) {
    query[i] = 'a';
  }
  query[MESSAGE_SIZE] = '\0';

  const char *cp;
  cp = query;
  size_t remaining = strlen(query);
  while (remaining) {
    int n_written = send(sockfd, cp, remaining, 0);
    fprintf(stdout, "send into buffer %ld \n", n_written);
    if (n_written <= 0) {
      perror("send failed");
      return;
    }
    remaining -= n_written;
    cp += n_written;
  }

  return;
}

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in servaddr;

  //if (argc != 2) error(1, 0, "usage: tcpclient <IPaddress>");

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(12345);
  inet_pton(AF_INET, SERVER_ADDR, &servaddr.sin_addr);
  int connect_rt =
      connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  if (connect_rt < 0) {
    perror("connet failed");
  }
  send_data(sockfd);
  exit(0);
}

