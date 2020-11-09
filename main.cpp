// #include <assert.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <uv.h>


// // gcc -Wall main.c -o uvcat -luv
// // ./uvcat ./1.txt


// //void on_read(uv_fs_t *req);
// //
// //uv_fs_t open_req;
// //uv_fs_t read_req;
// //uv_fs_t write_req;
// //
// //static char buffer[1024];
// //
// //static uv_buf_t iov;
// //
// //void on_write(uv_fs_t *req) {
// //  if (req->result < 0) {
// //    fprintf(stderr, "Write error: %s\n", uv_strerror((int) req->result));
// //  } else {
// //    uv_fs_read(uv_default_loop(), &read_req, open_req.result, &iov, 1, -1, on_read);
// //  }
// //}
// //
// //void on_read(uv_fs_t *req) {
// //  if (req->result < 0) {
// //    fprintf(stderr, "Read error: %s\n", uv_strerror(req->result));
// //  } else if (req->result == 0) {
// //    uv_fs_t close_req;
// //    // synchronous
// //    uv_fs_close(uv_default_loop(), &close_req, open_req.result, NULL);
// //    printf("******Read file done!!!");
// //  } else if (req->result > 0) {
// //    iov.len = req->result;  // 读取数据的长度(数据读写完毕才触发回调)
// //    // 因为cat功能，所以将读取的数据写入控制台
// //    uv_fs_write(uv_default_loop(), &write_req, 1, &iov, 1, -1, on_write);
// //  }
// //}
// //
// //void on_open(uv_fs_t *req) {
// //  // The request passed to the callback is the same as the one the call setup
// //  // function was passed.
// //  assert(req == &open_req);
// //  if (req->result >= 0) {
// //    iov = uv_buf_init(buffer, sizeof(buffer));
// //    uv_fs_read(uv_default_loop(), &read_req, req->result,
// //               &iov, 1, -1, on_read);
// //  } else {
// //    fprintf(stderr, "error opening file: %s\n", uv_strerror((int) req->result));
// //  }
// //}

// static int count = 0;

// static void timer_cb1(uv_timer_t* handle) {
//   printf("timer_cb1 count: %d \n", ++count);
// }
// static void timer_cb2(uv_timer_t* handle) {
//   printf("timer_cb2 count: %d \n", --count);
// }

// int main(int argc, char **argv) {
//   //  printf("******Read file done!!!");
//   //  argv[1]
// //  char p[] = "/Users/wangwenjie/code/cpp-test/hilibuv/1.txt";
// //  uv_fs_open(uv_default_loop(), &open_req, p, O_RDONLY, 0, on_open);

// //  uv_run(uv_default_loop(), UV_RUN_DEFAULT);
  
// //  uv_fs_req_cleanup(&open_req);
// //  uv_fs_req_cleanup(&read_req);
// //  uv_fs_req_cleanup(&write_req);


//   int r;
//   uv_loop_t *loop;
//   loop = uv_default_loop();
//   uv_timer_t timer_handle1;
//   uv_timer_t timer_handle2;

//   uv_timer_init(loop, &timer_handle1);
//   uv_timer_init(loop, &timer_handle2);
//   uv_timer_start(&timer_handle1, timer_cb1, 1, 1000 * 5);
//   uv_timer_start(&timer_handle2, timer_cb2, 1, 1000 * 3);
  
//   r = uv_run(loop, UV_RUN_DEFAULT);
  
//   printf("r => %d", r);

//   return 0;
// }