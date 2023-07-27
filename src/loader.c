#include "../headers/loader.h"
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void* loadLib(cstr path) {
    system("./build/buildLib.sh");
    void* library_handle = dlopen(path, RTLD_NOW);
    if (library_handle == NULL) {
        fprintf(stderr, "Error to load lib %s: %s\n", path, dlerror());
        return NULL;
    }
    return library_handle;
}

int retFunc(void* lib, cstr fn_name) {
    if (lib != NULL) {
        Fn_t func = (Fn_t)dlsym(lib, fn_name);
        if (func == NULL) {
            fprintf(stderr, "Function %s not found in the library: %s\n", fn_name, dlerror());
            return 1;
        }
    } else {
        fprintf(stderr, "Library handle is NULL.\n");
        return 1;
    }
    return 0;
}

void unload_library(void* library_handle) {
    dlclose(library_handle);
}
int open_and_call(cstr path,cstr fn_name){
    void* lib = loadLib(path);
    if (lib == NULL) {
        fprintf(stderr, "Lib can't open it %s: %s\n",path, dlerror());
        return 1;
    }

    if (retFunc(lib,fn_name) != 0) {
        fprintf(stderr,"Error occurred in retFunc %s:%s\n",path,dlerror());
        unload_library(lib);
        return 1;
    }
    Fn_t func = (Fn_t)dlsym(lib,fn_name);
    if (func == NULL) {
        fprintf(stderr, "Function my_func not found in the library: %s\n", dlerror());
        unload_library(lib);
        return 1;
    }
    func();
    unload_library(lib);
    return 0;
}
