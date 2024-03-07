#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquareMesh(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateStarMesh(const std::string& name,glm::vec3 CenterStar, float length,glm::vec3 color);
    Mesh* CreateRectMesh(const std::string& name, glm::vec3 CenterStar, float length, glm::vec3 color);
    Mesh* CreateRombMesh(const std::string& name, glm::vec3 CenterStar, float length, glm::vec3 color);
    Mesh* CreateHexMesh(const std::string& name, glm::vec3 CenterStar, float length, glm::vec3 color, glm::vec3 color2);
    Mesh* CreateHeartMesh(const std::string& name, glm::vec3 CenterStar, float length, glm::vec3 color);
    Mesh* CreateLawnMowerMesh(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color);
}

#pragma once
