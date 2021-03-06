#ifndef H_JSGREP_V8_SESSION_H
#define H_JSGREP_V8_SESSION_H

#include <functional>
#include "v8.h"
#include "jsgrep/types.hpp"
#include "jsgrep/v8_module.hpp"

using v8::Context;
using v8::Handle;
using v8::MaybeLocal;
using v8::HandleScope;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

namespace jsgrep {
  class v8_session {
  public:
    v8_session();
    virtual ~v8_session();

    Isolate* get_isolate() const;

    /**
     * Load a script from memory buffer into an existing context.
     */
    v8_module require(Local<Context>&, const unsigned char *, const unsigned int) const;

    Handle<Value> get(Local<Context>&, Local<Object> const&, const char*) const;

  protected:
    Isolate *isolate_;
    Isolate::CreateParams isolate_create_params_;

    MaybeLocal<Value> eval_script(Local<Context> &, const unsigned char *, const unsigned int) const;

    void read_module_exports(Local<Context> const &context, v8_module &module, MaybeLocal<Value> const& script) const;
  };
}

#endif