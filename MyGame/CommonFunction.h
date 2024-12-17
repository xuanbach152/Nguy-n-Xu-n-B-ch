//Các hàm xử lí chung
//tạo header guard
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
    #include <Windows.h>
    #include<SDL.h>
    #include<SDL_image.h>
    #include<string>
    #include <cstdio>   // fopen_s, fclose, fscanf_s
    #include <cstring>  // Để xử lý chuỗi
    #include<vector>

//screen
const int FRAME_PER_SECOND = 60;//fps
const int SCREEN_WIDTH = 1280;//kích thước
const int SCREEN_HEIGHT = 640;//kích thước
const int SCREEN_BPP = 32;//tỷ lệ pixel
const int CORLOR_KEY_R = 167;
const int CORLOR_KEY_G = 175;
const int CORLOR_KEY_B = 180;
const int RENDER_DRAW_COLOR = 0xff;

extern SDL_Window* g_window ;       // Cửa sổ SDL
extern SDL_Renderer* g_screen;  // Renderer SDL
extern SDL_Event g_event;       // Sự kiện SDL


#define TILE_SIZE 64
#define MAX_MAP_X 400
#define MAX_MAP_Y 10
#define BLANK_TILE 0
#define STATE_MONEY 7


struct Input{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
} ;
struct Map{//câu trúc dữ liệu 1 map
    int start_x_;//vị trí tọa độ hiên tại
    int start_y_;

    int max_x_;//vị trí ô thứ bao nhiêu
    int max_y_;

    int tile[MAX_MAP_Y][MAX_MAP_X];//mảng lưu trữ tile
    char* file_name_;

};
#endif
//COMMON_FUNCTION_H_
