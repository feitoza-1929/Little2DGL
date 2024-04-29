#include <Renderable.hpp>

namespace L2DGE::Graphics
{
  Renderable::Renderable(Vector2 &position, Vector2 &size, Color &color, unsigned int primitiveType)
      : _position(&position), _size(&size), _color(&color), _primitiveType(primitiveType), _vertexCount(8)
  {
    _shader = new Shader("/home/feitoza/Sources/personal/Little2DGraphicsLib/src/DefaultVertexShader.vert", "/home/feitoza/Sources/personal/Little2DGraphicsLib/src/DefaultFragmentShader.frag");
    _shader->activate();
    _shader->setVariableFloat4("u_Color", new float[4]{color.r, color.g, color.b, color.a});

    float positions[]
    {
	 size.x, size.y,
	 size.x,-size.y,
	-size.x, size.y,
	-size.x, -size.y
    };

    unsigned int indices[]
    {
      0, 1, 2,
      1, 2, 3
    };

    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

    _VBO = new VertexBuffer(GL_ARRAY_BUFFER,  positions, sizeof(positions));
    //glGenBuffers(1, &_VBO);
    //glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    _EBO = new VertexBuffer(GL_ELEMENT_ARRAY_BUFFER,  indices, sizeof(indices));
    //glGenBuffers(1, &_EBO);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    _VBO->unbind();
    _EBO->unbind();
  }

  unsigned int Renderable::getVAO(){ return _VAO; }
  VertexBuffer* Renderable::getEBO(){ return _EBO; }
  VertexBuffer* Renderable::getVBO(){ return _VBO; }

  Color* Renderable::getColor(){ return _color; }
  Vector2* Renderable::getPosition(){ return _position; }
  Vector2* Renderable::getSize(){ return _size; }
  Shader* Renderable::getShader(){ return _shader; }

  unsigned int Renderable::getVertexCount(){ return _vertexCount; }
  unsigned int Renderable::getPrimitiveType() { return _primitiveType; }

  void Renderable::paint(Color &color)
  {
    _color = &color;
    _shader->activate();
    _shader->setVariableFloat4("u_Color", new float[4]{color.r, color.g, color.b, color.a});
  }
  void Renderable::move(const Vector2 &position)
  {
    Transform transform;
    transform.translate(position);
    transform.print();
    
    _shader->activate();
    _shader->setVariableMatrix4("u_Transform", transform.transformation);
  }
  void Renderable::rotate(float angle){}
  void Renderable::scale(const Vector2 &scaleOffset)
  {
    Transform transform;
    transform.scale(scaleOffset);
    transform.print();
    
    _shader->activate();
    _shader->setVariableMatrix4("u_Transform", transform.transformation);
  }
}
