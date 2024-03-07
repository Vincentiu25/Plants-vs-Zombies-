#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}

float hex_x = 16.f;

void Tema1::Init()
{
    auto camera = GetSceneCamera();
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    logicSpace.x = 0;       // logic x
    logicSpace.y = 0;       // logic y
    logicSpace.width = 16;   // logic width
    logicSpace.height = 9;  // logic height

    glm::vec3 corner = glm::vec3(0.001, 0.001, 0);
    length = 1;

    //green squares
    Mesh* square1 = object2D::CreateSquareMesh("square1", corner, length , glm::vec3(0, 1, 0), true);
    AddMeshToList(square1);

    // up squares
    Mesh* square2 = object2D::CreateSquareMesh("square2", corner, length , glm::vec3(0, 0, 0), false);
    AddMeshToList(square2);

    // lawnMower
    Mesh* lawnMower = object2D::CreateLawnMowerMesh("lawnMower", corner, length, glm::vec3(0, 0, 0));
    AddMeshToList(lawnMower);

    //red rectangle
    Mesh* rect1 = object2D::CreateRectMesh("rect1", corner, length , glm::vec3(1, 0, 0));
    AddMeshToList(rect1);

    // rombs 
    Mesh* romb1 = object2D::CreateRombMesh("romb_blue", corner, length, glm::vec3(0, 0, 1));
    AddMeshToList(romb1);

    Mesh* rombPurple = object2D::CreateRombMesh("romb_purple", corner, length, glm::vec3(0.7, 0, 1));
    AddMeshToList(rombPurple);

    Mesh* rombYellow = object2D::CreateRombMesh("romb_yellow", corner, length, glm::vec3(1, 0.9, 0));
    AddMeshToList(rombYellow);

    Mesh* rombOrange = object2D::CreateRombMesh("romb_orange", corner, length, glm::vec3(1, 0.5, 0));
    AddMeshToList(rombOrange);

    // stars
    Mesh* star1 = object2D::CreateStarMesh("star1", corner, length / 4, glm::vec3(1, 1, 1));
    AddMeshToList(star1);

    Mesh* star_yellow = object2D::CreateStarMesh("star_yellow", corner, length / 4, glm::vec3(1, 1, 0));
    AddMeshToList(star_yellow);

    Mesh* star_orange = object2D::CreateStarMesh("star_orange", corner, length / 4, glm::vec3(1, 0.5, 0));
    AddMeshToList(star_orange);

    Mesh* star_blue = object2D::CreateStarMesh("star_blue", corner, length / 4, glm::vec3(0, 0, 1));
    AddMeshToList(star_blue);

    Mesh* star_purple = object2D::CreateStarMesh("star_purple", corner, length / 4, glm::vec3(0.7, 0, 1));
    AddMeshToList(star_purple);

    // pink stars
    Mesh* star_pink = object2D::CreateStarMesh("star_pink", corner, length / 2, glm::vec3(1, 0, 1));
    AddMeshToList(star_pink);

    // orange hex
    Mesh* hex1 = object2D::CreateHexMesh("hex_orange", corner, length , glm::vec3(1, 0.5, 0), glm::vec3(1, 0, 0));
    AddMeshToList(hex1);

    // blue hex
    Mesh* hex2 = object2D::CreateHexMesh("hex_blue", corner, length , glm::vec3(0, 0, 1), glm::vec3(0, 1, 1));
    AddMeshToList(hex2);

    // yellow hex
    Mesh* hex3 = object2D::CreateHexMesh("hex_yellow", corner, length , glm::vec3(1, 1, 0), glm::vec3(1, 0, 0));
    AddMeshToList(hex3);

    // purple hex
    Mesh* hex4 = object2D::CreateHexMesh("hex_purple", corner, length , glm::vec3(0.7, 0, 1), glm::vec3(0, 1, 1));
    AddMeshToList(hex4);

    // red heart
    Mesh* heart = object2D::CreateHeartMesh("heart", corner, length / 3 , glm::vec3(1, 0, 0));
    AddMeshToList(heart);


    // create array of green squares
    Tema1::GreenSquare GreenSquare1;
    GreenSquare1.x = 1.5;
    GreenSquare1.y = 0;
    Tema1::green_squares.push_back(GreenSquare1);
    
    Tema1::GreenSquare GreenSquare2;
    GreenSquare2.x = 1.5;
    GreenSquare2.y = 2;
    Tema1::green_squares.push_back(GreenSquare2);

    Tema1::GreenSquare GreenSquare3;
    GreenSquare3.x = 1.5;
    GreenSquare3.y = 4;
    Tema1::green_squares.push_back(GreenSquare3);

    Tema1::GreenSquare GreenSquare4;
    GreenSquare4.x = 3.5;
    GreenSquare4.y = 0;
    Tema1::green_squares.push_back(GreenSquare4);

    Tema1::GreenSquare GreenSquare5;
    GreenSquare5.x = 3.5;
    GreenSquare5.y = 2;
    Tema1::green_squares.push_back(GreenSquare5);

    Tema1::GreenSquare GreenSquare6;
    GreenSquare6.x = 3.5;
    GreenSquare6.y = 4;
    Tema1::green_squares.push_back(GreenSquare6);

    Tema1::GreenSquare GreenSquare7;
    GreenSquare7.x = 5.5;
    GreenSquare7.y = 0;
    Tema1::green_squares.push_back(GreenSquare7);

    Tema1::GreenSquare GreenSquare8;
    GreenSquare8.x = 5.5;
    GreenSquare8.y = 2;
    Tema1::green_squares.push_back(GreenSquare8);

    Tema1::GreenSquare GreenSquare9;
    GreenSquare9.x = 5.5;
    GreenSquare9.y = 4;
    Tema1::green_squares.push_back(GreenSquare9);


    // create array for up squares
    Tema1::UpSquare UpSquare1;
    UpSquare1.x = 1;
    UpSquare1.y = 7.5;
    Tema1::up_squares.push_back(UpSquare1);

    Tema1::UpSquare UpSquare2;
    UpSquare2.x = 3;
    UpSquare2.y = 7.5;
    Tema1::up_squares.push_back(UpSquare2);

    Tema1::UpSquare UpSquare3;
    UpSquare3.x = 5;
    UpSquare3.y = 7.5;
    Tema1::up_squares.push_back(UpSquare3);

    Tema1::UpSquare UpSquare4;
    UpSquare4.x = 7;
    UpSquare4.y = 7.5;
    Tema1::up_squares.push_back(UpSquare4);

    // create array for hearts
    Tema1::Heart Heart1;
    Heart1.x = 11;
    Heart1.y = 8.15;
    Heart1.alive = 1;
    Tema1::hearts.push_back(Heart1);

    Tema1::Heart Heart2;
    Heart2.x = 13;
    Heart2.y = 8.15;
    Heart2.alive = 1;
    Tema1::hearts.push_back(Heart2);

    Tema1::Heart Heart3;
    Heart3.x = 15;
    Heart3.y = 8.15;
    Heart3.alive = 1;
    Tema1::hearts.push_back(Heart3);

    // add the sun collected to the sunCollected arr
    // which is drawn under the hearts
    for (int i = 0; i < Tema1::collectedSun; i++) {
        Tema1::Sun sunCollected;

        sunCollected.x = Tema1::sunDrawPositionX;
        sunCollected.y = Tema1::sunDrawPositionY;

        Tema1::sunsCollected.push_back(sunCollected);
        Tema1::sunDrawPositionX += 0.65;
        if (Tema1::sunDrawPositionX >= 15.5) {
            Tema1::sunDrawPositionX = 11;
            Tema1::sunDrawPositionY -= 0.75;
        }
    }

    // fill the lawnMower array on x = 0;
    for (int i = 0; i < 3; i++) {
        // place a lawnMower at the same lines as the squares
        // but in the middle of the square
        Tema1::LawnMower lawnMower;
        lawnMower.x = 0;
        lawnMower.y = Tema1::green_squares[i].y + 0.75;
        Tema1::lawnMower_arr.push_back(lawnMower);
		
	}


}


