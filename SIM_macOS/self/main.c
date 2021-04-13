//
//  main.c
//  Xcode_12
//
//  Created by Randle.Helmslay on 2021/4/7.
//

#include <stdio.h>
#include <ctype.h>
#include "RH_gui.h"
#include "RH_gui_api.h"
#include "RH_color.h"
#include <time.h>




void Dummy(int x, int y){
    printf("x=%d,y=%d\n",x,y);
    size_t cnt = 9999;
    while(cnt--);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    
    printf("[%d]\n",isprint(126));
    
    
    __RECORD_TIME( Dummy(3,4), printf );
    
    Simul_API_Init();
    
    GUI_Init();
    GUI_set_penSize(5);
//    GUI_sausage_raw(20, 20, 40, 30);
//    GUI_RefreashScreen();
#if 1
    
    
//    __GUI_Window_t cfg;
//    GUI_window_quickSet(&cfg);
//    cfg.area.xs     = 20;
//    cfg.area.ys     = 20;
//    cfg.area.height = 40;
//    cfg.area.width  = 90;
//    cfg.type        = kGUI_WindowType_win10;
//    cfg.size        = 9;
//    cfg.appearance  = kGUI_Appearance_Light;
//    cfg.title       = "Text";
//    cfg.text        = NULL;
//    cfg.text_size   = 8;
//
//    ID_t ID_Window1 = GUI_window_create(&cfg);
//    GUI_window_insert( ID_Window1 );
    
    
    __GUI_Object_t cfg_obj = {0};

    GUI_object_quickSet(&cfg_obj);

    cfg_obj.style       = kGUI_ObjStyle_barH;
    cfg_obj.area.xs     = 30;
    cfg_obj.area.ys     = 30;
    cfg_obj.area.height = 3;
    cfg_obj.area.width  = 30;
    cfg_obj.min         = 0;
    cfg_obj.max         = 256;
    cfg_obj.font        = kGUI_FontStyle_ArialRounded_Bold;
    cfg_obj.text_color  = M_COLOR_WHITE;
    cfg_obj.text        = "size:";
    cfg_obj.text_size   = 8;
    cfg_obj.text_align  = kGUI_FontAlign_Left;
    cfg_obj.showFrame   = false;

    cfg_obj.bk_color    = M_COLOR_BLACK;

    cfg_obj.val         = 200;

    ID_t ID_Obj1 = GUI_object_create( &cfg_obj );
    GUI_object_insert(ID_Obj1);
    GUI_object_frame(ID_Obj1,false);
    
    GUI_object_adjust(ID_Obj1, 0);
    
    __RECORD_TIME( GUI_RefreashScreen(), printf );

//    GUI_object_frame(ID_Obj1,true);
//
//    GUI_object_adjust(ID_Obj1, 11);
//
//    GUI_RefreashScreen();
//
//    for( int i=0; i<128; i++ ){
//        GUI_object_adjust(ID_Obj1, i%2);
//        GUI_RefreashScreen();
//    }
//    for( int i=0; i<128; i++ ){
//        GUI_object_adjust(ID_Obj1, i%2);
//        GUI_RefreashScreen();
//    }
//    for( int i=0; i<128; i++ ){
//        GUI_object_adjust(ID_Obj1, i%2);
//        GUI_RefreashScreen();
//    }
//    for( int i=0; i<128; i++ ){
//        GUI_object_adjust(ID_Obj1, i%2);
//        GUI_RefreashScreen();
//    }
//    for( int i=0; i<128; i++ ){
//        GUI_object_adjust(ID_Obj1, i);
//        GUI_RefreashScreen();
//    }
//    for( int i=0; i<128; i++ ){
//        GUI_object_adjust(ID_Obj1, i);
//        GUI_RefreashScreen();
//    }
    
    
#endif
    return 0;
}
