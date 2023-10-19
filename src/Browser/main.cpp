/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <webkit2/webkit2.h>
#include <webkit2/webkit-web-extension.h>
//#include <webkit/WebKitWebPage.h>
#include <webkitdom/webkitdom.h>

std::vector<std::string> findScriptElements(WebKitWebView* webView) {
    std::vector<std::string> scriptContents;

    WebKitWebPage* webPage = webkit_web_view_get_page(webView);
    if (!webPage) {
        std::cerr << "Não foi possível obter a página da web." << std::endl;
        return scriptContents;
    }

    WebKitDOMDocument* document = webkit_web_page_get_dom_document(webPage);
    WebKitDOMNodeList* scriptNodes = webkit_dom_document_query_selector_all(document, "script", NULL);

    gulong numScripts = webkit_dom_node_list_get_length(scriptNodes);
    for (gulong i = 0; i < numScripts; ++i) {
        WebKitDOMNode* node = webkit_dom_node_list_item(scriptNodes, i);
        WebKitDOMElement* element = WEBKIT_DOM_ELEMENT(node);

        gchar* content = webkit_dom_element_get_inner_html(element);
        scriptContents.push_back(std::string(content));
        g_free(content);
    }
    g_object_unref(scriptNodes);

    return scriptContents;
}

static void load_finished(WebKitWebView* webView, WebKitLoadEvent load_event, gpointer user_data) {
    if(load_event == WEBKIT_LOAD_FINISHED) {
        auto script_elements = findScriptElements(webView);
        for(const std::string& scr : script_elements) {
            std::cout << "Script encontrado: " << scr << std::endl;
        }
        gtk_main_quit();
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    WebKitWebView* webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
    WebKitSettings* settings = webkit_web_view_get_settings(webView);
    g_object_set(G_OBJECT(settings), "enable-javascript", FALSE, NULL); 

    g_signal_connect(webView, "load-changed", G_CALLBACK(load_finished), NULL);

    webkit_web_view_load_uri(webView, "http://google.com/");
    gtk_main();
    return 0;
}

