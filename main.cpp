#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <uv.h>

uv_loop_t loop;

static void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf)
{
  static char buffer[1 << 16];
  *buf = uv_buf_init(buffer, 1 << 16);
}

static void timer_cb(uv_timer_t* handle) {
  printf("timer_cb val: %s \n", handle->data);
}

#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

static void read_stdin(uv_stream_t *stream, ssize_t nread, const uv_buf_t* buf)
{
  if (nread < 0) {
    // stdin closed
    uv_read_stop(stream);
    return;
  }
  
  char delim[] = " ";
  char str[] = "";
  char *p = NULL;
  char *pre = NULL;
  int timeout = 0;

  p = strtok(buf->base, delim);
  while(true) {
    if (p == NULL) {
      timeout = atoi(pre);
      break;
    }
    if (pre != NULL) {
      strcpy (str, pre);
    }
    pre = p;
    p = strtok(NULL, delim);
  }
  
  if (strlen(str) == 0) {
    strcpy (str, pre);
    timeout = 0;
  }
  pre = NULL;
  
  uv_timer_t timer_handle;
  uv_timer_init(&loop, &timer_handle);
  timer_handle.data = str;
  uv_timer_start(&timer_handle, timer_cb, timeout, 0);

  printf("str => %s", str);
  printf("pre => %s", pre);
  printf("timeout => %d\n", timeout);
  printf("==============================\n");
}

int main(int argc, char *argv[])
{
  /* Initialize loop */
  uv_loop_init(&loop);

  /* Input */
  uv_tty_t input;
  uv_tty_init(&loop, &input, STDIN_FILENO, 1);
  uv_read_start((uv_stream_t *)&input, alloc_buffer, read_stdin);

  /* Run loop */
  uv_run(&loop, UV_RUN_DEFAULT);

  return 0;
}