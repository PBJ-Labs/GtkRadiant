/*builtinshaders.h*/
#ifndef __BUILTIN_SHADERS__
#define __BUILTIN_SHADERS__

#include "radiant/stdafx.h"

#define SHADER_VERSION "0.0.1"

class RadiantBuiltinShaders {
public:
   RadiantBuiltinShaders();
   ~RadiantBuiltinShaders();

   /*each builtin shader has their own id*/
   int ShaderNumberId;

   bool bShaderTransparent;
   bool bShaderSelected;

   const char* Shader;

   float ShaderScale[3]; //should use vec3_t

   unsigned int w;
   unsigned int h;

};

class RadiantPluginShaderTable{
public:
   RadiantPluginShaderTable();
   ~RadiantPluginShaderTable();

   /*counts when shader is added to a list*/
   int ShaderCount;

   bool bShaderAdded;

   const char* ShaderNameAdded(RadiantBultinShaders* pShader){
      return pShader->Shader;
   }

};

#endif
