#include <Windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include "CommonFunction.h"
#include"MainObject.h"
#include"Map.h"
#include"ImpTimer.h"
#include "ThreatsObject.h"


BaseObject g_background;
//khởi tạo
bool InitData()
{
    int ret = SDL_Init(SDL_INIT_VIDEO);//thiet lap moi truong ban dau
    if(ret < 0) return 0;//init ko thanh công
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");//thiết lập tỉ lệ và chất lượng

    g_window = SDL_CreateWindow("BACH VIP",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);//tạo cửa sổ với tiêu đề và kích thước
    if (g_window==NULL)
    {
        SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
        return false;
    }

    g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);//tạo renderer cho cửa sổ
    if (g_screen==NULL)
    {
        SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(g_screen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
    int imgFlags=IMG_INIT_PNG;

    if (!(IMG_Init(imgFlags) && imgFlags))//khởi tạo SDL_image để hỗ trợ dạng PNG
    {
        SDL_Log("SDL_image could not initialize! IMG_Error: %s", IMG_GetError());
        return false;
    }

    return true;
}
//tải ảnh nền
bool LoadBackground(){
    bool ret = g_background.LoadImg("img//background.png",g_screen);
    if(ret==false) return false;
    return true;
}

//giải phóng
void Close(){
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen=NULL;
    SDL_DestroyWindow(g_window);
    g_window=NULL;
    IMG_Quit();
    SDL_Quit();
}
//hàm tạo dnah sách quái
std::vector<ThreatsObject*> MakeThreatList(){
    std::vector<ThreatsObject*> list_threats;

    ThreatsObject* threats_objs = new ThreatsObject[20];

    for(int i = 0; i < 20 ; i++){

        ThreatsObject* p_threat = (threats_objs + i);
        if(p_threat != NULL)
        {
            p_threat->LoadImg("img//threat_level1.png",g_screen);
            p_threat->set_clips();
            p_threat->set_x_pos(700 + i*1200);//đặt quái
            p_threat->set_y_pos(250);

            list_threats.push_back(p_threat);
        }
    }

    return list_threats;
}


int main(int argc, char* argv[])
{
    //
    ImpTimer fps_timer;

    if (!InitData())
    {
        return -1;
    }

    if(!LoadBackground())
    {
        return -1;
    }

    GameMap game_map;
    game_map.LoadMap("map/map01.dat");
    game_map.LoadTiles(g_screen);


    //Vẽ nhân vật
    MainObject p_player;//khỏi tạo đối tượng

    bool ret = p_player.LoadImg("img//player_right.png",g_screen);
    p_player.set_clips();

    if(!ret){
        return 0;
    }

    std::vector<ThreatsObject*> threats_list = MakeThreatList();//tạo danh sách quái


   bool is_running = true; // Vòng lặp game
   while (is_running)
{
    fps_timer.start();
    // Xử lý sự kiện
    while (SDL_PollEvent(&g_event))
    {
        if (g_event.type == SDL_QUIT)
        {
            is_running = false;
        }
        p_player.HandelInputAction(g_event,g_screen);
    }

    //dặt màn hình đen
        SDL_SetRenderDrawColor(g_screen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);//xóa màn hình đi vẽ lại
     // Vẽ lai background lien tuc
        g_background.Render(g_screen,NULL);//vẽ ảnh lên màn hình

        Map map_data =game_map.GetMap();
        p_player.HandleBullet(g_screen);
        p_player.SetMapXY(map_data.start_x_,map_data.start_y_);//xác định vị trí đầu của map
        p_player.DoPlayer(map_data);
        p_player.Show(g_screen);

        game_map.SetMap(map_data);//dặt lại map
        game_map.DrawMap(g_screen);//vẽ lại map

        for(int i = 0;i < threats_list.size(); i++){
            ThreatsObject* p_threat = threats_list.at(i);
            if(p_threat != NULL){
                p_threat->SetMapXY(map_data.start_x_,map_data.start_y_);
                p_threat->DoPlayer(map_data);
                p_threat->Show(g_screen);
            }
        }
    // Hiển thị renderer

    SDL_RenderPresent(g_screen);//update lại màn hình

    int real_imp_time = fps_timer.get_ticks();//thời gian thực sự đã trôi qua
    int time_one_frame = 1000/FRAME_PER_SECOND;//ms thời gian 1 frame

    if(real_imp_time < time_one_frame){
        int delay_time = time_one_frame - real_imp_time;//đồng bộ
        if(delay_time >= 0)
        SDL_Delay(delay_time);
    }
}
    Close();
    return 0;
}
