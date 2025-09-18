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

#include "env.h"
#include <stdlib.h>

const char *Env_Value(const char *envvar) {
  return getenv(envvar);
}

const char *Env_Value_Default(const char *envvar, const char *defval) {
  const char *val = Env_Value(envvar);
  return (val != NULL && val[0] != NULL) ? val : defval;
}