// 2D visualization matrix
glm::mat3 Tema1::VisualizationTransf2D(const LogicSpace& logicSpace, const ViewportSpace& viewSpace)
{
    float sx, sy, tx, ty;
    sx = viewSpace.width / logicSpace.width;
    sy = viewSpace.height / logicSpace.height;
    tx = viewSpace.x - sx * logicSpace.x;
    ty = viewSpace.y - sy * logicSpace.y;

    return glm::transpose(glm::mat3(
        sx, 0.0f, tx,
        0.0f, sy, ty,
        0.0f, 0.0f, 1.0f));
}


// Uniform 2D visualization matrix (same scale factor on x and y axes)
glm::mat3 Tema1::VisualizationTransf2DUnif(const LogicSpace& logicSpace, const ViewportSpace& viewSpace)
{
    float sx, sy, tx, ty, smin;
    sx = viewSpace.width / logicSpace.width;
    sy = viewSpace.height / logicSpace.height;
    if (sx < sy)
        smin = sx;
    else
        smin = sy;
    tx = viewSpace.x - smin * logicSpace.x + (viewSpace.width - smin * logicSpace.width) / 2;
    ty = viewSpace.y - smin * logicSpace.y + (viewSpace.height - smin * logicSpace.height) / 2;

    return glm::transpose(glm::mat3(
        smin, 0.0f, tx,
        0.0f, smin, ty,
        0.0f, 0.0f, 1.0f));
}


