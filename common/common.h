/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: 2020年03月29日 星期日 23时40分39秒
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

char *get_value(char *path, char *key);
void make_nonblock_ioctl(int fd);
void make_block_ioctl(int fd);
void make_nonblock(int fd);
void make_block(int fd);

#endif
