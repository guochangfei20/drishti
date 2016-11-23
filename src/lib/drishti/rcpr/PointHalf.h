/*!
  @file   PointHalf.h
  @author David Hirvonen
  @brief  Declaration of half precision floating point 2D point.

  \copyright Copyright 2014-2016 Elucideye, Inc. All rights reserved.
  \license{This project is released under the 3 Clause BSD License.}

*/

#ifndef DRISHTI_RCPR_POINT_HALF_H
#define DRISHTI_RCPR_POINT_HALF_H 1

#include "drishti/rcpr/drishti_rcpr.h"
#include "drishti/core/serialization.h"
#include "half/half.hpp"

DRISHTI_RCPR_NAMESPACE_BEGIN

struct PointHalf
{
    PointHalf() {}

    PointHalf( const cv::Point2f &p )
        : x( half_float::detail::float2half<std::round_to_nearest>(p.x) )
        , y( half_float::detail::float2half<std::round_to_nearest>(p.y) )
    {}

    operator cv::Point2f() const
    {
        return cv::Point2f(asFloat(x), asFloat(y));
    }

    static float asFloat(const half_float::detail::uint16 &src)
    {
        return half_float::detail::half2float(src);
    }

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & x;
        ar & y;
    }

    half_float::detail::uint16 x, y;
};

DRISHTI_RCPR_NAMESPACE_END

#endif // DRISHTI_RCPR_POINT_HALF_H 1
