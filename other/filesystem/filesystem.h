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

#ifndef __SRT_FILESYSTEM__
#define __SRT_FILESYSTEM__

#if defined _WIN32
#define DIR_SEPARATOR_CHAR		'\\'
#define DIR_SEPARATOR_STR		"\\"
#define PATH_SEPARATOR_CHAR		';'
#define PATH_SEPARATOR_STR		";"
#define HOME_ENV "USERPROFILE"
#else
#define DIR_SEPARATOR_CHAR		'/'
#define DIR_SEPARATOR_STR		"/"
#define PATH_SEPARATOR_CHAR		':'
#define PATH_SEPARATOR_STR		":"
#define HOME_ENV "HOME"
#endif

/*
  Split string of pathes by PATH_SEPARATOR.

  pathstring -- string of pathes

  return path list
 */ 
const char **FS_SplitPath(const char *pathstring);

/*
  Free path list.

  pathlist -- path list
 */
void FS_FreePathList(char** pathlist);

/*
  User's home directory.

  return home direcory path or NULL.
*/
const char *FS_Home();

#endif // __SRT_FILESYSTEM__
