/*
 Copyright (c) 2023 [Henrique] [Zing]
 SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

//#include "Tabs.h"

class Tab; // TODO remover isso quando 'Tabs.h' for criado

// FIXME adicionar WebRenderer no Makefile.

/* 
 Every tab will have an DOM
 and a framebuffer that represents the DOM
 after execution.

WARNING: For now, we have just ONE tab support for simplicity·
*/

void __sdl2_thread_for_each_tab();

class WebRenderer {
  private:
    //std::vector<Tab> m_tabs = {};
    Tab* m_open_tab = nullptr;

  public:
    WebRenderer() {
      std::cout << "WebRenderer::WebRenderer(): created!\n";
      m_open_tab = new Tab();
      m_open_tab->render();
    }

    bool change_current_tab(Tab* new_tab) {
      m_open_tab = new_tab;
      return true;
    }

    //bool change_tab();

};
