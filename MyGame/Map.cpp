#include"Map.h"

//hàm tải map
void GameMap :: LoadMap(char* name){
    FILE*fp = fopen(name,"rb");// mở file
    if(fp==NULL){
        return ;
    }
    game_map_.max_x_ = 0;//vị trí ô đầu tiên theo chiều x
    game_map_.max_y_ = 0;// theo chiều y
    for(int i = 0; i < MAX_MAP_Y; i++){
        for(int j = 0; j < MAX_MAP_X; j++){
            fscanf(fp,"%d",&game_map_.tile[i][j]);//đọc từ file ra ghi vào mảng tile
            int val = game_map_.tile[i][j];
            if(val > 0){
                if( j > game_map_.max_x_ ){//kiểm tra giới hạn x
                    game_map_.max_x_ = j;
                }
               if( i > game_map_.max_y_ ){//kiểm tra giới hạn y
                    game_map_.max_y_ = i;
                }
            }
        }
    }
    game_map_.max_x_ = (game_map_.max_x_ + 1)*TILE_SIZE;//kích thước chính xác của map
    game_map_.max_y_ = (game_map_.max_y_ + 1)*TILE_SIZE;//

    game_map_.start_x_ = 0;//đặt tọa độ đầu bằng 0
    game_map_.start_y_ = 0;

    game_map_.file_name_=name;//lưu lại tên map
    fclose(fp);
}
//Hàm tải ảnh tile cho map
void GameMap :: LoadTiles(SDL_Renderer *screen){
    char file_img[30];
    FILE* fp = NULL;

    for(int i = 0; i < MAX_TILE; i++){
        sprintf(file_img,"map/%d.png",i);//chuyển i sang thành map/i.png đưa vào file_img
        fp = fopen(file_img,"rb");// mở file và kiểm tra
        if(fp==NULL){
            continue;
        }
        fclose(fp);
        tile_map[i].LoadImg(file_img,screen);//tải sẵn ảnh
    }
}

//Vẽ Map
void GameMap::DrawMap(SDL_Renderer * screen){
    int x1 = 0;//vị trí bắt đầu fill ảnh
    int x2 = 0;//vị trí kết thúc

    int y1 = 0;//vị trí bắt đầu fill
    int y2 = 0;

    int map_x = 0;//chỉ số ô thứ bao nhiêu
    int map_y = 0;

    map_x = game_map_.start_x_/TILE_SIZE;//xác định ô thứ bao nhiêu chiều ngang
    x1 = (game_map_.start_x_%TILE_SIZE)*(-1);//xác định x1 để fill đủ màn hình
    x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);//x2

    map_y = game_map_.start_y_/TILE_SIZE;// xác định ô thứ bao nhiêu chiều cao
    y1 = (game_map_.start_y_%TILE_SIZE)*(-1);//xác định y1 để fill đủ màn hình
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);

    for(int i = y1; i < y2; i += TILE_SIZE){
        map_x = game_map_.start_x_/TILE_SIZE;//chỉ số của ô cập nhật lại để vẽ dòng tiếp
        for(int j = x1; j < x2; j += TILE_SIZE){
            int val = game_map_.tile[map_y][map_x];//giá trị ô
            if(val > 0){
                tile_map[val].SetRect(j,i);//vẽ HCN với tọa độ j i
                tile_map[val].Render(screen);//vẽ
            }
            map_x++;
        }
        map_y++;
    }

}
