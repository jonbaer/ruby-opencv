/************************************************************

   cvpoint2d32f.h -

   $Author: lsxi $

   Copyright (C) 2005 Masakazu Yonekura

************************************************************/
#ifndef RUBY_OPENCV_CVPOINT2D32F_H
#define RUBY_OPENCV_CVPOINT2D32F_H

#define __NAMESPACE_BEGIN_CVPOINT2D32F namespace cCvPoint2D32f{
#define __NAMESPACE_END_CVPOINT2D32F }

#include"opencv.h"

__NAMESPACE_BEGIN_OPENCV
__NAMESPACE_BEGIN_CVPOINT2D32F
    
VALUE rb_class();

void define_ruby_class();

VALUE rb_compatible_q(VALUE klass, VALUE object);

VALUE rb_allocate(VALUE klass);
VALUE rb_initialize(int argc, VALUE *argv, VALUE self);
VALUE rb_x(VALUE self);
VALUE rb_set_x(VALUE self, VALUE x);
VALUE rb_y(VALUE self);
VALUE rb_set_y(VALUE self, VALUE y);

VALUE rb_to_s(VALUE self);
VALUE rb_to_ary(VALUE self);

VALUE new_object(CvPoint2D32f point);

__NAMESPACE_END_CVPOINT2D32F

inline CvPoint2D32f*
CVPOINT2D32F(VALUE object)
{
  CvPoint2D32f *ptr;
  Data_Get_Struct(object, CvPoint2D32f, ptr);
  return ptr;
}

inline CvPoint2D32f
VALUE_TO_CVPOINT2D32F(VALUE object)
{
  if(cCvPoint2D32f::rb_compatible_q(cCvPoint2D32f::rb_class(), object)){
    return cvPoint2D32f(NUM2DBL(rb_funcall(object, rb_intern("x"), 0)),
                        NUM2DBL(rb_funcall(object, rb_intern("y"), 0)));
  }else{
    rb_raise(rb_eTypeError, "require %s or compatible object.", rb_class2name(cCvPoint2D32f::rb_class()));
  }
}

__NAMESPACE_END_OPENCV
#endif // RUBY_OPENCV_CVPOINT2D32F_H
