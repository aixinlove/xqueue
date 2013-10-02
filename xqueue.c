//
//
//  Created by Peng Yunchou on 13-9-23.
//  Copyright (c) 2013年 Peng Yunchou. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "xqueue.h"

struct  xqueue_item{
    void *ud;
    struct xqueue_item* next;
};
struct xqueue_t {
    long count;
    struct xqueue_item* head;
    struct xqueue_item* tail;
};
struct xqueue_item* xqueue_item_new(void* ud){
    struct xqueue_item* item=malloc(sizeof(struct xqueue_item));
    item->next=NULL;
    item->ud=ud;
    return item;
}
int xqueue_item_destroy(struct xqueue_item* item){
    free(item);
    return 0;
}
struct xqueue_t* xqueue_new(){
    struct xqueue_t* q=malloc(sizeof(struct xqueue_t));
    q->head=NULL;
    q->tail=NULL;
    q->count=0;
    return q;
}
int xqueue_destroy(struct xqueue_t* q){
    free(q);
    return 0;
}
int xqueue_push(struct xqueue_t* q,void* ud){
    struct xqueue_item* item=xqueue_item_new(ud);
    if (q->count==0) {
        q->head=item;
        q->tail=item;
    }else{
        q->tail->next=item;
        q->tail=item;
    }
    q->count++;
    return 0;
}
void* xqueue_pop(struct xqueue_t* q){
    void *ud=NULL;
    if(q->count>0){
        struct xqueue_item* head=q->head;
        q->head=q->head->next;
        ud=head->ud;
        xqueue_item_destroy(head);
        q->count--;
    }
    return ud;
}
long xqueue_count(struct xqueue_t* q){
    return q->count;
}


