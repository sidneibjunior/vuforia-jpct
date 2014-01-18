/*==============================================================================
 Copyright (c) 2012-2013 Qualcomm Connected Experiences, Inc.
 All Rights Reserved.
 ==============================================================================*/

#include "SampleMath.h"

#include <math.h>
#include <stdlib.h>


QCAR::Vec2F
SampleMath::Vec2FSub(QCAR::Vec2F v1, QCAR::Vec2F v2)
{
    QCAR::Vec2F r;
    r.data[0] = v1.data[0] - v2.data[0];
    r.data[1] = v1.data[1] - v2.data[1];
    return r;
}


float
SampleMath::Vec2FDist(QCAR::Vec2F v1, QCAR::Vec2F v2)
{
    float dx = v1.data[0] - v2.data[0];
    float dy = v1.data[1] - v2.data[1];
    return sqrt(dx * dx + dy * dy);
}


QCAR::Vec3F
SampleMath::Vec3FAdd(QCAR::Vec3F v1, QCAR::Vec3F v2)
{
    QCAR::Vec3F r;
    r.data[0] = v1.data[0] + v2.data[0];
    r.data[1] = v1.data[1] + v2.data[1];
    r.data[2] = v1.data[2] + v2.data[2];
    return r;
}


QCAR::Vec3F
SampleMath::Vec3FSub(QCAR::Vec3F v1, QCAR::Vec3F v2)
{
    QCAR::Vec3F r;
    r.data[0] = v1.data[0] - v2.data[0];
    r.data[1] = v1.data[1] - v2.data[1];
    r.data[2] = v1.data[2] - v2.data[2];
    return r;
}


QCAR::Vec3F
SampleMath::Vec3FScale(QCAR::Vec3F v, float s)
{
    QCAR::Vec3F r;
    r.data[0] = v.data[0] * s;
    r.data[1] = v.data[1] * s;
    r.data[2] = v.data[2] * s;
    return r;
}


float
SampleMath::Vec3FDot(QCAR::Vec3F v1, QCAR::Vec3F v2)
{
    return v1.data[0] * v2.data[0] + v1.data[1] * v2.data[1] + v1.data[2] * v2.data[2];
}


QCAR::Vec3F
SampleMath::Vec3FCross(QCAR::Vec3F v1, QCAR::Vec3F v2)
{
    QCAR::Vec3F r;
    r.data[0] = v1.data[1] * v2.data[2] - v1.data[2] * v2.data[1];
    r.data[1] = v1.data[2] * v2.data[0] - v1.data[0] * v2.data[2];
    r.data[2] = v1.data[0] * v2.data[1] - v1.data[1] * v2.data[0];
    return r;
}


QCAR::Vec3F
SampleMath::Vec3FNormalize(QCAR::Vec3F v)
{
    QCAR::Vec3F r;
    
    float length = sqrt(v.data[0] * v.data[0] + v.data[1] * v.data[1] + v.data[2] * v.data[2]);
    if (length != 0.0f)
        length = 1.0f / length;
    
    r.data[0] = v.data[0] * length;
    r.data[1] = v.data[1] * length;
    r.data[2] = v.data[2] * length;
    
    return r;
}


QCAR::Vec3F
SampleMath::Vec3FTransform(QCAR::Vec3F& v, QCAR::Matrix44F& m)
{
    QCAR::Vec3F r;
    float lambda;
    lambda    = m.data[12] * v.data[0] +
                m.data[13] * v.data[1] +
                m.data[14] * v.data[2] +
                m.data[15];

    r.data[0] = m.data[0] * v.data[0] +
                m.data[1] * v.data[1] +
                m.data[2] * v.data[2] +
                m.data[3];
    r.data[1] = m.data[4] * v.data[0] +
                m.data[5] * v.data[1] +
                m.data[6] * v.data[2] +
                m.data[7];
    r.data[2] = m.data[8] * v.data[0] +
                m.data[9] * v.data[1] +
                m.data[10] * v.data[2] +
                m.data[11];
    
    r.data[0] /= lambda;
    r.data[1] /= lambda;
    r.data[2] /= lambda;

    return r;
}


QCAR::Vec3F
SampleMath::Vec3FTransformNormal(QCAR::Vec3F& v, QCAR::Matrix44F& m)
{
    QCAR::Vec3F r;
    
    r.data[0] = m.data[0] * v.data[0] +
                m.data[1] * v.data[1] +
                m.data[2] * v.data[2];
    r.data[1] = m.data[4] * v.data[0] +
                m.data[5] * v.data[1] +
                m.data[6] * v.data[2];
    r.data[2] = m.data[8] * v.data[0] +
                m.data[9] * v.data[1] +
                m.data[10] * v.data[2];
    
    return r;
}