void Tema1::SetViewportArea(const ViewportSpace& viewSpace, glm::vec3 colorColor, bool clear)
{
    glViewport(viewSpace.x, viewSpace.y, viewSpace.width, viewSpace.height);

    glEnable(GL_SCISSOR_TEST);
    glScissor(viewSpace.x, viewSpace.y, viewSpace.width, viewSpace.height);

    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(colorColor.r, colorColor.g, colorColor.b, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);

    GetSceneCamera()->SetOrthographic((float)viewSpace.x, (float)(viewSpace.x + viewSpace.width), (float)viewSpace.y, (float)(viewSpace.y + viewSpace.height), 0.1f, 400);
    GetSceneCamera()->Update();
}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Tema1::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->GetResolution();

    viewSpace = ViewportSpace(0, 0, resolution.x , resolution.y);
    SetViewportArea(viewSpace, glm::vec3(0.5f), true);

    // Compute uniform 2D visualization matrix
    visMatrix = glm::mat3(1);
    visMatrix *= VisualizationTransf2DUnif(logicSpace, viewSpace);

    time_to_spawn_enemy += deltaTimeSeconds;
    time_to_spawn_stars += deltaTimeSeconds;

    // add hexagons randomly
    if (time_to_spawn_enemy >= rand() % 5 + 5) {
		Tema1::HEX hex;
		hex.x = 16 + 1;
		
        int row = rand() % 3;

        if (row == 0) {
            hex.y = 0.75;
		}
		else if (row == 1) {
			hex.y = 2.75;
		}
        else {
            hex.y = 4.75;
        }
        
        hex.hitpoints = 3;
		hex.color = rand() % 4;
		Tema1::enemies_arr.push_back(hex);
		time_to_spawn_enemy = 0;
	}

    vector<int> hexToDelete;
    vector<int> starsToDelete;
    vector<int> rombsToDelete;
    vector<int> lawnMowerToDelete;
    bool used_lawnMower = false;

    // update hex position
    for (int i = 0; i < Tema1::enemies_arr.size(); i++) {
        // check if hex is out of bounds (player is hit)
        if (Tema1::enemies_arr[i].x <= 1) {
            // check if there is a lawnMower alive on that raw
            for (int j = 0; j < Tema1::lawnMower_arr.size(); j++) {
                if (Tema1::enemies_arr[i].y == Tema1::lawnMower_arr[j].y) {
                    // delete hex
                    hexToDelete.push_back(i);
                    // add lawnMower to LawnMower translate array
                    Tema1::LawnMower lawnMower;
                    lawnMower.x = 0;
                    lawnMower.y = Tema1::lawnMower_arr[j].y;
                    Tema1::lawnMower_translate.push_back(lawnMower);
                    // delete lawnMower
                    Tema1::lawnMower_arr.erase(Tema1::lawnMower_arr.begin() + j);
                    used_lawnMower = true;

				}
			}
            if (used_lawnMower == false) {
				// delete hex
				hexToDelete.push_back(i);
				// delete heart
                Tema1::hearts.erase(Tema1::hearts.begin() + Tema1::hearts.size() - 1);
				Tema1::player_hitpoints--;
				printf("player hitpoints = %d\n", Tema1::player_hitpoints);
			}         

            // check if player lost the game
            if (Tema1::player_hitpoints == 0) {
				printf("GAME OVER\n");
				exit(0);
			}
			continue;
		}
        // check if a star hits the hex
        for (int j = 0; j < Tema1::starsProjectile.size(); j++) {
            if (Tema1::starsProjectile[j].x >= Tema1::enemies_arr[i].x - 0.5 &&
                Tema1::starsProjectile[j].x <= Tema1::enemies_arr[i].x + 0.5 &&
                Tema1::starsProjectile[j].y == Tema1::enemies_arr[i].y &&
                Tema1::starsProjectile[j].color == Tema1::enemies_arr[i].color) {

				Tema1::enemies_arr[i].hitpoints--;
                starsToDelete.push_back(j);

                // check if hex is dead
                if (Tema1::enemies_arr[i].hitpoints == 0) {
                    // delete the hex
                    hexToDelete.push_back(i);
                    
                }
			}
		}

        // if a lawnmower that is moving hits a hex,
        // delete the hex
        for (int j = 0; j < Tema1::lawnMower_translate.size(); j++) {
            if (Tema1::lawnMower_translate[j].x >= Tema1::enemies_arr[i].x - 0.5 &&
                Tema1::lawnMower_translate[j].x <= Tema1::enemies_arr[i].x + 0.5 &&
                Tema1::lawnMower_translate[j].y == Tema1::enemies_arr[i].y) {

                // delete the hex
                hexToDelete.push_back(i);
            }
        }

        // if the hex hits a romb, delete the romb
        for (int j = 0; j < Tema1::rombsOnMap.size(); j++) {
            if (Tema1::rombsOnMap[j].x >= Tema1::enemies_arr[i].x - 1.2 &&
                Tema1::rombsOnMap[j].x <= Tema1::enemies_arr[i].x + 1.2 &&
                Tema1::rombsOnMap[j].y == Tema1::enemies_arr[i].y) {
				// delete the romb
				rombsToDelete.push_back(j);
			}
		}

        // decrease x position for hex (move it to the left)
        Tema1::enemies_arr[i].x -= 0.5 * deltaTimeSeconds;
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(Tema1::enemies_arr[i].x, Tema1::enemies_arr[i].y);
        modelMatrix = visMatrix * modelMatrix;
        string mesh_name = "hex_" + color[Tema1::enemies_arr[i].color];
        RenderMesh2D(meshes[mesh_name], shaders["VertexColor"], modelMatrix);
    }
   
    // delete rombs that hit hexagons
    for (int i = rombsToDelete.size() - 1; i >= 0; i--) {
        Romb romb = Tema1::rombsOnMap[rombsToDelete[i]];
        Tema1::scalingRomb.push_back(romb);
        Tema1::rombsOnMap.erase(Tema1::rombsOnMap.begin() + rombsToDelete[i]);
    }

    // render scaling rombs
    for (int i = 0; i < Tema1::scalingRomb.size(); i++) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(Tema1::scalingRomb[i].x, Tema1::scalingRomb[i].y);
		modelMatrix *= transform2D::Scale(Tema1::scalingRomb[i].scale, Tema1::scalingRomb[i].scale);
		modelMatrix = visMatrix * modelMatrix;
		string mesh_name = "romb_" + color[Tema1::scalingRomb[i].color % 4];
		RenderMesh2D(meshes[mesh_name], shaders["VertexColor"], modelMatrix);
	}

    // delete hexagons that are dead
    for (int i = hexToDelete.size() - 1; i >= 0; i--) {
        HEX hex = Tema1::enemies_arr[hexToDelete[i]];
        Tema1::scalingHex.push_back(hex);
        Tema1::enemies_arr.erase(Tema1::enemies_arr.begin() + hexToDelete[i]);
	}

    // render scaling hex
    for (int i = 0; i < Tema1::scalingHex.size(); i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(Tema1::scalingHex[i].x, Tema1::scalingHex[i].y);
        modelMatrix *= transform2D::Scale(Tema1::scalingHex[i].scale, Tema1::scalingHex[i].scale);
        modelMatrix = visMatrix * modelMatrix;
        string mesh_name = "hex_" + color[Tema1::scalingHex[i].color];
        RenderMesh2D(meshes[mesh_name], shaders["VertexColor"], modelMatrix);
    }

    // scale down hex from scaleHex arr
    for (int i = 0; i < Tema1::scalingHex.size(); i++) {
		Tema1::scalingHex[i].scale -=  deltaTimeSeconds;
		// delete hex from array if it is too small
		if (Tema1::scalingHex[i].scale <= 0) {
            Tema1::scalingHex.erase(Tema1::scalingHex.begin() + i);
            continue;
        }
    }

    // render translated lawnMower
    for (int i = 0; i < Tema1::lawnMower_translate.size(); i++) {
        lawnMower_translate[i].x += 2 * deltaTimeSeconds;
        // if the lawnMower is out of bounds, delete it
        if (lawnMower_translate[i].x >= 16) {
			lawnMower_translate.erase(lawnMower_translate.begin() + i);
			continue;
		}
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(Tema1::lawnMower_translate[i].x, Tema1::lawnMower_translate[i].y);
        modelMatrix = visMatrix * modelMatrix;
        RenderMesh2D(meshes["lawnMower"], shaders["VertexColor"], modelMatrix);
    }
    

    // delete stars that hit hexagons
    for (int i = starsToDelete.size() - 1; i >= 0; i--) {
		Tema1::starsProjectile.erase(Tema1::starsProjectile.begin() + starsToDelete[i]);
	}

    // rombs fire at enemy
    if (time_to_spawn_stars >= spawn_time_stars && Tema1::rombsOnMap.size() != 0) {
        // for every romb on table, add a star only if there is a hex on the same line
        // and has the same color
        for (int i = 0; i < Tema1::rombsOnMap.size(); i++) {
            for (int j = 0; j < Tema1::enemies_arr.size(); j++) {
                if (Tema1::rombsOnMap[i].y == Tema1::enemies_arr[j].y && 
                    Tema1::rombsOnMap[i].color == Tema1::enemies_arr[j].color) {
					Tema1::Star star;
					star.x = Tema1::rombsOnMap[i].x;
					star.y = Tema1::rombsOnMap[i].y;
					star.color = Tema1::rombsOnMap[i].color;
					Tema1::starsProjectile.push_back(star);
                    // only one star per romb
                    break;
				}
			}
		}
        // reset time to spawn
        time_to_spawn_stars = 0;
	}

    angularStep += deltaTimeSeconds * 1;
    // for each romb on the map, fire stars at the hexagons
    for (int i = 0; i < Tema1::starsProjectile.size(); i++) {
        // move all projectiles to the right
        // rotate the stars while moving
        Tema1::starsProjectile[i].x += 2 * deltaTimeSeconds;

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(Tema1::starsProjectile[i].x, Tema1::starsProjectile[i].y);
        modelMatrix *= transform2D::Rotate(2 * angularStep);
        modelMatrix = visMatrix * modelMatrix;
        string mesh_name = "star_" + color[Tema1::starsProjectile[i].color];
        RenderMesh2D(meshes[mesh_name], shaders["VertexColor"], modelMatrix);

        // delete projectile if it is out of picture
        if (Tema1::starsProjectile[i].x >= 16) {
			Tema1::starsProjectile.erase(Tema1::starsProjectile.begin() + i);
			continue;
		}
    }
        
     // every 2 seconds, a star appears on the map anywhere randomly
    time_to_spawn_sun += deltaTimeSeconds;
    if (time_to_spawn_sun >= spawn_time_sun && Tema1::collectedSun < Tema1::maximSun) {
        // sun appears only if there are less than 21 suns collected
        Tema1::Sun sun;
        sun.x = rand() % 15 + 1;
        sun.y = rand() % 6 + 1;
        Tema1::suns.push_back(sun);
        time_to_spawn_sun = 0;
    }

    // scale down rombs from scalingRomb arr and render
    for (int i = 0; i < Tema1::scalingRomb.size(); i++) {
        Tema1::scalingRomb[i].scale -= deltaTimeSeconds;
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(Tema1::scalingRomb[i].x, Tema1::scalingRomb[i].y);
        modelMatrix *= transform2D::Scale(Tema1::scalingRomb[i].scale, Tema1::scalingRomb[i].scale);
        modelMatrix = visMatrix * modelMatrix;
        string mesh_name = "romb_" + color[Tema1::scalingRomb[i].color % 4];
        RenderMesh2D(meshes[mesh_name], shaders["VertexColor"], modelMatrix);

        // delete romb from array if it is too small
        if (Tema1::scalingRomb[i].scale <= 0) {
			Tema1::scalingRomb.erase(Tema1::scalingRomb.begin() + i);
			continue;
		}

    }
    


    DrawScene(visMatrix);
}


