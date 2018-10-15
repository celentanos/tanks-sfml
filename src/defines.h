#ifndef DEFINES_H
#define DEFINES_H

typedef float myfloat;

// static myfloat MOVE_SPEED = 2;
static const myfloat sprite_size16 = 16;
static const myfloat sprite_size8 = 8;
static const myfloat sprite_size4 = 4;
static const myfloat sprite_scale = 2;

template <typename T> class Vector4 {
public:
  ////////////////////////////////////////////////////////////
  /// \brief Default constructor
  ///
  /// Creates a Vector4(0, 0, 0, 0).
  ///
  ////////////////////////////////////////////////////////////
  Vector4() {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
  }

  ////////////////////////////////////////////////////////////
  /// \brief Construct the vector from its coordinates
  ///
  ////////////////////////////////////////////////////////////
  Vector4(T A, T B, T C, T D) {
    x = A;
    y = B;
    w = C;
    h = D;
  }

  ////////////////////////////////////////////////////////////
  /// \brief Construct the vector from another type of vector
  ///
  /// This constructor doesn't replace the copy constructor,
  /// it's called only when U != T.
  /// A call to this constructor will fail to compile if U
  /// is not convertible to T.
  ///
  /// \param vector Vector to convert
  ///
  ////////////////////////////////////////////////////////////
  //  template <typename U> explicit Vector4(const Vector4<U> &vector);

  ////////////////////////////////////////////////////////////
  // Member data
  ////////////////////////////////////////////////////////////
  T x; ///< A coordinate of the vector
  T y; ///< B coordinate of the vector
  T w; ///< C coordinate of the vector
  T h; ///< D coordinate of the vector
};

#endif // DEFINES_H
