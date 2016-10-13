#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "memory.h"
#include "sys/time.h"
#include "data.h"
#include "buffer.h"
void memzero(){
int t;
uint8_t src[5000], dst[5000];
struct timeval my_memmove_start,my_memmove_end,memmove_start,memmove_end,my_memzero_start,my_memzero_end,memset_start,memset_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&my_memzero_start, NULL); // gets time in the start
my_memzero(src,length); // executes function my_memove
gettimeofday(&my_memzero_end, NULL);// gets time in the end
secs  = my_memzero_end.tv_sec  - my_memzero_start.tv_sec;
usecs = my_memzero_end.tv_usec - my_memzero_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for my_memove for %d bytes: %ld usec\n", length,time);
}

void memmove(){
int t;
uint8_t src[5000],dst[5000];
struct timeval my_memmove_start,my_memmove_end,memmove_start,memmove_end,my_memzero_start,my_memzero_end,memset_start,memset_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&my_memmove_start, NULL); // gets time in the start
my_memmove(src,dst,length); // executes function my_memove
gettimeofday(&my_memmove_end, NULL);// gets time in the end
secs  = my_memmove_end.tv_sec  - my_memmove_start.tv_sec;
usecs = my_memmove_end.tv_usec - my_memmove_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for my_memmove for %d bytes: %ld usec\n", length,time);
}

void my_reverse(){
int t;
uint8_t src[5000],dst[5000];
struct timeval my_memmove_start,my_memmove_end,memmove_start,memmove_end,my_memzero_start,my_memzero_end,memset_start,memset_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&my_reverse_start, NULL); // gets time in the start
my_reverse(src,length); // executes function my_memove
gettimeofday(&my_reverse_end, NULL);// gets time in the end
secs  = my_reverse_end.tv_sec  - my_reverse_start.tv_sec;
usecs = my_reverse_end.tv_usec - my_reverse_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for my_reverse for %d bytes: %ld usec\n", length,time);
}

void itoa(){
int t;
uint8_t src;
uint32_t data,d;
struct timeval my_itoa_start,my_itoa_end,my_atoi_start,my_atoi_end,my_ftoa_start,my_ftoa_end,itoa_start,atoi_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&my_itoa_start, NULL); // gets time in the start
my_itoa(&src,data,d); // executes function my_memove
gettimeofday(&my_memmove_end, NULL);// gets time in the end
secs  = my_memmove_end.tv_sec  - my_memmove_start.tv_sec;
usecs = my_memmove_end.tv_usec - my_memmove_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for my_itoa for %d bytes: %ld usec\n", length,time);
}


void atoi(){
int t;
uint8_t src;
uint32_t data,d;
struct timeval my_itoa_start,my_itoa_end,my_atoi_start,my_atoi_end,my_ftoa_start,my_ftoa_end,itoa_start,atoi_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&my_atoi_start, NULL); // gets time in the start
int8_t z=my_atoi(&src); // executes function my_memove
gettimeofday(&my_atoi_end, NULL);// gets time in the end
secs  = my_atoi_end.tv_sec  - my_atoi_start.tv_sec;
usecs = my_atoi_end.tv_usec - my_atoi_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for my_atoi for %d bytes: %ld usec\n", length,time);
}

void ftoa(){
int t;
char src;
uint32_t data,d;
struct timeval my_itoa_start,my_itoa_end,my_atoi_start,my_atoi_end,my_ftoa_start,my_ftoa_end,itoa_start,atoi_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&my_ftoa_start, NULL); // gets time in the start
my_ftoa(&src,data,d); // executes function my_memove
gettimeofday(&my_ftoa_end, NULL);// gets time in the end
secs  = my_ftoa_end.tv_sec  - my_ftoa_start.tv_sec;
usecs = my_ftoa_end.tv_usec - my_ftoa_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for my_ftoa for %d bytes: %ld usec\n", length,time);
}

void add_buffer(){
int t;
uint8_t src;
uint32_t data,d;
struct timeval add_item_start,add_item_end,del_item_start,del_item_end,buffer_init_start,buffer_init_end,release_start,release_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&add_item_start, NULL); // gets time in the start
add_item(&cb,item); // executes function my_memove
gettimeofday(&add_item_end, NULL);// gets time in the end
secs  = add_item_end.tv_sec  - add_item_start.tv_sec;
usecs = add_item_end.tv_usec - add_item_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for add_item for %d bytes: %ld usec\n", length,time);
}

void del_buffer(){
int t;
uint8_t item;
uint32_t data,d;
struct timeval add_item_start,add_item_end,del_item_start,del_item_end,buffer_init_start,buffer_init_end,release_start,release_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&del_item_start, NULL); // gets time in the start
del_item(&src); // executes function my_memove
gettimeofday(&del_item_end, NULL);// gets time in the end
secs  = del_item_end.tv_sec  - del_item_start.tv_sec;
usecs = del_item_end.tv_usec - del_item_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for del_item for %d bytes: %ld usec\n", length,time);
}


void release{
int t;
uint8_t item;
uint32_t data,d;
struct timeval add_item_start,add_item_end,del_item_start,del_item_end,buffer_init_start,buffer_init_end,release_start,release_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&del_item_start, NULL); // gets time in the start
release(&src); // executes function my_memove
gettimeofday(&release_end, NULL);// gets time in the end
secs  = release_end.tv_sec  - release_start.tv_sec;
usecs = release_end.tv_usec - release_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for free for %d bytes: %ld usec\n", length,time);
}

void buffer_init(){
int t;
uint8_t item;
uint32_t data,d;
struct timeval add_item_start,add_item_end,del_item_start,del_item_end,buffer_init_start,buffer_init_end,release_start,release_end, my_reverse_start, my_reverse_end;
long time,mtime, secs, usecs;
int32_t length=10;
gettimeofday(&buffer_init_start, NULL); // gets time in the start
int z=buffer_init(&src); // executes function my_memove
gettimeofday(&buffer_init_end, NULL);// gets time in the end
secs  = buffer_init_end.tv_sec  - buffer_init_start.tv_sec;
usecs = buffer_init_end.tv_usec - buffer_init_start.tv_usec;
time = ((secs*1000000)+usecs); // calculates time in us
printf("Elapsed time for bufffer_init for %d bytes: %ld usec\n", length,time);
}