void Tema1::FrameEnd()
{
}


void Tema1::DrawScene(glm::mat3 visMatrix)
{   
    //draw heldromb
    if (Heldromb.color >= 0 && Heldromb.color < 4) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(Heldromb.x, Heldromb.y);
        modelMatrix = visMatrix * modelMatrix;
        string mesh_name = "romb_" + color[Heldromb.color % 4];
        
        RenderMesh2D(meshes[mesh_name], shaders["VertexColor"], modelMatrix);
    }

    // draw pink stars from suns array
    for (int i = 0; i < Tema1::suns.size(); i++) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(Tema1::suns[i].x, Tema1::suns[i].y);
		modelMatrix = visMatrix * modelMatrix;
		RenderMesh2D(meshes["star_pink"], shaders["VertexColor"], modelMatrix);
    }

    // draw suns collected
    for (int i = 0; i < Tema1::sunsCollected.size(); i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(Tema1::sunsCollected[i].x, Tema1::sunsCollected[i].y);
        modelMatrix = visMatrix * modelMatrix;
        RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);
    }


	// draw hearts
	for (int i = 0; i < Tema1::hearts.size(); i++) {
        if (Tema1::hearts[i].alive == 1) {
			modelMatrix = glm::mat3(1);
			modelMatrix *= transform2D::Translate(Tema1::hearts[i].x, Tema1::hearts[i].y);
			modelMatrix = visMatrix * modelMatrix;
			RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
		}
	}

    // place rombs on board
    for (int i = 0; i < Tema1::rombsOnMap.size(); i++) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(Tema1::rombsOnMap[i].x, Tema1::rombsOnMap[i].y);
		modelMatrix = visMatrix * modelMatrix;
		string mesh_name = "romb_" + color[Tema1::rombsOnMap[i].color % 4];
		RenderMesh2D(meshes[mesh_name], shaders["VertexColor"], modelMatrix);
	}
    
    // rectangle 
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(0, 0);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["rect1"], shaders["VertexColor"], modelMatrix);

    // draw green squares from array
    for (int i = 0; i < Tema1::green_squares.size(); i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(Tema1::green_squares[i].x, Tema1::green_squares[i].y);
        modelMatrix = visMatrix * modelMatrix;
        RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);
    }

    // draw up squares from arr
    for (int i = 0; i < Tema1::up_squares.size(); i++) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(Tema1::up_squares[i].x, Tema1::up_squares[i].y);
		modelMatrix = visMatrix * modelMatrix;
		RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);
	}

    // romb
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(3, 7.5);
    modelMatrix *= transform2D::Translate(0.75, 0.8);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["romb_blue"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(7, 7.5);
    modelMatrix *= transform2D::Translate(0.75, 0.8);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["romb_purple"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(5, 7.5);
    modelMatrix *= transform2D::Translate(0.75, 0.8);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["romb_yellow"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1, 7.5);
    modelMatrix *= transform2D::Translate(0.75, 0.8);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["romb_orange"], shaders["VertexColor"], modelMatrix);

    // stars for cost

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1, 7.5);
    modelMatrix *= transform2D::Translate(0.2, -0.4 * length);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(3, 7.5);
    modelMatrix *= transform2D::Translate(0.2, - 0.4 * length);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(3, 7.5);
    modelMatrix *= transform2D::Translate(0.7, -0.4 * length);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(5, 7.5);
    modelMatrix *= transform2D::Translate(0.2, -0.4 * length);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(5, 7.5);
    modelMatrix *= transform2D::Translate(0.7, -0.4 * length);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(7, 7.5);
    modelMatrix *= transform2D::Translate(0.2, -0.4 * length);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(7, 7.5);
    modelMatrix *= transform2D::Translate(0.7, -0.4 * length);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(7, 7.5);
    modelMatrix *= transform2D::Translate(1.2, -0.4 * length);
    modelMatrix = visMatrix * modelMatrix;
    RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);


    // draw red hearts from array
    for (int i = 0; i < Tema1::hearts.size(); i++) {
        if (Tema1::hearts[i].alive == 1) {
			modelMatrix = glm::mat3(1);
			modelMatrix *= transform2D::Translate(Tema1::hearts[i].x, Tema1::hearts[i].y);
			modelMatrix = visMatrix * modelMatrix;
			RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
		}
	}

    // draw lawnMowers
    for (int i = 0; i < Tema1::lawnMower_arr.size(); i++) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(Tema1::lawnMower_arr[i].x, Tema1::lawnMower_arr[i].y);
		modelMatrix = visMatrix * modelMatrix;
		RenderMesh2D(meshes["lawnMower"], shaders["VertexColor"], modelMatrix);
	}

}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
    // generate random hexagons

}


