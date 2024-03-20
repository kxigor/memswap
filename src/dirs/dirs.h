#ifndef DIRS_H
#define DIRS_H

#include <assert.h>
#include <dirent.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define PATH_MAX 4096

typedef struct Dir
{
    DIR* dir        ;
    char* dir_path  ;
} Dir;


/*
    The folder does not necessarily exist, 
    we mean that there is a nesting of non-existent folders

    Hardware dependent, calls mkdir -p
*/
void    DirInit(const char* dir_path);

/*
    Create a folder object
*/
Dir*    DirCtor(const char* dir_path);

/*
    To return the following file, 
    we do not consider folders as files
*/
FILE*   DirGetNextFile  (Dir* dir);

/*
    If there is a Ctor, 
    there must be a Dtor
*/
void    DirDtor         (Dir* dir);

#endif // !DIRS_H