QCAR::Vec4F
SampleMath::Vec4FTransform(QCAR::Vec4F& v, QCAR::Matrix44F& m)
{
    QCAR::Vec4F r;
    
    r.data[0] = m.data[0] * v.data[0] +
                m.data[1] * v.data[1] +
                m.data[2] * v.data[2] +
                m.data[3] * v.data[3];
    r.data[1] = m.data[4] * v.data[0] +
                m.data[5] * v.data[1] +
                m.data[6] * v.data[2] +
                m.data[7] * v.data[3];
    r.data[2] = m.data[8] * v.data[0] +
                m.data[9] * v.data[1] +
                m.data[10] * v.data[2] +
                m.data[11] * v.data[3];
    r.data[3] = m.data[12] * v.data[0] +
                m.data[13] * v.data[1] +
                m.data[14] * v.data[2] +
                m.data[15] * v.data[3];
    
    return r;
}


QCAR::Vec4F
SampleMath::Vec4FDiv(QCAR::Vec4F v, float s)
{
    QCAR::Vec4F r;
    r.data[0] = v.data[0] / s;
    r.data[1] = v.data[1] / s;
    r.data[2] = v.data[2] / s;
    r.data[3] = v.data[3] / s;
    return r;
}


QCAR::Matrix44F
SampleMath::Matrix44FIdentity()
{
    QCAR::Matrix44F r;
    
    for (int i = 0; i < 16; i++)
        r.data[i] = 0.0f;
    
    r.data[0] = 1.0f;
    r.data[5] = 1.0f;
    r.data[10] = 1.0f;
    r.data[15] = 1.0f;
    
    return r;
}


QCAR::Matrix44F
SampleMath::Matrix44FTranspose(QCAR::Matrix44F m)
{
    QCAR::Matrix44F r;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            r.data[i*4+j] = m.data[i+4*j];
    return r;
}


float
SampleMath::Matrix44FDeterminate(QCAR::Matrix44F& m)
{
    return  m.data[12] * m.data[9] * m.data[6] * m.data[3] - m.data[8] * m.data[13] * m.data[6] * m.data[3] -
            m.data[12] * m.data[5] * m.data[10] * m.data[3] + m.data[4] * m.data[13] * m.data[10] * m.data[3] +
            m.data[8] * m.data[5] * m.data[14] * m.data[3] - m.data[4] * m.data[9] * m.data[14] * m.data[3] -
            m.data[12] * m.data[9] * m.data[2] * m.data[7] + m.data[8] * m.data[13] * m.data[2] * m.data[7] +
            m.data[12] * m.data[1] * m.data[10] * m.data[7] - m.data[0] * m.data[13] * m.data[10] * m.data[7] -
            m.data[8] * m.data[1] * m.data[14] * m.data[7] + m.data[0] * m.data[9] * m.data[14] * m.data[7] +
            m.data[12] * m.data[5] * m.data[2] * m.data[11] - m.data[4] * m.data[13] * m.data[2] * m.data[11] -
            m.data[12] * m.data[1] * m.data[6] * m.data[11] + m.data[0] * m.data[13] * m.data[6] * m.data[11] +
            m.data[4] * m.data[1] * m.data[14] * m.data[11] - m.data[0] * m.data[5] * m.data[14] * m.data[11] -
            m.data[8] * m.data[5] * m.data[2] * m.data[15] + m.data[4] * m.data[9] * m.data[2] * m.data[15] +
            m.data[8] * m.data[1] * m.data[6] * m.data[15] - m.data[0] * m.data[9] * m.data[6] * m.data[15] -
            m.data[4] * m.data[1] * m.data[10] * m.data[15] + m.data[0] * m.data[5] * m.data[10] * m.data[15] ;
}


