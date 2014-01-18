/*==============================================================================
 Copyright (c) 2012-2013 Qualcomm Connected Experiences, Inc.
 All Rights Reserved.
 ==============================================================================*/

#ifndef _QCAR_SAMPLEMATH_H_
#define _QCAR_SAMPLEMATH_H_

// Includes:
#include <QCAR/Tool.h>

/// A utility class used by the Vuforia SDK samples.
class SampleMath
{
public:
    
    static QCAR::Vec2F Vec2FSub(QCAR::Vec2F v1, QCAR::Vec2F v2);
    
    static float Vec2FDist(QCAR::Vec2F v1, QCAR::Vec2F v2);
    
    static QCAR::Vec3F Vec3FAdd(QCAR::Vec3F v1, QCAR::Vec3F v2);
    
    static QCAR::Vec3F Vec3FSub(QCAR::Vec3F v1, QCAR::Vec3F v2);
    
    static QCAR::Vec3F Vec3FScale(QCAR::Vec3F v, float s);
    
    static float Vec3FDot(QCAR::Vec3F v1, QCAR::Vec3F v2);
    
    static QCAR::Vec3F Vec3FCross(QCAR::Vec3F v1, QCAR::Vec3F v2);
    
    static QCAR::Vec3F Vec3FNormalize(QCAR::Vec3F v);
    
    static QCAR::Vec3F Vec3FTransform(QCAR::Vec3F& v, QCAR::Matrix44F& m);
    
    static QCAR::Vec3F Vec3FTransformNormal(QCAR::Vec3F& v, QCAR::Matrix44F& m);
    
    static QCAR::Vec4F Vec4FTransform(QCAR::Vec4F& v, QCAR::Matrix44F& m);
    
    static QCAR::Vec4F Vec4FDiv(QCAR::Vec4F v1, float s);

    static QCAR::Matrix44F Matrix44FIdentity();
    
    static QCAR::Matrix44F Matrix44FTranspose(QCAR::Matrix44F m);
    
    static float Matrix44FDeterminate(QCAR::Matrix44F& m);
    
    static QCAR::Matrix44F Matrix44FInverse(QCAR::Matrix44F& m);
    
};

#endif // _QCAR_SAMPLEMATH_H_
