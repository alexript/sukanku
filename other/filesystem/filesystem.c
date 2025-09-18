/*
 * Copyright (C) 2025  Alex 'Ript' Malyshev <alexript@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "filesystem.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "env.h"

void FS_FreePathList(char** pathlist) {
  if (pathlist == NULL) return;

  char** ptr = pathlist;
  for (; *ptr; ptr++)
    free(*ptr);
  free(pathlist);
}

const char **FS_SplitPath(const char *pathstring) {
  unsigned int size, i, j, k;
  char** pathlist, ptr;
  size_t n;

  size = 2;
  
  for (i = 0; pathstring[i]; i++) {
    if (pathstring[i] == PATH_SEPARATOR_CHAR) size++;
  }

  n = sizeof(char*)*size;
  pathlist = (char**)malloc(n);
  
  if (pathlist == NULL) {
    perror(strerror(errno));
    return NULL;
  }

  memset(pathlist,0,n);

  for (i = 0; *pathstring; ++i) {
    /* get length of current string  */
    for (j = 0; pathstring[j] && pathstring[j] != PATH_SEPARATOR_CHAR; ++j) ;

    pathlist[i] = (char*)malloc(j+1);
      
    if (pathlist[i] == NULL) {
      perror(strerror(errno));
      FS_FreePathList(pathlist);
      return NULL;
    }

    for (k = j = 0; pathstring[j] && pathstring[j] != PATH_SEPARATOR_CHAR; ++j, ++k) {
      pathlist[i][k] = pathstring[j];
    }
    pathlist[i][k] = 0;

    pathstring += j;
    if (*pathstring == PATH_SEPARATOR_CHAR) pathstring++; 
  }
  
  return pathlist;
  
}

const char *FS_Home() {
  return Env_Value(HOME_ENV);
}
