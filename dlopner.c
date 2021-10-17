/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <dlfcn.h>

int main() {
    char libname[80];
    int rc = 0;
    void *handle;

    printf("Shared library name: ");
    scanf("%s", libname);

    handle = dlopen(libname, RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "Error opening %s: %s\n", libname, dlerror());
        rc = 1;
        goto exit;
    }
    printf("dlopen successful\n");

exit:
    if (handle)
        dlclose(handle);

    handle = NULL;

    return rc;
}
