//
//
//  Created by Peng Yunchou on 13-9-23.
//  Copyright (c) 2013年 Peng Yunchou. All rights reserved.
//

#ifndef xhttpd_msg_queue_c_h
#define xhttpd_msg_queue_c_h



struct xqueue_t;

struct xqueue_t* xqueue_new();
int xqueue_destroy(struct xqueue_t* q);
int xqueue_push(struct xqueue_t* q,void* ud);
void* xqueue_pop(struct xqueue_t* q);
long xqueue_count(struct xqueue_t* q);

#endif
