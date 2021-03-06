#include <string>

#include "gl.h"
#include "cl.h"
#include "FreeImage.h"

#include <iostream>
#include <fstream>
#include <cstring> // for std::strlen
#include <cstddef>

using namespace cl;

void glPrintString(void *font, const char *str);

void glPrintString(int x, int y, std::string str);

void setFloat3(cl_float3 &v, float x, float y, float z);

const int X = 0, Y = 1, Z = 2;
const cl_float3 X_VEC = { 1.0f, 0.0f, 0.0f }, Y_VEC = { 0.0f, 1.0f, 0.0f }, Z_VEC = { 0.0f, 0.0f, 1.0f };

const float FOV = 2.0f * tanf(45.0f / 2.0f);

typedef struct Camera_S {
	cl_float3 pos;
	cl_float3 norm;
	cl_float3 left;
	cl_float3 up;
	cl_int2 size;
} Camera;

float dotFloat3(cl_float3 &a, cl_float3 &b);

cl_float3 crossFloat3(cl_float3 &a, cl_float3 &b);

cl_float3 addFloat3(cl_float3 &a, cl_float3 &b);

cl_float3 subFloat3(cl_float3 &a, cl_float3 &b);

cl_float3 multFloat3(cl_float3 &a, cl_float3 &b);

cl_float3 multFloat3(cl_float3 &a, float x, float y, float z);

cl_float3 divFloat3(cl_float3 &a, cl_float3 &b);

cl_float3 scaleFloat3(cl_float3 &a, float b);

cl_float3 normFloat3(cl_float3 &a);

float len2Float3(cl_float3 &a);

float lenFloat3(cl_float3 &a);

float FastInvSqrt(float x);

void setTranCam(Camera &cam, float x, float y, float z);

void tranCam(Camera &cam, float x, float y, float z);

void setRotCam(Camera &cam, float x, float y, float z);

void rotCam(Camera &cam, float x, float y, float z);

void rotXCam(Camera &cam, float x);

void rotYCam(Camera &cam, float y);

void rotZCam(Camera &cam, float z);

cl_float3 transform(cl_float3 a, float m[3][3]);

void makeLUCam(Camera &cam);

///
//  Load an image using the FreeImage library and create an OpenCL
//  image out of it
//
Image2D LoadCLImage(Context context, char *fileName);

typedef struct AABB_s {
	cl_float3 pos;
	cl_float3 half;
	cl_int8 child;

	cl_int value;
} AABB;

void loadVolume(char *fileName, int width, int height, int depth, short ***data, int &min, int &max);

AABB makeAABB(float x, float y, float z, float half, int value);