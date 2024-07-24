#pragma once

#include <cmath>
#include <iostream>

template <typename T> class Vector2 {
public:
  // constructors
  Vector2() = default;

  Vector2(T x, T y) : x(x), y(y) {}

  Vector2(const Vector2 &other_copy) : x(other_copy.x), y(other_copy.y) {}

  template <typename OtherT>
  explicit Vector2(const Vector2<OtherT> &other_copy)
      : x(other_copy.x), y(other_copy.y) {}

  Vector2(Vector2 &&other_move) noexcept : x(other_move.x), y(other_move.y) {}

  template <typename OtherT>
  explicit Vector2(Vector2<OtherT> &&other_move)
      : x(other_move.x), y(other_move.y) {}

  Vector2 &operator=(const Vector2 &other_copy) {
    if (this == &other_copy) {
      return *this;
    }

    x = other_copy.x;
    y = other_copy.y;

    return *this;
  }

  template <typename OtherT>
  Vector2 &operator=(const Vector2<OtherT> &other_copy) {
    x = other_copy.x;
    y = other_copy.y;

    return *this;
  }

  Vector2 &operator=(Vector2 &&other_move) noexcept {
    if (this == &other_move) {
      return *this;
    }

    x = other_move.x;
    y = other_move.y;

    return *this;
  }

  template <typename OtherT> Vector2 &operator=(Vector2<OtherT> &&other_move) {
    if (this == &other_move) {
      return *this;
    }

    x = other_move.x;
    y = other_move.y;

    return *this;
  }

  ~Vector2() = default;

  [[nodiscard]] double Length() const { return sqrt(x * x + y * y); }

  Vector2 GetProjection(const Vector2 &direction) {
    Vector2 dir_normalized = direction;
    dir_normalized.Normalize();
    return dir_normalized * (*this * dir_normalized);
  }

  void Normalize() {
    double length = Length();
    if (length != 0.0f) {
      x /= length;
      y /= length;
    }
  }

  void Resize(double new_length) {
    Normalize();
    (*this) *= new_length;
  }

  void Reflect(const Vector2 &normal) {
    (*this) = 2 * (normal * *this) * normal - (*this);
  }

  [[nodiscard]] double Angle() const { return atan2(y, x); }

  void Rotate(const double d_phi) {
    double length = Length();
    double angle = Angle() + d_phi;
    x = cos(angle) * length;
    y = sin(angle) * length;
  }

  template <typename OtherT> Vector2 &operator+=(const Vector2<OtherT> &right) {
    x += right.x;
    y += right.y;
    return *this;
  }

  template <typename OtherT> Vector2 &operator-=(const Vector2<OtherT> &right) {
    x -= right.x;
    y -= right.y;
    return *this;
  }

  template <typename OtherT> Vector2 &operator*=(const OtherT scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
  }

  Vector2 operator-() const { return Vector2(-x, -y); }

  bool operator==(const Vector2 &right) const {
    return x == right.x && y == right.y;
  }

  template <typename OtherT>
  Vector2 operator+(const Vector2<OtherT> &right) const {
    return Vector2(x + right.x, y + right.y);
  }

  template <typename OtherT>
  Vector2 operator-(const Vector2<OtherT> &right) const {
    return Vector2(x - right.x, y - right.y);
  }

  Vector2 operator*(const double scalar) const {
    return Vector2(x * scalar, y * scalar);
  }

  double operator*(const Vector2 &right) const {
    return x * right.x + y * right.y;
  }

  void Print() const { std::cout << "x: " << x << ", y: " << y << '\n'; }

public:
  T x = 0;
  T y = 0;
};

template <typename T>
Vector2<T> operator*(const double scalar, const Vector2<T> &vector) {
  Vector2<T> res = vector;
  res *= scalar;
  return res;
}

template <typename T>
double Vector2Cos(const Vector2<T> &first, const Vector2<T> &second) {
  T numerator = first * second;
  if (!numerator)
    return 0;
  return numerator / (first.Length() * second.Length());
}

