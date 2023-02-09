/*
 * @Author       : lqm283
 * @Date         : 2023-02-09 11:40:14
 * @LastEditTime : 2023-02-09 15:17:42
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------<
 * @FilePath     : /cmake/test/main.c
 */
#include <stdio.h>

#include "config.h"

int main(int argc, char **argv) {
    printf("hello world\r\n");
    printf("project version is v%d.%d \n", main_VERSION_MAJOR, main_VERSION_MINOR);
    return 0;
}
