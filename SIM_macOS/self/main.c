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
    GUI_set_penColor(M_COLOR_WHITE);
    GUI_circle_raw(32, 10, 19);
    GUI_circle_qrt1_raw( 32  ,32  ,10 );
    GUI_circle_qrt2_raw( 32  ,32  ,10 );
    GUI_circle_qrt3_raw( 32  ,32  ,10 );
    GUI_circle_qrt4_raw( 32  ,32  ,10 );
    
//    GUI_circle_raw(32, 10, 18);
//    GUI_circle_qrt1_raw( 32  ,32+1,10 );
//    GUI_circle_qrt2_raw( 32+1,32+1,10 );
//    GUI_circle_qrt3_raw( 32+1,32  ,10 );
//    GUI_circle_qrt4_raw( 32  ,32  ,10 );

    GUI_RefreashScreen();

#if 0
    
    
    __GUI_Object_t cfg_obj = {0};

    GUI_object_quickSet(&cfg_obj);

    cfg_obj.style       = kGUI_ObjStyle_joystick;
    cfg_obj.area.xs     = 10;
    cfg_obj.area.ys     = 10;
    cfg_obj.area.height = 45;
    cfg_obj.area.width  = 46;
    cfg_obj.min[0]      = 0;
    cfg_obj.max[0]      = 4096;
    cfg_obj.min[1]      = 0;
    cfg_obj.max[1]      = 4096;
    
    cfg_obj.font        = kGUI_FontStyle_ArialRounded_Bold;
    cfg_obj.text_color  = M_COLOR_WHITE;
    cfg_obj.text        = "size:";
    cfg_obj.text_size   = 8;
    cfg_obj.text_align  = kGUI_FontAlign_Left;
    cfg_obj.showFrame   = false;

    cfg_obj.bk_color    = M_COLOR_BLACK;

    cfg_obj.val[0]      = 0;
    cfg_obj.val[1]      = 2048;

    ID_t ID_Obj1 = GUI_object_create( &cfg_obj );
    GUI_object_insert(ID_Obj1);
//    GUI_object_frame(ID_Obj1,false);
//    
    GUI_object_adjust(ID_Obj1, 0,2048);
    GUI_object_adjust(ID_Obj1, 2048,0);
    GUI_object_adjust(ID_Obj1, 2048,4096);
    GUI_object_adjust(ID_Obj1, 4096,2048);
    GUI_object_adjust(ID_Obj1, 4096,2048);
    GUI_object_adjust(ID_Obj1, 3496,3496);
    GUI_object_adjust(ID_Obj1, 1398,3864);
    __RECORD_TIME( GUI_RefreashScreen(), printf );


    
    
#endif
    return 0;
}
