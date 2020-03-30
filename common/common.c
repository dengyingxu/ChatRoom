/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月29日 星期日 23时39分42秒
 ************************************************************************/

#include "head.h"

char *get_value(char *path, char *key) {
    FILE *fp = NULL;
    ssize_t nrd;
    char *line = NULL, *sub = NULL;
    size_t linecap = 0;
    extern char ans[50];

    if (path == NULL || key == NULL) {
        fprintf(stderr, "Error in argument!\n");
        return NULL;
    }

    if ((fp = fopen(path, "r")) == NULL) {
        perror("fopen");
        return NULL;
    }

    while ((nrd = getline(&line, &linecap, fp)) != -1) {
        if ((sub = strstr(line, key)) == NULL) continue;
        if (line[strlen(key)] == '=') {
            strncpy(ans, sub + strlen(key) + 1, nrd - strlen(key) - 2); 
            *(ans + nrd - strlen(key) - 1) = '\0';
            break;
        }
    }
    free(line);
    fclose(fp);
    if (sub == NULL) {
        return NULL;
    }
    return ans;
}


void make_nonblock_ioctl(int fd) {
    unsigned long ul = 1;
    ioctl(fd, FIONBIO, &ul);
}

void make_block_ioctl(int fd) {
    unsigned long ul = 0;
    ioctl(fd, FIONBIO, &ul);
}

void make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return ;
    }
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
}
void make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return ;
    }
    flag &= ~O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
}
