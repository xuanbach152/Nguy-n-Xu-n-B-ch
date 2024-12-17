#ifndef MAP_H_
#define MAP_H_


#include"CommonFunction.h"
#include"BaseObject.h"
#define MAX_TILE 20
class TileMap : public BaseObject{//các ô vuông
    public :
    TileMap(){;}
    ~TileMap(){;}

};
class GameMap{
public :
    GameMap(){;}
    ~GameMap(){;}
    void LoadMap(char* name);//dọc file map
    void LoadTiles(SDL_Renderer *screen);//tải tile
    void DrawMap(SDL_Renderer *screen);//vẽ map
    Map GetMap()const {return game_map_;};
    void SetMap(Map& map_data){game_map_ = map_data;};

private :
    Map game_map_;//cái map
    TileMap tile_map[MAX_TILE];//số lượng tile map đá đát các thứ

};

#endif // MAP_H_
