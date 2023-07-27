#ifndef LOADER_H
#define LOADER_H

typedef const char* cstr;
typedef void (*Fn_t)();

void* loadLib(cstr path);
int retFunc(void* lib, cstr fn_name);
void unload_library(void* library_handle);
int open_and_call(cstr path,cstr fn_name);
#endif // LOADER_H
