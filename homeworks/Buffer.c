#include<stdio.h>
#include<stdint.h>
#define MAX 10
#include "buffer.h"
enum state {bufferfull,bufferempty,itemadded,itemdeleted};   
    /*typedef struct
    {
        uint8_t *buffer;
        uint8_t *head;
        uint8_t *tail;
        uint8_t size; //max number of items in the buffer
        uint8_t item_size; //items present in the buffer
        uint8_t num_items; //size of each item in the buffer
    }circbuf_t;*/
        uint8_t *buffer;
        uint8_t *head;
        uint8_t *tail;
    uint8_t add_item(circbuf_t *circbuf,uint8_t items)
    {
        if(circbuf->item_size!=circbuf->size)
        {
        *circbuf->head=items;   
    printf("element:%d",*circbuf->head);
        circbuf->head++;
        printf("The elements are added/n");
        circbuf->item_size++;
    }
    else
    return 0;
    }
    uint8_t buffer_empty(circbuf_t *circbuf,uint8_t item,uint8_t size,uint8_t item_size)   
    {
        if(item_size=0)
        {
        printf("The buffer is empty/n");
        circbuf->head++;
        *circbuf->head=item;
       }
    }
    uint8_t buffer_full(circbuf_t *circbuf,uint8_t *tail,uint8_t *head)
    {
        if (tail=head+1)
        printf("The buffer is full/n");
        else
        {
            return 0;
        }
    }
    uint8_t delete_item(circbuf_t *circbuf)
    {if(circbuf->item_size=circbuf->size)
    {
        uint8_t val=*circbuf->tail ;
        printf("element deleted is:%d",*circbuf->tail);
        circbuf->tail++ ;
    }
    else
    return 0;
    }
   
    void main()
    { uint8_t item[30];
        circbuf_t cb;
        uint8_t size,item_size,i;      
    printf("Enter the number of elements"); 
    for(i=0;i<10;i++)
    {
    scanf("%d",&item[i]);
    }
    cb.size=10;
    cb.item_size=0;
    cb.buffer=item;
    cb.head=cb.buffer;
    cb.tail=cb.buffer;
    for(i=0;i<10;i++)
    {
     add_item(&cb,item[i]);
     delete_item(&cb); 
    }
    
}
