#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquareMesh(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(1.5 * length, 0, 0), color),
        VertexFormat(corner + glm::vec3(1.5 * length, 1.5 * length, 0), color),
        VertexFormat(corner + glm::vec3(0, 1.5 * length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateLawnMowerMesh(
    const std::string& name,
    glm::vec3 centerLawn ,
    float length,
    glm::vec3 color)
{
    glm::vec3 center = centerLawn;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(center + glm::vec3(0, 0, 1), color),
        VertexFormat(center + glm::vec3(-0.5 * length, -0.5 * length, 1), color),
        VertexFormat(center + glm::vec3(-0.5 * length, 0.5 * length, 1), color),
        VertexFormat(center + glm::vec3(0.5 * length, 0.5 * length, 1), color),
        VertexFormat(center + glm::vec3(0.5 * length, - 0.5  * length, 1), color),
        VertexFormat(center + glm::vec3(1.2 * length, 0, 1), color),
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = 
    { 3, 2, 1, 
      1, 4, 3,
      4, 5, 3};


    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectMesh(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length ,5.5 * length, 0), color),
        VertexFormat(corner + glm::vec3(0, 5.5  * length, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = 
    { 0, 1, 2, 
      2, 3 ,0 
    };


    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* object2D::CreateStarMesh(
    const std::string& name,
    glm::vec3 CenterStar,
    float length,
    glm::vec3 color
    )
{
    glm::vec3 center = CenterStar;

    std::vector<VertexFormat> vertices;
    vertices.push_back(VertexFormat(center, color));
    for (int i = 0; i < 5; i++) {
        
        vertices.push_back(VertexFormat(center + glm::vec3(length * cos(2 * M_PI * i / 5 + M_PI / 2), length * sin(2 * M_PI * i / 5 + M_PI / 2) , 1), color));
    }
    for (int i = 0; i < 5; i++) {
		vertices.push_back(VertexFormat(center + glm::vec3(length / 2 * cos(2 * M_PI * i / 5 + M_PI / 5 + M_PI / 2), length / 2 * sin(2 * M_PI * i / 5 + M_PI / 5 + M_PI / 2), 1), color));
	}

    Mesh* star = new Mesh(name);
    std::vector<unsigned int> indices = 
    { 1, 3, 9,
      5, 2, 8,
      4, 1, 7
    };
            

    star->InitFromData(vertices, indices);
    return star;
}


Mesh* object2D::CreateRombMesh(
    const std::string& name,
    glm::vec3 CenterRomb,
    float length,
    glm::vec3 color)
{
    glm::vec3 center = CenterRomb;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(CenterRomb, color),
        VertexFormat(CenterRomb + glm::vec3(0, 0.6 *  length, 0.5), color),
        VertexFormat(CenterRomb + glm::vec3(- 0.4 * length, 0, 0.5), color),
        VertexFormat(CenterRomb + glm::vec3(0.4 * length ,0 * length, 0.5), color),
        VertexFormat(CenterRomb + glm::vec3(0, -0.6 * length, 0.5), color),
        VertexFormat(CenterRomb + glm::vec3(0, 0.1 * length, 0.5), color), // inner upper point
        VertexFormat(CenterRomb + glm::vec3(0, -0.1 * length, 0.5), color), // inner lower point
        VertexFormat(CenterRomb + glm::vec3(0.7 * length, 0.1 * length, 0.5), color), // outer upper point
        VertexFormat(CenterRomb + glm::vec3(0.7 * length, -0.1 * length, 0.5), color) , // outer lower point

    };

    Mesh* romb = new Mesh(name);
    std::vector<unsigned int> indices = 
    { 1, 2, 3,
      2, 4, 3, 
      7, 5, 0,
      0, 6, 8,
      8, 7, 0
    };


    romb->InitFromData(vertices, indices);
    return romb;
}


Mesh* object2D::CreateHexMesh(
    const std::string& name,
    glm::vec3 CenterHex,
    float length,
    glm::vec3 color,
    glm::vec3 color2)
{
    glm::vec3 center = CenterHex;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(CenterHex + glm::vec3(0, 0, 0.5), color),
        VertexFormat(CenterHex + glm::vec3(0.5 * length, 0, 0.5), color),
        VertexFormat(CenterHex + glm::vec3(0.3 * length, 0.4 * length, 0.5), color),
        VertexFormat(CenterHex + glm::vec3(-0.3 * length ,0.4 * length, 0.5), color),
        VertexFormat(CenterHex + glm::vec3(-0.5 * length, 0, 0.5), color),
        VertexFormat(CenterHex + glm::vec3(-0.3 * length, -0.4 * length, 0.5), color),
        VertexFormat(CenterHex + glm::vec3(0.3 * length, -0.4 * length, 0.5), color),
 
        VertexFormat(CenterHex + glm::vec3(0, 0, 0.75), color2),
        VertexFormat(CenterHex + glm::vec3(0.25 * length, 0, 0.75), color2),
        VertexFormat(CenterHex + glm::vec3(0.15 * length, 0.2 * length, 0.75), color2),
        VertexFormat(CenterHex + glm::vec3(-0.15 * length, 0.2 * length, 0.75), color2),
        VertexFormat(CenterHex + glm::vec3(-0.25 * length, 0, 0.75), color2),
        VertexFormat(CenterHex + glm::vec3(-0.15 * length, -0.2 * length, 0.75), color2),
        VertexFormat(CenterHex + glm::vec3(0.15 * length, -0.2 * length, 0.75), color2),

        
    };

    Mesh* hex = new Mesh(name);
    std::vector<unsigned int> indices = 
    { 
        1, 2, 0,
        2, 3, 0,
        3, 4, 0,
        4, 5, 0,
        5, 6, 0,
        6, 1, 0,
        8, 9, 7,
        9, 10, 7,
        10, 11, 7,
        11, 12, 7,
        12, 13, 7,
        13, 8, 7,
    };


    hex->InitFromData(vertices, indices);
    return hex;
}

Mesh* object2D::CreateHeartMesh(
    const std::string& name,
    glm::vec3 CenterHeart,
    float length,
    glm::vec3 color)
{
    glm::vec3 center = CenterHeart;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(CenterHeart + glm::vec3(0, 0, 0), color),
        VertexFormat(CenterHeart + glm::vec3( 0, -1.1 * length ,0), color), // down
        VertexFormat(CenterHeart + glm::vec3(length, 0, 0), color), //right
        VertexFormat(CenterHeart + glm::vec3(-length ,0, 0), color),// left
        VertexFormat(CenterHeart + glm::vec3(1.5 * length, 1.2 * length, 0), color), // mid left
        VertexFormat(CenterHeart + glm::vec3(-1.5 * length, 1.2 * length, 0), color),// mid right
        VertexFormat(CenterHeart + glm::vec3(1.5 * length, 2 * length, 0), color), // up right 2
        VertexFormat(CenterHeart + glm::vec3(-1.5 * length, 2 * length, 0), color), // up left 2
        VertexFormat(CenterHeart + glm::vec3(0.75 * length, 2.3 * length, 0), color), // up right mid
        VertexFormat(CenterHeart + glm::vec3(-0.75 * length, 2.3 * length, 0), color), // up left mid
        VertexFormat(CenterHeart + glm::vec3(0, 1.7 * length, 0), color), // up 


    };

    Mesh* heart = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        2, 0, 1,
        0, 3, 1,
        2, 4, 0,
        0, 5, 3,
        4, 6, 0,
        0, 7, 5,
        6, 8, 0,
        0, 9, 7,
        8, 10, 0,
        0, 10, 9,
    };


    heart->InitFromData(vertices, indices);
    return heart;
}