template <typename T>
double Vector2Sin(const Vector2<T> &first, const Vector2<T> &second) {
  T cos = Vector2Cos(first, second);
  return sqrt(1 - cos * cos);
}

typedef Vector2<double> Vector2d;
typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

template <typename T> struct Rect {
  Vector2<T> position;
  Vector2<T> size;

  Rect() = default;

  Rect(const Vector2<T> &position, const Vector2<T> &size)
      : position(position), size(size) {}

  Rect(const T &position_x, const T &position_y, const T &width,
       const T &height)
      : position(position_x, position_y), size(width, height) {}

  Rect(const Rect &other_copy)
      : position(other_copy.position), size(other_copy.size) {}

  template <typename OtherT>
  explicit Rect(const Rect<OtherT> &other_copy)
      : position(other_copy.position), size(other_copy.size) {}

  Rect(Rect &&other_move) noexcept
      : position(other_move.position), size(other_move.size) {}

  template <typename OtherT>
  explicit Rect(Rect<OtherT> &&other_move)
      : position(other_move.position), size(other_move.size) {}

  Rect &operator=(const Rect &other_copy) {
    if (this == &other_copy) {
      return *this;
    }

    position = other_copy.position;
    size = other_copy.size;

    return *this;
  }

  template <typename OtherT> Rect &operator=(const Rect<OtherT> &other_copy) {
    position = other_copy.position;
    size = other_copy.size;

    return *this;
  }

  Rect &operator=(Rect &&other_move) noexcept {
    if (this == &other_move) {
      return *this;
    }

    position = other_move.position;
    size = other_move.size;

    return *this;
  }

  template <typename OtherT> Rect &operator=(Rect<OtherT> &&other_move) {
    if (this == &other_move) {
      return *this;
    }

    position = other_move.position;
    size = other_move.size;

    return *this;
  }

  bool IsPointInRect(const Vector2<T> &point) const {
    return position.x < point.x && point.x < position.x + size.x &&
           position.y < point.y && point.y < position.y + size.y;
  }
};

using IntRect = Rect<int>;
using UIntRect = Rect<unsigned int>;
using FloatRect = Rect<float>;

template <typename T> struct Circle {
  Vector2<T> center;
  T radius;

  Circle() = default;

  Circle(const Vector2<T> &center, const T radius)
      : center(center), radius(radius) {}

  Circle(const T center_x, const T center_y, const T radius)
      : Circle(Vector2<T>(center_x, center_y), radius) {}

  Circle(const Circle &other_copy)
      : center(other_copy.center), radius(other_copy.radius) {}

  template <typename OtherT>
  explicit Circle(const Circle<OtherT> &other_copy)
      : center(other_copy.center), radius(other_copy.radius) {}

  Circle(Circle &&other_move) noexcept
      : center(other_move.center), radius(other_move.radius) {}

  template <typename OtherT>
  explicit Circle(Circle<OtherT> &&other_move)
      : center(other_move.center), radius(other_move.radius) {}

  Circle &operator=(const Circle &other_copy) {
    if (this == &other_copy) {
      return *this;
    }

    center = other_copy.center;
    radius = other_copy.radius;

    return *this;
  }

  template <typename OtherT>
  Circle &operator=(const Circle<OtherT> &other_copy) {
    center = other_copy.center;
    radius = other_copy.radius;

    return *this;
  }

  Circle &operator=(Circle &&other_move) noexcept {
    if (this == &other_move) {
      return *this;
    }

    center = other_move.center;
    radius = other_move.radius;

    return *this;
  }

  template <typename OtherT> Circle &operator=(Circle<OtherT> &&other_move) {
    if (this == &other_move) {
      return *this;
    }

    center = other_move.center;
    radius = other_move.radius;

    return *this;
  }

  bool IsPointInside(const T x, const T y) const {
    return (center.x - x) * (center.x - x) + (center.y - y) * (center.y - y) <=
           radius * radius;
  }

  bool IsPointInside(const Vector2<T> &point) const {
    return IsPointInside(point.x, point.y);
  }
};

using IntCircle = Circle<int>;
using UIntCircle = Circle<unsigned int>;
using FloatCircle = Circle<float>;