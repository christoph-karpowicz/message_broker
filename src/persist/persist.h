#ifndef PERSIST_H
#define PERSIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "../util/mem.h"
#include "../util/util.h"

#define PERSIST_ADD_QUEUE       1
#define PERSIST_REMOVE_QUEUE    2
#define PERSIST_READ_QUEUE      3
#define PERSIST_GET_QUEUE_LIST  4
#define PERSIST_ADD_NODE        5
#define PERSIST_REMOVE_NODE     6
#define PERSIST_READ_NODE       7
#define PERSIST_GET_NEXT_ID     8

struct persist_request {
    const unsigned short int    type;
    const char                  *queueName;
    const unsigned int          nodeId;
    void                        *data;
};

struct persist_response {
    char *errorMessage;
    bool success;
    void *data;
};

struct persist_response persist_dispatch();

static char *create_error_message(const char *part1, const char *part2);

static bool create_node_file(const char *path, const char *name, const char *content);

static bool create_queue_dir(const char *dirName);

static unsigned int *get_next_node_id(const char *path);

static size_t get_queue_length(const char *path);

static void **get_queue_list();

static char *read_node(const char *path, const char *name);

static bool remove_node(const char *path, const char *name);

static int *read_queue(const char *path);

static bool persist_remove_queue(const char *path);

#endif