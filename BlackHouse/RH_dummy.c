
#if 0==1

__UNION_PixelRGB888_t in_[6][6] = {
    {{.R =  90},{.R = 100},{.R = 100},{.R =  90},{.R = 100},{.R = 100}},
    {{.R = 100},{.R = 120},{.R =  80},{.R = 100},{.R = 120},{.R = 100}},
    {{.R = 100},{.R =  20},{.R = 100},{.R = 100},{.R = 120},{.R = 100}},
    {{.R =  90},{.R = 100},{.R = 100},{.R =  90},{.R = 100},{.R = 100}},
    {{.R = 100},{.R = 120},{.R =  70},{.R = 100},{.R = 120},{.R = 100}},
    {{.R = 100},{.R =  20},{.R = 100},{.R = 100},{.R = 120},{.R = 100}},
};
__UNION_PixelRGB888_t out_[3][3] = {0};

__ImageRGB888_t in = {
    .pBuffer = in_[0],
    .width   = 6,
    .height  = 6
};

__ImageRGB888_t out = {
    .pBuffer = out_[0],
    .width   = 3,
    .height  = 3
};
__Area_t AREA = {
    .xs = 2,
    .ys = 2,
    .width  = 3,
    .height = 3
};

__Blur_Average_ImgRGB888(&in,&out,&AREA,10,100);

#if   ( GRAPHIC_COLOR_TYPE == GRAPHIC_COLOR_BIN    )
            while(1);
#elif ( GRAPHIC_COLOR_TYPE == GRAPHIC_COLOR_RGB565 )
            while(1);
#elif ( GRAPHIC_COLOR_TYPE == GRAPHIC_COLOR_RGB888 )
            __Blur_Average_ImgRGB888(pInfo, &GCFG.blur_tmp, &GCFG.blur_area, GCFG.blur_size, GCFG.blur_br_100);
#else
  #error "[RH_graphic]: Unknown color type."
#endif

const char* __restrict__ src  = "/Users/randle_h/desktop/lenna.bmp";
const char* __restrict__ des  = "/Users/randle_h/desktop/lenna_.bmp";

__ImageRGB888_t* IMG_IN  = __LoadBMP_ImgRGB888(src);
__Area_t         AREA    = {
    .xs = 1,
    .ys = 1,
    .width  = 300,
    .height = 300
};
__ImageRGB888_t* IMG_OUT = __Create_ImgRGB888(AREA.width, AREA.height);


__Blur_Average_ImgRGB888(IMG_IN,IMG_OUT,&AREA,40000,100);
__OutBMP_ImgRGB888(des, IMG_OUT);



( *applyPixelMethod [method] )(x1,y1,GCFG.penColor,pInfo);


long __pascal_triangle(int row, int col){
    __exitReturn( col>row || col<0 || row<0 , -1 );

    struct __Link{
        struct __Link* pNext;
        int*           data;
        size_t         row;
    };
    typedef struct __Link __Link;
    static struct __Link Head = {
        .pNext = NULL ,
        .data  = NULL ,
        .row   = 0
    };
    if( Head.data == NULL ){
        Head.data = (int*)malloc(sizeof(int));
        Head.data[0] = 1;
    }

    __Link* pIter = &Head;
    __Link* pOpti = &Head;
    __Link* pLast = &Head;
    
    long dis_row_min    = row - pIter->row;

    do{
        // 行差越小，需要迭代的次数就越少
        if( row > pIter->row && (row-pIter->row) < dis_row_min ){
            dis_row_min = row - pIter->row;
            pOpti = pIter;
        }
        // 如果就是那一行，即行差为0，则直接返回值
        if( pIter->row==row ){
            return ( pIter->data[col] );
        }
        // 继续迭代寻找
        pLast = pIter;
        pIter = pIter->pNext;
   
    }while( pIter != NULL );
    
    // 没有找到那一行，则从最接近那一行（pOpti->row）的数值开始向下相邻累加计算，并记录之
    // 此时 pOpti 代表最佳的那一行数据，pLast为链表最后节点末尾。
    __Link*  pasc_link = pLast;
    int*     last_data = pOpti->data;
    size_t   pasc_size = pOpti->row+2;                                 // 该行的元素个数为上一行行号+2
    
    while( dis_row_min-- ){
        pasc_link->pNext    = (__Link*)malloc( sizeof(__Link) );       // 新建一行
        pasc_link           = pasc_link->pNext;
        

        pasc_link->data     = (int*)malloc( pasc_size * sizeof(int));
        pasc_link->row      = pasc_size-1;                             // 该行行号为该行元素数量-1
        pasc_link->pNext    = NULL;
        
        pasc_link->data[pasc_size-1] = pasc_link->data[0] = 1;        // 该行边界均为1
        for( int i=1;i<=(pasc_size-1-i);i++ ){
            pasc_link->data[i] = pasc_link->data[pasc_size-1-i] = last_data[i] + last_data[i-1];
            
        }

        last_data           = pasc_link->data;
        pasc_size           = pasc_link->row+2;
    }

    return pasc_link->data[col];
}



#ifndef __RH_ASSERT_H
#define __RH_ASSERT_H

#ifdef __cpluplus
extern "C"{
#endif


#ifdef __cpluplus
}
#endif

#endif


#endif


