#ifndef __QUAD_SHAPE_HPP
#define __QUAD_SHAPE_HPP
namespace Little2DGL{ namespace Graphics
{
    class QuadShape
    {
    private:
        int _width;
        int _height;
        int _vectorSize = 2;
        int _verticesCount = 6;
        unsigned int _VBO;
        unsigned int _VAO;

    public:
        QuadShape(float width, float height);
        void draw();
        
    };
}}
#endif