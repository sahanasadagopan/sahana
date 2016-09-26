#ifndef _buffer_H
#define _buffer_H
#include<stdint.h>
typedef struct
    {
        uint8_t *buffer;
        uint8_t *head;
        uint8_t *tail;
        uint8_t size; //max number of items in the buffer
        uint8_t item_size; //items present in the buffer
        uint8_t num_items; //size of each item in the buffer
    }circbuf_t;
    
     uint8_t add_item(circbuf_t *circbuf,uint8_t items);
     uint8_t buffer_empty(circbuf_t *circbuf,uint8_t item,uint8_t size,uint8_t item_size);
     uint8_t buffer_full(circbuf_t *circbuf,uint8_t *tail,uint8_t *head);
     uint8_t delete_item(circbuf_t *circbuf);
     # endif
      
