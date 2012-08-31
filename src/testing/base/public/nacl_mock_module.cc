// Copyright 2010-2012, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "base/base.h"

extern "C" {
// The following functions are not implemented in NaCl environment.
// But the gtest library requires these functions in link phase.
// So We implement these dummy functions.

char *getcwd(char *buf, size_t size) {
  LOG(WARNING) << "dummy getcwd called";
  if (size < 5) {
    errno = ENAMETOOLONG;
    return NULL;
  }
  memcpy(buf, "/tmp", size);
  return buf;
}

int access(const char *pathname, int mode) {
  LOG(WARNING) << "dummy access called pathname: \"" << pathname
               << "\" mode: " << mode;
  return -1;
}

int unlink(const char *pathname) {
  LOG(WARNING) << "dummy unlink called pathname: \"" << pathname << "\"";
  return -1;
}

int mkdir(const char *pathname, mode_t mode) {
  LOG(WARNING) << "dummy mkdir called pathname: \"" << pathname << "\""
               << " mode: " << mode;
  return -1;
}

}  // extern "C"