void Tema1::OnKeyPress(int key, int mods)
{
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    float logicDeltaX = deltaX * logicSpace.width / window->GetResolution().x;
    float logicDeltaY = -deltaY * logicSpace.height / window->GetResolution().y;
    Heldromb.x += logicDeltaX;
    Heldromb.y += logicDeltaY;
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
    // when touch a up square
    // creeate coordonates for mouse cursor
    float x = (float)mouseX * logicSpace.width / window->GetResolution().x;
    float y = logicSpace.height - (float)mouseY * logicSpace.height / window->GetResolution().y;

    if (button == 1) {
        for (int i = 0; i < Tema1::up_squares.size(); i++) {
            if (x < Tema1::up_squares[i].x + 1.5 * length && x > Tema1::up_squares[i].x && y < Tema1::up_squares[i].y + 1.5 * length && y > Tema1::up_squares[i].y) {
                // check what romb is picked
                if (x >= 1 && x <= 2.5 && Tema1::collectedSun >= 1) {
                    Heldromb.x = x;
                    Heldromb.y = y;
                    Heldromb.color = 0;
                }
                else if (x >= 3 && x <= 4.5 && Tema1::collectedSun >= 2) {
                    Heldromb.x = x;
                    Heldromb.y = y;
                    Heldromb.color = 1;     
                }
                else if (x >= 5 && x <= 6.5 && Tema1::collectedSun >= 2) {
                    Heldromb.x = x;
                    Heldromb.y = y;
                    Heldromb.color = 2;
                }
                else if (x >= 7 && x <= 8.5 && Tema1::collectedSun >=3) {
                    Heldromb.x = x;
                    Heldromb.y = y;
                    Heldromb.color = 3;
                }
                else {
                    Heldromb.x = 0;
                    Heldromb.y = 0;
                    Heldromb.color = -1;
                }

            }
        }
        // if click on a star, collect it
        for (int i = 0; i < Tema1::suns.size(); i++) {
            if (x < Tema1::suns[i].x + 0.5 && x > Tema1::suns[i].x - 0.5 && y < Tema1::suns[i].y + 0.5 && y > Tema1::suns[i].y - 0.5) {
                // if the maximum amount of sun has been reached, do not
                // add more sun
                if (Tema1::collectedSun < Tema1::maximSun) {
                    Tema1::collectedSun++;
                    // create a new sun the same as the old one and add it on the sunCollected
                    Tema1::Sun sunCollected;

                    sunCollected.x = Tema1::sunDrawPositionX;
                    sunCollected.y = Tema1::sunDrawPositionY;
                    Tema1::sunsCollected.push_back(sunCollected);
                    Tema1::sunDrawPositionX += 0.65;
                    if (Tema1::sunDrawPositionX >= 15.5) {
                        Tema1::sunDrawPositionX = 11;
                        Tema1::sunDrawPositionY -= 0.75;
                    }
                }
                // delete the clicked sun
                Tema1::suns.erase(Tema1::suns.begin() + i);
			}
		}
    }
    else if (button == 2) {
        for (int i = 0; i < Tema1::green_squares.size(); i++) {
            if (x < Tema1::green_squares[i].x + 1.5 * length && x > Tema1::green_squares[i].x && y < Tema1::green_squares[i].y + 1.5 * length && y > Tema1::green_squares[i].y) {
                //check if there is a romb on the green square
                for (int j = 0; j < Tema1::rombsOnMap.size(); j++) {
                    if (Tema1::rombsOnMap[j].x == Tema1::green_squares[i].x + 0.75 && Tema1::rombsOnMap[j].y == Tema1::green_squares[i].y + 0.75) {
						// add romb to scalingRomb
                        Tema1::Romb romb = Tema1::rombsOnMap[j];
                        Tema1::scalingRomb.push_back(romb);
                        
                        // delete romb
						Tema1::rombsOnMap.erase(Tema1::rombsOnMap.begin() + j);
						break;
                    }
				}
            }
        }


    }
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
    if (button == 1 && Heldromb.color >= 0) {
        // if lmb released on a green square, add a romb
        float x = (float)mouseX * logicSpace.width / window->GetResolution().x;
        float y = logicSpace.height - (float)mouseY * logicSpace.height / window->GetResolution().y;
        

        for (int i = 0; i < Tema1::green_squares.size(); i++) {
            if (x < Tema1::green_squares[i].x + 1.5 * length && 
                x > Tema1::green_squares[i].x 
                && y < Tema1::green_squares[i].y + 1.5 * length 
                && y > Tema1::green_squares[i].y) {
                // check if there is a romb on the green square
                bool romb_on_square = false;
                for (int j = 0; j < Tema1::rombsOnMap.size(); j++) {
                    if (Tema1::rombsOnMap[j].x == Tema1::green_squares[i].x + 0.75 && Tema1::rombsOnMap[j].y == Tema1::green_squares[i].y + 0.75) {
                        romb_on_square = true;
                    }
                }
                if (romb_on_square == false) {
                    // draw romb
                    Tema1::Romb romb;
                    romb.x = Tema1::green_squares[i].x + 0.75;
                    romb.y = Tema1::green_squares[i].y + 0.75;
                    romb.color = Heldromb.color;
                    Tema1::rombsOnMap.push_back(romb);
                    // reduce the amount of available sun
                    if (Heldromb.color == 0) {
						Tema1::collectedSun -= 1;
                         //delete sun from sunsCollected
                        Tema1::sunsCollected.erase(Tema1::sunsCollected.begin() + Tema1::sunsCollected.size() - 1);
                         // decrese x
                        Tema1::sunDrawPositionX -= 0.65;
                        if (Tema1::collectedSun == 6 || Tema1::collectedSun == 13 || Tema1::collectedSun == 20) {
                            Tema1::sunDrawPositionX = Tema1::sunsCollected[Tema1::sunsCollected.size() - 1].x + 0.65;
                            Tema1::sunDrawPositionY += 0.75;
                        }
					}
                    else if (Heldromb.color == 1) {
                        for (int i = 0; i < 2; i++) {
                            Tema1::collectedSun -= 1;
                            Tema1::sunsCollected.erase(Tema1::sunsCollected.begin() + Tema1::sunsCollected.size() - 1);
                            // decrese x
                            Tema1::sunDrawPositionX -= 0.65;
                            if (Tema1::collectedSun == 6 || Tema1::collectedSun == 13 || Tema1::collectedSun == 20) {
                                Tema1::sunDrawPositionX = Tema1::sunsCollected[Tema1::sunsCollected.size() - 1].x + 0.65;
                                Tema1::sunDrawPositionY += 0.75;
                            }
                        }
                        
					}
                    else if (Heldromb.color == 2) {
                        for (int i = 0; i < 2; i++) {
                            Tema1::collectedSun -= 1;
                            Tema1::sunsCollected.erase(Tema1::sunsCollected.begin() + Tema1::sunsCollected.size() - 1);
                            // decrese x
                            Tema1::sunDrawPositionX -= 0.65;
                            if (Tema1::collectedSun == 6 || Tema1::collectedSun == 13 || Tema1::collectedSun == 20) {
                                Tema1::sunDrawPositionX = Tema1::sunsCollected[Tema1::sunsCollected.size() - 1].x + 0.65;
                                Tema1::sunDrawPositionY += 0.75;
                            }
                        }
					}
                    else if (Heldromb.color == 3) {
                        for (int i = 0; i < 3; i++) {
                            Tema1::collectedSun -= 1;
                            Tema1::sunsCollected.erase(Tema1::sunsCollected.begin() + Tema1::sunsCollected.size() - 1);
                            // decrese x
                            Tema1::sunDrawPositionX -= 0.65;
                            if (Tema1::collectedSun == 6 || Tema1::collectedSun == 13 || Tema1::collectedSun == 20) {
                                Tema1::sunDrawPositionX = Tema1::sunsCollected[Tema1::sunsCollected.size() - 1].x + 0.65;
                                Tema1::sunDrawPositionY += 0.75;
                            }
                        }
					}
				} 
            
            }
            
		}
        // reset heldromb
        Heldromb.x = 0;
        Heldromb.y = 0;
        Heldromb.color = -1;
        
    }
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}
