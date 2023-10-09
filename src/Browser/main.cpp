/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "../HTML/HTML.h"
#include "../JS/JS.h"

#if 0
#include <webkitgtk-6.0/webkit/webkit.h>
std::vector<DOMScriptElement> findScriptElements(WebKitWebView* webView) {
    std::vector<DOMScriptElement> scriptElements;
    // Seu código para percorrer o DOM do webView e preencher scriptElements
    return scriptElements;
}

class DOM; // TODO implementar em HTML.h
class AST;
#endif
int main(int argc, char *argv[]) {
  std::cout << "main(): Hello, World!\n";
#if 0
  WebKitWebView* webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
  WebKitSettings* settings = webkit_web_view_get_settings(webView);
  g_object_set(G_OBJECT(settings), "enable-javascript", FALSE, NULL); // We will use our own Javascript Engine.
  
  auto script_elements = findScriptElements(webView);
  for(int i = 0; i < script_elements.size(); ++i) {
    std::cout << "script_element " << script_elements[i].getInnerHTML();
  }

  webkit_web_view_load_uri(webView, "http://google.com/");
#endif
  exit(0);
}
