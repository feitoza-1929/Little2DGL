
namespace L2DGE::Graphics
{
  QuadShape::QuadShape(unsigned int width, unsigned int height, Canvas::Window *canvas)
    {
      unsigned int canvasWidth = canvas->getWidth();
      unsigned int canvasHeight = canvas->getHeight();
      
      
      float nw =(float)width/canvasWidth;
      float nh = (float)height/canvasHeight;
      
      
      const char *vertexShaderPath = "/home/feitoza/Sources/personal/Little2DGraphicsLib/src/DefaultVertexShader.vert";
      const char *fragmentShaderPath = "/home/feitoza/Sources/personal/Little2DGraphicsLib/src/DefaultFragmentShader.frag";

      _shader = Shader(vertexShaderPath, fragmentShaderPath);
      
      float positions[] =
        {
           nw,  nh,
           nw, -nh,
          -nw,  nh,
          -nw, -nh
        };

      unsigned int indices[] =
      {
        0, 1, 2,
        1, 2, 3
      };

      glGenVertexArrays(1, &_VAO);
      glBindVertexArray(_VAO);

      glGenBuffers(1, &_VBO);
      glBindBuffer(GL_ARRAY_BUFFER, _VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

      glGenBuffers(1, &_EBO);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

      glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
      glEnableVertexAttribArray(0);
    }

    void QuadShape::draw()
    {
        _shader.activate();
        glBindVertexArray(_VAO);
        glDrawElements(GL_TRIANGLES, 8, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

  void QuadShape::move(const Vector2& offset)
  {
    Transform transform;
    transform.translate(offset);
    transform.print();
    
    _shader.activate();
    _shader.setVariableMatrix4("u_Transform", transform.transformation);
    
  }

    void QuadShape::paint(Color color)
    {
        _color = color;
        _shader.activate();
        _shader.setVariableFloat4("u_Color", new float[4]{color.r, color.g, color.b, color.a});
    }

    void QuadShape::paint()
    {
        _color = Color();
        _shader.activate();
        _shader.setVariableFloat4("u_Color", new float[4]{_color.r, _color.g, _color.b, _color.a});
    } 
}
