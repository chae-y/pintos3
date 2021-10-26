#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"

tid_t process_create_initd (const char *file_name);
tid_t process_fork (const char *name, struct intr_frame *if_);
int process_exec (void *f_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (struct thread *next);
void argument_stack(char **argv, int argc, struct intr_frame *if_);

bool install_page (void *upage, void *kpage, bool writable);
bool setup_stack (struct intr_frame *if_);

struct thread *get_child_with_pid(int pid);

//project 10
//aux 구조체
struct box {
    struct file *file;
    off_t ofs;
    size_t page_read_bytes;
};

bool lazy_load_segment (struct page *page, void *aux);
#endif /* userprog/process.h */
