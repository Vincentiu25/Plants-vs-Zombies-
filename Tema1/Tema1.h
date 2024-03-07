#pragma once
#pragma once

#include "components/simple_scene.h"


using namespace std;

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        struct ViewportSpace
        {
            ViewportSpace() : x(0), y(0), width(1), height(1) {}
            ViewportSpace(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };

        struct LogicSpace
        {
            LogicSpace() : x(0), y(0), width(1), height(1) {}
            LogicSpace(float x, float y, float width, float height)
                : x(x), y(y), width(width), height(height) {}
            float x;
            float y;
            float width;
            float height;
        };

    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void DrawScene(glm::mat3 visMatrix);

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;

        // Sets the logic space and view space
        // logicSpace: { x, y, width, height }
        // viewSpace: { x, y, width, height }+
        glm::mat3 VisualizationTransf2D(const LogicSpace& logicSpace, const ViewportSpace& viewSpace);
        glm::mat3 VisualizationTransf2DUnif(const LogicSpace& logicSpace, const ViewportSpace& viewSpace);

        void SetViewportArea(const ViewportSpace& viewSpace, glm::vec3 colorColor = glm::vec3(0), bool clear = true);

        typedef struct HEX {
            float x, y;
            int hitpoints;
            int color;
            float scale = 1;
        } HEX;

        float time_to_spawn_enemy = 0;        // time until next enemy spawn

        float time_to_spawn_stars = 0;
        float spawn_time_stars = 2.0f;  // time between projectiles

        float time_to_spawn_sun = 0;
        float spawn_time_sun = 2.0f;    // time between suns

        float angularStep = 0.5f;
        
        int maximSun = 21;
        int collectedSun = 3;

        float sunDrawPositionX = 11;
        float sunDrawPositionY = 7.35;


        vector<HEX> enemies_arr;
        vector<string> color = { "orange", "blue", "yellow", "purple" };


        int player_hitpoints = 3;

        // structs for green squares and up squares
        typedef struct GreenSquare {
            float x, y;
        } GreenSquare;

        vector<GreenSquare> green_squares;

        typedef struct UpSquare {
			float x, y;
		} UpSquare;

        vector<UpSquare> up_squares;

        // struct for heldRomb
        typedef struct Heldromb {
			float x, y;
			int color = -1;
		} Heldromb;
        Heldromb Heldromb;

        // struct for romb
        typedef struct Romb {
			float x, y;
			int color;
            float scale = 1;
		} Romb;
        
		vector<Romb> rombsOnMap;

        // struct for stars
        typedef struct Star {
            float x, y;
            int color;
        } Star; 

        vector<Star> starsProjectile;

        // struct for hearts
        typedef struct Heart {
			float x, y;
            int alive;
		} Heart;

        vector<Heart> hearts;

        // struct for sun
        typedef struct Sun {
			float x, y;
			int alive;
		} Sun;
        vector<Sun> suns;
        vector<Sun> sunsCollected;

        //struct for lawnMower
        typedef struct LawnMower {
			float x, y;
            bool alive;
		} LawnMower;

        vector<LawnMower> lawnMower_arr;
        vector<LawnMower> lawnMower_translate;

        vector<HEX> scalingHex;
        vector<Romb> scalingRomb;

    protected:
        float length;
        ViewportSpace viewSpace;
        LogicSpace logicSpace;
        glm::mat3 modelMatrix, visMatrix;
    };
}   // namespace m1
