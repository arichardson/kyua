// Copyright 2010 Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
// * Neither the name of Google Inc. nor the names of its contributors
//   may be used to endorse or promote products derived from this software
//   without specific prior written permission.
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

/// \file engine/config.hpp
/// Test suite configuration parsing and representation.

#if !defined(ENGINE_CONFIG_HPP)
#define ENGINE_CONFIG_HPP

#include "utils/config/nodes.hpp"
#include "utils/config/tree_fwd.hpp"
#include "utils/fs/path.hpp"
#include "utils/passwd.hpp"

namespace engine {


/// Tree node to hold a system user identifier.
class user_node : public utils::config::typed_leaf_node< utils::passwd::user > {
public:
    virtual base_node* deep_copy(void) const;

    void push_lua(lutok::state&) const;
    void set_lua(lutok::state&, const int);

    void set_string(const std::string&);
    std::string to_string(void) const;
};


utils::config::tree default_config(void);
utils::config::tree empty_config(void);
utils::config::tree load_config(const utils::fs::path&);


}  // namespace engine

#endif  // !defined(ENGINE_CONFIG_HPP)
