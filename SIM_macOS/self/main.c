//
//  main.c
//  Xcode_12
//
//  Created by Randle.Helmslay on 2021/4/7.
//

#include <stdio.h>
#include "RH_gui.h"
#include "RH_gui_api.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    Simul_API_Init();
    
    GUI_Init();
    GUI_set_penSize(5);
    
    __GUI_Window_t cfg;
    GUI_easySet_window(&cfg);
    cfg.area.xs     = 20;
    cfg.area.ys     = 20;
    cfg.area.height = 40;
    cfg.area.width  = 90;
    cfg.type        = kGUI_WindowType_win10;
    cfg.size        = 9;
    cfg.appearance  = kGUI_Appearance_Light;
    cfg.title       = "Text";
    cfg.text        = "I love Nicole. I love my wife.";
    cfg.text_size   = 8;

    ID_t ID_Window1 = GUI_create_window(&cfg);
    GUI_insert_window( ID_Window1 );

    GUI_RefreashScreen();
    return 0;
}
