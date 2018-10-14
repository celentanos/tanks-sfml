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
    a = 0;
    b = 0;
    c = 0;
    d = 0;
  }

  ////////////////////////////////////////////////////////////
  /// \brief Construct the vector from its coordinates
  ///
  ////////////////////////////////////////////////////////////
  Vector4(T A, T B, T C, T D) {
    a = A;
    b = B;
    c = C;
    d = D;
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
  T a; ///< A coordinate of the vector
  T b; ///< B coordinate of the vector
  T c; ///< C coordinate of the vector
  T d; ///< D coordinate of the vector
};

#endif // DEFINES_H