QCAR::Matrix44F
SampleMath::Matrix44FInverse(QCAR::Matrix44F& m)
{
    QCAR::Matrix44F r;
    
    float det = 1.0f / Matrix44FDeterminate(m);
    
    r.data[0]   = m.data[6]*m.data[11]*m.data[13] - m.data[7]*m.data[10]*m.data[13]
                + m.data[7]*m.data[9]*m.data[14] - m.data[5]*m.data[11]*m.data[14]
                - m.data[6]*m.data[9]*m.data[15] + m.data[5]*m.data[10]*m.data[15];
    
    r.data[4]   = m.data[3]*m.data[10]*m.data[13] - m.data[2]*m.data[11]*m.data[13]
                - m.data[3]*m.data[9]*m.data[14] + m.data[1]*m.data[11]*m.data[14]
                + m.data[2]*m.data[9]*m.data[15] - m.data[1]*m.data[10]*m.data[15];
    
    r.data[8]   = m.data[2]*m.data[7]*m.data[13] - m.data[3]*m.data[6]*m.data[13]
                + m.data[3]*m.data[5]*m.data[14] - m.data[1]*m.data[7]*m.data[14]
                - m.data[2]*m.data[5]*m.data[15] + m.data[1]*m.data[6]*m.data[15];
    
    r.data[12]  = m.data[3]*m.data[6]*m.data[9] - m.data[2]*m.data[7]*m.data[9]
                - m.data[3]*m.data[5]*m.data[10] + m.data[1]*m.data[7]*m.data[10]
                + m.data[2]*m.data[5]*m.data[11] - m.data[1]*m.data[6]*m.data[11];
    
    r.data[1]   = m.data[7]*m.data[10]*m.data[12] - m.data[6]*m.data[11]*m.data[12]
                - m.data[7]*m.data[8]*m.data[14] + m.data[4]*m.data[11]*m.data[14]
                + m.data[6]*m.data[8]*m.data[15] - m.data[4]*m.data[10]*m.data[15];
    
    r.data[5]   = m.data[2]*m.data[11]*m.data[12] - m.data[3]*m.data[10]*m.data[12]
                + m.data[3]*m.data[8]*m.data[14] - m.data[0]*m.data[11]*m.data[14]
                - m.data[2]*m.data[8]*m.data[15] + m.data[0]*m.data[10]*m.data[15];
    
    r.data[9]   = m.data[3]*m.data[6]*m.data[12] - m.data[2]*m.data[7]*m.data[12]
                - m.data[3]*m.data[4]*m.data[14] + m.data[0]*m.data[7]*m.data[14]
                + m.data[2]*m.data[4]*m.data[15] - m.data[0]*m.data[6]*m.data[15];
    
    r.data[13]  = m.data[2]*m.data[7]*m.data[8] - m.data[3]*m.data[6]*m.data[8]
                + m.data[3]*m.data[4]*m.data[10] - m.data[0]*m.data[7]*m.data[10]
                - m.data[2]*m.data[4]*m.data[11] + m.data[0]*m.data[6]*m.data[11];
    
    r.data[2]   = m.data[5]*m.data[11]*m.data[12] - m.data[7]*m.data[9]*m.data[12]
                + m.data[7]*m.data[8]*m.data[13] - m.data[4]*m.data[11]*m.data[13]
                - m.data[5]*m.data[8]*m.data[15] + m.data[4]*m.data[9]*m.data[15];
    
    r.data[6]   = m.data[3]*m.data[9]*m.data[12] - m.data[1]*m.data[11]*m.data[12]
                - m.data[3]*m.data[8]*m.data[13] + m.data[0]*m.data[11]*m.data[13]
                + m.data[1]*m.data[8]*m.data[15] - m.data[0]*m.data[9]*m.data[15];
    
    r.data[10]  = m.data[1]*m.data[7]*m.data[12] - m.data[3]*m.data[5]*m.data[12]
                + m.data[3]*m.data[4]*m.data[13] - m.data[0]*m.data[7]*m.data[13]
                - m.data[1]*m.data[4]*m.data[15] + m.data[0]*m.data[5]*m.data[15];
    
    r.data[14]  = m.data[3]*m.data[5]*m.data[8] - m.data[1]*m.data[7]*m.data[8]
                - m.data[3]*m.data[4]*m.data[9] + m.data[0]*m.data[7]*m.data[9]
                + m.data[1]*m.data[4]*m.data[11] - m.data[0]*m.data[5]*m.data[11];
    
    r.data[3]   = m.data[6]*m.data[9]*m.data[12] - m.data[5]*m.data[10]*m.data[12]
                - m.data[6]*m.data[8]*m.data[13] + m.data[4]*m.data[10]*m.data[13]
                + m.data[5]*m.data[8]*m.data[14] - m.data[4]*m.data[9]*m.data[14];
    
    r.data[7]  = m.data[1]*m.data[10]*m.data[12] - m.data[2]*m.data[9]*m.data[12]
                + m.data[2]*m.data[8]*m.data[13] - m.data[0]*m.data[10]*m.data[13] 
                - m.data[1]*m.data[8]*m.data[14] + m.data[0]*m.data[9]*m.data[14];
    
    r.data[11]  = m.data[2]*m.data[5]*m.data[12] - m.data[1]*m.data[6]*m.data[12]
                - m.data[2]*m.data[4]*m.data[13] + m.data[0]*m.data[6]*m.data[13]
                + m.data[1]*m.data[4]*m.data[14] - m.data[0]*m.data[5]*m.data[14];
    
    r.data[15]  = m.data[1]*m.data[6]*m.data[8] - m.data[2]*m.data[5]*m.data[8]
                + m.data[2]*m.data[4]*m.data[9] - m.data[0]*m.data[6]*m.data[9]
                - m.data[1]*m.data[4]*m.data[10] + m.data[0]*m.data[5]*m.data[10];
    
    for (int i = 0; i < 16; i++)
        r.data[i] *= det;
    
    return r;
}
