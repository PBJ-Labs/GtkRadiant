/*builtinshaders.h*/
#ifndef __BUILTIN_SHADERS__
#define __BUILTIN_SHADERS__

#define SHADER_VERSION "0.0.1"

class RadiantBuiltinShaders {
public:
   RadiantBuiltinShaders();
   ~RadiantBuiltinShaders();

   /*each builtin shader has their own id*/
   int ShaderNumberId;

   bool bShaderTransparent;
   bool bShaderSelected;

   float ShaderScale[3]; //should use vec3_t

};

class RadiantPluginShaderTable{
public:
   RadiantPluginShaderTable();
   ~RadiantPluginShaderTable();

   /*counts when shader is added to a list*/
   int ShaderCount;

};

#endif
