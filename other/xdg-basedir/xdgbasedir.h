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

#ifndef __SRT_XDGBASEDIR__
#define __SRT_XDGBASEDIR__

#include "filesystem.h"

/*
This is a single base directory relative to which user-specific data files
should be written. This directory is defined by the environment variable
`$XDG_DATA_HOME`.

If `$XDG_DATA_HOME` is either not set or empty, a default equal
to `$HOME` /.local/share should be used.
*/
static const char *XDG_DataHome_Env = "XDG_DATA_HOME";
static const char *XDG_DataHome_Default =
  DIR_SEPARATOR_STR ".local" DIR_SEPARATOR_STR "share";


/*
This is a single base directory relative to which user-specific configuration
files should be written. This directory is defined by the environment
variable `$XDG_CONFIG_HOME`.

If `$XDG_CONFIG_HOME` is either not set or empty, a default equal
to `$HOME` /.config should be used.
*/
static const char *XDG_ConfigHome_Env = "XDG_CONFIG_HOME";
static const char *XDG_ConfigHome_Default =
  DIR_SEPARATOR_STR ".config";

/*
This is a single base directory relative to which user-specific state data
should be written. This directory is defined by the environment
variable `$XDG_STATE_HOME`.

If `$XDG_STATE_HOME` is either not set or empty, a default equal
to `$HOME` /.local/state should be used.

The `$XDG_STATE_HOME` contains state data that should persist between
(application) restarts, but that is not important or portable enough to the user
that it should be stored in `$XDG_DATA_HOME`.

It may contain:
 - actions history (logs, history, recently used files, …)
 - current state of the application that can be reused on
 a restart (view, layout, open files, undo history, …)
*/
static const char *XDG_StateHome_Env = "XDG_STATE_HOME";
static const char *XDG_StateHome_Default =
  DIR_SEPARATOR_STR ".local" DIR_SEPARATOR_STR "state";

/*
This is a set of preference ordered base directories relative to which data
files should be searched. This set of directories is defined by the environment
variable `$XDG_DATA_DIRS`.

`$XDG_DATA_DIRS` defines the preference-ordered set of base directories
to search for data files in addition to the `$XDG_DATA_HOME` base directory.
The directories in `$XDG_DATA_DIRS` should be separated with the separator used
for `$PATH` on the platform (typically this is a colon `:`).

If `$XDG_DATA_DIRS` is either not set or empty, a value equal
to /usr/local/share/:/usr/share/ should be used.
*/
static const char *XDG_DataDirs_Env = "XDG_DATA_DIRS";
static const char *XDG_DataDirs_Default[] =
  {
    DIR_SEPARATOR_STR "usr" DIR_SEPARATOR_STR "local" DIR_SEPARATOR_STR "share",
    DIR_SEPARATOR_STR "usr" DIR_SEPARATOR_STR "share"
  };

/*
This is a set of preference ordered base directories relative to which
configuration files should be searched. This set of directories is defined by
the environment variable `$XDG_CONFIG_DIRS`.

`$XDG_CONFIG_DIRS` defines the preference-ordered set of base directories to
search for configuration files in addition to the `$XDG_CONFIG_HOME`
base directory. The directories in `$XDG_CONFIG_DIRS` should be separated with
the separator used for `$PATH` on the platform (typically this is a colon `:`).

If `$XDG_CONFIG_DIRS` is either not set or empty, a value equal
to /etc/xdg should be used.
*/
static const char *XDG_ConfigDirs_Env = "XDG_CONFIG_DIRS";
static const char *XDG_ConfigDirs_Default[] =
  {
    DIR_SEPARATOR_STR "etc" DIR_SEPARATOR_STR "xdg"
  };

/*
This is a single base directory relative to which user-specific non-essential
(cached) data should be written. This directory is defined by the environment
variable `$XDG_CACHE_HOME`.

If `$XDG_CACHE_HOME` is either not set or empty, a default equal
to `$HOME` /.cache should be used.
*/
static const char *XDG_CacheHome_Env = "XDG_CACHE_HOME";
static const char *XDG_CacheHome_Default =
  DIR_SEPARATOR_STR ".cache";

/*
This is a single base directory relative to which user-specific executable
files may be written.

User-specific executable files may be stored in `$HOME` /.local/bin.
Distributions should ensure this directory shows up in the UNIX `$PATH`
environment variable, at an appropriate place.

There is no environment variable for this directory.
*/
static const char *XDG_BinHome_Default =
  DIR_SEPARATOR_STR ".local" DIR_SEPARATOR_STR "bin";

/*
This is a single base directory relative to which user-specific runtime files
and other file objects should be placed. This directory is defined by the
environment variable `$XDG_RUNTIME_DIR`.

`$XDG_RUNTIME_DIR` defines the base directory relative to which user-specific
non-essential runtime files and other file objects (such as sockets,
named pipes,...) should be stored. The directory MUST be owned by the user,
and they MUST be the only one having read and write access to it.
Its Unix access mode MUST be 0700.

If `$XDG_RUNTIME_DIR` is not set applications should fall back to a replacement
directory with similar capabilities and print a warning message. Applications
should use this directory for communication and synchronization purposes and
should not place larger files in it, since it might reside in runtime memory
and cannot necessarily be swapped out to disk.
*/
static const char *XDG_RuntimeDir_Env = "XDG_RUNTIME_DIR";
static const char *XDG_RuntimeDir_Default =
  DIR_SEPARATOR_STR "run" DIR_SEPARATOR_STR "user";

const char *XDG_Get_DataHome();
const char *XDG_Get_ConfigHome();
const char *XDG_Get_StateHome();
const char **XDG_Get_DataDirs();
const char **XDG_Get_ConfigDirs();
const char *XDG_Get_CacheHome();
const char *XDG_Get_BinHome();
const char *XDG_Get_RuntimeDir();

/*
  Free internal memory allocations.
 */
void XDG_Close();

#endif // __SRT_XDGBASEDIR__
