#include "gdb-tests.h"
#include "jsapi.h"

FRAGMENT(JSObject, simple) {
  JS::Rooted<JSObject *> glob(cx, JS::CurrentGlobalOrNull(cx));
  JS::Rooted<JSObject *> plain(cx, JS_NewObject(cx, 0, 0, 0));
  JS::Rooted<JSObject *> func(cx, (JSObject *) JS_NewFunction(cx, (JSNative) 1, 0, 0,
                                                              JS::CurrentGlobalOrNull(cx), "dys"));
  JS::Rooted<JSObject *> anon(cx, (JSObject *) JS_NewFunction(cx, (JSNative) 1, 0, 0,
                                                              JS::CurrentGlobalOrNull(cx), 0));
  JS::Rooted<JSFunction *> funcPtr(cx, JS_NewFunction(cx, (JSNative) 1, 0, 0,
                                                      JS::CurrentGlobalOrNull(cx), "formFollows"));

  JSObject &plainRef = *plain;
  JSFunction &funcRef = *funcPtr;
  JSObject *plainRaw = plain;
  JSObject *funcRaw = func;

  breakpoint();

  (void) glob;
  (void) plain;
  (void) func;
  (void) anon;
  (void) funcPtr;
  (void) &plainRef;
  (void) &funcRef;
  (void) plainRaw;
  (void) funcRaw;
}

FRAGMENT(JSObject, null) {
  JS::Rooted<JSObject *> null(cx, nullptr);
  JSObject *nullRaw = null;

  breakpoint();

  (void) null;
  (void) nullRaw;
}
