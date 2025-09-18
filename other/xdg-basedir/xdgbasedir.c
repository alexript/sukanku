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

#include "xdgbasedir.h"
#include "env.h"
#include "filesystem.h"
#include <stdio.h>

// TODO: implement values cache
// TODO: use FS_Home()
// TODO: validate results by specification

const char *XDG_Get_DataHome(){
  return Env_Value_Default(XDG_DataHome_Env, XDG_DataHome_Default);
}

const char *XDG_Get_ConfigHome(){
  return Env_Value_Default(XDG_ConfigHome_Env, XDG_ConfigHome_Default);
}

const char *XDG_Get_StateHome(){
  return Env_Value_Default(XDG_StateHome_Env, XDG_StateHome_Default);
}

const char **XDG_Get_DataDirs(){
  const char *pathstring = Env_Value(XDG_DataDirs_Env);
  if(pathstring == NULL) {
    return XDG_DataDirs_Default;
  }

  return FS_SplitPath(pathstring);
}

const char **XDG_Get_ConfigDirs(){
  const char *pathstring = Env_Value(XDG_ConfigDirs_Env);
  if(pathstring == NULL) {
    return XDG_ConfigDirs_Default;
  }
  return FS_SplitPath(pathstring);
}

const char *XDG_Get_CacheHome(){
  return Env_Value_Default(XDG_CacheHome_Env, XDG_CacheHome_Default);
}

const char *XDG_Get_BinHome(){
  return XDG_BinHome_Default;
}

const char *XDG_Get_RuntimeDir(){
  return Env_Value_Default(XDG_RuntimeDir_Env, XDG_RuntimeDir_Default);
}

void XDG_Close() {
  // TODO: free cache
  // TODO: free path lists by FS_FreePathList
}
