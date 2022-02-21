# Graphics

Contains classes and functions for 3D graphics rendering. For now, only the OpenGL backend is supported. 
First the `framework::graphics::Rendered` needs to be created with a window as render output.

``` cpp
Window main_window("Window name", {800, 640});
Renderer renderer(main_window);
```

Then meshes, shaders, and textures can be loaded to the graphics backend through the renderer.

``` cpp
Mesh mesh;
mesh.set_vertices(...);

Shader shader;
shader.set_vertex_source(...);
shader.set_fragment_source(...);

Texture texture;
texture.set_image(...);

renderer.load(mesh);
renderer.load(shader);
renderer.load(texture);
```

The renderer has global uniforms, that would be passed to each shader on each draw call.
``` cpp
renderer.set_uniform("viewMatrix", camera.get_view());
```
 
And each draw call can be provided with its uniforms.
 
``` cpp
Matrix4f model_matrix = translate(Matrix4f(), Vector3f(0.2f, 0.2f, 0.2f));
renderer.render(mesh, shader, {{"modelMatrix", model_matrix}, {"texture0", texture}});

// Show result on screen
renderer.display();
```
