// main.c

#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *lib = dlopen("./libmylib.so", RTLD_LAZY);
    if (lib) {
        void (*myFunction)() = dlsym(lib, "myFunction");
        if (myFunction) {
            myFunction();
        } else {
            printf("Function not found\n");
        }
        dlclose(lib);
    } else {
        printf("Library not found\n");
    }
    return 0;
}
